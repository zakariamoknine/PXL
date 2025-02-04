cmake_minimum_required(VERSION 3.16)

project(PXL VERSION 1.0 LANGUAGES C)

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -no-pie -pg")

add_library(PXL STATIC
    src/main.c
)

find_package(Vulkan REQUIRED)

target_include_directories(PXL PRIVATE
    ${Vulkan_INCLUDE_DIRS}
)

target_link_libraries(PXL PRIVATE
    ${Vulkan_LIBRARIES}
)
