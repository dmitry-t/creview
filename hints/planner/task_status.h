#pragma once

namespace hints {
namespace planner {

enum class TaskStatus
{
    CREATED = 0,
    STARTED,
    SUSPENDED,
    CLOSED,
    CANCELLED,
};

} // namespace planner
} // namespace hints
