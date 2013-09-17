#pragma once

#include <string>

using namespace std;

//Forward decleration of our Window Interface
class IWindow;

struct GameOptionsDesc
{
	wstring gameName;
	int width;
	int height;
	bool fullscreen;
};

using namespace std;

class CGameApplication
{
public:
	CGameApplication(void);
	virtual ~CGameApplication(void);
	virtual bool init();
	void run();
	virtual void render();
	virtual void update();
private:
	bool initInput();
	bool initGame();
	bool initGraphics();
	bool initPhysics();

	bool initWindow();
private:
	IWindow * m_pWindow;
	GameOptionsDesc m_GameOptionDesc;
};