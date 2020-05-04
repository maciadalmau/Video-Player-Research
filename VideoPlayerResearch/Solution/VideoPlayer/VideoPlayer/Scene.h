#ifndef __Scene_H__
#define __Scene_H__

#include <map>
#include "Module.h"

struct SDL_Texture;
struct SDL_Surface;

class Scene : public Module
{
public:

	Scene();

	// Destructor
	virtual ~Scene();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start();

	bool Update(float dt);

	// Called before quitting
	bool CleanUp();

	

public:
	SDL_Texture* video_texture = nullptr;
	int my_video;
};


#endif // __Textures_H__

