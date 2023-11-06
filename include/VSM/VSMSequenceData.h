#pragma once

#include "VocaloidCoreGloble.h"

#include "VSMSamplingRate.h"

namespace vocaloid {
namespace vsm {

struct VSMSequenceData
{
    VSMSamplingRate SamplingRate;
    size_t MaxNumTracks;
    size_t MaxUndoCount;
};

}
}
