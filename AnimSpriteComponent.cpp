#include "AnimSpriteComponent.h"
#include "Math.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	,mCurrFrame(0.0f)
	,mAnimFPS(12.0f)
	,mAnimStart(0)
	,mAnimEnd(-1)
	,mAnimLoopFlag(true)
{

}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	if (mAnimTextures.size() > 0)
	{
		mCurrFrame += mAnimFPS * deltaTime;

		// �A�j���[�V�����̍Ō�̗v�f�ԍ������̏ꍇ�A�Ō�̗v�f�ԍ��ɂ���
		if (mAnimEnd < 0)
		{
			mAnimEnd = static_cast<int>(mAnimTextures.size()) - 1;
		}

		if (mAnimLoopFlag) 
		{
			int range = mAnimEnd - mAnimStart + 1;
			while (mCurrFrame >= range)
			{
				mCurrFrame -= range;
			}
		}
		else
		{
			if (mCurrFrame >= mAnimEnd - (mAnimStart - 1))
			{
				mCurrFrame = mAnimEnd - mAnimStart;
			}
		}

		int idx = static_cast<int>(mCurrFrame) + mAnimStart;
		SetTexture(mAnimTextures[idx]);
	}
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures)
{
	mAnimTextures = textures;
	if (mAnimTextures.size() > 0)
	{
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}