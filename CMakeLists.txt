# Dreamcast PS5 Homebrew — build principal
#
# Este CMakeLists é o esqueleto inicial (M2). Ele ainda não compila
# o Flycast — integração do core vem no M5. O build real usa a
# toolchain do PS5SDK (CMake 3.20+, Ninja, Clang/lld).

cmake_minimum_required(VERSION 3.20)
project(dreamcast_ps5 C)

if(CMAKE_TOOLCHAIN_FILE MATCHES "prospero")
    add_compile_definitions(PS5_BUILD)
endif()

# Fontes do payload
add_executable(dreamcast_ps5
    port/ps5/main.c
)

# C do projeto — sem STL, sem dependências pesadas no estágio inicial
set_target_properties(dreamcast_ps5 PROPERTIES
    C_STANDARD 11
)

# Camadas futuras (criadas nos próximos marcos):
# add_subdirectory(port/ps5/video)   # M3
# add_subdirectory(port/ps5/audio)   # M4
# add_subdirectory(port/ps5/input)   # M4
# add_subdirectory(port/ps5/storage) # M4
# add_subdirectory(frontend)         # M6
