#pragma once

#include <string>

namespace vocaloid {
namespace vdm {
class DatabaseManager;
}

namespace vsm {
class WIVSMSequenceManager;
}

bool Init(const std::wstring& vocaloidPath, std::string& error);
void Destroy();

vdm::DatabaseManager& getDatabaseManager();
vsm::WIVSMSequenceManager& getSequenceManager();

};
