#pragma once

#include "hints/net/url/segment.h"

#include <string>
#include <vector>

namespace hints {
namespace net {
namespace url {

class Mapper {
public:
    typedef int T;
    void put(const std::string& url, T value);
    
private:
    Segment root_;
};

} // namespace url
} // namespace net
} // namespace hints
