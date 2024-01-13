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

	//SALIDA
	addCube({ 10, -0.5f, 300 }, { 30, 2, 500 }, Grey, 0, 0, 0);
	addCube({ 100, -0.5f, 580 }, { 200, 2, 30 }, Grey, 0, -30, 0);
	addCube({ 279, -0.5f, 628 }, { 200, 2, 30 }, Grey, 0, 0, 0);
	addCube({ 190, -0.5f, 636 }, { 50, 2, 10 }, Grey, 0, 0, 10);	//rampa
	addCube({ 185, -0.5f, 636 }, { 50, 2, 10 }, Grey, 0, 0, 3);		//rampa
	addCube({ 360, -0.5f, 618 }, { 50, 2, 10 }, Grey, 0, 0, 10);//rampa
	addCube({ 355, -0.5f, 618 }, { 50, 2, 10 }, Grey, 0, 0, 3);	//rampa
	addCoin({ 355, 3, 618 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ 190, 3, 636 }, { 5, 5, 5 }, Yellow, 0, 0, 30);

	//ZONA ANTES DEL WALLRIDE
	addCube({ 475, -0.5f, 611 }, { 200, 2, 40 }, Grey, 0, 10, 0);
	addCube({ 613, -0.5f, 610 }, { 100, 2, 30 }, Grey, 0, -20, 0);
	addCoin({ 613, 3, 610 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ 694, -0.5f, 657 }, { 100, 2, 30 }, Grey, 0, -40, 0);
	addCube({ 754, -0.5f, 728 }, { 100, 2, 30 }, Grey, 0, -60, 0);
	addCheckpoint({ 786, 2, 816 }, { 2, 2, 2 }, Yellow, 0, 0, 0);
	addCube({ 786, -0.5f, 816 }, { 100, 2, 30 }, Grey, 0, -80, 0);
	addCoin({ 816, 7, 900 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ 807, -0.5f, 900 }, { 30, 2, 100 }, Grey, 0, 0, 30);	//Wallride
	addCube({ 817, 4, 1000 }, { 30, 2, 100 }, Grey, 0, 0, 60);		//Wallride
	addCube({ 800, 4, 1110 }, { 30, 2, 100 }, Grey, 0, -10, 0);
	addCube({ 819, 4, 1085 }, { 2, 30, 30 }, Grey, 0, -15, 0);


	//CURVA DE IVO
	addCube({ 1.7f + 782, 4, 195 + 1009 }, { 30, 2, 100 }, Grey, 0, -10, 0);
	addCoin({ 1.7f + 782, 7, 195 + 1009 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -24 + 782,  4, 288 + 1009 }, { 30, 2, 100 }, Grey, 0, -20, 0);
	addCube({ -64.8 + 782,4, 375 + 1009 }, { 30, 2, 100 }, Grey, 0, -30, 0);
	addCube({ -120 + 782, 4, 453 + 1009 }, { 30, 2, 100 }, Grey, 0, -40, 0);
	addCoin({ -120 + 782, 7, 453 + 1009 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -188 + 782, 4, 520 + 1009 }, { 30, 2, 100 }, Grey, 0, -50, 0);
	addCube({ -262 + 782, 4, 570 + 1009 }, { 30, 2, 100 }, Grey, 0, -60, 0);
	addCube({ -350 + 782, 4, 610 + 1009 }, { 30, 2, 100 }, Grey, 0, -70, 0);
	addCoin({ -350 + 782, 7, 610 + 1009 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -443 + 782, 4, 635 + 1009 }, { 30, 2, 100 }, Grey, 0, -80, 0);
	addCube({ -539 + 782, 4, 643 + 1009 }, { 30, 2, 100 }, Grey, 0, -90, 0);

	//ZONA DEL BARRO
	addCube({ 244,	13, 1652 }, { 100, 2, 30 }, Grey, 0, 0, -10);
	addCube({ 149,	38, 1652 }, { 100, 2, 30 }, Grey, 0, 0, -20);
	addCube({ -148,	55, 1652 }, { 500, 2, 120 }, Grey, 0, 0, 0);
	//barros	
	addMud({ 78,		56, 1652 -35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ 78 -50,	56, 1652 - 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ 78 - 100,	56, 1652 + 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ 78 - 150,	56, 1652 + 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ 78 - 125,	56, 1652 +10 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -118 - 100,56, 1652 + 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -118 - 150,56, 1652 + 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -118 - 125,56, 1652 + 10 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -78 - 40,	56, 1652 - 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -78 - 90,	56, 1652 - 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -78 - 240,	56, 1652 - 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -78 - 290,	56, 1652 - 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addMud({ -78 - 300,	56, 1652 + 35 }, { 50, 2, 50 }, Brown, 0, 0, 0);
	addCube({ 58,	150, 1652 }, { 2, 150, 120 }, Grey, 0, 0, 0);
	//monedas
	addCoin({ -148 + 180, 58, 1652 + 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 + 140, 58, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 + 100, 58, 1652 - 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 + 50, 58, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 , 58, 1652 + 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 50 , 58, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 100 , 58, 1652 - 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 140 , 58, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 180 , 58, 1652 + 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 220 , 58, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -148 - 300 , 58, 1652 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	//out of barro
	addCube({ -448,	55, 1652 }, { 100, 2, 30 }, Grey, 0, 0, 0);
	addCube({ -534,	55, 1629 }, { 100, 2, 30 }, Grey, 0, -30, 0);
	addCube({ -597,	55, 1566 }, { 100, 2, 30 }, Grey, 0, -60, 0);
	addCube({ -627 ,55, 1486 }, { 30, 2, 100 }, Grey, 0, 0, -40); //Wallride
	addCube({ -653 ,79, 1486 }, { 30, 2, 100 }, Grey, 0, 0, -60); //Wallride
	addCube({ -653,	45, 1300 }, { 30, 2, 300 }, Grey, -10, 0, 0);
	addCoin({ -653,	48, 1300 }, { 5, 5, 5 }, Yellow, 0, 0, 30);


	//HIELO 1 + SETA 1
	addCube({ -653,	19, 1010 }, { 30, 2, 300 }, Grey, 0, 0, 0);
	addCoin({ -653,	22, 1050 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addBoosterUp({ -653, 19, 1010 }, { 5, 5, 5 }, Orange, 0, 0, 0);
	addCube({ -653,	19, 710 }, { 120, 20, 500 }, Grey, 0, 0, 0);
	addCoin({ -653,	32, 800 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 +50,	32, 800 -40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 ,32, 800 - 80 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 -50,32, 800 - 120 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 ,32, 800 - 160 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 + 50,32, 800 - 200 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,32, 800 - 240 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 - 50,32, 800 - 280 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,32, 800 - 320 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -653,	69, 810 }, { 120, 2, 500 }, Grey, 0, 0, 0);

	//SETA 2
	addCube({ -653,	19, 430 }, { 30, 20, 60 }, Grey, 0, 0, 0);
	addCoin({ -653,	32, 480 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addBoosterUp({ -653, 29, 460 }, { 5, 5, 5 }, Orange, 0, 0, 0);


	//HIELO 2 + TUNEL
	addCube({ -653,	39, 150 }, { 120, 20, 500 }, Grey, 0, 0, 0);
	addCoin({ -653,	32, 800 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 + 50,50, 250 - 40 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,		50, 250 - 80 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 - 50,50, 250 - 120 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,		50, 250 - 160 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 + 50,50, 250 - 200 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,		50, 250 - 240 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653 - 50,50, 250 - 280 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCoin({ -653,		50, 250 - 320 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -653,	89, 250 }, { 120, 2, 500 }, Grey, 0, 0, 0);
	addCube({ -653,	10, -133 }, { 30, 2, 100 }, Grey, -50, 0, 0);
	addCube({ -653 - 15,	25, -143 }, { 2, 60, 70 }, Blue, 0, 0, 0);
	addCube({ -653 + 15,25, -143 }, { 2, 60, 70 }, Blue, 0, 0, 0);
	addCube({ -653,	45, -123 }, { 30, 2, 30 }, Grey, -40, 0, 0);
	addCube({ -653,8, -143 }, { 30, 2, 100 }, Grey, -30, 0, 0);
	addCube({ -653,	5, -153 }, { 30, 2, 100 }, Grey, -10, 0, 0);
	addCube({ -653,	-0.5f, -203 }, { 30, 2, 100 }, Grey, 0, 0, 0);
	addCube({ -653,	-0.5f, -368 }, { 30, 2, 230 }, Grey, 0, 0, 0);

	//WALLRIDE
	addCube({ -647 - 15,-0.5f, -353 }, { 50, 2, 300 }, Grey, 0, 0, -20);
	addCoin({ -652,	10, -353 }, { 5, 5, 5 }, Yellow, 0, 0, 30);
	addCube({ -647 - 25,-0.5f, -353 }, { 50, 2, 300 }, Grey, 0, 0, -40);
	addCube({ -647 - 63,-0.5f, -353 }, { 50, 50, 300 }, Grey, 0, 0, 0);
	addCube({ -647 - 35,-0.5f, -483 }, { 2, 50, 50 }, Grey, 0, -10, 0);
	addCube({ -647 - 30,-0.5f, -493 }, { 2, 50, 50 }, Grey, 0, -20, 0);
	addCube({ -647 - 25,-0.5f, -503 }, { 2, 50, 50 }, Grey, 0, -40, 0);
	addCube({ -647 - 20,-0.5f, -513 }, { 2, 50, 50 }, Grey, 0, -60, 0);
	addCube({ -647 - 10,-0.5f, -523 }, { 2, 50, 50 }, Grey, 0, -80, 0);
	addCube({ -640 ,-0.5f, -551 }, { 400, 50, 50 }, Grey, 0, 0, 0);
	addCube({ -587 ,-0.5f, -513 }, { 200, 2, 50 }, Grey, 50, 0, 0);
	addCube({ -493,	-0.5f, -498 }, { 400, 2, 30 }, Grey, 0, 0, 0);

	//ZONA BOCARRIBA
	addCube({ -393,	20, -408 }, { 60, 2, 300 }, Grey, 0, 0, 0);
	addCube({ -363,	20, -498 }, { 2, 50, 30 }, Grey, 0, 0, 0);
	addGravityChanger({ -410 ,1, -490 }, { 2, 2, 2 }, Blue, 0);  
	addGravityChanger({ -410 ,1, -496 }, { 2, 2, 2 }, Blue,  0); 
	addGravityChanger({ -410 ,1, -502 }, { 2, 2, 2 }, Blue, 0);  
	addGravityChanger({ -410 ,1, -508 }, { 2, 2, 2 }, Blue, 0);  
	addGravityChanger({ -410, 18, -298 }, { 2, 2, 2 }, Blue,1);  
																

	addCube({ -393,	-0.5f, -275 }, { 50, 2, 75 }, Grey, 0, 0, 0);
	addCube({ -258 - 75,	-0.5f, -475 + 250 }, { 100, 2, 30 }, Grey, 0, -30, 0);
	addCube({ -196 - 75,	-0.5f, -412 + 250 }, { 100, 2, 30 }, Grey, 0, -60, 0);
	addCube({ -173 - 75,	-0.5f, -327 + 250 }, { 100, 2, 30 }, Grey, 0, -90, 0);
	addCube({ -173 - 65,-0.5f, -15 }, { 50, 2, 30 }, Grey, 0, -60, 0);
	addCube({ -173 - 36,-0.5f, 12 }, { 50, 2, 30 }, Grey, 0, -30, 0);

	//ULTIMA CURVA
	addCube({ -50 ,-0.5f, 10 }, { 300, 2, 30 }, Grey, 30, 0, 0);
	addCube({ -50 ,-0.5f, -18 }, { 200, 50, 30 }, Grey, 0, 0, 0);
	addCube({ 24 ,-0.5f,38 - 12 }, { 2, 50, 100 }, Grey, 0, 20, 0);
	addCube({ 24 ,-0.5f,34 - 12 }, { 2, 50, 100 }, Grey, 0, 30, 0);
	addCube({ 24 ,-0.5f,30 - 12 }, { 2, 50, 100 }, Grey, 0, 40, 0);
	addCube({ 24 ,-0.5f,26 - 12 }, { 2, 50, 100 }, Grey, 0, 50, 0);
	addCube({ 24 ,-0.5f,22 - 12 }, { 2, 50, 100 }, Grey, 0, 60, 0);
	addCube({ 24 ,-0.5f,18 - 12 }, { 2, 50, 100 }, Grey, 0, 70, 0);
	addCube({ 24 ,-0.5f,14 - 12 }, { 2, 50, 100 }, Grey, 0, 80, 0);
	addCube({ 24 ,-0.5f,10 - 14 }, { 2, 50, 100 }, Grey, 0, 90, 0);
	addCube({ 20 ,-5, 50 }, { 2, 75, 100 }, Grey, 0, 0, -30);



	
	
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
	/*p2List_item<Booster>* d = boosterPointList.getFirst();
	while (d != NULL) {
		d->data.cube.Render();
		d = d->next;
	}*/
	p2List_item<Booster>* currentItem = boosterPointList.getFirst();

	while (currentItem != NULL) {
		
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
				App->player->vehicle->body->setLinearVelocity(App->player->vehicle->body->getLinearVelocity()*1.5);
				
			
			}
			else {
				currentItem = currentItem->next;
			}
		
		
	}

	p2List_item<Mud>* currentItem8 = mudPointList.getFirst();

	while (currentItem8 != NULL) {
		timer3++;
			currentItem8->data.cube.Render();
		btVector3 boosterPos = currentItem8->data.body->GetPos();
		btVector3 carPos = App->player->vehicle->GetPos();
		float Xdistance = abs(boosterPos.x()) - abs(carPos.x());
		float Ydistance = abs(boosterPos.y()) - abs(carPos.y());
		float Zdistance = abs(boosterPos.z()) - abs(carPos.z());

		// Homebrew collision detection for sensors
		if ((Xdistance > -3 && Xdistance < 3) && (Ydistance > -3 && Ydistance < 3) && (Zdistance > -3 && Zdistance < 3)) {
			LOG("car touch coing");
			//currentItem->data->pendingToDelete = true;
			//patata

			currentItem8 = currentItem8->next;
			//App->audio->PlayFx(coinFx);
			if (timer3 > 300) 
			{
				timer3 = 0;
				App->player->vehicle->body->setLinearVelocity(App->player->vehicle->body->getLinearVelocity() / 2);
			}
			


		}
		else {
			currentItem8 = currentItem8->next;
		}


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

					App->player->vehicle = App->physics->AddVehicle(car);
					App->player->vehicle->SetPos(p.x(), p.y(), p.z());
					App->physics->world->setGravity(GRAVITY);
					acx = App->player->acceleration;
					inverted = false;
				}



				timerGrav = 0;
			}

			

		}
		else {
			currentItem3 = currentItem3->next;
		}


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

