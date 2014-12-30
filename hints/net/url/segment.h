#pragma once

#include <string>

namespace hints {
namespace net {
namespace url {

class Segment
{
public:
    explicit Segment(std::string value);

    bool matches(const Segment& segment) const;
    const std::string& value() const;
    bool isParam() const;

private:
    std::string value_;
};

} // namespace url
} // namespace net
} // namespace hints
