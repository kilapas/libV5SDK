#pragma once

#include "VocaloidCoreGloble.h"

namespace vocaloid {
namespace vdm {

class VoiceBank
{
    DECLARE_AS_MANAGED(VoiceBank)
public:
    const wchar_t* CompID();
    const wchar_t* Name();
    int LangID();
};

}
}
