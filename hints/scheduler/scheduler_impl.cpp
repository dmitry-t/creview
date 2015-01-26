#include "hints/scheduler/scheduler_impl.h"
#include "Poco/Util/TimerTask.h"
#include "Poco/Util/TimerTaskAdapter.h"

namespace hints {
namespace scheduler {

void SchedulerImpl::schedule(
    std::function<void()> job,
    Timestamp timestamp)
{
    struct TimerTask : public Poco::Util::TimerTask, std::function<void()>
    {
        TimerTask(std::function<void()> job) :
                std::function<void()>(std::move(job)) {}

        virtual void run() override
        {
            (*this)();
        }
    };

    timer_.schedule(new TimerTask(job), timestamp);
}

} // namespace scheduler
} // namespace hints
