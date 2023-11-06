#pragma once

#include "VocaloidCoreGloble.h"

#include "DatabaseManager.h"
#include "VDMError.h"

namespace vocaloid {
namespace vdm {

class DatabaseManagerIF
{
    DatabaseManagerIF() = delete;
public:
    static DatabaseManager CreateDatabaseManager(const std::wstring& explibPath, VDMError& result);
};

}
}
