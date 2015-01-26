add_subdirectory(net)
add_subdirectory(scheduler)
add_subdirectory(db)
add_subdirectory(resources)

add_executable(hints-server
    main.cpp
)

target_link_libraries(hints-server
    hints-net
    hints-scheduler
    hints-db
    hints-resources
    ctemplator
    PocoNet
    PocoUtil
)
