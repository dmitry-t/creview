#include <algorithm>

#include "hints/net/url/path.h"

#include "Poco/URI.h"

namespace hints {
namespace net {
namespace url {

Path::Path(const std::string& url, int value) :
    value_(value)
{
    Poco::URI uri(url);
    std::vector<std::string> segmentStrings;
    uri.getPathSegments(segmentStrings);

    for (auto& segmentString : segmentStrings)
    {
        segments_.push_back(Segment(segmentString));
    }
}

bool Path::operator==(const Path& rhs) const
{
    return segments_.size() == rhs.segments_.size() && std::equal(
        segments_.begin(),
        segments_.end(),
        rhs.segments_.begin());
}

int Path::value() const
{
    return value_;
}

} // namespace url
} // namespace net
} // namespace hints
