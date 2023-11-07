#pragma once

#include "VocaloidCoreGloble.h"

#include "VoiceBank.h"

namespace vocaloid {
namespace vdm {

class DatabaseManager
{
    DECLARE_AS_MANAGED(DatabaseManager)
public:
    size_t NumVoiceBanks();
    VoiceBank GetVoiceBankByIndex(size_t index);
    VoiceBank GetVoiceBankByCompID(const std::wstring& compID);
};

}
}
