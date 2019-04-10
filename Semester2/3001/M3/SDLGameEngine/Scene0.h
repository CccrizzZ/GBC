#pragma once
#include "Scene.h"

class Scene0 : public Scene{
public:
	Scene0();
	~Scene0();
	
	// Global instance
	static Scene0* Instance() {
		static Scene0* instance = new Scene0();
		return instance;
	}

	void Setup();
};
