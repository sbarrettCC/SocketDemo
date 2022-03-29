#pragma once
#include "GameFiles/JoinerInput.h"

class GameObject;
class LinkingContext;
class GraphicsLibrary;
class JoinerInput;

struct Location;

class WorldState
{
	const float SCREEN_X = 1000;
	const float SCREEN_Y = 500;
	const string FILE_PATH = "\\..\\..\\images\\";
	const string BACKGROUND = "background.jpg";

	public:
		WorldState(GraphicsLibrary* gl);
		~WorldState();
		void Update(bool isCreator, vector<JoinerInput>& joinerInput);
		void Render();

		void CreateLock();
		void CreateLock(int posX, int posY);

		void Write(OutputMemoryBitStream& stream) const;
		virtual void Read(InputMemoryBitStream& stream);
	protected:
	private:
		vector<GameObject*> mGameObjects;
		LinkingContext* mpGameObjectLinker;
		GraphicsLibrary* mpGraphicsLibrary;
};

