#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "Scene.h"
#include "Video.h"
#include "Render.h"
#include "Input.h"
#include "Window.h"


Scene::Scene() : Module()
{
	name = "scene";
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::Awake(pugi::xml_node& config)
{
	
	bool ret = true;
	

	return ret;
}

// Called before the first frame
bool Scene::Start()
{
	//TODO 5: Pass the path and the renderer to the Load function and save it to my_video variable
	

	bool ret = true;

	return ret;
}

bool Scene::Update(float dt)
{

	
	if (my_video != 0)
	{
		video_texture = App->video->UpdateVideo(my_video);

		App->render->Blit(video_texture, 0, 0);

		if (App->video->IsPlaying(my_video) == 0)
		{
			App->video->DestroyVideo(my_video);
			my_video = 0;
		}
	}


	bool ret = true;

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	
	return true;
}





