#pragma once

#include "VocaloidCoreGloble.h"

namespace vocaloid {
namespace vsm {
class WIVSMSequenceManager;

class WVSMModuleIF
{
    WVSMModuleIF() = delete;
public:
    static WIVSMSequenceManager CreateManager(const std::wstring& appID, const std::wstring& vsqxSchemaDirPath, std::string& error);
    static void RemoveManager(const WIVSMSequenceManager& sequenceMgr);

private:
    static std::unordered_map<std::wstring, void*> _managers;
};

}
}
