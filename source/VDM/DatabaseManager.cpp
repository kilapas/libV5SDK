#include "DatabaseManager.h"

#include <iostream>

using namespace vocaloid::vdm;

extern "C" {
    IMPORT void VDM_DatabaseManager_destroy(void* manager);
}

void DatabaseManager::Dispose()
{
    VDM_DatabaseManager_destroy(_cppObjPtr);
    _cppObjPtr = nullptr;
}
