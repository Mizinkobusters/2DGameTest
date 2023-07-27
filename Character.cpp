#include "Character.h"
#include "AnimSpriteComponent.h"
#include "Game.h"
#include "Math.h"

Character::Character(Game* game)
	:Actor(game)
	, mRightSpeed(0.0f)
	, mDownSpeed(0.0f)
{
	asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims =
	{
		game->GetTexture("Assets/Character01.png"),
		game->GetTexture("Assets/Character02.png"),
		game->GetTexture("Assets/Character03.png"),
		game->GetTexture("Assets/Character04.png"),
		game->GetTexture("Assets/Character05.png"),
		game->GetTexture("Assets/Character06.png"),
		game->GetTexture("Assets/Character07.png"),
		game->GetTexture("Assets/Character08.png"),
		game->GetTexture("Assets/Character09.png"),
		game->GetTexture("Assets/Character10.png"),
		game->GetTexture("Assets/Character11.png"),
		game->GetTexture("Assets/Character12.png"),
		game->GetTexture("Assets/Character13.png"),
		game->GetTexture("Assets/Character14.png"),
		game->GetTexture("Assets/Character15.png"),
		game->GetTexture("Assets/Character16.png"),
		game->GetTexture("Assets/Character17.png"),
		game->GetTexture("Assets/Character18.png"),
	};

	asc->SetAnimStart(0);
	asc->SetAnimEnd(5);
	asc->SetAnimTextures(anims);
}

void Character::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;

	if (pos.x < 40.0f)
	{
		pos.x = 40.0f;
	}
	else if (pos.x > 1035.0f)
	{
		pos.x = 1035.0f;
	}
	if (pos.y < 40.0f)
	{
		pos.y = 40.0f;
	}
	else if (pos.y > 700.0f)
	{
		pos.y = 700.0f;
	}
	SetPosition(pos);
}

void Character::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;

	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
		asc->SetAnimStart(0);
		asc->SetAnimEnd(5);
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
		asc->SetAnimStart(0);
		asc->SetAnimEnd(5);
	}
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 300.0f;
		asc->SetAnimStart(15);
		asc->SetAnimEnd(17);
	}
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 300.0f;
		asc->SetAnimStart(6);
		asc->SetAnimEnd(15);
	}
}