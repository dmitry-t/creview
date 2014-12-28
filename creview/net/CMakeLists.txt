add_library(creview-net
    request_handler_factory.cpp
)

target_link_libraries(creview-net
    PocoNet
    PocoUtil
    PocoFoundation
)
