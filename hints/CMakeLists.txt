add_subdirectory(net)
add_subdirectory(scheduler)

add_executable(hints-server
    main.cpp
)

target_link_libraries(hints-server
    hints-net
    hints-scheduler
    ctemplator
    PocoNet
    PocoUtil
)
