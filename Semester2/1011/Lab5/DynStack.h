#ifndef DYNSTACK_H
#define DYNSTACK_H
#include <iostream>
using namespace std;

template <class T>
class DynStack {
private:
  // Class inside a class
  class StackNode{
		friend class DynStack;
		T value;
		StackNode *next;
		// Constructor
		StackNode(T value1, StackNode *next1 = NULL){
			value = value1;
			next = next1;
		}
	};
	StackNode *top;

public:
  virtual ~DynStack (){};
  DynStack() { top = NULL; }


  void push(T e);
  void pop(T &e);
  bool isEmpty() const;


};


#endif
