add_subdirectory(git)

add_library(creview-vcs
    text_diff.cpp
    text_fragment.cpp
)

target_link_libraries(creview-vcs
    creview-vcs-git
)
