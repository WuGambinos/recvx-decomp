#include <SDL3/SDL.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_init.h>
#include <stdio.h>
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

typedef struct {
    SDL_Window* window;
    SDL_GPUDevice* device;
    bool game_ready;
    Uint64 last_ns;
    Uint64 accum_ns;
} App;

struct Vertex {
    float x, y, z;
};

// Stubs
void RendererInit()
{
}

void RendererShutdown()
{
}

void GamePadInit()
{
}

void InputEvent(SDL_Event* event)
{
}

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD)) {
        SDL_Log("SDL couldn't be initialized: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Log("Init");
    App* my_app_state = calloc(1, sizeof(App));
    if (!my_app_state) return SDL_APP_FAILURE;
    *appstate = my_app_state;

    my_app_state->window = SDL_CreateWindow("Hello, SDL GPU!", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (my_app_state->window == NULL) {
        SDL_Log("Couldn't create window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_GPUShaderFormat format_flags = SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_DXIL | SDL_GPU_SHADERFORMAT_MSL;
    my_app_state->device = SDL_CreateGPUDevice(format_flags, true, NULL);

    if (my_app_state->device == NULL) {
        SDL_Log("Couldn't create GPU device: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_ClaimWindowForGPUDevice(my_app_state->device, my_app_state->window)) {
        SDL_Log("Couldn't claim window for GPU device: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    RendererInit();
    GamePadInit();

    my_app_state->game_ready = true;
    my_app_state->last_ns = SDL_GetTicksNS();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    SDL_Log("Event");
    switch (event->type) {
        case SDL_EVENT_QUIT:
            return SDL_APP_SUCCESS;
        default:
            InputEvent(event);
            return SDL_APP_CONTINUE;
    }
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
    SDL_Log("Iterate");
    App* my_app_state = (App*) (appstate);
    SDL_GPUCommandBuffer* command_buffer = SDL_AcquireGPUCommandBuffer(my_app_state->device);

    if (command_buffer == NULL) {
        SDL_Log("Couldn't acquire GPU command buffer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_GPUTexture* swapchain_texture;

    if (!SDL_WaitAndAcquireGPUSwapchainTexture(command_buffer, my_app_state->window, &swapchain_texture, NULL, NULL)) {
        SDL_Log("Couldn't acquire swapchain texture: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (swapchain_texture != NULL) {
        SDL_FColor clear = {0.4f, 0.6f, 0.9f, 1.0f};
        SDL_GPUColorTargetInfo color_target_info = {
            .texture = swapchain_texture,
            .clear_color = clear,
            .load_op = SDL_GPU_LOADOP_CLEAR,
            .store_op = SDL_GPU_STOREOP_STORE,
        };

        SDL_GPURenderPass* render_pass = SDL_BeginGPURenderPass(command_buffer, &color_target_info, 1, NULL);
        SDL_EndGPURenderPass(render_pass);
    }

    SDL_SubmitGPUCommandBuffer(command_buffer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    SDL_Log("Quit");
    App* my_app_state = (App*) appstate;

    RendererShutdown();

    SDL_ReleaseWindowFromGPUDevice(my_app_state->device, my_app_state->window);
    SDL_DestroyGPUDevice(my_app_state->device);
    SDL_DestroyWindow(my_app_state->window);
    free(my_app_state);
}
