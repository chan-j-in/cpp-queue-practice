#include <iostream>
#include "CQueue.h"

using namespace std;

int main() {

	CQueue<int> queueInt;
	CCircleQueue<int> circleQueueInt;

	for (int i = 0; i < 100; i++) {
		queueInt.push(i + 1);
	}

	while(!queueInt.isEmpty()) {
		cout << queueInt.pop() << endl;
	}

	cout << "==================" << endl;

	for (int i = 0; i < 100; i++) {
		circleQueueInt.push(i + 1);
	}

	while(!circleQueueInt.isEmpty()) {
		cout << circleQueueInt.pop() << endl;
	}

	cout << "==================" << endl;

	CCircleQueue<int, 10> circleQueueInt2;

	for (int i = 0; i < 10; i++) {
		circleQueueInt2.push(i + 1);
	}
	for (int i = 0; i < 3; i++) {
		cout << circleQueueInt2.pop() << endl;
	}

	return 0;
}