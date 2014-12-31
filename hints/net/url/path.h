#pragma once

#include "hints/net/url/segment.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace hints {
namespace net {
namespace url {

class Path
{
public:
    typedef std::unordered_map<std::string, std::string> Params;

    Path(const std::string& url, size_t id);

    bool operator==(const Path& rhs) const;
    void extract(Path& concretePath, Params& params, size_t& value) const;

private:
    std::vector<Segment> segments_;
    size_t id_;
};

} // namespace url
} // namespace net
} // namespace hints
