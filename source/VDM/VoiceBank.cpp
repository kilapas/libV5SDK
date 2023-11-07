#include "VoiceBank.h"

using namespace vocaloid::vdm;

extern "C" {
    IMPORT const wchar_t* VDM_VoiceBank_compID(void* voiceBankHandle);
    IMPORT const wchar_t* VDM_VoiceBank_name(void* voiceBankHandle);
    IMPORT int VDM_VoiceBank_langID(void* voiceBankHandle);
}

const wchar_t* VoiceBank::CompID()
{
    return VDM_VoiceBank_compID(_cppObjPtr);
}

const wchar_t* VoiceBank::Name()
{
    return VDM_VoiceBank_name(_cppObjPtr);
}

int VoiceBank::LangID()
{
    return VDM_VoiceBank_langID(_cppObjPtr);
}
