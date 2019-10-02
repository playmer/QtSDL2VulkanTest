
add_subdirectory(SDL)

##########################################################################
# Turn off/configure various parts of VkHLF.
set(BUILD_VKCPP_SAMPLES OFF CACHE BOOL "Build the VkCpp based samples" )
option(BUILD_VKCPP_GLFW "Build GLFW" OFF)
option(ENABLE_TESTING "Allow building of tests and looking for gmock" OFF)
option(ENABLE_HLSL "Enables HLSL input support" OFF)
option(BUILD_TESTING "Enables testing" OFF)

set(LLVM_USE_CRT_DEBUG "MDd")
set(LLVM_USE_CRT_MINSIZEREL "MD")
set(LLVM_USE_CRT_RELEASE "MD")
set(LLVM_USE_CRT_RELWITHDEBINFO "MD")

set(SKIP_GLSLANG_INSTALL ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VkHLF/3rdparty)

add_subdirectory(VkHLF) 

target_compile_definitions(glslang 
PUBLIC 
  AMD_EXTENSIONS
  NV_EXTENSIONS
)

# Turn the warnings off on our dependencies.
if (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
  set(disableWarning /W0)
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang OR
        ${CMAKE_CXX_COMPILER_ID} STREQUAL AppleClang)
  # Also, this is an easy place to force color output for me in this moment
  # Future maintainers of this file may judge me, but I will do this thing.
  set(disableWarning -Wno-everything -fcolor-diagnostics)
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
  set(disableWarning -w)
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Intel)
  set(disableWarning -w0)
endif()

target_compile_options(SDL2                  PRIVATE ${disableWarning})
target_compile_options(SDL2main              PRIVATE ${disableWarning})
target_compile_options(SDL2-static           PRIVATE ${disableWarning})
