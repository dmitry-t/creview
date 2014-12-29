add_library(hints-scheduler
    scheduler_impl.cpp
)

target_link_libraries(hints-scheduler
    PocoUtil
)
