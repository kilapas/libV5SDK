#pragma once

#include "VocaloidCoreGloble.h"

#include "WIVSMSequence.h"
#include "VSMSequenceData.h"

namespace vocaloid {
namespace vdm {
class DatabaseManager;
}

namespace dse {
class DSEManager;
}

namespace vsm {

class WIVSMSequenceManager
{
    DECLARE_AS_MANAGED(WIVSMSequenceManager)
public:
    explicit WIVSMSequenceManager(void* pSeqMgr, const std::wstring& vsqxSchemaDirPath, bool isCreateUnmanagedObj = false);

    void SetDatabaseManager(const vdm::DatabaseManager& databaseManager);
    void SetDSEManager(const dse::DSEManager& dseManager);

    WIVSMSequence OpenSequence(const std::wstring& filePath, VSMSequenceData sequenceData);

private:
    bool _isCreateUnmanagedObj;
    std::wstring _vsqxSchemaDirPath;
};

}
}
