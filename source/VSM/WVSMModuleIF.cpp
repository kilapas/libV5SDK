#include "WVSMModuleIF.h"

#include "WIVSMSequenceManager.h"

using namespace vocaloid::vsm;

extern "C" {
    IMPORT void* VIS_VSM_WVSMModuleIF_createManager(const wchar_t* appID);
}

std::unordered_map<std::wstring, void*> WVSMModuleIF::_managers;

WIVSMSequenceManager WVSMModuleIF::CreateManager(const std::wstring& appID, const std::wstring& vsqxSchemaDirPath, std::string& error)
{
    if (appID.empty())
    {
        error = "param is empty";
        return {};
    }

    if (_managers.count(appID) > 0)
    {
        return WIVSMSequenceManager(_managers[appID], vsqxSchemaDirPath, false);
    }

    void* intPtr = VIS_VSM_WVSMModuleIF_createManager(appID.c_str());
    if (intPtr)
    {
        _managers[appID] = intPtr;
        return WIVSMSequenceManager(intPtr, vsqxSchemaDirPath, true);
    }

    error = "create failed";
    return {};
}

void WVSMModuleIF::RemoveManager(const WIVSMSequenceManager& sequenceMgr)
{
    for (const auto& keyValuePair : _managers)
    {
        if (keyValuePair.second == sequenceMgr)
        {
            _managers.erase(keyValuePair.first);
            break;
        }
    }
}
