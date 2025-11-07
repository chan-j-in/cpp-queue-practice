#include <iostream>
#include "CQueue.h"

using namespace std;

int main() {

	CQueue<int> queueInt;

	for (int i = 0; i < 100; i++) {
		queueInt.push(i + 1);
	}

	while(!queueInt.isEmpty()) {
		cout << queueInt.pop() << endl;
	}

	return 0;
}