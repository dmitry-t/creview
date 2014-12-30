#include "hints/net/url/segment.h"

namespace hints {
namespace net {
namespace url {

Segment::Segment(std::string value) :
    value_(std::move(value))
{
}

bool Segment::operator==(const std::string& rhs) const
{
    return value_ == rhs;
}

void Segmnent::addNext(Segment segment)
{
    next_.push_back(std::move(segment));
}

} // namespace url
} // namespace net
} // namespace hints
