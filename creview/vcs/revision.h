#pragma once

namespace creview {
namespace vcs {

class Revision {
public:
    virtual std::string name() const = 0;
};

} // namespace vcs
} // namespace creview
