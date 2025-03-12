# This is the root CMakeLists file for the Triomino project

cmake_minimum_required(VERSION 3.28)

if(POLICY CMP0110)
  cmake_policy(SET CMP0110 NEW)
endif()

project(
  Triomino
  VERSION 1.0.0
  DESCRIPTION "C library for creating a simplified version of the Triomino game."
  LANGUAGES C
  )

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)
include(CPack)
include(Doxygen)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -std=c11")

set(CMAKE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(CPACK_GENERATOR "ZIP")
set(CPACK_SOURCE_GENERATOR "ZIP")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}")
set(CPACK_SOURCE_IGNORE_FILES "/.gitignore;/build/;/.vscode/;/.git/;~$;${CPACK_SOURCE_IGNORE_FILES}")

if(${BUILD_TESTS})
  message(STATUS "Building tests")
  find_program(VALGRIND "valgrind")
  enable_testing()
  add_subdirectory(tests)
endif()

add_subdirectory(examples)

if (${DEBUG_INSTALL})
  message(STATUS "Debug install enabled")
  set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Install path" FORCE)
endif()

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/*.c")
message(STATUS "SOURCES=${SOURCES}")

file(GLOB HEADERS "${CMAKE_SOURCE_DIR}/*.h")
message(STATUS "HEADERS=${HEADERS}")

add_library(triomino SHARED ${SOURCES})
target_include_directories(triomino PUBLIC ${CMAKE_SOURCE_DIR})
set_target_properties(triomino PROPERTIES VERSION ${PROJECT_VERSION})

add_library(triominoStatic STATIC ${SOURCES})
target_include_directories(triominoStatic PUBLIC ${CMAKE_SOURCE_DIR})
set_target_properties(triominoStatic PROPERTIES OUTPUT_NAME triomino)

install(
  TARGETS triomino triominoStatic
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT "Library"
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT "Library"
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT "Runtime"
)

install(
    FILES ${HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    COMPONENT "Headers"
)

configure_file(
  ${CMAKE_SOURCE_DIR}/triomino.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/triomino.pc
  @ONLY
)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/triomino.pc
  DESTINATION share/pkgconfig
  COMPONENT "PkgConfig"
)

configure_package_config_file(
  ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION cmake
)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  DESTINATION cmake
)

find_package(Coverage)
enable_coverage()
