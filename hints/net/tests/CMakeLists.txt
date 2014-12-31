add_executable(hints-net-tests
    url/mapper_tests.cpp
    url/segment_tests.cpp
    main.cpp
)

target_link_libraries(hints-net-tests
    hints-net
    gtest
)
