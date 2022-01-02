#pragma once
#include "definations.h"
class button{
	private:
		SDL_Rect box;
		SDL_Rect *clip;
	public:
		button(int x,int y, int w, int h);
		void handle_event();
		void show();
};
