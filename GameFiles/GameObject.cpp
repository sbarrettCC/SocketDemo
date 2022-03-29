#include "RoboCatPCH.h"
#include "..\GameFiles\GameObject.h"
#include "allegro_wrapper_functions-main/GraphicsLibrary.h"

GameObject::GameObject(std::string graphicsID, int posX, int posY, int width, int height)
{
	mpGraphicsID = new std::string(graphicsID);
	mGraphicsData.mX = posX;
	mGraphicsData.mY = posY;
	mGraphicsData.mZ = width;
	mGraphicsData.mW = height;
}

GameObject::GameObject(std::string graphicsID, int width, int height)
{
	mpGraphicsID = new std::string(graphicsID);
	mGraphicsData.mX = 0;
	mGraphicsData.mY = 0;
	mGraphicsData.mZ = width;
	mGraphicsData.mW = height;
}

void GameObject::Render(GraphicsLibrary* gl)
{
	//gl->drawImage(*mpGraphicsID, mGraphicsData.mX, mGraphicsData.mY);
	gl->drawImage(*mpGraphicsID, mGraphicsData.mX - (mGraphicsData.mZ / 2.0f), mGraphicsData.mY - (mGraphicsData.mW / 2.0f));
	//gl->drawImage(*mpGraphicsID, -35,-35);
	//gl->drawImage(*mpGraphicsID, 0,0);
}

void GameObject::SetPostion(int posX, int posY)
{
	mGraphicsData.mX = posX;
	mGraphicsData.mY = posY;
}

GameObject::~GameObject()
{
	delete mpGraphicsID;
}