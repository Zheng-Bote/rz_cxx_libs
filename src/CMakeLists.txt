cmake_minimum_required(VERSION 3.23)

project(
  test_libs
  VERSION 2.0.0
  DESCRIPTION "CXX20 console app to test c++20 libraries"
  HOMEPAGE_URL "https://github.com/Zheng-Bote/cxx_libs"
  LANGUAGES CXX)

#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("Building with CMake version: ${CMAKE_VERSION}")
include(ProcessorCount)
ProcessorCount(N)
message("number of processors: " ${N})

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

message(${CMAKE_SOURCE_DIR})
#add_library(rz_filesystem "${CMAKE_SOURCE_DIR}/include/rz_filesystem.h")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/configure")

add_executable(test_libs main.cpp "${CMAKE_SOURCE_DIR}/include/rz_filesystem.cpp")

set(PROG_NAME "${PROJECT_NAME}")
set(PROG_VERSION "${PROJECT_VERSION}")
set(PROG_HOMEPAGE "${PROJECT_HOMEPAGE_URL}")
configure_file("${CMAKE_SOURCE_DIR}/configure/rz_config.h.in" configured/rz_config.h)

target_link_libraries(test_libs)

target_compile_features(test_libs PUBLIC cxx_std_20)
target_include_directories(test_libs PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_compile_definitions(
  test_libs
  PRIVATE $<$<COMPILE_LANG_AND_ID:CXX,AppleClang,Clang>:CXX_CLANG>
          $<$<COMPILE_LANG_AND_ID:CXX,Intel>:CXX_INTEL>
          $<$<COMPILE_LANG_AND_ID:C,Clang,Clang>:C_CLANG>
)

# are we clean?
include(ClangTidy)
addclangtidy(test_libs)

include(Doxygen)
doxygen(. docs)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message(STATUS "building SHA256sum on Linux ${CMAKE_SYSTEM_VERSION}")
  add_custom_command(
    TARGET test_libs
    POST_BUILD
    COMMAND sha256sum ARGS "test_libs" >
            "test_libs.sha256sum")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  message(STATUS "building SHA256sum on MacOS ${CMAKE_SYSTEM_VERSION}")
  add_custom_command(
    TARGET test_libs
    POST_BUILD
    COMMAND shasum ARGS "-a 256 test_libs" >
            "test_libs.sha256sum")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  message(STATUS "building SHA256sum on Windows ${CMAKE_SYSTEM_VERSION}")
  # Powershell
  add_custom_command(
    TARGET test_libs
    POST_BUILD
    COMMAND Get-Filehash ARGS "$<TARGET_FILE_NAME:test_libs.exe>"
            > "test_libs.sha256sum")
endif()

include(GNUInstallDirs)
install(
  TARGETS test_libs
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
