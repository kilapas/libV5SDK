#pragma once

#include "VocaloidCoreGloble.h"

namespace vocaloid {
namespace vdm {

enum VDMError
{
    None,
    OutOfMemory,
    FailedToLoadModule,
    ExportedSymbolNotFound,
    InvalidAppID,
    FailedToInitSetting,
    FailedToOpenSystemSetting,
    DatabaseKeyNotFound,
    InvalidComponent,
    UninstalledComponent,
    InvalidCompID,
    VoiceBankNotFound,
    ExpDBPathNotFound,
    InvalidVibratoTemplateType,
    ActivationInfoNotFound
};

std::string enumToString(VDMError error);

}
}
