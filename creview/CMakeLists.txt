add_compile_options(-std=c++11)

add_executable(creview-server
  main.cpp
)

target_link_libraries(creview-server
  PocoNet
  PocoUtil
  PocoFoundation
)
