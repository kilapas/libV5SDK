#include "DSEManagerIF.h"

#include <iostream>

#include "DSEManager.h"
#include "DSEResult.h"
#include "VDM/DatabaseManager.h"

using namespace vocaloid::dse;
using namespace vocaloid::vdm;

extern "C" {
    IMPORT void* VIS_DSE_CreateManager();
    IMPORT DSEResult VIS_DSE_InitializeManager(void* pDSEManager, void* pDatabaseManager);
    IMPORT DSEResult VIS_DSE_TerminateManager(void* pDSEManager);
    IMPORT void VIS_DSE_DestroyManager(void* pDSEManager);
}

DSEManager DSEManagerIF::CreateManager(const vdm::DatabaseManager& databaseManager, std::string& error)
{
    if (!databaseManager)
    {
        error = "param is null";
        return {};
    }

    void* manager = VIS_DSE_CreateManager();
    if (!manager)
    {
        error = "create failed";
        return {};
    }

    DSEResult result = VIS_DSE_InitializeManager(manager, databaseManager);
    if (result != DSEResult::Successful)
    {
        error = "init failed: " + enumToString(result);
        return {};
    }

    return DSEManager(manager);
}

void DSEManagerIF::DestroyManager(const DSEManager& dseManager)
{
    if (!dseManager)
        return;

    if (VIS_DSE_TerminateManager(dseManager) != DSEResult::Successful)
        throw std::runtime_error("DSE terminate failed.");

    VIS_DSE_DestroyManager(dseManager);
}
