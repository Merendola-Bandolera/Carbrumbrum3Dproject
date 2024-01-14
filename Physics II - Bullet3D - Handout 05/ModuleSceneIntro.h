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

enum vehicles
{
	GravityVehicle = 0, NormalVehicle = 1, AutobusVehicle = 2,
};

struct GravityChange
{
	PhysBody3D* body;
	Cube cube;
	bool passed;
	int id2 = 0;
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

struct Brake
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

struct Mud
{
	PhysBody3D* body;
	Cube cube;
	bool passed;
	float timer;
};

struct Ice
{
	PhysBody3D* body;
	Cube cube;
	bool passed;
	float timer;
};



struct NormalVehicleChanger
{
	PhysBody3D* body;
	Cube cube;
	bool passed;

};
struct AutobusVehicleChanger
{
	PhysBody3D* body;
	Cube cube;
	bool passed;

};
struct TricicleVehicleChanger
{
	PhysBody3D* body;
	Cube cube;
	bool passed;

};
struct HabiaOtroMasInterroganteVehicleChanger
{
	PhysBody3D* body;
	Cube cube;
	bool passed;

};

struct DestructibleBox
{
	PhysBody3D* body;
	Cube cube;
	bool passed;


};

struct WinBox
{
	PhysBody3D* body;
	Cube cube;
	bool passed;


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

	void addNormalVehicleChanger(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addAutobusVehicleChanger(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addTricicleVehicleChanger(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addHabiaOtroMasInterroganteVehicleChanger(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);

	void addDBox(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);

	void addWinBox(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	
	void addCoin(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addGravityChanger(vec3 pos, vec3 size, Color rgb, int id = GravityVehicle, bool passed_ = false);
	void addCubeSensor(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1);
	void addBooster(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addIce(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addMud(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
	void addBrake(vec3 pos, vec3 size, Color rgb, int angle = 0, bool rot_X = false, bool rot_Y = false, bool rot_Z = false, int id = -1, bool passed_ = false);
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

	p2List<Booster> boosterPointList;
	p2List<BoosterUp> boosterUpPointList;
	p2List<Brake> brakePointList;
	p2List<DestructibleBox> dBoxPointList;

	p2List<NormalVehicleChanger> NormalVehicleChangerPointList;
	p2List<TricicleVehicleChanger> TricicleVehicleChangerPointList;
	p2List<AutobusVehicleChanger> AutobusVehicleChangerPointList;
	p2List<HabiaOtroMasInterroganteVehicleChanger> HabiaOtroMasInterroganteVehicleChangerPointList;
	
	p2List<WinBox> WinBoxPointList;


	p2List<Checkpoint> checkpointPointList;
	p2List<GravityChange> gravityChangePointList;
	p2List<Coin> coinPointList;
	p2List<Mud> mudPointList;
	p2List<Ice> icePointList;

	bool inverted = false;
	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;
	float timerGrav = 0;
	Cube box;
	float timerVehicleChange = 0;
	int timer2 = 0;
	float timer3 = 0;
	int coin = 0;
	float dt2 = 0;
	float timer4 = 0;

	bool normalVehicle = true;
	bool AutobusVehicle = false;
	bool monsterTruck = false;
	bool tricicle = false;
	p2List<Cube> buildingBlocks;

};
