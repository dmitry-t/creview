add_library(hints-net
    request_handler_factory.cpp
    url/mapper.cpp
    url/path.cpp
    url/segment.cpp
)

target_link_libraries(hints-net
    PocoNet
    PocoUtil
    PocoFoundation
)

add_subdirectory(tests)
