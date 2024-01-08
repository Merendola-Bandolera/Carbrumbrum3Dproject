#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "ModulePlayer.h"

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
	addBooster({ 50, 1, 20 }, { 5, 5, 5 }, Red, 0, 0, 0);
	
	//cubos de ivo
	addCube({ 10, -0.5f, 100 }, { 30, 2, 100 }, Grey, 0, 0, 0);
	addCube({ 1.7f, -0.5f, 195 }, { 30, 2, 100 }, Grey, 0, -10, 0);
	addCube({ -24, -0.5f, 288 }, { 30, 2, 100 }, Grey, 0, -20, 0);
	addCube({ -64.8, -0.5f, 375 }, { 30, 2, 100 }, Grey, 0, -30, 0);
	addCube({ -120, -0.5f, 453 }, { 30, 2, 100 }, Grey, 0, -40, 0);
	addCube({ -188, -0.5f, 520 }, { 30, 2, 100 }, Grey, 0, -50, 0);


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
	/*p2List_item<Booster>* d = boosterPointList.getFirst();
	while (d != NULL) {
		d->data.cube.Render();
		d = d->next;
	}*/
	p2List_item<Booster>* currentItem = boosterPointList.getFirst();

	//while (currentItem != NULL) {
	//	
	//	
	//		



	//	//btVector3 coinPos = currentItem->data.body->GetPos();
	//	//	btVector3 carPos = App->player->vehicle->GetPos();
	//	//	float Xdistance = abs(coinPos.x()) - abs(carPos.x());
	//	//	float Ydistance = abs(coinPos.y()) - abs(carPos.y());
	//	//	float Zdistance = abs(coinPos.z()) - abs(carPos.z());

	//	//	// Homebrew collision detection for sensors
	//	//	if ((Xdistance > -2 && Xdistance < 2) && (Ydistance > -2 && Ydistance < 2) && (Zdistance > -2 && Zdistance < 2) && !currentItem->data->pendingToDelete) {
	//	//		LOG("car touch coing");
	//	//		//currentItem->data->pendingToDelete = true;

	//	//		currentItem = currentItem->next;
	//	//		//App->audio->PlayFx(coinFx);
	//	//		App->player->vehicle;
	//	//		

	//	//	}
	//	//	else {
	//	//		currentItem = currentItem->next;
	//	//	}
	//	
	//	
	//}


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

void ModuleSceneIntro::addBooster(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
{
	Cube cube;

	cube.SetPos(pos.x, pos.y, pos.z);
	cube.size = size;
	cube.color = rgb;
	
	if (rot_X == true)
		cube.SetRotation(angle, { 1, 0, 0 });	// X-axis
	if (rot_Y == true)
		cube.SetRotation(angle, { 0, 1, 0 });	// Y-axis
	if (rot_Z == true)
		cube.SetRotation(angle, { 0, 0, 1 });	// Z-axis

	Booster checkpoint;
	checkpoint.body = App->physics->AddBody(cube, 0.0f);
	
	checkpoint.body->SetAsSensor(false);
	checkpoint.body->SetId(id);
	checkpoint.cube = cube;
	checkpoint.passed = passed_;
	boosterPointList.add(checkpoint);

	
}


void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

