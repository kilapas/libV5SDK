#include "VocaloidCore.h"

#include "VDM/DatabaseManagerIF.h"
#include "VDM/DatabaseManager.h"
#include "VDM/VDMError.h"
#include "DSE/DSEManagerIF.h"
#include "DSE/DSEManager.h"
#include "VSM/WVSMModuleIF.h"
#include "VSM/WIVSMSequenceManager.h"

using namespace vocaloid::vdm;
using namespace vocaloid::dse;
using namespace vocaloid::vsm;

namespace vocaloid {

std::wstring mVocaloidPath;
void InitPath(const std::wstring& vocaloidPath)
{
    mVocaloidPath = vocaloidPath;
    if (mVocaloidPath.back() != L'\\')
    {
        mVocaloidPath += L'\\';
    }
}

DatabaseManager mDatabaseManager {};
bool InitVDM(std::string& error)
{
    VDMError vdmerror = (VDMError)(-1);
    mDatabaseManager = DatabaseManagerIF::CreateDatabaseManager(mVocaloidPath + L"Explib\\", vdmerror);
    if (!mDatabaseManager || vdmerror != VDMError::None)
    {
        error = enumToString(vdmerror);
        return false;
    }

    return true;
}

DSEManager mDSEManager {};
bool InitDSE(std::string& error)
{
    mDSEManager = DSEManagerIF::CreateManager(mDatabaseManager, error);
    if (!mDSEManager)
        return false;

    return true;
}

WIVSMSequenceManager mSequenceManager {};
bool InitVSM(std::string& error)
{
    mSequenceManager = WVSMModuleIF::CreateManager(APP_ID, mVocaloidPath, error);
    if (!mSequenceManager)
        return false;

    mSequenceManager.SetDatabaseManager(mDatabaseManager);
    mSequenceManager.SetDSEManager(mDSEManager);

    return true;
}

bool Init(const std::wstring& vocaloidPath, std::string& error)
{
    InitPath(vocaloidPath);

    std::string vdmError;
    if (!InitVDM(vdmError))
    {
        error = "Init VDM fail: " + vdmError;
        return false;
    }

    std::string dseError;
    if (!InitDSE(dseError))
    {
        error = "Init DSE fail: " + dseError;
        return false;
    }

    std::string vsmError;
    if (!InitVSM(vsmError))
    {
        error = "Init VSM fail: " + vsmError;
        return false;
    }

    return true;
}

void Destroy()
{
    if (mSequenceManager)
    {
        mSequenceManager.Dispose();
        mSequenceManager = {};
    }

    if (mDSEManager)
    {
        mDSEManager.Dispose();
        mDSEManager = {};
    }

    if (mDatabaseManager)
    {
        mDatabaseManager.Dispose();
        mDatabaseManager = {};
    }
}

DatabaseManager& GetDatabaseManager()
{
    return mDatabaseManager;
}

WIVSMSequenceManager& GetSequenceManager()
{
    return mSequenceManager;
}

}
