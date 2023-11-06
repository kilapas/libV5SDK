#pragma once

#include "VocaloidCoreGloble.h"

#include "WIVSMPart.h"

namespace vocaloid {
namespace vsm {

class WIVSMTrack
{
    DECLARE_AS_MANAGED(WIVSMTrack)
public:
    WIVSMPart GetPart(size_t index);
};

}
}
