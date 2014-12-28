#pragma once

namespace creview {
namespace vcs {

class DirectoryItem
{
public:
    virtual Directory* directory() = 0;
    virtual File* file() = 0;
};

} // namespace vcs
} // namespace creview
