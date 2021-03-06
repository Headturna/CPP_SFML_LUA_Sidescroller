#pragma once

#include "State.h"

constexpr const char* LUA_ENGINE_ACCESSOR = "ENGINE";

class Engine
{
private:
	std::stack<State*> states;
	sf::RenderWindow window;

	float deltaTime;
	sf::Clock dtClock;

	void initVariables();
	void initStates();
	void registerCppFunctions(lua_State* L);

public:
	//Constructors & Destructors
	Engine();
	~Engine();

	//Accessors

	//Modifiers

	//Functions
	void pushState(const char* lua_state_file);

	void pollEvent();
	void update();
	void render();
	void run();

	//LUA FUNCTIONS
	static int cpp_createWindow(lua_State* L);
	static int cpp_setWindowFramerateLimit(lua_State* L);
	static int cpp_clearWindow(lua_State* L);
	static int cpp_displayWindow(lua_State* L);
};

