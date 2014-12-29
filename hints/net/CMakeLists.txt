add_library(hints-net
    request_handler_factory.cpp
)

target_link_libraries(hints-net
    PocoNet
    PocoUtil
    PocoFoundation
)
