#pragma once

template <typename T>
class CQueueNode
{
private:
	CQueueNode() : next(nullptr), prev(nullptr) {}
	~CQueueNode() {}

private:
	CQueueNode<T>* next;
	CQueueNode<T>* prev;
	T data;

private:
	template <typename U>
	friend class CQueue;
};

template <typename T>
class CQueue {
private:
	typedef CQueueNode<T> NODE;
	typedef CQueueNode<T>* PNODE;

private:
	PNODE front;
	PNODE rear;
	unsigned int size;

public:
	CQueue() {
		front = new NODE;
		rear = new NODE;
		size = 0;

		front->next = rear;
		front->prev = nullptr;

		rear->prev = front;
		rear->next = nullptr;
	}
	~CQueue() {
		PNODE node = front;
		while (node) {
			PNODE next = node->next;
			delete node;
			node = next;
		}
	}

public:
	void push(const T& data) {
		PNODE node = new NODE;
		node->data = data;

		rear->prev->next = node;
		node->prev = rear->prev;

		node->next = rear;
		rear->prev = node;

		size++;
	}

	T pop() {
		if (isEmpty()) return T{};

		PNODE node = front->next;
		T data = node->data;

		front->next = node->next;
		node->next->prev = front;
		delete node;

		size--;

		return data;
	}

	bool isEmpty() const{ return size == 0; }
};

template <typename T, int SIZE = 100>
class CCircleQueue {
public:
	CCircleQueue() : size(0), head(0), tail(0) {}
	~CCircleQueue() {}

private:
	template <typename U>
	friend class CQueue;

private:
	T arr[SIZE + 1];
	unsigned int size;
	unsigned int head;
	unsigned int tail;

public:
	void push(const T& data) {
		if (isFull()) return;

		tail = (tail + 1) % (SIZE + 1);
		arr[tail] = data;

		size++;
	}

	T pop() {
		if (isEmpty()) return T{};

		head = (head + 1) % (SIZE + 1);

		size--;

		return arr[head];
	}

	bool isFull() { return size == SIZE; }
	bool isEmpty() { return size == 0; }
};