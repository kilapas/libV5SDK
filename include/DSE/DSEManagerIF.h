#pragma once

#include "VocaloidCoreGloble.h"

namespace vocaloid {
namespace vdm {
class DatabaseManager;
}

namespace dse {
class DSEManager;

class DSEManagerIF
{
    DSEManagerIF() = delete;
public:
    static DSEManager CreateManager(const vdm::DatabaseManager& databaseManager, std::string& error);
    static void DestroyManager(const DSEManager& dseManager);
};

}
}
