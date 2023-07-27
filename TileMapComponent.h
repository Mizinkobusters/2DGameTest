#pragma once
#include "SpriteComponent.h"
#include "Math.h"
#include <vector>

class TileMapComponent : public SpriteComponent
{
public:
	TileMapComponent(class Actor* owner, int drawOrder = 10);
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	void SetTexture(SDL_Texture* texture) { mTexture = texture; }
	void SetScreenSize(const Vector2& size) { mScreenSize = size; }
	void SetChipSize(const Vector2& size) { mChipSize = size; }
	void SetChipNumX(const int numX) { mChipNumX = numX; }
	void SetChipNumY(const int numY) { mChipNumX = numY; }

	void SetMapChips(std::vector<std::vector<int> > mapChips) { mMapChips = mapChips; }

private:
	std::vector<std::vector<int> > mMapChips;
	SDL_Texture* mTexture;

	Vector2 mScreenSize;
	Vector2 mChipSize;	// �}�b�v�`�b�v�̑傫��(pixel)
	int mChipNumX;		// ��ʏ�E���ɕ��ԃ^�C���}�b�v�̐�
	int mChipNumY;		// ��ʏ�E�c�ɕ��ԃ^�C���}�b�v�̐�
};