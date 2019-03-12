#include "TestDemo.h"
#include "MoveInCircle.h"
#include "SpriteRenderer.h"


TestDemo::TestDemo()
{
}


TestDemo::~TestDemo() 
{
}

void TestDemo::Setup()
{
	GameObject* go = CreateGameObject("Test", 640, 360, 45);
	go->AddComponent(new  SpriteRenderer("Assets/Tank.png"));
	go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));
	go->AddComponent(new MoveInCircle(go));
	go->GetComponent<MoveInCircle>()->radius = 100;
}