#include "game.h"
#include "player.h"
#include "building.h"
#include "eagle.h"
#include "coin.h"
#include "definations.h"

game::game(){
	p.set_src_values(0,SCREEN_HEIGHT/2,34,24);
	p.set_dest_values(10,10,34,24);
	float c = 500; 
	float x_val = c;
	float y_val;
	//int j=1;
	//x_val = rand() % int(c) + j*c;
	//pi.set_src_values(50,0,50,82);
	for(int i=0; i<500; i++){
		//if(i%3 == 0){
		//	pi.set_dest_values(x_val,400,100,80);
		//}
		//else if(i%3 == 1){
		//set_dest_values(x,0,SCREEN_WIDTH/25,SCREEN_HEIGHT/2-50);
		//	pi.set_dest_values(x_val,400,100,80);
		//}
		//else if(i%3 == 2){
		//	pi.set_dest_values(x_val,400,100,80);
		//}
		y_val = rand() % 350;
		pi.set_x_value(x_val);
		co.set_x_value(x_val + 75);
		co.set_y_value(y_val);
		eag.set_x_value(1.5*x_val - (rand() % 100) - 150);
		eag.set_y_value(y_val);
		pipes.insert(pipes.begin() + i,pi);
		coins.insert(coins.begin() + i,co);
		eagles.insert(eagles.begin() + i,eag);
		if(i<=30){
			x_val = rand() % int(c) + i*c;
		}
		else if(i>30){
			x_val = rand() % int(c) + i*350;
		}
		
		//else{
		//	x_val = rand() %  180 + i*180;
		//}
		
		
		//j++;
	}
}
game::~game(){
}
//void game::init(const char *title, int x, int y, int w, int h, bool fullscreen){
void game::init(SDL_Renderer *rend, SDL_Window *wind){
	int flag = SDL_WINDOW_RESIZABLE;
	//SDL_Init(SDL_INIT_EVERYTHING);
	
	//window = SDL_CreateWindow(title, x, y, w, h, flag);
	window = wind;
	if(window){
		//renderer = SDL_CreateRenderer(window, -1, 0);
		renderer = rend;
		is_running = true;
		//t = texturemanage::texture("image.png",renderer);
		p.create_texture("img/yellowbird111.png",renderer);
		p.CreateTexture1("img/yellowbird222.png",renderer);
		p.CreateTexture2("img/yellowbird333.png",renderer);
		bg.create_texture("img/background.png",renderer);
		
		
		
		
		for(int i=0;i<500;i++){
			pipes[i].create_texture("img/building.png",renderer);
			coins[i].create_texture("img/coin-modified.png",renderer);
			eagles[i].create_texture("img/eagle.png",renderer);
		}
		// for(int i=0;i<100;i++){
		// }
		//pi.create_texture("pipe.png",renderer);
		//background = texturemanage::texture("background.png",renderer);
	}
	else{
		is_running = false;
	}
	
}
void game::update(SDL_Texture *texture_1,SDL_Rect r_1,SDL_Texture *texture_2,SDL_Rect r_2){
	
	//p.update();
	SDL_RenderCopy(renderer,texture_1,NULL,&r_1);
	SDL_RenderCopy(renderer,texture_2,NULL,&r_2);
	SDL_RenderPresent(renderer);

	
}
void game::render(){
	
	//SDL_RenderCopy(renderer,player,&src,&dest);
	//SDL_RenderCopy(renderer,background,NULL,NULL);
	//SDL_SetRenderDrawColor(renderer,0,255,255,0);
	bg.Render(renderer);
	p.Render(renderer);
	for(int i=0;i<500;i++){
		pipes[i].Render(renderer);
		coins[i].Render(renderer);
		eagles[i].Render(renderer);
	}
	
	//SDL_RenderCopy(renderer, texture0, NULL, &rec[0]);
	//SDL_RenderCopy(renderer, texture1, NULL, &rec[1]);
	
	// SDL_RenderPresent(renderer);
}
bool game::myComparison(const pair<string,int> &a,const pair<string,int> &b){
	return a.second > b.second;
}
void game::handleEvent(){
	p.set_jump_timer();
	pi.set_jump_timer();
	
	//pi.set_random_pipe();
	SDL_PollEvent(&event);
	for(int i=0;i<500;i++){
		pipes[i].move();
		coins[i].move();
		eagles[i].move();
	}
	if(event.type == SDL_QUIT) is_running = false;
	if(event.type == SDL_KEYDOWN){
		if(event.key.keysym.sym == SDLK_UP){
			if(p.get_jump_state() == false){
				p.Jump();
			}
			else{
				p.gravity_up();
			}
		}
		else if(event.key.keysym.sym == SDLK_UP){
			p.gravity_up();
		}
		
	}
	else{
		p.gravity_down();
	}
	//if(p.get_y_pos() < 0 || p.get_y_pos() > 500){
	//	is_running = false;
	//	SDL_Delay(1000);
	//}



	//if(event.type == SDL_MOUSEMOTION){
	//	std::cout << event.motion.x << " " << event.motion.y << std::endl;
	//}
	//if(event.type == SDL_MOUSEBUTTONDOWN){
	//	std::cout << "pressed" << std::endl;
	//}
	//if(event.type == SDL_KEYDOWN){
	//	if(event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP){
	//		dest.y++;
	//	}
	//	if(event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN){
	//		dest.y--;
	//	}
	//	if(event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT){
	//		dest.x++;
	//	}
	//	if(event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT){
	//		dest.x--;
	//	}
	//}
	
}

//Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, 2, 2048) ;


bool game::Checkcollision(string s)
{
	for(int i=0;i<500;i++){
		if(p.IsCollision(pipes[i].get_dest(),p.get_dest()) || (p.IsCollision(eagles[i].get_dest(),p.get_dest()))){
			SDL_Delay(1000);
			ifstream indata;
			ofstream outdata;
			indata.open("Score_Data.txt");
			vector<pair<string, int>> v;
			pair<string,int> p;
			//string s = "krushi";
			p.first = s;
			p.second = score; 
			v.insert(v.begin(),p);
			
			string s1;
			int s2;
			int i = 1;
			while(!indata.eof()){
				indata >> s1 >> s2;
				p.first = s1;
				p.second = s2;
				v.insert(v.begin() + i,p);
				i++;
			}
			v.pop_back();
			indata.close();
			
			
			sort(v.begin(),v.end(),myComparison);
			
			outdata.open("Score_Data.txt");
			
			for(i=0;i<v.size();i++){
				outdata << v[i].first << " " << v[i].second << endl;
				if(i>=4){
					break;
				}
			}
			outdata.close();
			return false;
			
		}
		if(p.IsCollision(coins[i].get_dest(),p.get_dest())){

			//Mix_PlayChannel(-1,collection_sound, 0);
			score += 5;
			coins[i].set_x_value(coins[i].get_x_value() - 1000);
			return true;
		}
	}
	if(p.get_y_pos() < 0 || p.get_y_pos() > SCREEN_HEIGHT){
		SDL_Delay(1000);
		ifstream indata;
			ofstream outdata;
			indata.open("Score_Data.txt");
			vector<pair<string, int>> v;
			pair<string,int> p;
			//string s = "krushi";
			p.first = s;
			p.second = score; 
			v.insert(v.begin(),p);
			
			string s1;
			int s2;
			int i = 1;
			while(!indata.eof()){
				indata >> s1 >> s2;
				p.first = s1;
				p.second = s2;
				v.insert(v.begin() + i,p);
				i++;
			}
			v.pop_back();
			indata.close();
			
			
			sort(v.begin(),v.end(),myComparison);
			
			outdata.open("Score_Data.txt");
			
			for(i=0;i<v.size();i++){
				outdata << v[i].first << " " << v[i].second << endl;
				if(i>=4){
					break;
				}
			}
			outdata.close();
		return false;
	}
	return true;
		
}
int game::get_score()
{
	return score;
}
