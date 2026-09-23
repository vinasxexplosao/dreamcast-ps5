add_executable(dreamcast_ps5 port/ps5/main.c)

if(CMAKE_TOOLCHAIN_FILE MATCHES "prospero")
    add_compile_definitions(PS5_BUILD)
    target_link_libraries(dreamcast_ps5 PRIVATE SceNotification)
endif()
