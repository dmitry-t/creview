#pragma once

#include <string>

namespace hints {
namespace net {
namespace url {

class Segment
{
public:
    explicit Segment(std::string value);

    bool operator==(const Segment& rhs) const;
    const std::string& value() const;
    bool isParam() const;

private:
    std::string value_;
    bool isParam_;
};

} // namespace url
} // namespace net
} // namespace hints
