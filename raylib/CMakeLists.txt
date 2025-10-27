cmake_minimum_required(VERSION 3.25)
#this change avoid the warning that appear when we include raylib using Cmake fatch content 
project(raylib)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(CompilerFlags)

include(CMakeOptions.txt)

if (UNIX AND NOT APPLE AND NOT "${PLATFORM}" MATCHES "DRM" AND NOT "${PLATFORM}" MATCHES "Web")
  if (NOT GLFW_BUILD_WAYLAND AND NOT GLFW_BUILD_X11)
    message(FATAL_ERROR "Cannot disable both Wayland and X11")
  endif()
endif()

add_subdirectory(src raylib)
