#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "Color.h"
#include "ModulePlayer.h"
#include "PhysVehicle3D.h"
#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

struct GravityChange
{
	PhysBody3D* body;
	Cube cube;
	bool passed;
};

struct Booster
{
	PhysBody3D* body;
	Cube cube;
	bool passed;
};

struct BoosterUp
{
	PhysBody3D* body;
	Cube cube;
	bool passed;
};

struct Checkpoint
{
	PhysBody3D* body;
	Cube cube;
	bool passed;
};

struct Train
{
	PhysBody3D* body;
	Cube cube;
	bool passed;
};

struct Coin
{
	PhysBody3D* body;
	Cylinder cylinder;
	bool passed;
	int timer = 0;
	bool deleted = false;
};


class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void createGround();
	void addCube(vec3 pos, vec3 size, Color rgb, float rotX, float rotY , float rotZ );
	
	void addCoin(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addGravityChanger(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addCubeSensor(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1);
	void addBooster(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addBoosterUp(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addCheckpoint(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	Train train;

	p2List<Booster> boosterPointList;
	p2List<BoosterUp> boosterUpPointList;
	
	p2List<Checkpoint> checkpointPointList;
	p2List<GravityChange> gravityChangePointList;
	p2List<Coin> coinPointList;

	bool inverted = false;
	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;
	float timerGrav = 0;
	Cube box;

	int coin = 0;

	p2List<Cube> buildingBlocks;

};
