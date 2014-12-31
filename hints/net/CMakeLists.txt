add_library(hints-net
    request_handler_registry.cpp
    server_request_impl.cpp
    server_response_impl.cpp
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
