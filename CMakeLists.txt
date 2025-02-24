cmake_minimum_required(VERSION 3.16)

project(PXL VERSION 1.0.0 LANGUAGES C)

# We make sure we're on Windows
if(NOT WIN32)
	message(FATAL_ERROR "PXL is Windows only")
endif()

# By default we build PXL as a static library
# The USER must add -DPXL_BUILD_DLL=ON for building a shared/dynamic library
option(PXL_BUILD_DLL "Build PXL as a shared library / DLL" OFF)

if(PXL_BUILD_DLL)
	set(PXL_LIBRARY_TYPE SHARED)
else()
	set(PXL_LIBRARY_TYPE STATIC)
endif()

add_library(PXL ${PXL_LIBRARY_TYPE}
	src/init.c
)

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

# Forward all output binaries in the binary dir, keeping it simple
set_target_properties(PXL PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# include/PXL/Hat.h -> USER
target_include_directories(PXL PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# PXL/src/* -> PXL
target_include_directories(PXL PRIVATE
	"${PXL_SOURCE_DIR}/src"
)
