#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int capacity;
    int front, rear;

    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return rear == capacity - 1;
    } 

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        front++;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(5); // no #define, no macro

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.peek() << endl;

    q.dequeue();

    cout << "After dequeue, Front: " << q.peek() << endl;

    return 0;
}
