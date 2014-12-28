#pragma once

#include <string>
#include <vector>

namespace creview {
namespace vcs {

class DirectoryItem;

} // namespace vcs
} // namespace creview

namespace creview {
namespace vcs {

class Directory
{
public:
    virtual std::string name() const = 0;
    virtual std::vector<DirectoryItem*> items() const = 0;
};

} // namespace vcs
} // namespace creview
