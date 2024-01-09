#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Bullet/include/LinearMath/btVector3.h"

struct PhysVehicle3D;


#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	bool CleanUp();
	
public:
	int gears;
	float revs = 0.0f;
	PhysVehicle3D* vehicle;
	float turn;
	btVector3 checkpoint;
	float acceleration;
	float brake;

	float half_width = 2 * 0.5f;
	float half_length = 4 * 0.5f;

	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;
};