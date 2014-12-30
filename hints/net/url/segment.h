#pragma once

#include <string>
#include <vector>

namespace hint {
namespace net {
namespace url {

class Segment
{
public:
    Segment(std::string value);

    bool operator==(const std::string& rhs) const;
    void addNext(Segment segment);

private:
    std::string value_;
    std::vector<Segment> next_;
};

} // namespace url
} // namespace net
} // namespace hint
