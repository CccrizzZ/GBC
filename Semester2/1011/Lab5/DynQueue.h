#ifndef DYNQUEUE_H
#define DYNQUEUE_H

template <class T>
class DynQueue{
private:
	class QueueNode{
		friend class DynQueue;
		T value;
		QueueNode *next;
		QueueNode(T value1, QueueNode *next1 = NULL){
			value = value1;
			next = next1;
		}
	};

	// Front and rear of the queue
	QueueNode *front;
	QueueNode *rear;
public:
	// Constructor and Destructor
	DynQueue(){
		front = NULL;
		rear = NULL;
	}

	~DynQueue(){
		clear();
	}

	// enqueue
	void enqueue(T num){
		if (isEmpty()){
			front = new QueueNode(num);
			rear = front;
		}else{
			rear->next = new QueueNode(num);
			rear = rear->next;
		}
	}


	// dequeue
	void dequeue(T &num){
		QueueNode *temp;
		if (isEmpty()){
			cout << "[All customers are served]";
		}else{
			num = front->value;
			temp = front;
			front = front->next;
			delete temp;
		}
	}



	// isEmpty
	bool isEmpty() const{
		if (front == NULL){
	    return true;
	  }else{
	    return false;
	  }
	}


	// clear
	void clear(){
		cout << "[30 Customers marched away from our pancake shop]" << '\n';
		T value;
		while (!isEmpty()){
	    dequeue(value);
	  }
	}




	void Add30(){
		cout << "[30 Customers marched up to our pancake shop]" << '\n';
		for (int i = 0; i < 30; i++) {
			enqueue(100);
		}
	}

};
#endif
