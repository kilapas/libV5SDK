#pragma once

#include "VocaloidCoreGloble.h"

#include "VSMResult.h"

namespace vocaloid {
namespace vsm {

class WIVSMPart
{
    DECLARE_AS_MANAGED(WIVSMPart)
public:
    VSMResult Render(const std::wstring& path);
};

}
}
