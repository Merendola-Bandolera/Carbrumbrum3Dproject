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
	
	car.num_wheels = 8;
	car.wheels = new Wheel[8];

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

	//RUEADAS ARRIBA

	car.wheels[4].connection.Set(half_width - 0.3f * wheel_width, 3, half_length - wheel_radius);
	car.wheels[4].direction = direction;
	car.wheels[4].axis = axis;
	car.wheels[4].suspensionRestLength = suspensionRestLength;
	car.wheels[4].radius = wheel_radius;
	car.wheels[4].width = wheel_width;
	car.wheels[4].front = true;
	car.wheels[4].drive = true;
	car.wheels[4].brake = false;
	car.wheels[4].steering = true;



	// FRONT-RIGHT ------------------------
	car.wheels[5].connection.Set(-half_width + 0.3f * wheel_width, 3, half_length - wheel_radius);
	car.wheels[5].direction = direction;
	car.wheels[5].axis = axis;
	car.wheels[5].suspensionRestLength = suspensionRestLength;
	car.wheels[5].radius = wheel_radius;
	car.wheels[5].width = wheel_width;
	car.wheels[5].front = true;
	car.wheels[5].drive = true;
	car.wheels[5].brake = false;
	car.wheels[5].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[6].connection.Set(half_width - 0.3f * wheel_width, 3, -half_length + wheel_radius);
	car.wheels[6].direction = direction;
	car.wheels[6].axis = axis;
	car.wheels[6].suspensionRestLength = suspensionRestLength;
	car.wheels[6].radius = wheel_radius;
	car.wheels[6].width = wheel_width;
	car.wheels[6].front = false;
	car.wheels[6].drive = true;
	car.wheels[6].brake = true;
	car.wheels[6].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[7].connection.Set(-half_width + 0.3f * wheel_width, 3, -half_length + wheel_radius);
	car.wheels[7].direction = direction;
	car.wheels[7].axis = axis;
	car.wheels[7].suspensionRestLength = suspensionRestLength;
	car.wheels[7].radius = wheel_radius;
	car.wheels[7].width = wheel_width;
	car.wheels[7].front = false;
	car.wheels[7].drive = true;
	car.wheels[7].brake = true;
	car.wheels[7].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 2, 10);
	
	vehicle->collision_listeners.add(this);
	vehicle->SetId(1);

	checkpoint = btVector3(0, 2, 0);

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

	if (App->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN && gears != 1) {
		gears--;
	}

	if (App->input->GetKey(SDL_SCANCODE_X) == KEY_DOWN && gears != 3) {
		gears++;
	}
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
			
		acceleration = -MAX_ACCELERATION * 600;

	}if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		
		acceleration = MAX_ACCELERATION;

	}
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_UP)
	{
		revs = 0.0f;
	}
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT && gears == 1)
	{
		if (revs <= 3000) {
			revs = revs + 100.0f;
			acceleration = MAX_ACCELERATION * revs;
		}
		else if (revs <= 4000) {
			revs = revs + 10.0f;
			acceleration = MAX_ACCELERATION * revs;
		}
		if (revs >= 4000) {
			acceleration = MAX_ACCELERATION;
		}
		
	}
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT && gears == 2)
	{
		if (revs <= 4500) {
			revs = revs + 10.0f;
			acceleration = MAX_ACCELERATION * revs;
		}
		if (revs >= 4500) {
			acceleration = MAX_ACCELERATION;
		}
	}
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT && gears == 3)
	{
		if (revs <= 5000) {
			revs = revs + 5.0f;
			acceleration = MAX_ACCELERATION * revs;
		}
		if (revs >= 5000) {
			acceleration = MAX_ACCELERATION;
		}
	}

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if (turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
	{
		if (gears == 1) { brake = 100; }
		if (gears == 2) { brake = 75; }
		if (gears == 3) { brake = 50; }
	}

	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_REPEAT)
	{
		btVector3 p = vehicle->GetPos();
		vehicle->ResetCarOrientation();
		vehicle->SetPos(p.x(), p.y(), p.z());
	}

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_REPEAT)
	{
		
		vehicle->ResetCarOrientation();
		vehicle->SetPos(checkpoint.x(),checkpoint.y(),checkpoint.z());
	}

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	char title[80];
	sprintf_s(title, "%.1f Km/h Gear: %d Revs: %.1f", vehicle->GetKmh(), gears, revs);
	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	p2List_item<Booster>* checkItem = App->scene_intro->boosterPointList.getFirst();
	while (checkItem != NULL) {
		if (checkItem->data.body->id == body2->id && checkItem->data.passed == false && body2->id != 6) {
			checkItem->data.passed = true;
			vehicle->Push(0,100,0);
		}

		checkItem = checkItem->next;
	}

}





