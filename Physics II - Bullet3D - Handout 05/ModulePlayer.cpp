#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	timer = 0;
	LOG("Loading player");
	gears = 1;
	
	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 1, 4);
	car.chassis_offset.Set(0, 1, 0);
	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 20;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 2000.0f;

	// Wheel properties ---------------------------------------
	

	// Don't change anything below this line ------------------

	
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	////RUEADAS ARRIBA

	//car.wheels[4].connection.Set(half_width - 0.3f * wheel_width, 3, half_length - wheel_radius);
	//car.wheels[4].direction = direction;
	//car.wheels[4].axis = axis;
	//car.wheels[4].suspensionRestLength = suspensionRestLength;
	//car.wheels[4].radius = wheel_radius;
	//car.wheels[4].width = wheel_width;
	//car.wheels[4].front = true;
	//car.wheels[4].drive = true;
	//car.wheels[4].brake = false;
	//car.wheels[4].steering = true;



	//// FRONT-RIGHT ------------------------
	//car.wheels[5].connection.Set(-half_width + 0.3f * wheel_width, 3, half_length - wheel_radius);
	//car.wheels[5].direction = direction;
	//car.wheels[5].axis = axis;
	//car.wheels[5].suspensionRestLength = suspensionRestLength;
	//car.wheels[5].radius = wheel_radius;
	//car.wheels[5].width = wheel_width;
	//car.wheels[5].front = true;
	//car.wheels[5].drive = true;
	//car.wheels[5].brake = false;
	//car.wheels[5].steering = true;

	//// REAR-LEFT ------------------------
	//car.wheels[6].connection.Set(half_width - 0.3f * wheel_width, 3, -half_length + wheel_radius);
	//car.wheels[6].direction = direction;
	//car.wheels[6].axis = axis;
	//car.wheels[6].suspensionRestLength = suspensionRestLength;
	//car.wheels[6].radius = wheel_radius;
	//car.wheels[6].width = wheel_width;
	//car.wheels[6].front = false;
	//car.wheels[6].drive = true;
	//car.wheels[6].brake = true;
	//car.wheels[6].steering = false;

	//// REAR-RIGHT ------------------------
	//car.wheels[7].connection.Set(-half_width + 0.3f * wheel_width, 3, -half_length + wheel_radius);
	//car.wheels[7].direction = direction;
	//car.wheels[7].axis = axis;
	//car.wheels[7].suspensionRestLength = suspensionRestLength;
	//car.wheels[7].radius = wheel_radius;
	//car.wheels[7].width = wheel_width;
	//car.wheels[7].front = false;
	//car.wheels[7].drive = true;
	//car.wheels[7].brake = true;
	//car.wheels[7].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos (0, 2 + 200, 250);
	
	vehicle->collision_listeners.add(this);
	vehicle->SetId(1);

	checkpoint = btVector3(0, 2, 90);

	 object.body = App->physics->AddBody(Cube(1, 1, 1), 0.1f);
	 object.body->body->setGravity({ 0,9.8f,0 });


	
	App->physics->AddConstraintHinge(*vehicle, *object.body, vec3(0, 1, 0), vec3(0, 0, 6), vec3(0, 1, 0), vec3(0, 1, 0), false);
	
	object.body->SetAsSensor(true);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
			
		acceleration = -MAX_ACCELERATION * 600;

	}

	if (change == true) {

		vehicle->collision_listeners.add(this);

		change = false;
	}

	if (vehicle->GetPos().y() < 175) 
	{
		vehicle->ResetCarOrientation();
		vehicle->SetPos(checkpoint.x(), checkpoint.y(), checkpoint.z());
		vehicle->body->setLinearVelocity({ 0,0,0 });
	}
	//if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	//{
	//	
	//	acceleration = MAX_ACCELERATION;
	object.cube.Update(object.body);
	//}
	if (vehicle->GetKmh() <= 0 && App->input->GetKey(SDL_SCANCODE_DOWN) != KEY_REPEAT && revs >= 0) { revs = 0; }

	if (App->input->GetKey(SDL_SCANCODE_UP) != KEY_REPEAT && vehicle->GetKmh() >= 0 )
	{
		
		if (ice == false)
		acceleration = acceleration - 400;
	}
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT && gears == 1 && App->player->vehicle->GetKmh() < 250)
	{
		acceleration = MAX_ACCELERATION * 800;
		
	}


	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if (turn < TURN_DEGREES) {
			if (gears == 1) { 
				if (App->player->vehicle->GetKmh() < 150) { turn += TURN_DEGREES; }
				else if (App->player->vehicle->GetKmh() >= 150 && App->player->vehicle->GetKmh() < 250) { turn += TURN_DEGREES / 2; }
				else if (App->player->vehicle->GetKmh() >= 250) { turn += TURN_DEGREES / 3; }
			}

			if (App->scene_intro->AutobusVehicle == true)
				turn += TURN_DEGREES * 2;

			if (App->scene_intro->tricicle == true)
				turn += TURN_DEGREES;

			if (App->scene_intro->monsterTruck == true)
				turn += TURN_DEGREES;


			if (ice == true) { turn += TURN_DEGREES * 2; }
		}
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if (turn > -TURN_DEGREES) {
			if (gears == 1) {
			
				if (App->player->vehicle->GetKmh() < 150) { turn -= TURN_DEGREES; }
				else if (App->player->vehicle->GetKmh() >= 150 && App->player->vehicle->GetKmh() < 250) { turn -= TURN_DEGREES / 2; }
				else if (App->player->vehicle->GetKmh() >= 250) { turn -= TURN_DEGREES / 3; }
			}

			if (App->scene_intro->AutobusVehicle == true)
				turn -= TURN_DEGREES * 2;

			if (App->scene_intro->tricicle == true)
				turn -= TURN_DEGREES;

			if (App->scene_intro->monsterTruck == true)
				turn -= TURN_DEGREES;
			if (ice == true) { turn -= TURN_DEGREES * 2; }
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_I) == KEY_DOWN)
	{
		if (ice == false)
		{
			ice = true;

		}
		else {
			ice = false;
		}
	}
	
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
	{
		if (gears == 1) { brake = 100; }
		
		if (ice == true) { brake = 0; }
	}

	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_REPEAT)
	{
		btVector3 p = vehicle->GetPos();
		vehicle->ResetCarOrientation();
		vehicle->SetPos(p.x(), p.y(), p.z());
		vehicle->body->setLinearVelocity({0,0,0});
	}

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_REPEAT)
	{
		
		vehicle->ResetCarOrientation();
		vehicle->SetPos(checkpoint.x(),checkpoint.y(),checkpoint.z());
		vehicle->body->setLinearVelocity({ 0,0,0 });
	}

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();
	gameTimer += 1 * dt;
	char title[80];
	sprintf_s(title, "Time: %.0f  %.1f Km/h Gear: %d Revs: %.1f Coins: %d", gameTimer,vehicle->GetKmh(), gears, revs, App->scene_intro->coin);
	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{

	p2List_item<Mud>* currentItem8 =App->scene_intro->mudPointList.getFirst();

	while (currentItem8 != NULL) {
		App->scene_intro->timer3+= 1* App->scene_intro->dt2;
		currentItem8->data.cube.Render();
	

		// Homebrew collision detection for sensors
		
			LOG("car touch coing");
			//currentItem->data->pendingToDelete = true;
			//patata
			
		
			//App->audio->PlayFx(coinFx);
		
			if (currentItem8->data.body == body2 && currentItem8->data.passed == false && body2->id != 6) {
				currentItem8->data.passed = true;
				App->scene_intro->timer3 = 0;
				App->player->vehicle->body->setLinearVelocity(App->player->vehicle->body->getLinearVelocity() / 2);
			}

			currentItem8 = currentItem8->next;
	}

	p2List_item<Ice>* currentItem2 = App->scene_intro->icePointList.getFirst();

	while (currentItem2 != NULL) {
		App->scene_intro->timer3 += 1 * App->scene_intro->dt2;
		currentItem2->data.cube.Render();


		// Homebrew collision detection for sensors

		LOG("car touch coing");
		//currentItem->data->pendingToDelete = true;
		//patata


		//App->audio->PlayFx(coinFx);

		if (currentItem2->data.body == body2 && currentItem2->data.passed == false && body2->id != 6) {
			App->player->ice = true;
		}

		currentItem2 = currentItem2->next;
	}

}








