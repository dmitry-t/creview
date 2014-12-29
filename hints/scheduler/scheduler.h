#pragma once

#include "Poco/Timestamp.h"

#include <chrono>
#include <functional>

namespace hints {
namespace scheduler {

class Scheduler
{
public:
    typedef Poco::Timestamp Timestamp;

    virtual void schedule(
        std::function<void()> job,
        Timestamp timestamp) = 0;
};

} // namespace scheduler
} // namespace hints
