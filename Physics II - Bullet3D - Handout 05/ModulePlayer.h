#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Bullet/include/LinearMath/btVector3.h"

struct PhysVehicle3D;


#define MAX_ACCELERATION 2.0f
#define TURN_DEGREES 8.0f * DEGTORAD
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
	float tempspeed;
	int timer;
	btVector3 checkpoint;
	float acceleration;
	float brake;
};