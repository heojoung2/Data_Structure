#include "queue_linked_list.h"

int main()
{
	Queue<double> queue;

	Data<double> data1(1.1);
	Data<double> data2(2.2);
	Data<double> data3(3.3);
	
	queue.Enqueue(&data1);
	queue.Display();
	queue.Enqueue(&data2);
	queue.Display();
	queue.Enqueue(&data3);
	queue.Display();
	
	Data<double> dequeue_data = queue.Dequeue();
	cout << "Dequeue : "<<dequeue_data.Get_data() << endl;
	queue.Display();

	Data<double> data4(4.4);
	queue.Enqueue(&data4);
	queue.Display();

	Data<double> peek_data = queue.Peek();
	cout << "Peek : " << peek_data.Get_data() << endl;
	queue.Display();
	
	return 0;
}
