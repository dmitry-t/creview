#pragma once

#include "hints/scheduler/scheduler.h"

#include "Poco/Util/Timer.h"
#include "Poco/Util/TimerTask.h"

#include <memory>

namespace hints {
namespace scheduler {

class SchedulerImpl : public Scheduler
{
public:
    virtual void schedule(
        std::function<void()> job,
        Timestamp timestamp) override;

private:
    Poco::Util::Timer timer_;
};

} // namespace scheduler
} // namespace hints
