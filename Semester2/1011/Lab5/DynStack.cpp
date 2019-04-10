#include "DynStack.h"
using namespace std;

template <class T>
void DynStack<T>::push(T e){
  top = new StackNode(e, top);
}


template <class T>
void DynStack<T>::pop(T &e){
  StackNode* temp;
  if (isEmpty()) {
    cout << "This stack is empty" << '\n';
    exit(1);
  }else{
    e = top -> value;
    temp = top;
    top = top -> next;
    delete temp;
  }
}


template <class T>
bool DynStack<T>::isEmpty() const{
  if (!top) {
    return true;
  }else{
    return false;
  }
}
