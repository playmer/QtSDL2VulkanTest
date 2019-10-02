cmake_minimum_required(VERSION 3.9.1 FATAL_ERROR) 
set_property(GLOBAL PROPERTY USE_FOLDERS ON)  
project(QtSDL2VulkanTest CXX C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Source_Root}/cmake/modules/")


set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(Dependencies)

add_executable(QtSDL2VulkanTest 
    Source.cpp
    VkHLFSampleWindow.cpp
    VkHLFSampleWindow.h
)


if (CMAKE_SYSTEM_NAME STREQUAL Windows)
  # Find the QtWidgets library
  set(QtPath $ENV{Qt})
  if(NOT QtPath) 
    message(FATAL_ERROR "Please define the environment variable `Qt` with the path to Qt 5.9.0 - i.e. export Qt = C:/Qt/5.9")
  endif()

  set(CMAKE_PREFIX_PATH ${QtPath}/msvc2017_64/)
endif()

find_package(Qt5Widgets)

target_link_libraries(QtSDL2VulkanTest YTEMain Qt5::Widgets SDL2main SDL2 VkHLF)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT QtSDL2VulkanTest) 