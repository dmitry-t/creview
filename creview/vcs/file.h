#pragma once

#include <string>
#include <vector>

namespace creview {
namespace vcs {

class File
{
public:
    virtual std::string name() const = 0;
    virtual std::vector<std::string> lines() const = 0;
};

} // namespace vcs
} // namespace creview
