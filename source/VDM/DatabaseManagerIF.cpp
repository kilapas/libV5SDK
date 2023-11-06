#include "DatabaseManagerIF.h"

#include "DatabaseManager.h"
#include "VDMError.h"

using namespace vocaloid::vdm;

extern "C" {
    IMPORT void* VDM_createDatabaseManager(const wchar_t* appID, const wchar_t* expDBDirPath, VDMError& result);
}

DatabaseManager DatabaseManagerIF::CreateDatabaseManager(const std::wstring& explibPath, VDMError& error)
{
    if (explibPath.empty())
    {
        error = ExpDBPathNotFound;
        return {};
    }

    DatabaseManager manager {};
    try
    {
        DatabaseManager databaseManager(VDM_createDatabaseManager(APP_ID, explibPath.c_str(), error));
        manager = ((error != VDMError::None) ? DatabaseManager() : databaseManager);
    }
    catch (...)
    {
        manager = {};
    }

    return manager;
}
