#pragma once

#include "hints/net/url/segment.h"

#include <string>
#include <vector>

namespace hints {
namespace net {
namespace url {

class Path
{
public:
    Path(const std::string& url, int value);

    bool matches(const Path& other) const;
    int value() const;

private:
    std::vector<Segment> segments_;
};

} // namespace url
} // namespace net
} // namespace hints
