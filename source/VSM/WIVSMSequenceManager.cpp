#include "WIVSMSequenceManager.h"

#include <iostream>

#include "WVSMModuleIF.h"
#include "VDM/DatabaseManager.h"
#include "DSE/DSEManager.h"

using namespace vocaloid::vsm;

extern "C" {
    IMPORT bool VIS_VSM_WIVSMSequenceManager_destroy(void* cppobjptr);
    IMPORT void VIS_VSM_WIVSMSequenceManager_setDatabaseManager(void* cppobjptr, void* databaseManager);
    IMPORT void VIS_VSM_WIVSMSequenceManager_setDSEManager(void* cppobjptr, void* dseManager);
    IMPORT void* VIS_VSM_WIVSMSequenceManager_openSequence(void* cppobjptr, const wchar_t* filePath, const wchar_t* vsqxSchemaDirPath, VSMSequenceData& sequenceData);
}

WIVSMSequenceManager::WIVSMSequenceManager(void* pSeqMgr, const std::wstring& vsqxSchemaDirPath, bool isCreateUnmanagedObj)
{
    if (!pSeqMgr)
        throw std::runtime_error("Not an unmanaged object.");
    
    _isCreateUnmanagedObj = isCreateUnmanagedObj;
    _cppObjPtr = pSeqMgr;
    _vsqxSchemaDirPath = vsqxSchemaDirPath;
}

void WIVSMSequenceManager::Dispose()
{
    if (_isCreateUnmanagedObj)
    {
        if (_cppObjPtr)
        {
            if (!VIS_VSM_WIVSMSequenceManager_destroy(_cppObjPtr))
                throw std::runtime_error("Failed to destroy the sequence manager.");

            WVSMModuleIF::RemoveManager(*this);
            _cppObjPtr = nullptr;
        }
        _isCreateUnmanagedObj = false;
        return;
    }
    _cppObjPtr = nullptr;
}

void WIVSMSequenceManager::SetDatabaseManager(const vdm::DatabaseManager& databaseManager)
{
    VIS_VSM_WIVSMSequenceManager_setDatabaseManager(_cppObjPtr, databaseManager);
}

void WIVSMSequenceManager::SetDSEManager(const dse::DSEManager& dseManager)
{
    VIS_VSM_WIVSMSequenceManager_setDSEManager(_cppObjPtr, dseManager);
}

WIVSMSequence WIVSMSequenceManager::OpenSequence(const std::wstring& filePath, VSMSequenceData sequenceData)
{
    if (filePath.empty() || _vsqxSchemaDirPath.empty())
        return {};

    void* intPtr = VIS_VSM_WIVSMSequenceManager_openSequence(_cppObjPtr, filePath.c_str(), _vsqxSchemaDirPath.c_str(), sequenceData);
    if (!intPtr)
        return {};

    return WIVSMSequence(intPtr, true);
}
