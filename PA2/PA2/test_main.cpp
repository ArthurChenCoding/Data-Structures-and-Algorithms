#include <iostream>
#include <cstdlib>
using namespace std;
#include "queue.h"
// main function
int main()
{
	// create a queue of capacity 5
	queue q(5);

	q.enqueue(99);
	q.enqueue(2);
	q.enqueue(3);
	
	cout << "Front element is: " << q.front() << endl;
	q.dequeue();
	
	q.enqueue(4);

	cout << "Queue size is " << q.size() << endl;

	q.dequeue();
	q.dequeue();
	q.dequeue();
	
	if (q.isEmpty())
		cout << "Queue Is Empty\n";
	else
		cout << "Queue Is Not Empty\n";

	return 0;
}