cmake_minimum_required(VERSION 3.27)

# ##############################################################################
# Normal Configure
# ##############################################################################

project(mlib LANGUAGES C CXX)
add_library(mlib SHARED mlib.h mlib.cpp interpolation.h interpolation.cpp fft.h fft.cpp integral.h integral.cpp )
find_package(Matplot++ CONFIG REQUIRED)
target_link_libraries(mlib PRIVATE Matplot++::cimg  Matplot++::matplot)

set_target_properties(mlib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# ##############################################################################
# Install
# ##############################################################################

# 安装动态库
install(TARGETS mlib DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
