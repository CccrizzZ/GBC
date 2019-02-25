#include <iostream>
#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "tinyxml2.h"
#include "tinyxml2.cpp"
using namespace tinyxml2;
using namespace std;




int main(int argc, char* args[]) {

	// // Create a new xml document element
	// XMLDocument xmlDoc;
	//
	// // Create and insert Root element
	// XMLNode* bRoot = xmlDoc.NewElement("Root");
	// xmlDoc.InsertEndChild(bRoot);
	//
	//
	// // Create and insert 4 box element
	// XMLElement* bElement = xmlDoc.NewElement("GameObject");
	// bElement->SetAttribute("class", "Box");
	// bElement->SetAttribute("xpos", 100);
	// bElement->SetAttribute("ypos", 100);
	// bElement->SetAttribute("w", 100);
	// bElement->SetAttribute("h", 100);
	// bElement->SetAttribute("r", 0);
	// bElement->SetAttribute("g", 0);
	// bElement->SetAttribute("b", 255);
	// bRoot->InsertEndChild(bElement);
	//
	// bElement = xmlDoc.NewElement("GameObject");
	// bElement->SetAttribute("class", "Box");
	// bElement->SetAttribute("xpos", 800);
	// bElement->SetAttribute("ypos", 100);
	// bElement->SetAttribute("w", 100);
	// bElement->SetAttribute("h", 100);
	// bElement->SetAttribute("r", 0);
	// bElement->SetAttribute("g", 120);
	// bElement->SetAttribute("b", 255);
	// bRoot->InsertEndChild(bElement);
	//
	// bElement = xmlDoc.NewElement("GameObject");
	// bElement->SetAttribute("class", "Box");
	// bElement->SetAttribute("xpos", 100);
	// bElement->SetAttribute("ypos", 500);
	// bElement->SetAttribute("w", 100);
	// bElement->SetAttribute("h", 100);
	// bElement->SetAttribute("r", 255);
	// bElement->SetAttribute("g", 255);
	// bElement->SetAttribute("b", 0);
	// bRoot->InsertEndChild(bElement);
	//
	// bElement = xmlDoc.NewElement("GameObject");
	// bElement->SetAttribute("class", "Box");
	// bElement->SetAttribute("xpos", 800);
	// bElement->SetAttribute("ypos", 500);
	// bElement->SetAttribute("w", 100);
	// bElement->SetAttribute("h", 100);
	// bElement->SetAttribute("r", 0);
	// bElement->SetAttribute("g", 255);
	// bElement->SetAttribute("b", 0);
	// bRoot->InsertEndChild(bElement);
	// xmlDoc.SaveFile("SavedObjects.xml");



	// Array for Boxes
	vector<Box*> myBoxes;

	// Create XMLDocument
	XMLDocument xmlDoc;

	// Read the xml document
	xmlDoc.LoadFile("SavedObjects.xml");

	// Find Root
	XMLNode* myRoot = xmlDoc.FirstChild();

	// Find The First Child Element
	XMLElement* myElement = myRoot -> FirstChildElement("GameObject");

	// While there is still a next sibling
	while (myElement != nullptr) {
		// Attribute return the value of this Attribute
		// If this element's class Attribute == Box
		if (strcmp(myElement -> Attribute("class"), "Box") == 0) {
			// Create Variables
			int b_xpos;
			int b_ypos;
			int b_w;
			int b_h;
			int red;
			int green;
			int blue;

			// Change Variables
			myElement->QueryIntAttribute("xpos", &b_xpos);
			myElement->QueryIntAttribute("ypos", &b_ypos);
			myElement->QueryIntAttribute("w", &b_w);
			myElement->QueryIntAttribute("h", &b_h);
			myElement->QueryIntAttribute("r", &red);
			myElement->QueryIntAttribute("g", &green);
			myElement->QueryIntAttribute("b", &blue);

			// Create Boxes Object



			myBoxes.push_back(new Box({b_xpos, b_ypos, b_w, b_h,}, red, green, blue));
		}
		myElement = myElement -> NextSiblingElement("GameObject");
	}


	// We have the same basic structure as before but no more Game object
	// as we can now access everything through the static Game instance.
	Game::Instance()->Init("Box tinyxml2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0, myBoxes);
	while (Game::Instance()->Running()) {
		Game::Instance()->HandleEvents();
		if (Game::Instance()->Tick()) {
			Game::Instance()->Update();
			Game::Instance()->Render();
		}
	}
	Game::Instance()->Clean();
	return 0;
}
