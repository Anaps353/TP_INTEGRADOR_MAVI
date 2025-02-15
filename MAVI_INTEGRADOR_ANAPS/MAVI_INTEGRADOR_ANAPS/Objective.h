#pragma once
#include "stdafx.h"
#include "Data.h"
#include "Common.h"

class Objective {

	Texture _objectiveTexture;
	Sprite _objectiveSprite;
	Vector2i _position;
	int _positionNumber;
	bool _isInnocent;
	bool _isActive;

public:
	Objective();
	Objective(int position);
	void Initilize();
	void Update();
	void Draw(RenderWindow* window);
	void SetSprite();

	bool CheckCollision(Vector2i position);

	bool IsInnocent();
	void SetAsNoInnocent();
	void SetAsInnocent();

	bool IsActive();
	void SetActive();
	void SetInactive();

};

