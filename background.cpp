#include "background.h"

void background::Render(SDL_Renderer *ren){
	//timer++;
	//if(timer < 50){
	SDL_RenderCopy(ren, this->get_texture(), NULL, NULL);
	//}
	//else if(timer == 50){
	//	timer = 0;
	//}
}
void background::move(SDL_Renderer *ren){
	if((jump_timer - last_jump) > 1000){
		
		last_jump = jump_timer;
	}
	else{
		Move_bg(ren);
	}
}

void background::Move_bg(SDL_Renderer *ren){
	x -= 2;
	set_dest_values(0,0,266,512);
	set_dest_values(x,0,266,512);
	SDL_RenderCopy(ren,this->get_texture(),&src,&dest);
	//move(ren);
}
void background::set_jump_timer(){
	jump_timer = SDL_GetTicks();
}



