#include "hints/net/url/mapper.h"

#include "Poco/URI.h"

#include <stdexcept>

namespace hints {
namespace net {

void Mapper::put(const std::string& url, T value)
{
    Poco::URI uri(url);
    std::vector<std::string> segments;
    uri.getPathSegments(segments);
    for (auto& segment : segments)
    {
        if (segment.empty())
        {
            throw std::logic_error("Empty URL path segment");
        }
        
        if (segment[0] != '{')
        {
            continue;
        }
    }
}

} // namespace net
} // namespace hints
