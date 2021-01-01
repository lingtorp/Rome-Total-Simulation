#include <filesystem>
#include <string>
#include <iostream>
#include <cassert>

// NOTE: If MSVC++ complains about main function missing or smt use this below
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "include/imgui.h"
#include "include/imgui_impl_sdl.h"
#include "include/imgui_impl_opengl3.h"

struct Resolution
{
  int width  = 0;
  int height = 0;
  Resolution(const int w, const int h): width(w), height(h) {}
};

// Parsed at start up from the config.json 
struct Config
{
  Resolution resolution = Resolution(1920, 1080);
  bool fullscreen = false;
  std::string filepath_root;
  std::string filepath_rsrc;
  std::string filepath_save;
};

// Parses the config.json at the project root and inits the Config struct at startup
Config parse_config_file() 
{
  return Config();
}
// void parse_config_file() {
//   const char *raw_json = open_file("config.json");

//   if (raw_json) {
//     cJSON *json = cJSON_Parse(raw_json);

//     if (json) {
//       struct cJSON *root_folder = cJSON_GetObjectItemCaseSensitive(json, "root_folder");
//       if (cJSON_IsString(root_folder) && root_folder->valuestring) {
//         CONFIG.FILEPATH_ROOT = root_folder->valuestring;
//       }

//       struct cJSON *save_folder = cJSON_GetObjectItemCaseSensitive(json, "save_folder");
//       if (cJSON_IsString(save_folder) && save_folder->valuestring) {
//         CONFIG.FILEPATH_SAVE = save_folder->valuestring;
//       } else {
//         CONFIG.FILEPATH_SAVE = CONFIG.FILEPATH_ROOT;
//       }

//       struct cJSON *gui = cJSON_GetObjectItem(json, "gui");
//       if (cJSON_IsBool(gui)) {
//         CONFIG.GUI = gui->valueint;
//       }

//       struct cJSON *hard_mode = cJSON_GetObjectItem(json, "hard_mode");
//       if (cJSON_IsBool(hard_mode)) {
//         CONFIG.HARD_MODE = hard_mode->valueint;
//       }

//       struct cJSON *language = cJSON_GetObjectItem(json, "language");
//       if (cJSON_IsNumber(language)) {
//         CONFIG.LANGUAGE = language->valueint;
//       }

//       struct cJSON *resolution = cJSON_GetObjectItem(json, "resolution");
//       if (cJSON_IsObject(resolution)) {
//         struct Resolution res;

//         struct cJSON *width = cJSON_GetObjectItem(resolution, "width");
//         if (cJSON_IsNumber(width)) {
//           res.width = width->valueint;
//         }

//         struct cJSON *height = cJSON_GetObjectItem(resolution, "height");
//         if (cJSON_IsNumber(height)) {
//           res.height = height->valueint;
//         }

//         CONFIG.RESOLUTION = res;
//       }

//       struct cJSON *start_date = cJSON_GetObjectItem(json, "start_date");
//       if (cJSON_IsObject(start_date)) {
//         struct cJSON *year = cJSON_GetObjectItem(start_date, "year");
//         if (cJSON_IsNumber(year)) {
//           date.year = year->valueint;
//         }

//         struct cJSON *month = cJSON_GetObjectItem(start_date, "month");
//         if (cJSON_IsNumber(month)) {
//           date.month = month->valueint;
//         }

//         struct cJSON *day = cJSON_GetObjectItem(start_date, "day");
//         if (cJSON_IsNumber(day)) {
//           date.day = day->valueint;
//         }
//       }

//       struct cJSON *fullscreen = cJSON_GetObjectItem(json, "fullscreen");
//       if (cJSON_IsBool(fullscreen)) {
//         CONFIG.FULLSCREEN = fullscreen->valueint;
//       }

//     } else {
//       const char *error_ptr = cJSON_GetErrorPtr();
//       if (error_ptr) {
//         fprintf(stderr, "[ColoniaC]: cJSON error before: %s \n", error_ptr);
//       }
//     }
//   } else {
//     fprintf(stderr, "[ColoniaC]: Failed to load config.json");
//   }
//   CONFIG.FILEPATH_RSRC = str_concat_new(CONFIG.FILEPATH_ROOT, "resources/");
// }

uint32_t ms_per_timestep_for(uint32_t simulation_speed)
{
  return static_cast<uint32_t>((1.0f / 10.0f) * simulation_speed);
}

int main(void) {
  srand((unsigned int)time(NULL));
  Config cfg = parse_config_file();

  /* SDL setup */
  SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "0");
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  int win_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
  if (cfg.fullscreen) {
    win_flags |= SDL_WINDOW_FULLSCREEN;
  }

  SDL_Window *window = SDL_CreateWindow(
      "Rome: Total Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      cfg.resolution.width, cfg.resolution.height, win_flags);
  assert(window);
  SDL_GLContext gl_context = SDL_GL_CreateContext(window);

  glViewport(0, 0, cfg.resolution.width, cfg.resolution.height);
  glewExperimental = true;
  if (glewInit() != GLEW_OK)
  {
    std::cerr << "Error could not initialize GLEW" << std::endl;
    return -1;
  }

  bool quit = false;
  bool pause = false; // Pauses simulation when window goes inactive
  uint32_t simulation_speed = 0;

  // ImGUI
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();

  // Setup Platform/Renderer backends
  ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
  ImGui_ImplOpenGL3_Init("#version 150");

  while (!quit) {

    /* Input */
    SDL_Event evt;
    while (SDL_PollEvent(&evt)) {
      if (evt.type == SDL_QUIT) {
        return 0;
      }
      if (evt.type == SDL_WINDOWEVENT) {
        switch (evt.window.event) {
        case SDL_WINDOWEVENT_FOCUS_LOST:
          pause = true;
          break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
          pause = false;
          break;
        }
      }
      if (evt.type == SDL_KEYDOWN) {
        switch (evt.key.keysym.sym) {
        case SDLK_ESCAPE:
          return 0;
          break;
        case SDLK_SPACE:
          break;
        case SDLK_0:
          simulation_speed = 0;
          break;
        case SDLK_1:
          simulation_speed = 1;
          break;
        case SDLK_2:
          simulation_speed = 2;
          break;
        case SDLK_3:
          simulation_speed = 3;
          break;
        case SDLK_4:
          simulation_speed = 4;
          break;
        case SDLK_5:
          simulation_speed = 5;
          break;
        case SDLK_6:
          simulation_speed = 6;
          break;
        case SDLK_7:
          simulation_speed = 7;
          break;
        case SDLK_8:
          simulation_speed = 8;
          break;
        case SDLK_9:
          simulation_speed = 9;
          break;
        }
      }

      /* GUI */
      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplSDL2_NewFrame(window);
      ImGui::NewFrame();

      // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
      static bool show_demo_window = true;
      if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);

      // Rendering
      ImGui::Render();
      glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
      glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
      SDL_GL_SwapWindow(window);
    }
  }

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();

  SDL_GL_DeleteContext(gl_context);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
