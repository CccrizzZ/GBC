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
	DynQueue();
	~DynQueue();

	// Member functions
	void enqueue(T num);
	void dequeue(T &num);
	bool isEmpty() const;
	void clear();
};
#endif
