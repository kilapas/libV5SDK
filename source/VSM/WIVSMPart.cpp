#include "WIVSMPart.h"

using namespace vocaloid::vsm;

extern "C" {
    IMPORT VSMResult VIS_VSM_WIVSMMidiPart_render(void* cppobjptr, const wchar_t* path);
}

VSMResult WIVSMPart::Render(const std::wstring& path)
{
    if (path.empty())
        return InvalidArgument;

    return VIS_VSM_WIVSMMidiPart_render(_cppObjPtr, path.c_str());
}
