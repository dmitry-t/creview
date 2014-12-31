#include "hints/net/url/segment.h"

#include <stdexcept>

namespace hints {
namespace net {
namespace url {

Segment::Segment(std::string value) :
    value_(std::move(value)), isParam_(false)
{
    if (value_.empty())
    {
        throw std::logic_error("Empty URL path segment");
    }
    if (value_[0] == '{')
    {
        if (value_.back() != '}')
        {
            throw std::logic_error("Unbalanced curly bracket");
        }
        value_.erase(0, 1);
        value_.erase(value_.size() - 1);
        isParam_ = true;
    }
}

bool Segment::operator==(const Segment& rhs) const
{
    if (isParam() || rhs.isParam())
    {
        return true;
    }
    return value_ == rhs.value();
}

const std::string& Segment::value() const
{
    return value_;
}

bool Segment::isParam() const
{
    return isParam_;
}

} // namespace url
} // namespace net
} // namespace hints
