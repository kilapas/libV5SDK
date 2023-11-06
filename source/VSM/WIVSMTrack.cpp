#include "WIVSMTrack.h"

using namespace vocaloid::vsm;

extern "C" {
    IMPORT void* VIS_VSM_WIVSMMidiTrack_part(void* cppobjptr, size_t size_t_index);
}

WIVSMPart WIVSMTrack::GetPart(size_t index)
{
    return WIVSMPart(VIS_VSM_WIVSMMidiTrack_part(_cppObjPtr, index));
}
