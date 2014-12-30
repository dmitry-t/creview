#pragma once

#include "hints/net/url/path.h"

#include <string>
#include <vector>

namespace hints {
namespace net {
namespace url {

class Mapper {
public:
    typedef int T;
    void put(const std::string& url, T value);
    bool get(const std::string& url, T& result) const;

private:
    const Path* find(const Path& path) const;

    std::vector<Path> paths_;
};

} // namespace url
} // namespace net
} // namespace hints
