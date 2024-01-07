#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	createGround();

	addCube({ 25, 1, 100 }, { 2, 2, 100 }, Grey, 0, 0, 0);
	addCube({ 10, 1, 20 }, { 20, 50, 6 }, Grey, 0, 0, -65);
	

	box = Cube(1, 1, 1);
	App->physics->AddBody(box, 1.0f);
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{

	
	box.SetPos(1, 1, 1);
	box.Render();

	p2List_item<Cube>* c = buildingBlocks.getFirst();
	while (c != NULL) {
		c->data.Render();
		c = c->next;
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::addCube(vec3 pos, vec3 size, Color rgb, float rotX, float rotY, float rotZ)
{
	Cube cube;

	cube.SetPos(pos.x, pos.y, pos.z);
	cube.size = size;
	cube.color = rgb;

	if (rotX != 0)
	cube.SetRotation(rotX, { 1, 0, 0 });	
	
	if (rotY != 0)
	cube.SetRotation(rotY, { 0, 1, 0 });	

	if (rotZ != 0)
	cube.SetRotation(rotZ, { 0, 0, 1 });	

	App->physics->AddBody(cube, 0);
	buildingBlocks.add(cube);
}

void ModuleSceneIntro::createGround() {
	Cube groundToAdd;

	float groundTerrainSize = 20;	// Change this value to increase/decrease basic ground size

	groundToAdd.size = { groundTerrainSize, 1, groundTerrainSize };

	int type = 0;
	// X-axis
	for (int i = 0; i < 10; i++)
	{
		// Z-axis
		for (int j = 0; j < 3; j++) {

			groundToAdd.SetPos(i * -groundTerrainSize + groundTerrainSize, 0, j * groundTerrainSize);

			
				groundToAdd.color = White;	// Ground color

				App->physics->AddBody(groundToAdd, 0);
				buildingBlocks.add(groundToAdd);

				
			
		}
	}
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

