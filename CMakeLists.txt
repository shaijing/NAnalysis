cmake_minimum_required(VERSION 3.27)

# ##############################################################################
# Normal Configure
# ##############################################################################

project(demo LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "D:\\ProgramData\\vcpkg\\installed\\x64-mingw-dynamic")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 11)
message(STATUS "CMAKE_BINARY_DIR:" ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(INCLUDE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/include)
include_directories(include)


# ##############################################################################
# Build
# ##############################################################################

add_subdirectory(src/mlib)
add_executable(main src/main.cpp)
# add_executable(ieee754 src/ieee754.c)
# add_executable(eatnum src/eatnum.c)
# add_executable(harmonic_series src/harmonic_series.c)
# add_executable(Interpolation src/Interpolation_use.cpp)
target_link_libraries(main PRIVATE mlib)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION ${INCLUDE_OUTPUT_DIRECTORY})


# 在构建时添加一个自定义命令，将库复制到可执行文件所在目录
add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:mlib>
    $<TARGET_FILE_DIR:main>
    COMMENT "Copying mlib to output directory"
)
# ##############################################################################
# Test
# ##############################################################################
enable_testing()
add_executable(test_add tests/test_add.cpp)
add_test(NAME test_add COMMAND test_add 1 24 25)


# ##############################################################################
# Install
# ##############################################################################
install(TARGETS main DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(DIRECTORY ${CMAKE_BINARY_DIR}/include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)