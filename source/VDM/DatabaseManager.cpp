#include "DatabaseManager.h"

#include <iostream>

using namespace vocaloid::vdm;

extern "C" {
    IMPORT void VDM_DatabaseManager_destroy(void* manager);
    IMPORT size_t VDM_DatabaseManager_numVoiceBanks(void* manager);
    IMPORT void* VDM_DatabaseManager_voiceBankByIndex(void* manager, size_t size_t_index);
    IMPORT void* VDM_DatabaseManager_voiceBankByCompID(void* manager, const wchar_t* compID);
}

void DatabaseManager::Dispose()
{
    VDM_DatabaseManager_destroy(_cppObjPtr);
    _cppObjPtr = nullptr;
}

size_t DatabaseManager::NumVoiceBanks()
{
    return VDM_DatabaseManager_numVoiceBanks(_cppObjPtr);
}

VoiceBank DatabaseManager::GetVoiceBankByIndex(size_t index)
{
    return VoiceBank(VDM_DatabaseManager_voiceBankByIndex(_cppObjPtr, index));
}

VoiceBank DatabaseManager::GetVoiceBankByCompID(const std::wstring& compID)
{
    return VoiceBank(VDM_DatabaseManager_voiceBankByCompID(_cppObjPtr, compID.c_str()));
}
