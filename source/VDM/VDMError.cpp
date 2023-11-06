#include "VDMError.h"

#include <map>

std::string vocaloid::vdm::enumToString(VDMError error)
{
    static std::map<VDMError, std::string> map = {
        { None, "None" },
        { OutOfMemory, "OutOfMemory" },
        { FailedToLoadModule, "FailedToLoadModule" },
        { ExportedSymbolNotFound, "ExportedSymbolNotFound" },
        { InvalidAppID, "InvalidAppID" },
        { FailedToInitSetting, "FailedToInitSetting" },
        { FailedToOpenSystemSetting, "FailedToOpenSystemSetting" },
        { DatabaseKeyNotFound, "DatabaseKeyNotFound" },
        { InvalidComponent, "InvalidComponent" },
        { UninstalledComponent, "UninstalledComponent" },
        { InvalidCompID, "InvalidCompID" },
        { VoiceBankNotFound, "VoiceBankNotFound" },
        { ExpDBPathNotFound, "ExpDBPathNotFound" },
        { InvalidVibratoTemplateType, "InvalidVibratoTemplateType" },
        { ActivationInfoNotFound, "ActivationInfoNotFound" }
    };

    auto it = map.find(error);
    if (it != map.end())
        return it->second;

    return "Unknown";
}
