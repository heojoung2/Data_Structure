#include "circular_queue.h"

int main()
{
	Queue<int> queue(3);
	
	Data<int> data1(1);
	Data<int> data2(2);
	Data<int> data3(3);

	queue.Enqueue(data1);
	queue.Display();
	queue.Enqueue(data2);
	queue.Display();
	queue.Enqueue(data3);
	queue.Display();

	Data<int> dequeue_data = queue.Dequeue();
	cout<<"Dequeue data : "<<dequeue_data.Get_data()<<endl;
	queue.Display();

	Data<int> data4(4);
	queue.Enqueue(data4);
	queue.Display();

	Data<int> peek_data = queue.Peek();
	cout << "Dequeue data : " << peek_data.Get_data() << endl;
	queue.Display();
}
