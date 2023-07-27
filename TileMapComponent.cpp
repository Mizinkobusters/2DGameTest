#include "TileMapComponent.h"
#include "Actor.h"
#include "CSVConverter.h"

TileMapComponent::TileMapComponent(class Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	,mScreenSize(Vector2(1024.0f, 768.0f))
	,mChipSize(Vector2(32.0f, 32.0f))
	,mChipNumX(32)
	,mChipNumY(24)
{

}

void TileMapComponent::Update(float deltaTime)
{
	// nothing
}

void TileMapComponent::Draw(SDL_Renderer* renderer)
{
	SDL_Rect s;
	SDL_Rect r;

	for (int i = 0; i < mChipNumY; i++)
	{
		for (int j = 0; j < mChipNumX; j++)
		{
			int chipNum = mMapChips[i][j];

			if (chipNum == -1)
			{
				continue;
			}

			s.x = chipNum % 8 * mChipSize.x;
			s.y = chipNum / 8 * mChipSize.y;
			s.w = mChipSize.x;
			s.h = mChipSize.y;

			r.x = j * mChipSize.x;
			r.y = i * mChipSize.y;
			r.w = mChipSize.x;
			r.h = mChipSize.y;

			SDL_RenderCopyEx(renderer,
				mTexture,
				&s,
				&r,
				0,
				nullptr,
				SDL_FLIP_NONE);
		}
	}
}