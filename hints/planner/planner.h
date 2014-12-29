#pragma once

namespace hints {
namespace planner {

class Planner
{
public:
    virtual void startTask(std::unique_ptr<Task>&& task) = 0;
};

} // namespace planner
} // namespace hints
