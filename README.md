## PHYSICS II - Project - RaceCar ##

By Daniel Berrio, Pau Mora, Ivo Montes and Sergi Gantzer


Game Description:
We did a different approach to the RaceCar Project developed with SDL and Bullet3D.
You start off with the standard car in the green zone, where you will have to destroy the obstacles with your obstacle-destructor.
After a couple meters you'll reach the first ramps (note: get coins to get a higher score), you'll then approach your first wall-ride, 
shortly after you'll have the opportunity to change into a bus (grabbing the orange cube). After a short ramp, you'll enter the swamp.
Dodge the mud puddles to avoid losing speed. The second wall ride approaches, leading to the ice zone, where you'll have to opportunity to
change into a monster truck. Ice is slippery, watch out! Once you exit the ice zone, you'll have the opportunity to change into a tricycle,
approaching the second wall-ride, you'll enter the first inverted zone in the map, gravity is changed and you'll be racing through the ceiling.
After that you'll be in the final stretch of the race, do a last wall-ride to reach the end.

Notes: 
 - grab yellow cubes to track progress (checkpoints)
 - behind the starting line, there's different cubes so you can start as your favourite vehicle!
 - watch out when spawning! Sometimes you'll do so in the opposite direction, check for arrows and indications!
 - complete the track as fast as you can, time and coins can be tracked in the top bar of your game.
 - you'll need at least one coin to win the game!
 
We implemented different features, including:

 - constraint (obstacle destructor)
 - gravity changes (inverted racing)
 - different surfaces (ice and mud)
 - wallrides
 - boosters (horizontally and vertically)
 - jumps
 - obstacles
 - coins
 - car changers (bus, monster truck, tricycle and standard car) 
 - challenging track 

Game Controls:
 - Left and Right arrows: steer
 - Up arrow: thrust
 - Down arrow: reverse
 - Spacebar: brake
 - F: reset car position
 - R: go to the last checkpoint (yellow cube)
 - L: unlock camera (WASD, QE and right click to control camera)

Debug features:
 - F1: Show hitboxes
 - F2: Deactivate physic forces
 - F3: Activate physic forces
 - F4 (with phyisic forces deactivated): Lower Gravity
 - F5 (with phyisic forces deactivated): Higher Gravity
 - F6 (with phyisic forces deactivated): Lower vehicle mass
 - F7 (with phyisic forces deactivated): Higher vehicle mass
