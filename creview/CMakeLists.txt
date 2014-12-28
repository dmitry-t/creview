add_subdirectory(net)
add_subdirectory(vcs)

add_executable(creview-server
    main.cpp
)

target_link_libraries(creview-server
    creview-net
    creview-vcs
    PocoNet
    PocoUtil
)
