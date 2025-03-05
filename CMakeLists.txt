cmake_minimum_required(VERSION 3.16)

project(PXL VERSION 1.0.0 LANGUAGES C)

if(NOT WIN32)
	message(FATAL_ERROR "PXL is Windows only")
endif()

if(NOT MSVC)
	message(FATAL_ERROR "PXL requires the MSVC toolchain for building, Clang support might be added in the future")
endif()

# By default we build PXL as a shared library
# The USER must add -DPXL_BUILD_DLL=ON for building a shared/dynamic library
option(PXL_BUILD_DLL "Build PXL as a shared library / DLL" ON)

if(PXL_BUILD_DLL)
	set(PXL_LIBRARY_TYPE SHARED)
else()
	set(PXL_LIBRARY_TYPE STATIC)
endif()

add_library(PXL ${PXL_LIBRARY_TYPE}
	src/PXL.c
	src/init.c
)

# Linking against Win32 native libraries
target_link_libraries(PXL PRIVATE kernel32 user32 gdi32)

# PXL requires UNICODE support
target_compile_definitions(PXL PRIVATE 
	UNICODE
	_UNICODE
)

# We define PXL_DLL for all applications/libraries that use PXL as a shared library,
# We define _PXL_BUILD_DLL only for PXL, which is how the API knows it's building a shared library 
if(PXL_BUILD_DLL)
	target_compile_definitions(PXL PRIVATE _PXL_BUILD_DLL)
	target_compile_definitions(PXL INTERFACE PXL_DLL)
endif()

# Forward all output binaries to the binary dir, keeping it simple
set_target_properties(PXL PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add include/PXL/Hat.h to USERs
target_include_directories(PXL PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
# Add PXL/src/* is to PXL API
target_include_directories(PXL PRIVATE
	"${PXL_SOURCE_DIR}/src"
)
