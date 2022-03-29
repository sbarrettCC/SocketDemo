#include "Unit.h"
#include "Game.h"
#include <System.h>
#include <GraphicsSystem.h>
#include <Animation.h>

Unit::Unit(const Vector2D& position, const Animation& mainAnimation, const Animation& altAnimation)
	:mPos(position)
	,mMainAnimation(mainAnimation)
	,mAltAnimation(altAnimation)
	,mpCurrentAnimation(NULL)
{
	mpCurrentAnimation = &mMainAnimation;
}

void Unit::update(double dt)
{
	mpCurrentAnimation->update(dt);
}

void Unit::draw()
{
	const Sprite& currSprite = mpCurrentAnimation->getCurrentSprite();
	Vector2D offset = currSprite.getCenterOffset();
	Vector2D centerPos = mPos - offset;

	Game::getInstance()->getSystem()->getGraphicsSystem()->draw(centerPos, currSprite);
}

void Unit::toggleAnimation()
{
	Animation* pOldAnimation = mpCurrentAnimation;
	if (mpCurrentAnimation == &mMainAnimation)
	{
		mpCurrentAnimation = &mAltAnimation;
	}
	else
	{
		mpCurrentAnimation = &mMainAnimation;
	}

	mpCurrentAnimation->synch(*pOldAnimation);

}

void Unit::speedUpAnimation()
{
	float currentTiming = mpCurrentAnimation->getTimePerFrame();
	float gameTimePerFrame = (float)Game::getInstance()->getTargetTimePerFrame();
	currentTiming -= gameTimePerFrame;
	if (currentTiming < gameTimePerFrame)
	{
		currentTiming = gameTimePerFrame;
	}

	mpCurrentAnimation->setTimePerFrame(currentTiming);
}

int MAX_MULTIPLE = 50;

void Unit::slowDownAnimation()
{
	float currentTiming = mpCurrentAnimation->getTimePerFrame();
	float gameTimePerFrame = (float)Game::getInstance()->getTargetTimePerFrame();
	currentTiming += gameTimePerFrame;
	if (currentTiming > gameTimePerFrame*MAX_MULTIPLE)
	{
		currentTiming = gameTimePerFrame*MAX_MULTIPLE;
	}

	mpCurrentAnimation->setTimePerFrame(currentTiming);
}

void Unit::setAnimationPauseState(bool shouldPause)
{
	mpCurrentAnimation->setPauseState(shouldPause);
}

void Unit::toggleAnimationPauseState()
{
	mpCurrentAnimation->togglePause();
}

bool Unit::doesPointIntersect(const Vector2D& point) const
{
	Vector2D ul = getULPosition();
	Vector2D lr = getLRPosition();

	if (point.getX() < ul.getX())
	{
		return false;
	}
	else if (point.getY() < ul.getY())
	{
		return false;
	}

	else if (point.getX() > lr.getX())
	{
		return false;
	}
	else if (point.getY() > lr.getY())
	{
		return false;
	}

	return true;
}

Vector2D Unit::getULPosition() const
{
	Vector2D center = getCenterPosition();
	const Sprite& currSprite = mpCurrentAnimation->getCurrentSprite();
	return center - Vector2D(currSprite.getWidth() / 2.0f, currSprite.getHeight() / 2.0f);
}

Vector2D Unit::getLRPosition() const
{
	Vector2D center = getCenterPosition();
	const Sprite& currSprite = mpCurrentAnimation->getCurrentSprite();
	return center + Vector2D(currSprite.getWidth() / 2.0f, currSprite.getHeight() / 2.0f);
}





RandomDirUnit::RandomDirUnit(const Vector2D& position, Sprite& sprite)
	:mPos(position)
	, mSprite(sprite)
{

}

void RandomDirUnit::update(double dt)
{
	mpCurrentAnimation->update(dt);
}

void RandomDirUnit::draw()
{
	const Sprite& currSprite = mSprite;
	Vector2D offset = currSprite.getCenterOffset();
	Vector2D centerPos = mPos - offset;

	Game::getInstance()->getSystem()->getGraphicsSystem()->draw(centerPos, currSprite);
}



RandomSpawnedUnit::RandomSpawnedUnit(const Vector2D& position, const Animation& mainAnimation, const Animation& altAnimation, int seed)
	:mPos(position)
	, mMainAnimation(mainAnimation)
	, mAltAnimation(altAnimation)
	, mpCurrentAnimation(NULL)
	, mSeed(seed)
{
	mpCurrentAnimation = &mMainAnimation;
}

void RandomSpawnedUnit::update(double dt)
{
	
	mpCurrentAnimation->update(dt);
	
}

void RandomSpawnedUnit::draw()
{
	
	const Sprite& currSprite = mpCurrentAnimation->getCurrentSprite();
	Vector2D offset = currSprite.getCenterOffset();
	Vector2D centerPos = mPos - offset;

	Game::getInstance()->getSystem()->getGraphicsSystem()->draw(centerPos, currSprite);
	
}

bool RandomSpawnedUnit::doesPointIntersect(const Vector2D& point) const
{
	Vector2D ul = getULPosition();
	Vector2D lr = getLRPosition();

	if (point.getX() < ul.getX())
	{
		return false;
	}
	else if (point.getY() < ul.getY())
	{
		return false;
	}

	else if (point.getX() > lr.getX())
	{
		return false;
	}
	else if (point.getY() > lr.getY())
	{
		return false;
	}

	return true;
}

void RandomSpawnedUnit::toggleAnimation()
{
	Animation* pOldAnimation = mpCurrentAnimation;
	if (mpCurrentAnimation == &mMainAnimation)
	{
		mpCurrentAnimation = &mAltAnimation;
	}
	else
	{
		mpCurrentAnimation = &mMainAnimation;
	}

	mpCurrentAnimation->synch(*pOldAnimation);

}

Vector2D RandomSpawnedUnit::getULPosition() const
{
	Vector2D center = getCenterPosition();
	const Sprite& currSprite = mpCurrentAnimation->getCurrentSprite();
	return center - Vector2D(currSprite.getWidth() / 2.0f, currSprite.getHeight() / 2.0f);
}

Vector2D RandomSpawnedUnit::getLRPosition() const
{
	Vector2D center = getCenterPosition();
	const Sprite& currSprite = mpCurrentAnimation->getCurrentSprite();
	return center + Vector2D(currSprite.getWidth() / 2.0f, currSprite.getHeight() / 2.0f);
}

void RandomSpawnedUnit::setAnimationPauseState(bool shouldPause)
{
	mpCurrentAnimation->setPauseState(shouldPause);
}

void RandomSpawnedUnit::toggleAnimationPauseState()
{
	mpCurrentAnimation->togglePause();
}