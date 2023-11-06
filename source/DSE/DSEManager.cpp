#include "DSEManager.h"

#include <iostream>

#include "DSEManagerIF.h"

using namespace vocaloid::dse;

void DSEManager::Dispose()
{
    DSEManagerIF::DestroyManager(*this);
    _cppObjPtr = nullptr;
}
