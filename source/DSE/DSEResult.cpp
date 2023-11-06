#include "DSEResult.h"

#include <map>

std::string vocaloid::dse::enumToString(DSEResult result)
{
    static std::map<DSEResult, std::string> map = {
        { Error, "Error" },
        { Successful, "Successful" }
    };

    auto it = map.find(result);
    if (it != map.end())
        return it->second;

    return "Unknown";
}
