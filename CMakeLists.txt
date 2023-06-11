cmake_minimum_required(VERSION 3.5)
project(Gunny)

# Be nice to visual studio
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Be nice and export compile commands by default, this is handy for clang-tidy
# and for other tools.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# We can use include() and find_package() for our scripts in there
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
include(ConfigSafeGuards)


message(STATUS "src this is source dir " ${CMAKE_SOURCE_DIR})


SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )
SET(CMAKE_CXX_STANDARD 17)
add_compile_options(-std=c++17 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wunused -Wpedantic -pedantic-errors -Wconversion)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

find_package(SDL2_TTF REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

find_package(SDL2_IMAGE REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

find_package(SDL2_MIXER REQUIRED)
include_directories(${SDL2_MIXER_INCLUDE_DIR})


# 设置可执行文件名和源文件列表
file(GLOB SOURCES src/*.cpp main.cpp)


# 添加头文件目录
include_directories(include)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2_LIBRARY}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_MIXER_LIBRARY}
)

