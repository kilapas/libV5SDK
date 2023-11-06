#include "WIVSMSequence.h"

#include <iostream>

using namespace vocaloid::vsm;

extern "C" {
    IMPORT void* VIS_VSM_WIVSMSequence_track(void* cppobjptr, size_t size_t_index);
}

WIVSMSequence::WIVSMSequence(void* pSequence, bool isCreateUnmanagedObj)
{
    if (!pSequence)
        throw std::runtime_error("Not an unmanaged object.");

    _isCreateUnmanagedObj = isCreateUnmanagedObj;
    _cppObjPtr = pSequence;
}

void WIVSMSequence::Dispose()
{
    if (_isCreateUnmanagedObj && _cppObjPtr)
        throw std::runtime_error("The unmanaged object has not been disposed.");
}

WIVSMTrack WIVSMSequence::GetTrack(size_t index)
{
    return WIVSMTrack(VIS_VSM_WIVSMSequence_track(_cppObjPtr, index));
}
