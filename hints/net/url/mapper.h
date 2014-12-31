#pragma once

#include "hints/net/url/path.h"

#include <string>
#include <vector>

namespace hints {
namespace net {
namespace url {

class Mapper {
public:
    typedef Path::Params Params;

    void put(const std::string& url, size_t id);
    bool get(const std::string& url, Params& params, size_t& id) const;

private:
    const Path* find(const Path& path) const;

    std::vector<Path> paths_;
};

} // namespace url
} // namespace net
} // namespace hints
