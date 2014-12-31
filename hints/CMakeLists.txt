add_subdirectory(net)
add_subdirectory(scheduler)

add_executable(hints-server
    main.cpp
)

target_link_libraries(hints-server
    hints-net
    hints-scheduler
    PocoNet
    PocoUtil
)

add_custom_target(hints-tests)

add_custom_command(
    TARGET hints-tests
    POST_BUILD
    COMMAND hints-net-tests
)
