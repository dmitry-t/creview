#pragma once

namespace creview {
namespace vcs {

class FileDiff {
public:
    class Iterator {
    public:
        bool operator!=() const;
        TextDiff operator*() const;
        Iterator& operator++();
    };
};

} // namespace vcs
} // namespace creview