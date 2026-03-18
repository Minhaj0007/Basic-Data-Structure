#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int *arr;
    int capacity;
    int front, rear;
    int count;

    CircularQueue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull()
    {
        return count == capacity;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        front = (front + 1) % capacity;
        count--;
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

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); // Display all elements

    q.dequeue();
    q.display(); // Display after dequeue

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display(); // Display after wrapping

    return 0;
}
