#ifndef GAME_H
#define GAME_H

#include "GameBase/GameBase.h"
#include "../Objects/Player.h"
#include "../Objects/Coin.h"

namespace Engine
{
	class Game : public GameBase
	{
	private:
		

		Player* _dude;
		TileMap* _tileMap;

		//Lee tiles Izq-Der, Abajo-Arriba

		const int brickWall = 8;
		const int brickFloor = 2;
		const int chestL = 6;
		const int chestR = 7;


		vector<vector<TileModule>> dungeon
		{
			{{brickFloor, false}, { brickFloor, false}, { brickFloor, false}, { brickFloor, false}, { brickFloor, false}, { brickFloor, false}, { brickFloor, false}, { brickFloor, false}},
			{{brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickWall, true},       {brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickFloor, false}},
			{{brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickFloor, false},      {brickFloor, false}},
			{{brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickWall, true}, {brickWall, true},      {brickWall, true}},
			{{brickFloor, false}, {chestL, true}, {chestR, true}, {brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickFloor, false}, {brickFloor, false}},
			
		};

	public:
		Game();
		~Game();

		void Start();
		void Play();
		void Update(float deltaTime) override;
		void End();
	};
}

#endif;