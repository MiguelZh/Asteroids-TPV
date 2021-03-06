#pragma once

namespace msg {

enum ObjectId {
	None,  	// special value indicating no object (or more precisely component)
	Broadcast,   // special value indicating all objects
	Ball,
	Fighter,
	Asteroids,
	BulletsShooter,
	FighterGun,
	Bullets,
	GameManager,
	BlackHoles
};

enum MessageType {
	GAME_START,
	GAME_OVER,
	ROUND_START,
	ROUND_OVER,
	FIGHTER_SHOOT,
	BULLET_ASTEROID_COLLISION,
	ASTEROID_BLACKHOLE_COLLISION,
	FIGHTER_ASTEROID_COLLISION,
	BULLET_BLACKHOLE_COLLISION,
	FIGHTER_BLACKHOLE_COLLISION,
	ASTEROID_DESTROYED,
	NO_MORE_FIGHTER_LIVES,
	NO_MORE_ASTEROIDS,
	FIGHTER_INFO,
	BULLETS_INFO,
	ASTEROIDS_INFO,
	BLACKHOLE_INFO
};

struct Message;

};
