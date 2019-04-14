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
		StackNode* next;
		// Constructor
		StackNode(T value1, StackNode *next1 = NULL){
			value = value1;
			next = next1;
		}

	};


  StackNode* top;

public:
  virtual ~DynStack (){};
  DynStack() { top = NULL; }

  // Push
  void push(T e){
    top = new StackNode(e, top);
  }


  // Pop
  void pop(T &e){
    StackNode* temp;
    if (isEmpty()) {
      cout << "[No more pancakes under the heat lamp!]" << '\n' << '\n';
      Gimme5();
      e = top -> value;
      temp = top;
      top = top -> next;
      delete temp;
    }else{
      // cout << "[1 Pancake dispensed!]" << '\n';
      e = top -> value;
      temp = top;
      top = top -> next;
      delete temp;
    }
  }


  // Isempty
  bool isEmpty() const{
    if (!top) {
      return true;
    }else{
      return false;
    }
  }


  // Make 5 Pancake
  void Gimme5() {

    push(100);
    push(100);
    push(100);
    push(100);
    push(100);

    cout << "[5 Pancakes throwed under the heat lamp]" << '\n';
  }


  // Sell 3 pancake
  void take3() {
    cout << "[Customer asked for 3 Pancake]" << '\n';

    int x;
    pop(x);
    pop(x);
    pop(x);
    cout << "[3 Pancake dispensed!]" << '\n' << '\n';
  }

};


#endif
