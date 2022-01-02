#pragma once
#include "definations.h"
class text{
    private:
        SDL_Color color={0,0,0,0};
        //SDL_Rect rect[7]{};
	
	
    public:
        // void create_text(const char* font,SDL_Renderer *ren,TTF_Font* gfont,int x,int y);
        // SDL_Rect get_rect();
        void init(SDL_Renderer *rend,SDL_Window *wind);
        // void handle_events();

};
