#pragma once

#include "hints/planner/task_status.h"

namespace hints {
namespace planner {

class Task
{
public:
    TaskStatus status() const = 0;
};

} // namespace planner
} // namespace hints
