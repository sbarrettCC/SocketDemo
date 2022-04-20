# Install script for directory: C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-src/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-build/raylib/raylib.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-src/src/raylib.h"
    "C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-src/src/rlgl.h"
    "C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-src/src/physac.h"
    "C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-src/src/raymath.h"
    "C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-src/src/raudio.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-build/raylib/raylib.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/raylib" TYPE FILE FILES "C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-build/raylib/raylib-config-version.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/raylib" TYPE FILE FILES "C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-src/src/../cmake/raylib-config.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/spyid/Documents/NetworkingAssignment/RedEngine/out/build/x64-Debug/_deps/raylib-build/raylib/external/glfw/cmake_install.cmake")

endif()
