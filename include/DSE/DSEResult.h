#pragma once

#include "VocaloidCoreGloble.h"

namespace vocaloid {
namespace dse {

enum DSEResult
{
    Error = -1,
    Successful
};

std::string enumToString(DSEResult error);

}
}
