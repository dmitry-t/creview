#include "hints/net/url/path.h"

namespace hints {
namespace net {
namespace url {

Path::Path(const std::string& url, int value)
{
    Poco::URI uri(url);
    std::vector<std::string> segmentStrings;
    uri.getPathSegments(segmentStrings);

    for (auto& segmentString : segmentStrings)
    {
        segments_.push_back({segmentString});
    }
}

bool Path::matches(const Path& other) const
{
    if (segments_.size() != other.segments_.size())
    {
        return false;
    }
    auto i = segments_.begin();
    for (auto& segment : other.segments_)
    {
        if (!i->matches(segment))
        {
            return false;
        }
        ++i;
    }
    return true;
}

int Path::value() const
{

}

} // namespace url
} // namespace net
} // namespace hints
