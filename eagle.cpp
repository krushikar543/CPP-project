#include "eagle.h"
void eagle::Render(SDL_Renderer *ren){
	//timer++;
	//if(timer < 10){
	SDL_RenderCopy(ren, this->get_texture(), NULL, &dest);
	//}
	//else if(timer < 20){
	//	SDL_RenderCopy(ren,tex2,&src,&dest);
	//}
	//else{
	//	timer = 0;
	//}
}
void eagle::move_eagle(){
	if(jump_timer > 10000){
		x -= 3;
	}
	else{
		x -= 1.5;
	}
	//set_dest_values(0,0,50,82);
	static int i=0;
	if(i%2 != 0){
		set_dest_values(x,y,50,40);
		i++;
	}
	else{
		set_dest_values(x,y,50,40);
		i++;
	}
	//SDL_RenderCopy(ren,this->get_texture(),&src,&dest);
	//move(ren);
}
void eagle::move(){
	if((jump_timer - last_jump) > 1000){
		last_jump = jump_timer;
	}
	else{
		move_eagle();
	}
}
void eagle::set_jump_timer(){
	jump_timer = SDL_GetTicks(); 
}
//void eagle::CreateTexture2(const char* address, SDL_Renderer* ren){
//	tex2 = texturemanage::texture(address, ren);
//}
void eagle::set_x_value(float x_val){
	x = x_val;
}
void eagle::set_y_value(float y_val){
	y = y_val;
}
float eagle::get_x_value(){
	return x;
}
