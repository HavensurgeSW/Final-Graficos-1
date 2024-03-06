#include "Game.h"
#include <iostream>
#include <time.h>

namespace Engine
{
	Game::Game(): GameBase()
	{
		_dude = NULL;
		_tileMap = NULL;
	}

	Game::~Game()
	{
		if (_dude != NULL)
			delete _dude;
		
		if (_tileMap != NULL)
			delete _tileMap;
	}

	void Game::Start()
	{
		StartEngine(1280, 720, "FL4K");
		srand(time(NULL));

		SetCamera(CameraType::Perspective, 0.1f, 100.0f);
		SetCameraPosition(0, 0, 15);

		// --------------------------------
	
		cout << "Loading _dude" << endl;

		_dude = new Player(GetRenderer(), 2);
		_dude->ImportTexture("res/dude.png");

		_dude->SetTag("player");

		_dude->AddAnimation("walk_right", ivec2(6, 6), 0.5f, 14, 15);
		_dude->AddAnimation("walk_up", ivec2(6, 6), 0.5f, 34, 35);
		_dude->AddAnimation("walk_left", ivec2(6, 6), 0.5f, 12, 13);
		_dude->AddAnimation("walk_down", ivec2(6, 6), 0.5f, 32, 33);
		_dude->AddAnimation("idle", ivec2(6, 6), 1, 33, 33);

		_dude->SetPosition(-1.8, 0, 0);
		
	

		
		// --------------------------------
		

		const char* path = "res/castle-tileset.png";
		vec3 startPosition = vec3(-2, -3, 0);
		vec2 tileScale = vec2(1.1, 1.1);

		_tileMap = new TileMap(GetRenderer());
		_tileMap->InitTileMap(startPosition, path, ivec2(8,4), dungeon, tileScale);

		
	}
	
	void Game::Play()
	{
		UpdateEngine(0.0f, 0.0f, 0.0f, 1);
	}

	void Game::Update(float deltaTime)
	{
		_tileMap->DrawTileMap();

		_dude->Move(deltaTime);
	

		_tileMap->CheckTileCollisions(_dude);
		//GetCollisionManager()->CheckAllCollisions();
	}

	void Game::End()
	{
		EndEngine();
	}
}