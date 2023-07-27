#pragma once
#include "SpriteComponent.h"
#include <vector>

class AnimSpriteComponent : public SpriteComponent
{
public:
	AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
	void Update(float deltaTime) override;
	void SetAnimTextures(const std::vector<SDL_Texture*>& textures);
	float GetAnimFPS() const { return mAnimFPS; }
	void SetAnimFPS(float fps) { mAnimFPS = fps; }

	void SetAnimStart(int idx) { mAnimStart = idx; }
	void SetAnimEnd(int idx) { mAnimEnd = idx; }
	void SetAnimLoopFlag(bool flag) { mAnimLoopFlag = flag; }

private:
	std::vector<SDL_Texture*> mAnimTextures;
	float mCurrFrame;
	float mAnimFPS;

	int mAnimStart;
	int mAnimEnd;
	bool mAnimLoopFlag;
};