#pragma once
#include "hook_wrapper.h"
#include "memory.h"
#include <stdint.h>
#include "EqStructures.h"
#include "EqUI.h"
#include "directx.h"

enum DxStateType_
{
    DxStateType_Render,
    DxStateType_Texture
};

struct RenderState
{
    DWORD value;
    DWORD state;
    DxStateType_ type;
    RenderState(IDirect3DDevice8* device, DWORD state, DxStateType_ type);
    RenderState() = default;
};

class TargetRing
{
public:
    void callback_render();
    void set_enabled(bool enable);
    void render_ring(Vec3 position, float size, DWORD color);
    bool enabled;
    TargetRing(class ZealService* zeal, class IO_ini* ini);
    ~TargetRing();
private:
    std::vector<RenderState> render_states;
    void store_render_states();
    void reset_render_states();
};

// Color definitions
#define CON_WHITE D3DCOLOR_ARGB(0x55, 0xf0, 0xf0, 0xf0)
#define CON_RED D3DCOLOR_ARGB(0x55, 0xf0, 0x0, 0x0)
#define CON_BLUE D3DCOLOR_ARGB(0x55, 0x0, 0x0, 0xf0)
#define CON_YELLOW D3DCOLOR_ARGB(0x55, 0xf0, 0xf0, 0x0)
#define CON_LIGHTBLUE D3DCOLOR_ARGB(0x55, 0x0, 0xf0, 0xf0)
#define CON_GREEN D3DCOLOR_ARGB(0x55, 0x0, 0xf0, 0x0)

// Function declaration
DWORD GetLevelCon(Zeal::EqStructures::Entity* ent);
