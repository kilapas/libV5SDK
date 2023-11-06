#pragma once

#include "VocaloidCoreGloble.h"

#include "WIVSMTrack.h"

namespace vocaloid {
namespace vsm {

class WIVSMSequence
{
    DECLARE_AS_MANAGED(WIVSMSequence)
public:
    explicit WIVSMSequence(void* pSequence, bool isCreateUnmanagedObj = false);
    WIVSMTrack GetTrack(size_t index);

private:
    bool _isCreateUnmanagedObj;
};

}
}
