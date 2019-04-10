#include <iostream>
#include "DynQueue.h"
#include <cstdlib>
using namespace std;

// Constructor
template <class T>
DynQueue<T>::DynQueue(){
	front = NULL;
	rear = NULL;
}

// Destructor
template <class T>
DynQueue<T>::~DynQueue(){
	clear();
}



template <class T>
void DynQueue<T>::enqueue(T num){
	if (isEmpty()){
		front = new QueueNode(num);
		rear = front;
	}else{
		rear->next = new QueueNode(num);
		rear = rear->next;
	}
}

template <class T>
void DynQueue<T>::dequeue(T &num){
	QueueNode *temp;
	if (isEmpty()){
		cout << "The queue is empty.\n";
		exit(1);
	}else{
		num = front->value;
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <class T>
bool DynQueue<T>::isEmpty() const{
	if (front == NULL){
    return true;
  }else{
    return false;
  }
}


template <class T>
void DynQueue<T>::clear(){
	T value;

	while (!isEmpty()){
    dequeue(value);
  }
}
