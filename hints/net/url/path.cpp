#include <algorithm>

#include "hints/net/url/path.h"

#include "Poco/URI.h"

namespace hints {
namespace net {
namespace url {

Path::Path(const std::string& url, size_t id) :
    id_(id)
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

void Path::extract(Path& concretePath, Params& params, size_t& id) const
{
    params.clear();
    for (size_t i = 0; i < segments_.size(); ++i)
    {
        auto& ownSegment = segments_[i];
        auto& concreteSegment = concretePath.segments_[i];
        if (ownSegment.isParam())
        {
            params.emplace(
                ownSegment.value(),
                concreteSegment.value());
        }
    }
    id = id_;
}

} // namespace url
} // namespace net
} // namespace hints
