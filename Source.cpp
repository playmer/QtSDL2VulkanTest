#include <cassert>
#include <iostream>
#include <memory>
#include <system_error>
#include <vector>

#include <vkhlf/vkhlf.h>

#include "VkHLFSampleWindow.h"

#include "SDL.h"
#include "SDL_vulkan.h"

int SDL_main(int aArgumentsSize, char** aArguments)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return 1;
  }

  SDL_Vulkan_LoadLibrary(nullptr);


  SDL_Quit();

  return 0;
}

