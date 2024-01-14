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
	
	//addBooster({ 0, 3, 120 }, { 5, 5, 5 }, Red, 0, 0, 0);

	//addBrake({ 0, 3, 120 }, { 5, 5, 5 }, Purple, 0, 0, 0);

	addMud({ 0, 3, 120 }, { 10, 5, 10 }, Brown, 0, 0, 0);

	addCoin({ 0, 3, 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);

	addCheckpoint({ 0, 2, 90 }, { 2, 2, 2 }, Yellow, 0, 0, 0);

	addGravityChanger({ 0, 2, 150 }, { 2, 2, 2 }, Blue,1);
	//addGravityChanger({ 0, 10, 150 }, { 2, 2, 2 }, Blue,0);
	
	
	//cubos de pau
	/*addCube({ 10, 12, 100 }, { 30, 2, 100 },   Grey, 0, 0, 0);
	addCube({ 1.7f, 12, 195 }, { 30, 2, 100 }, Grey, 0, -10, 0);
	addCube({ -24, 12, 288 }, { 30, 2, 100 },  Grey, 0, -20, 0);
	addCube({ -64.8, 12, 375 }, { 30, 2, 100 },Grey, 0, -30, 0);
	addCube({ -120, 12, 453 }, { 30, 2, 100 }, Grey, 0, -40, 0);
	addCube({ -188, 12, 520 }, { 30, 2, 100 }, Grey, 0, -50, 0);
	addCube({ -262, 12, 570 }, { 30, 2, 100 }, Grey, 0, -60, 0);
	addCube({ -350, 12, 610 }, { 30, 2, 100 }, Grey, 0, -70, 0);
	addCube({ -443, 12, 635 }, { 30, 2, 100 }, Grey, 0, -80, 0);
	addCube({ -539, 12, 643 }, { 30, 2, 100 }, Grey, 0, -90, 0);*/

	//CIRCUITO

	addNormalVehicleChanger({ 20,2 + 200,150 }, { 2, 2, 2 }, Purple, 0, 0, 0);
	addTricicleVehicleChanger({ 20,2 + 200,125 }, { 2, 2, 2 }, Blue, 0, 0, 0);
	addAutobusVehicleChanger({ 20,2 + 200,100 }, { 2, 2, 2 }, Orange, 0, 0, 0);
	addHabiaOtroMasInterroganteVehicleChanger({ 20,2 + 200,175 }, { 2, 2, 2 }, Red, 0, 0, 0);




	//SALIDA
	addCube({ 10,  -0.5f + 200, 300 }, { 30, 2, 500 }, Green, 0, 0, 0);
	addCheckpoint({ 0, 2 + 200, 250 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCheckpoint({ 4, 2 + 200, 250 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCheckpoint({ 8, 2 + 200, 250 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCheckpoint({ 12,2 + 200,250 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCheckpoint({ 16,2 + 200,250 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCheckpoint({ 20,2 + 200,250 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCube({ 24,7.5f + 200,250 }, { 2, 15, 2 }, Grey, 0, 0, 0);
	addCube({ -4,7.5f + 200,250 }, { 2, 15, 2 }, Grey, 0, 0, 0);
	addCheckpoint({ 10,17 + 200,250 }, { 30, 5, 2 }, Yellow, 0, 0, 0);
	addCube({ 100, -0.5f + 200, 580 }, { 200, 2, 30 }, Green, 0, -30, 0);
	addCube({ 279, -0.5f + 200, 628 }, { 200, 2, 30 }, Green, 0, 0, 0);
	addCube({ 190, -0.5f + 200, 636 }, { 50, 2, 10 }, Brown, 0, 0, 10);	//rampa
	addCube({ 185, -0.5f + 200, 636 }, { 50, 2, 10 }, Brown, 0, 0, 3);	//rampa
	addCube({ 360, -0.5f + 200, 618 }, { 50, 2, 10 }, Brown, 0, 0, 10);	//rampa
	addCube({ 355, -0.5f + 200, 618 }, { 50, 2, 10 }, Brown, 0, 0, 3);	//rampa
	addCoin({ 355, 3 + 200, 618 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ 190, 3 + 200, 636 }, { 5, 5, 5 }, Yellow, 0, 0, 30);

	//ZONA ANTES DEL WALLRIDE
	addCube({ 475, -0.5f + 200, 611 }, { 200, 2, 40 }, Green, 0, 10, 0);
	addCube({ 613, -0.5f + 200, 610 }, { 100, 2, 30 }, Green, 0, -20, 0);
	addCoin({ 613, 1 + 200, 610 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ 694, -0.5f + 200, 657 }, { 100, 2, 30 }, Green, 0, -40, 0);
	addCube({ 754, -0.5f + 200, 728 }, { 100, 2, 30 }, Green, 0, -60, 0);
	addCheckpoint({ 786, 2 + 200, 816 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCube({ 786, -0.5f + 200, 816 }, { 100, 2, 30 }, Green, 0, -80, 0);
	addCoin({ 816, 4 + 200, 900 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ 807, -0.5f + 200, 900 }, { 30, 2, 100 }, Brown, 0, 0, 30);		//Wallride
	addCube({ 817, 4 + 200, 1000 }, { 30, 2, 100 }, Brown, 0, 0, 60);		//Wallride
	addCube({ 800, 4 + 200, 1110 }, { 30, 2, 100 }, Green, 0, -10, 0);
	addCube({ 819, 4 + 200, 1085 }, { 2, 30, 30 }, Brown, 0, -15, 0);


	//CURVA DE IVO
	addAutobusVehicleChanger({ 1.7f + 782, 6 + 200, 190 + 1000 }, { 2, 2, 2 }, Orange, 0, 0, 0);
	addCube({ 1.7f + 782, 4 + 200, 195 + 1009 }, { 30, 2, 100 }, Green, 0, -10, 0);
	addCoin({ 1.7f + 782, 6 + 200, 195 + 1009 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -24 + 782,  4 + 200, 288 + 1009 }, { 30, 2, 100 }, Green, 0, -20, 0);
	addCube({ -64.8 + 782,4 + 200, 375 + 1009 }, { 30, 2, 100 }, Green, 0, -30, 0);
	addCube({ -120 + 782, 4 + 200, 453 + 1009 }, { 30, 2, 100 }, Green, 0, -40, 0);
	addCoin({ -120 + 782, 6 + 200, 453 + 1009 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -188 + 782, 4 + 200, 520 + 1009 }, { 30, 2, 100 }, Green, 0, -50, 0);
	addCube({ -262 + 782, 4 + 200, 570 + 1009 }, { 30, 2, 100 }, Green, 0, -60, 0);
	addCube({ -350 + 782, 4 + 200, 610 + 1009 }, { 30, 2, 100 }, Green, 0, -70, 0);
	addCoin({ -350 + 782, 6 + 200, 610 + 1009 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -443 + 782, 4 + 200, 635 + 1009 }, { 30, 2, 100 }, Green, 0, -80, 0);
	addCube({ -539 + 782, 4 + 200, 643 + 1009 }, { 30, 2, 100 }, Green, 0, -90, 0);
	addCheckpoint({ 340, 6 + 200, 643 + 1000 }, { 2, 2, 2 }, Yellow, 0, 0, 0);


	//ZONA DEL BARRO
	addNormalVehicleChanger({ 50,57 + 200,1652 }, { 2, 2, 2 }, Blue, 0, 0, 0);
	addCube({ 244,	13 +200, 1652 }, { 100, 2, 30 }, Orange, 0, 0, -10);
	addCube({ 149,	38 +200, 1652 }, { 100, 2, 30 }, Orange, 0, 0, -20);
	addCube({ -148,	55 +200, 1652 }, { 500, 2, 120 },Orange, 0, 0, 0);
	//barros	
	addMud({ 78,		56+200, 1652 -35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ 78 -50,	56+200, 1652 - 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ 78 - 100,	56+200, 1652 + 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ 78 - 150,	56+200, 1652 + 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ 78 - 125,	56+200, 1652 +10 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -118 - 100,56+200, 1652 + 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -118 - 150,56+200, 1652 + 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -118 - 125,56+200, 1652 + 10 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -78 - 40,	56+200, 1652 - 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -78 - 90,	56+200, 1652 - 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -78 - 240,	56+200, 1652 - 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -78 - 290,	56+200, 1652 - 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -78 - 300,	56+200, 1652 + 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addCube({ 58,	140 +200, 1652 }, { 2, 150, 120 }, Invisible, 0, 0, 0);
	//monedas
	addCoin({ -148 + 180, 57 +200, 1652 + 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 + 140, 57 +200, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 + 100, 57 +200, 1652 - 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 + 50,  57 +200, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 ,	  57 +200, 1652 + 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 50 , 57 +200, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 100 ,57 +200, 1652 - 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 140 ,57 +200, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 180 ,57 +200, 1652 + 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 220 ,57 +200, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 300 ,57 +200, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	//out of barro
	addCube({ -448,	55 +200, 1652 }, { 100, 2, 30 }, Green, 0, 0, 0);
	addCheckpoint({ -468,	57 +200, 1652 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCube({ -534,	55+200, 1629 }, { 100, 2, 30 }, Green, 0, -30, 0);
	addCube({ -597,	55+200, 1566 }, { 100, 2, 30 }, Green, 0, -60, 0);
	addCube({ -627 ,55+200, 1486 }, { 30, 2, 100 }, Green, 0, 0, -40); //Wallride
	addCube({ -653 ,79+200, 1486 }, { 30, 2, 100 }, Green, 0, 0, -60); //Wallride
	addCube({ -653,	45+200, 1300 }, { 30, 2, 300 }, Green, -10, 0, 0);
	addCoin({ -653,	48+200, 1300 }, { 5, 5, 5 }, Yellow, 0, 0, 30);


	//HIELO 1 + SETA 1
	addCube({ -653,			19 +200, 1010 }, { 30, 2, 300 }, Green, 0, 0, 0);
	addCoin({ -653,			22 +200, 1050 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCheckpoint({ -653,	21 +200, 1080 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addBoosterUp({ -653,	19 +200, 1010 }, { 5, 5, 5 }, Orange, 0, 0, 0);
	//I
	addCube({ -658,	35 + 200, 1040 }, { 2, 5, 2 }, Grey, 0, 0, 0);
	//C
	addCube({ 0	   -655, 17 + 218,		1040 }, { 1, 2, 2 }, Grey, 0, 0, 0);
	addCube({ 0.5f -655, 18 + 218,	1040 }, { 1, 2, 2 }, Grey, 0, 0, -45);
	addCube({ 0.5f -655, 16 + 218,	1040 }, { 1, 2, 2 }, Grey, 0, 0, 45);
	addCube({ 1.5f -655, 18.6f + 218,1040 }, { 1, 2, 2 }, Grey, 0, 0, -65);
	addCube({ 1.5f -655, 15.4f + 218,1040 }, { 1, 2, 2 }, Grey, 0, 0, 65);
	addCube({ 2.5f -655, 19 + 218,	1040 }, { 1, 2, 2 }, Grey, 0, 0, -90);
	addCube({ 2.5f -655, 15 + 218,	1040 }, { 1, 2, 2 }, Grey, 0, 0, 90);
	//E
	addCube({ -649,	   35 + 200,	1040 }, { 2, 5, 2 }, Grey, 0, 0, 0);
	addCube({ -649 +2, 35 + 200,	1040 }, { 3, 1, 2 }, Grey, 0, 0, 0);
	addCube({ -649 +2, 37 + 200,	1040 }, { 3, 1, 2 }, Grey, 0, 0, 0);
	addCube({ -649 +2, 33 + 200,	1040 }, { 3, 1, 2 }, Grey, 0, 0, 0);

	addIce({ -653,			19 +200, 710 }, { 120, 20, 500 }, Blue, 0, 0, 0);
	addIce({ -653,			19 + 200, 710 }, { 120, 20, 500 }, Blue, 0, 0, 0);
	addHabiaOtroMasInterroganteVehicleChanger({ -653,30 + 200, 710 +100}, { 2, 2, 2 }, Red, 0, 0, 0);
	addCube({ -683,	22 + 200, 790 }, { 2, 50, 100 }, Blue, 0, -45, 0);
	addCube({ -683,	22 + 200, 717 }, { 2, 50, 100 }, Blue, 0, 45, 0);
	addCube({ -593,	22 + 200, 710 }, { 2, 50, 500 }, Blue, 0, 0, 0);
	addCube({ -713,	22 + 200, 710 }, { 2, 50, 500 }, Blue, 0, 0, 0);
	addCube({ -683,	22 + 200, 790 -150 }, { 2, 50, 100 }, Blue, 0, -45, 0);
	addCube({ -683,	22 + 200, 717 -150 }, { 2, 50, 100 }, Blue, 0, 45, 0);
	addCube({ -683 +60,	22 + 200, 717 - 75 }, { 2,50, 100 }, Blue, 0, -45, 0);
	addCube({ -683 +60,	22 + 200, 790 - 75 }, { 2,50, 100 }, Blue, 0, 45, 0);
	addCube({ -683 + 60,	22 + 200, 717 - 225 }, { 2, 50, 100 }, Blue, 0, -45, 0);
	addCube({ -683 + 60,	22 + 200, 790 - 225 }, { 2, 50, 100 }, Blue, 0, 45, 0);
	addCoin({ -653,			30 +200, 800 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 +50,		30 +200, 800 -40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 ,		30 +200, 800 - 80 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 -50,		30 +200, 800 - 120 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 ,		30 +200, 800 - 160 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 + 50,	30 +200, 800 - 200 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,			30 +200, 800 - 240 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 - 50,	30 +200, 800 - 280 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,			30 +200, 800 - 320 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -653,			69 +200, 810 }, { 120, 2, 500 }, Blue, 0, 0, 0);

	//SETA 2
	addCube({ -653,		19 +200, 430 }, { 30, 20, 60 }, Blue, 0, 0, 0);
	addBoosterUp({ -653,29 +200, 440 }, { 5, 5, 5 }, Orange, 0, 0, 0);


	//HIELO 2 + TUNEL
	addCube({ -653,		 39 +200, 150 }, { 120, 20, 500 }, Blue, 0, 0, 0);
			addCube({ -683,	42 + 200, 790 -550 }, { 2, 50, 100 }, Blue, 0, -45, 0);
			addCube({ -683,	42 + 200, 717- 550 }, { 2, 50, 100 }, Blue, 0, 45, 0);
			addCube({ -593,	42 + 200, 710- 550 }, { 2, 50, 500 }, Blue, 0, 0, 0);
			addCube({ -713,	42 + 200, 710- 550 }, { 2, 50, 500 }, Blue, 0, 0, 0);
			addCube({ -683,	42 + 200, 790 - 700 }, { 2, 50, 100 }, Blue, 0, -45, 0);
			addCube({ -683,	42 + 200, 717 - 700 }, { 2, 50, 100 }, Blue, 0, 45, 0);
			addCube({ -683 + 60,42 + 200, 717 - 625 }, { 2, 50, 100 }, Blue, 0, -45, 0);
			addCube({ -683 + 60,42 + 200, 790 - 625 }, { 2, 50, 100 }, Blue, 0, 45, 0);
			addCube({ -683 + 60,42 + 200, 717 - 775 }, { 2, 50, 100 }, Blue, 0, -45, 0);
			addCube({ -683 + 60,42 + 200, 790 - 775 }, { 2, 50, 100 }, Blue, 0, 45, 0);
	addCoin({ -653,		 32 +200, 800 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 + 50, 50 +200, 250 - 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,		 50 +200, 250 - 80 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 - 50, 50 +200, 250 - 120 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,		 50 +200, 250 - 160 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 + 50, 50 +200, 250 - 200 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,		 50 +200, 250 - 240 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 - 50, 50 +200, 250 - 280 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,		 50 +200, 250 - 320 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -653,		 89 +200, 250 }, { 120, 2, 500 }, Blue, 0, 0, 0);
	addCube({ -653,		 10 +200, -133 }, { 30, 2, 100 }, Blue, -50, 0, 0);
	addCube({ -653 - 15, 25 +200, -143 }, { 2, 60, 70 }, Blue, 0, 0, 0);
	addCube({ -653 + 15, 25 +200, -143 }, { 2, 60, 70 }, Blue, 0, 0, 0);
	addCheckpoint({ -653,52 +200, -83 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCube({ -653,		 45 +200, -123 }, { 30, 2, 30 }, Blue, -40, 0, 0);
	addCube({ -653,		  8 +200, -143 }, { 30, 2, 100 }, Blue, -30, 0, 0);
	addCube({ -653,		  5 +200, -153 }, { 30, 2, 100 }, Blue, -10, 0, 0);
	addCube({ -653,		-0.5f +200, -203 }, { 30, 2, 100 }, Green, 0, 0, 0);
	addCube({ -653,		-0.5f +200, -368 }, { 30, 2, 230 }, Green, 0, 0, 0);

	//WALLRIDE
	addTricicleVehicleChanger({ -652, 202, -200 }, { 2, 2, 2 }, Blue, 0, 0, 0);
	addBooster({ -652, 202, -250 }, { 5, 5, 5 }, Red, 0, 0, 0);
	addCube({ -647 - 15,-0.5f +200, -353 }, { 50, 2, 300 }, Green, 0, 0, -20);
	addCoin({ -675,		  208, -353 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -675,		  208, -453 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -647 - 25,-0.5f +200, -353 }, { 50, 2, 300 }, Green, 0, 0, -40);
	addCube({ -647 - 63,-0.5f +200, -353 }, { 50, 50, 300 }, Brown, 0, 0, 0);
	addCube({ -647 - 35,-0.5f +200, -483 }, { 2, 50, 50 }, Brown, 0, -10, 0);
	addCube({ -647 - 30,-0.5f +200, -493 }, { 2, 50, 50 }, Brown, 0, -20, 0);
	addCube({ -647 - 25,-0.5f +200, -503 }, { 2, 50, 50 }, Brown, 0, -40, 0);
	addCube({ -647 - 20,-0.5f +200, -513 }, { 2, 50, 50 }, Brown, 0, -60, 0);
	addCube({ -647 - 10,-0.5f +200, -523 }, { 2, 50, 50 }, Brown, 0, -80, 0);
	addCube({ -640 ,	-0.5f +200, -551 }, { 400, 50, 50 }, Brown, 0, 0, 0);
	addCube({ -587 ,	-0.5f +200, -513 }, { 200, 2, 50 }, Green, 50, 0, 0);
	addCube({ -493,		-0.5f +200, -498 }, { 400, 2, 30 }, Green, 0, 0, 0);

	//ZONA BOCARRIBA	
	addCoin({ -570 ,207, -514 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCheckpoint({ -460 ,	  1+200, -500 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCube({ -393,			 20+200, -408 }, { 60, 2, 300 }, Purple, 0, 0, 0);
	addCube({ -363,			 20+200, -498 }, { 2, 50, 30 }, Purple, 0, 0, 0);
	addGravityChanger({ -410 ,1+200, -490 }, { 2, 2, 2 }, Blue, 0);  
	addGravityChanger({ -410 ,1+200, -496 }, { 2, 2, 2 }, Blue,  0); 
	addGravityChanger({ -410 ,1+200, -502 }, { 2, 2, 2 }, Blue, 0);  
	addGravityChanger({ -410 ,1+200, -508 }, { 2, 2, 2 }, Blue, 0);
	addGravityChanger({ -374,18+200, -298 }, { 2, 2, 2 }, Blue, 1);
	addGravityChanger({ -380,18+200, -298 }, { 2, 2, 2 }, Blue, 1);
	addGravityChanger({ -386,18+200, -298 }, { 2, 2, 2 }, Blue, 1);
	addGravityChanger({ -392,18+200, -298 }, { 2, 2, 2 }, Blue,1);
	addGravityChanger({ -398,18+200, -298 }, { 2, 2, 2 }, Blue, 1);
	addGravityChanger({ -404,18+200, -298 }, { 2, 2, 2 }, Blue, 1);
	addGravityChanger({ -410,18+200, -298 }, { 2, 2, 2 }, Blue, 1);
																

	addCube({ -393,		-0.5f +200, -275 }, { 50, 2, 75 }, Green, 0, 0, 0);
	addCheckpoint({ -393,	3 +200, -275 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCube({ -258 - 75,-0.5f +200, -475 + 250 }, { 100, 2, 30 }, Green, 0, -30, 0);
	addCube({ -196 - 75,-0.5f +200, -412 + 250 }, { 100, 2, 30 }, Green, 0, -60, 0);
	addCube({ -173 - 75,-0.5f +200, -327 + 250 }, { 100, 2, 30 }, Green, 0, -90, 0);
	addCube({ -173 - 65,-0.5f +200, -15 }, { 50, 2, 30 }, Green, 0, -60, 0);
	addCube({ -173 - 36,-0.5f +200, 12 }, { 50, 2, 30 }, Green, 0, -30, 0);

	//ULTIMA CURVA
	addCube({ -50,-0.5f+ 200, 10 }, { 300, 2, 30 }, Green, 30, 0, 0);
	addCube({ -50,-0.5f+ 200, -18 }, { 200, 50, 30 }, Brown, 0, 0, 0);
	addCube({ 24 ,-0.5f+ 200,38 - 12 }, { 2, 50, 100 }, Brown, 0, 20, 0);
	addCube({ 24 ,-0.5f+ 200,34 - 12 }, { 2, 50, 100 }, Brown, 0, 30, 0);
	addCube({ 24 ,-0.5f+ 200,30 - 12 }, { 2, 50, 100 }, Brown, 0, 40, 0);
	addCube({ 24 ,-0.5f+ 200,26 - 12 }, { 2, 50, 100 }, Brown, 0, 50, 0);
	addCube({ 24 ,-0.5f+ 200,22 - 12 }, { 2, 50, 100 }, Brown, 0, 60, 0);
	addCube({ 24 ,-0.5f+ 200,18 - 12 }, { 2, 50, 100 }, Brown, 0, 70, 0);
	addCube({ 24 ,-0.5f+ 200,14 - 12 }, { 2, 50, 100 }, Brown, 0, 80, 0);
	addCube({ 24 ,-0.5f+ 200,10 - 14 }, { 2, 50, 100 }, Brown, 0, 90, 0);
	addCube({ 20 ,   -5+ 200, 50 }, { 2, 75, 100 }, Brown, 0, 0, -30);

	//FINAL
	addCube({ 24,7.5f +	200,	200 }, { 2, 15, 2 }, Grey, 0, 0, 0);
	addCube({ -4,7.5f +	200,	200 }, { 2, 15, 2 }, Grey, 0, 0, 0);
	addCheckpoint({ 10,17 + 200,200 }, { 30, 5, 2 }, Brown, 0, 0, 0);
	//E
	addCube({ 16 +3, 17 + 200,	199 }, { 2, 5, 2 }, Grey, 0, 0, 0);
	addCube({ 13 +3, 17 + 200,	199 }, { 4, 1, 2 }, Grey, 0, 0, 0);
	addCube({ 13 +3, 19 + 200,	199 }, { 4, 1, 2 }, Grey, 0, 0, 0);
	addCube({ 13 +3, 15 + 200,	199 }, { 4, 1, 2 }, Grey, 0, 0, 0);
	//N
	addCube({ 12, 17 + 200,	199 }, { 2, 5, 2 }, Grey, 0, 0, 0);
	addCube({ 9+0.5f, 17 + 200,	199 }, { 1, 6, 2 }, Grey, 0, 0, -45);
	addCube({ 7, 17 + 200,	199 }, { 2, 5, 2 }, Grey, 0, 0, 0);
	//D
	addCube({ 4, 17 + 200,	199 }, { 2, 5, 2 }, Grey, 0, 0, 0);
	addCube({ 0, 17 + 200,	199 }, { 1, 2, 1 }, Grey, 0, 0, 0);
	addCube({ 0.5f, 18 + 200,	199 }, { 1, 2, 1 }, Grey, 0, 0, -45);
	addCube({ 0.5f, 16 + 200,	199 }, { 1, 2, 1 }, Grey, 0, 0, 45);
	addCube({ 1.5f, 18.6f + 200,	199 }, { 1, 2, 1 }, Grey, 0, 0, -65);
	addCube({ 1.5f, 15.4f + 200,	199 }, { 1, 2, 1 }, Grey, 0, 0,  65);
	addCube({ 2.5f, 19 + 200,	199 }, { 1, 2, 1 }, Grey, 0, 0, -90);
	addCube({ 2.5f, 15 + 200,	199 }, { 1, 2, 1 }, Grey, 0, 0,  90);

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

	timerGrav++;
	box.SetPos(1, 1, 1);
	box.Render();
	dt2 = dt;

	
	/*p2List_item<Booster>* d = boosterPointList.getFirst();
	while (d != NULL) {
		d->data.cube.Render();
		d = d->next;
	}*/
	
   
	p2List_item<Cube>* c = buildingBlocks.getFirst();
	while (c != NULL) {
		c->data.Render();
		c = c->next;
	}

	p2List_item<Ice>* c4 = icePointList.getFirst();
	while (c4 != NULL) {
		c4->data.cube.Render();
		c4 = c4->next;
	}
	/*p2List_item<Booster>* d = boosterPointList.getFirst();
	while (d != NULL) {
		d->data.cube.Render();
		d = d->next;
	}*/
	p2List_item<Booster>* currentItem = boosterPointList.getFirst();

	while (currentItem != NULL) {
		timer4 += 1 * dt;
		currentItem->data.cube.Render();
			btVector3 boosterPos = currentItem->data.body->GetPos();
			btVector3 carPos = App->player->vehicle->GetPos();
			float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
			float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
			float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

			// Homebrew collision detection for sensors
			if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3) ) {
				LOG("car touch coing");
				//currentItem->data->pendingToDelete = true;

				currentItem = currentItem->next;
				//App->audio->PlayFx(coinFx);
				if (timer4 > 3)
				{
					App->player->vehicle->body->setLinearVelocity(App->player->vehicle->body->getLinearVelocity() * 1.5);
					timer4 = 0;
				}
			
				
			
			}
			else {
				currentItem = currentItem->next;
			}
		
		
	}

	p2List_item<Mud>* currentItem8 = mudPointList.getFirst();

	while (currentItem8 != NULL) {

			currentItem8->data.cube.Render();
	
	
			currentItem8 = currentItem8->next;
		


	}

	p2List_item<BoosterUp>* currentItem6 = boosterUpPointList.getFirst();

	while (currentItem6 != NULL) {
		

		currentItem6->data.cube.Render();
		btVector3 boosterPos = currentItem6->data.body->GetPos();
		btVector3 carPos = App->player->vehicle->GetPos();
		float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
		float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
		float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

		// Homebrew collision detection for sensors
		if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3)) {
			LOG("car touch coing");
			//currentItem->data->pendingToDelete = true;

			currentItem6 = currentItem6->next;
			//App->audio->PlayFx(coinFx);
			App->player->vehicle->Push(0, 2500, 0);


		}
		else {
			currentItem6 = currentItem6->next;
		}


	}

	p2List_item<Brake>* currentItem7 = brakePointList.getFirst();

	while (currentItem7 != NULL) {
		timer2++;

		currentItem7->data.cube.Render();
		btVector3 boosterPos = currentItem7->data.body->GetPos();
		btVector3 carPos = App->player->vehicle->GetPos();
		float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
		float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
		float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

		// Homebrew collision detection for sensors
		if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3)) {
			LOG("car touch coing");
			//currentItem->data->pendingToDelete = true;

			currentItem7 = currentItem7->next;
			//App->audio->PlayFx(coinFx);
			btVector3 zero = {0,0,0};
			if (timer2 > 120) {
				App->player->vehicle->body->setLinearVelocity(zero);
				
				timer2 = 0;
			}
		


		}
		else {
			currentItem7 = currentItem7->next;
		}


	}

	p2List_item<Coin>* currentItem4 = coinPointList.getFirst();

	while (currentItem4 != NULL) {

		if (currentItem4->data.deleted == false) {
			currentItem4->data.timer++;
			currentItem4->data.cylinder.Render();
			btVector3 boosterPos = currentItem4->data.body->GetPos();

			btVector3 carPos = App->player->vehicle->GetPos();
			float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
			float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
			float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

			btVector3 speed = currentItem4->data.body->body->getAngularVelocity();
			speed.setY(10);

			currentItem4->data.body->body->setAngularVelocity(speed);

			currentItem4->data.cylinder.Update(currentItem4->data.body);

			if (currentItem4->data.timer < 48)
				currentItem4->data.body->body->setLinearVelocity(btVector3(0, 1, 0));
			else
				currentItem4->data.body->body->setLinearVelocity(btVector3(0, -1, 0));


			currentItem4->data.cylinder.SetPos(boosterPos.x(), boosterPos.y(), boosterPos.z());

			if (currentItem4->data.timer > 80) {
				currentItem4->data.timer = 0;
			}
			// Homebrew collision detection for sensors
			if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3)) {
				LOG("car touch coing");

				currentItem4->data.deleted = true;
				coin++;
				currentItem4 = currentItem4->next;
				//App->audio->PlayFx(coinFx);
				//coin++;


			}
			else {
				currentItem4 = currentItem4->next;
			}
		}
		else {
			currentItem4 = currentItem4->next;
		}
		


	}

	p2List_item<Checkpoint>* currentItem2 = checkpointPointList.getFirst();

	while (currentItem2 != NULL) {

		currentItem2->data.cube.Render();
		btVector3 checkpointPos = currentItem2->data.body->GetPos();
		btVector3 carPos = App->player->vehicle->GetPos();
		float Xdistance = abs(checkpointPos.x()) - abs(carPos.x());
		float Ydistance = abs(checkpointPos.y()) - abs(carPos.y());
		float Zdistance = abs(checkpointPos.z()) - abs(carPos.z());

		// Homebrew collision detection for sensors
		if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3)) {
			LOG("car touch coing");
			//currentItem->data->pendingToDelete = true;

			currentItem2 = currentItem2->next;
			//App->audio->PlayFx(coinFx);
			
			App->player->checkpoint = checkpointPos;
			

		}
		else {
			currentItem2 = currentItem2->next;
		}


	}


	p2List_item<GravityChange>* currentItem3 = gravityChangePointList.getFirst();

	while (currentItem3 != NULL ) {

		currentItem3->data.cube.Render();
		btVector3 checkpointPos = currentItem3->data.body->GetPos();
		btVector3 carPos = App->player->vehicle->GetPos();
		float Xdistance = abs(checkpointPos.x()) - abs(carPos.x());
		float Ydistance = abs(checkpointPos.y()) - abs(carPos.y());
		float Zdistance = abs(checkpointPos.z()) - abs(carPos.z());

		// Homebrew collision detection for sensors
		if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3)) {
			LOG("car touch coing");
			//currentItem->data->pendingToDelete = true;

			currentItem3 = currentItem3->next;
			//App->audio->PlayFx(coinFx);

			if (timerGrav > 180) {
				if (inverted == false)
				{
					VehicleInfo car;

					float half_width = 2 * 0.5f;
					float half_length = 4 * 0.5f;

					float connection_height = 1.2f;
					float wheel_radius = 0.6f;
					float wheel_width = 0.5f;
					float suspensionRestLength = 1.2f;

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
					btVector3 p = App->player->vehicle->GetPos();
					float acx = App->player->acceleration;
					App->player->vehicle->SetPos(1000, 10, -1000);

					App->player->change = true;
					// Don't change anything below this line ------------------



					vec3 direction(0, -1, 0);
					vec3 axis(-1, 0, 0);

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
					App->player->change = true;
					App->player->vehicle = App->physics->AddVehicle(car);
					App->player->vehicle->SetPos(p.x(), p.y(), p.z());
					App->physics->world->setGravity(-GRAVITY);
					acx = App->player->acceleration;
					inverted = true;
				}
				else {
				
					VehicleInfo car;

					float half_width = 2 * 0.5f;
					float half_length = 4 * 0.5f;

					float connection_height = 1.2f;
					float wheel_radius = 0.6f;
					float wheel_width = 0.5f;
					float suspensionRestLength = 1.2f;

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
					btVector3 p = App->player->vehicle->GetPos();
					float acx = App->player->acceleration;
					App->player->vehicle->SetPos(1000, 10, -1000);

					// Don't change anything below this line ------------------



					vec3 direction(0, -1, 0);
					vec3 axis(-1, 0, 0);

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
					App->player->change = true;
					App->player->vehicle = App->physics->AddVehicle(car);
					App->player->vehicle->SetPos(p.x(), p.y(), p.z());
					App->physics->world->setGravity(GRAVITY);
					acx = App->player->acceleration;
					inverted = false;
				}


				timerVehicleChange = 0;
				timerGrav = 0;
			}

			

		}
		else {
			currentItem3 = currentItem3->next;
		}


	}

	p2List_item<NormalVehicleChanger>* currentItem10 = NormalVehicleChangerPointList.getFirst();

	while (currentItem10 != NULL) {
	

		currentItem10->data.cube.Render();
		btVector3 boosterPos = currentItem10->data.body->GetPos();
		btVector3 carPos = App->player->vehicle->GetPos();
		float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
		float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
		float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

		// Homebrew collision detection for sensors
		if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3) && timerVehicleChange > 6) {
			LOG("car touch coing");
			//currentItem->data->pendingToDelete = true;

			currentItem10 = currentItem10->next;
			//App->audio->PlayFx(coinFx);
			normalVehicle = true;
			AutobusVehicle = false;
			monsterTruck = false;
			tricicle = false;
			VehicleInfo car;

			float half_width = 2 * 0.5f;
			float half_length = 4 * 0.5f;

			float connection_height = 1.2f;
			float wheel_radius = 0.6f;
			float wheel_width = 0.5f;
			float suspensionRestLength = 1.2f;

			// Car properties ----------------------------------------		//Lo del chasis Lo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasis		//Lo del chasis Lo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasis
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
			btVector3 p = App->player->vehicle->GetPos();
			float acx = App->player->acceleration;
			App->player->vehicle->SetPos(1000, 10, -1000);

			// Don't change anything below this line ------------------



			vec3 direction(0, -1, 0);
			vec3 axis(-1, 0, 0);

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
			App->player->change = true;
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

			App->player->vehicle = App->physics->AddVehicle(car);
			App->player->vehicle->SetPos(p.x(), p.y(), p.z());
			App->physics->world->setGravity(GRAVITY);
			acx = App->player->acceleration;
			inverted = false;
			timerVehicleChange = 0;

		}
		else {
			currentItem10 = currentItem10->next;
		}
	}

	p2List_item<TricicleVehicleChanger>* currentItem11 = TricicleVehicleChangerPointList.getFirst();

	while (currentItem11 != NULL) {


		currentItem11->data.cube.Render();
		btVector3 boosterPos = currentItem11->data.body->GetPos();
		btVector3 carPos = App->player->vehicle->GetPos();
		float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
		float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
		float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

		// Homebrew collision detection for sensors
		if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3) && timerVehicleChange > 6) {
			LOG("car touch coing");
			//currentItem->data->pendingToDelete = true;

			currentItem11 = currentItem11->next;
			//App->audio->PlayFx(coinFx);
			btVector3 p = App->player->vehicle->GetPos();

			normalVehicle = false;
			AutobusVehicle = false;
			monsterTruck = false;
			tricicle = true;

			App->player->vehicle->SetPos(1000, 10, -1000);
			VehicleInfo car;
			float half_width = 2 * 0.5f;
			float half_length = 4 * 0.5f;

			float connection_height = 1.2f;
			float wheel_radius = 0.6f;
			float wheel_width = 0.5f;
			float suspensionRestLength = 1.2f;

			vec3 direction(0, -1, 0);
			vec3 axis(-1, 0, 0);

			car.num_wheels = 3;
			car.wheels = new Wheel[3];

			car.chassis_size.Set(3.5, 1.8, 7);
			car.chassis_offset.Set(0, 2, 0);
			car.mass = 100.0f;
			car.suspensionStiffness = 15.88f;
			car.suspensionCompression = 0.83f;
			car.suspensionDamping = 10;
			car.maxSuspensionTravelCm = 1000.0f;
			car.frictionSlip = 50.5;
			car.maxSuspensionForce = 10000;

			car.wheels[0].connection.Set(0, connection_height, half_length - wheel_radius);
			car.wheels[0].direction = direction;
			car.wheels[0].axis = axis;
			car.wheels[0].suspensionRestLength = suspensionRestLength;
			car.wheels[0].radius = wheel_radius;
			car.wheels[0].width = wheel_width * 0.75;
			car.wheels[0].front = true;
			car.wheels[0].drive = true;
			car.wheels[0].brake = false;
			car.wheels[0].steering = true;

			// REAR-LEFT ------------------------
			car.wheels[1].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
			car.wheels[1].direction = direction;
			car.wheels[1].axis = axis;
			car.wheels[1].suspensionRestLength = suspensionRestLength;
			car.wheels[1].radius = wheel_radius;
			car.wheels[1].width = wheel_width;
			car.wheels[1].front = false;
			car.wheels[1].drive = true;
			car.wheels[1].brake = true;
			car.wheels[1].steering = false;
			App->player->change = true;
			// REAR-RIGHT ------------------------
			car.wheels[2].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
			car.wheels[2].direction = direction;
			car.wheels[2].axis = axis;
			car.wheels[2].suspensionRestLength = suspensionRestLength;
			car.wheels[2].radius = wheel_radius;
			car.wheels[2].width = wheel_width;
			car.wheels[2].front = false;
			car.wheels[2].drive = true;
			car.wheels[2].brake = true;
			car.wheels[2].steering = false;

			App->player->vehicle = App->physics->AddVehicle(car);
			App->player->vehicle->SetPos(p.x(), p.y(), p.z());
			App->physics->world->setGravity(GRAVITY);
		
			timerVehicleChange = 0;
		}
		else {
			currentItem11 = currentItem11->next;
		}
	}
	p2List_item<AutobusVehicleChanger>* currentItem12 = AutobusVehicleChangerPointList.getFirst();

	while (currentItem12 != NULL) {


		currentItem12->data.cube.Render();
		btVector3 boosterPos = currentItem12->data.body->GetPos();
		btVector3 carPos = App->player->vehicle->GetPos();
		float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
		float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
		float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

		// Homebrew collision detection for sensors
		if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3) && timerVehicleChange > 6) {
			LOG("car touch coing");
			//currentItem->data->pendingToDelete = true;

			currentItem12 = currentItem12->next;
			//App->audio->PlayFx(coinFx);
			btVector3 p = App->player->vehicle->GetPos();

			App->player->vehicle->SetPos(1000, 10, -1000);
			VehicleInfo car;
			
			normalVehicle = false;
			AutobusVehicle = true;
			monsterTruck = false;
			tricicle = false;

			//x el 2
			float half_width = 2 * 0.5f;
			//y el 4 la z
			float half_length = 18 * 0.5f;

			float connection_height = 1.2f;
			float wheel_radius = 0.6f;
			float wheel_width = 0.5f;
			float suspensionRestLength = 1.2f;
		

			//Lo del chasis Lo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasis		//Lo del chasis Lo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasis
			car.chassis_size.Set(2, 1, 4);
			car.chassis_offset.Set(0, 1, 0);
			car.mass = 500.0f;
			car.suspensionStiffness = 15.88f;
			car.suspensionCompression = 0.83f;
			car.suspensionDamping = 20;
			car.maxSuspensionTravelCm = 1000.0f;
			car.frictionSlip = 50.5;
			car.maxSuspensionForce = 2000.0f;
				
			car.num_wheels = 8;
			car.wheels = new Wheel[8];

			vec3 direction(0, -1, 0);
			vec3 axis(-1, 0, 0);

			App->player->change = true;
			// 1 right ------------------------
			car.wheels[0].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
			car.wheels[0].direction = direction;
			car.wheels[0].axis = axis;
			car.wheels[0].suspensionRestLength = suspensionRestLength;
			car.wheels[0].radius = wheel_radius;
			car.wheels[0].width = wheel_width;
			car.wheels[0].front = true;
			car.wheels[0].drive = true;
			car.wheels[0].brake = false;
			car.wheels[0].steering = true;

			// 1 left ------------------------
			car.wheels[1].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
			car.wheels[1].direction = direction;
			car.wheels[1].axis = axis;
			car.wheels[1].suspensionRestLength = suspensionRestLength;
			car.wheels[1].radius = wheel_radius;
			car.wheels[1].width = wheel_width;
			car.wheels[1].front = true;
			car.wheels[1].drive = true;
			car.wheels[1].brake = false;
			car.wheels[1].steering = true;

			// 2 right ------------------------
			car.wheels[2].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
			car.wheels[2].direction = direction;
			car.wheels[2].axis = axis;
			car.wheels[2].suspensionRestLength = suspensionRestLength;
			car.wheels[2].radius = wheel_radius;
			car.wheels[2].width = wheel_width;
			car.wheels[2].front = false;
			car.wheels[2].drive = false;
			car.wheels[2].brake = true;
			car.wheels[2].steering = false;

			// 2 left ------------------------
			car.wheels[3].connection.Set(half_width - 0.3f * wheel_width, connection_height, (-half_length + wheel_radius) / 2);
			car.wheels[3].direction = direction;
			car.wheels[3].axis = axis;
			car.wheels[3].suspensionRestLength = suspensionRestLength;
			car.wheels[3].radius = wheel_radius;
			car.wheels[3].width = wheel_width;
			car.wheels[3].front = false;
			car.wheels[3].drive = false;
			car.wheels[3].brake = true;
			car.wheels[3].steering = false;

			// 3 Right ------------------------
			car.wheels[4].connection.Set(-half_width + 0.3f * wheel_width, connection_height, (+half_length + wheel_radius) / 2);
			car.wheels[4].direction = direction;
			car.wheels[4].axis = axis;
			car.wheels[4].suspensionRestLength = suspensionRestLength;
			car.wheels[4].radius = wheel_radius;
			car.wheels[4].width = wheel_width;
			car.wheels[4].front = false;
			car.wheels[4].drive = false;
			car.wheels[4].brake = true;
			car.wheels[4].steering = false;

			// 3 left ------------------------
			car.wheels[5].connection.Set(half_width - 0.3f * wheel_width, connection_height, (+half_length + wheel_radius) / 2);
			car.wheels[5].direction = direction;
			car.wheels[5].axis = axis;
			car.wheels[5].suspensionRestLength = suspensionRestLength;
			car.wheels[5].radius = wheel_radius;
			car.wheels[5].width = wheel_width;
			car.wheels[5].front = false;
			car.wheels[5].drive = false;
			car.wheels[5].brake = true;
			car.wheels[5].steering = false;

			// 4 Right ------------------------
			car.wheels[6].connection.Set(-half_width + 0.3f * wheel_width, connection_height, (-half_length + wheel_radius) / 2);
			car.wheels[6].direction = direction;
			car.wheels[6].axis = axis;
			car.wheels[6].suspensionRestLength = suspensionRestLength;
			car.wheels[6].radius = wheel_radius;
			car.wheels[6].width = wheel_width;
			car.wheels[6].front = false;
			car.wheels[6].drive = false;
			car.wheels[6].brake = true;
			car.wheels[6].steering = false;

			// 4 left ------------------------
			car.wheels[7].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
			car.wheels[7].direction = direction;
			car.wheels[7].axis = axis;
			car.wheels[7].suspensionRestLength = suspensionRestLength;
			car.wheels[7].radius = wheel_radius;
			car.wheels[7].width = wheel_width;
			car.wheels[7].front = false;
			car.wheels[7].drive = false;
			car.wheels[7].brake = true;
			car.wheels[7].steering = false;

			App->player->vehicle = App->physics->AddVehicle(car);
			App->player->vehicle->SetPos(p.x(), p.y(), p.z());
			App->physics->world->setGravity(GRAVITY);
			timerVehicleChange = 0;
		}
		else {
			currentItem12 = currentItem12->next;
		}
	}
	p2List_item<HabiaOtroMasInterroganteVehicleChanger>* currentItem13 = HabiaOtroMasInterroganteVehicleChangerPointList.getFirst();

	while (currentItem13 != NULL) {


		currentItem13->data.cube.Render();
		btVector3 boosterPos = currentItem13->data.body->GetPos();
		btVector3 carPos = App->player->vehicle->GetPos();
		float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
		float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
		float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

		// Homebrew collision detection for sensors
		if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3) && timerVehicleChange > 6) {
			LOG("car touch coing");
			//currentItem->data->pendingToDelete = true;
			
			btVector3 p = App->player->vehicle->GetPos();

			App->player->vehicle->SetPos(1000, 10, -1000);
			currentItem13 = currentItem13->next;
			//App->audio->PlayFx(coinFx);

			float half_width = 2 * 0.5f;
			float half_length = 4 * 0.5f;

			float connection_height = 1.2f;
			float wheel_radius = 1.8f;
			float wheel_width = 1.5f;
			float suspensionRestLength = 1.2f;
			VehicleInfo car;

			// Car properties ----------------------------------------		//Lo del chasis Lo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasis		//Lo del chasis Lo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasis
			car.chassis_size.Set(3.5, 1.8, 7);
			car.chassis_offset.Set(0, 2, 0);
			car.mass = 100.0f;
			car.suspensionStiffness = 15.88f;
			car.suspensionCompression = 0.83f;
			car.suspensionDamping = 10;
			car.maxSuspensionTravelCm = 1000.0f;
			car.frictionSlip = 50.5;
			car.maxSuspensionForce = 10000;
			//Lo del chasis Lo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasisLo del chasis
			// Wheel properties ---------------------------------------


			// Don't change anything below this line ------------------
			normalVehicle = false;
			AutobusVehicle = false;
			monsterTruck = true;
			tricicle = false;


			vec3 direction(0, -1, 0);
			vec3 axis(-1, 0, 0);

			car.num_wheels = 4;
			car.wheels = new Wheel[4];

			// FRONT-LEFT ------------------------
			car.wheels[0].connection.Set(half_width * 2 - 0.3f * wheel_width, connection_height, half_length * 3 - wheel_radius);
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
			car.wheels[1].connection.Set(-half_width * 2 + 0.3f * wheel_width, connection_height, half_length * 3 - wheel_radius);
			car.wheels[1].direction = direction;
			car.wheels[1].axis = axis;
			car.wheels[1].suspensionRestLength = suspensionRestLength;
			car.wheels[1].radius = wheel_radius;
			car.wheels[1].width = wheel_width;
			car.wheels[1].front = true;
			car.wheels[1].drive = true;
			car.wheels[1].brake = false;
			car.wheels[1].steering = true;
			App->player->change = true;
			// REAR-LEFT ------------------------
			car.wheels[2].connection.Set(half_width * 2 - 0.3f * wheel_width, connection_height, -half_length * 3 + wheel_radius);
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
			car.wheels[3].connection.Set(-half_width * 2 + 0.3f * wheel_width, connection_height, -half_length * 3 + wheel_radius);
			car.wheels[3].direction = direction;
			car.wheels[3].axis = axis;
			car.wheels[3].suspensionRestLength = suspensionRestLength;
			car.wheels[3].radius = wheel_radius;
			car.wheels[3].width = wheel_width;
			car.wheels[3].front = false;
			car.wheels[3].drive = false;
			car.wheels[3].brake = true;
			car.wheels[3].steering = false;

			App->player->vehicle = App->physics->AddVehicle(car);
			App->player->vehicle->SetPos(p.x(), p.y(), p.z());
			App->physics->world->setGravity(GRAVITY);
			timerVehicleChange = 0;
		}
		else {
			currentItem13 = currentItem13->next;
		}
	}

	timerVehicleChange += dt * 1;

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

void ModuleSceneIntro::addCoin(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
{
	Cylinder cube;

	cube.SetPos(pos.x, pos.y, pos.z);
	cube.radius = 1;
	cube.height = 0.15f;
	cube.color = rgb;

	if (rot_X == true)
		cube.SetRotation(angle, { 1, 0, 0 });	// X-axis
	if (rot_Y == true)
		cube.SetRotation(angle, { 0, 1, 0 });	// Y-axis
	if (rot_Z == true)
		cube.SetRotation(angle, { 0, 0, 1 });	// Z-axis

	Coin booster;
	booster.body = App->physics->AddBody(cube, 1.0f);
	booster.body->SetAsSensor(true);
	booster.body->SetId(id);
	booster.cylinder = cube;
	booster.passed = passed_;
	coinPointList.add(booster);


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

void ModuleSceneIntro::addGravityChanger(vec3 pos, vec3 size, Color rgb, int id, bool passed_)
{
	Cube cube;

	cube.SetPos(pos.x, pos.y, pos.z);
	cube.size = size;
	cube.color = rgb;

	
		cube.SetRotation(0, { 1, 0, 0 });	// X-axis
	
		cube.SetRotation(0, { 0, 1, 0 });	// Y-axis
	
		cube.SetRotation(0, { 0, 0, 1 });	// Z-axis

	GravityChange gravityChang;
	gravityChang.body = App->physics->AddBody(cube, 0.0f);

	gravityChang.body->SetAsSensor(true);
	gravityChang.body->SetId(id);
	
	gravityChang.id2 = id;
	gravityChang.cube = cube;
	gravityChang.passed = passed_;
	gravityChangePointList.add(gravityChang);


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

	Booster booster;
	booster.body = App->physics->AddBody(cube, 0.0f);
	
	booster.body->SetAsSensor(true);
	booster.body->SetId(id);
	booster.cube = cube;
	booster.passed = passed_;
	boosterPointList.add(booster);

	
}

void ModuleSceneIntro::addMud(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
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

	Mud mud;
	mud.body = App->physics->AddBody(cube, 0.0f);

	mud.body->SetAsSensor(true);
	mud.body->SetId(id);
	mud.cube = cube;
	mud.passed = passed_;
	mudPointList.add(mud);


}

void ModuleSceneIntro::addIce(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
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

	Ice booster;
	booster.body = App->physics->AddBody(cube, 0.0f);

	booster.body->SetAsSensor(false);
	booster.body->SetId(id);
	booster.cube = cube;
	booster.passed = passed_;
	icePointList.add(booster);


}

void ModuleSceneIntro::addBoosterUp(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
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

	BoosterUp booster;
	booster.body = App->physics->AddBody(cube, 0.0f);

	booster.body->SetAsSensor(true);
	booster.body->SetId(id);
	booster.cube = cube;
	booster.passed = passed_;
	boosterUpPointList.add(booster);


}

void ModuleSceneIntro::addBrake(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
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

	Brake brake;
	brake.body = App->physics->AddBody(cube, 0.0f);

	brake.body->SetAsSensor(true);
	brake.body->SetId(id);
	brake.cube = cube;
	brake.passed = passed_;
	brakePointList.add(brake);


}

void ModuleSceneIntro::addCheckpoint(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
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

	Checkpoint checkpoint;
	checkpoint.body = App->physics->AddBody(cube, 0.0f);

	checkpoint.body->SetAsSensor(true);
	checkpoint.body->SetId(id);
	checkpoint.cube = cube;
	checkpoint.passed = passed_;
	checkpointPointList.add(checkpoint);


}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{



}

void ModuleSceneIntro::addNormalVehicleChanger(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
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

	NormalVehicleChanger booster;
	booster.body = App->physics->AddBody(cube, 0.0f);

	booster.body->SetAsSensor(true);
	booster.body->SetId(id);
	booster.cube = cube;
	booster.passed = passed_;
	NormalVehicleChangerPointList.add(booster);


}
void ModuleSceneIntro::addTricicleVehicleChanger(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
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

	TricicleVehicleChanger booster;
	booster.body = App->physics->AddBody(cube, 0.0f);

	booster.body->SetAsSensor(true);
	booster.body->SetId(id);
	booster.cube = cube;
	booster.passed = passed_;
	TricicleVehicleChangerPointList.add(booster);


}
void ModuleSceneIntro::addAutobusVehicleChanger(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
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

	AutobusVehicleChanger booster;
	booster.body = App->physics->AddBody(cube, 0.0f);

	booster.body->SetAsSensor(true);
	booster.body->SetId(id);
	booster.cube = cube;
	booster.passed = passed_;
	AutobusVehicleChangerPointList.add(booster);


}
void ModuleSceneIntro::addHabiaOtroMasInterroganteVehicleChanger(vec3 pos, vec3 size, Color rgb, int angle, bool rot_X, bool rot_Y, bool rot_Z, int id, bool passed_)
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

	HabiaOtroMasInterroganteVehicleChanger booster;
	booster.body = App->physics->AddBody(cube, 0.0f);

	booster.body->SetAsSensor(true);
	booster.body->SetId(id);
	booster.cube = cube;
	booster.passed = passed_;
	HabiaOtroMasInterroganteVehicleChangerPointList.add(booster);


}