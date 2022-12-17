#include <iostream>
using namespace std;
#define SIZE 5

void enqueue(int);
void dequeue();
void display();
void makeEmpty();

class circularQueue
{
private:
    int queue[SIZE], front, rear;
public:
    circularQueue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        if (front == 0 && rear == SIZE - 1)
        {
            return true;
        }
        else
            return false;
        
    }

    bool isEmpty(){
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
            return false;
        
    }

    void enqueue(int item){
    if (isFull())
    {
        cout << ("Queue is full");
    }
    else
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = item;
        cout << "\nInserted -> " << item;

    }

    void dequeue(){
        if (isEmpty())
        {
            cout << "\nQueue is empty";
        }
        else{
            cout << "\nDeleted -> " << queue[front];
            front = (front + 1) % SIZE;
        }
    }

    void display(){
        if (isEmpty())
        {
            cout << "\nQueue is empty";
        }
        else{
            cout << "\nQueue: ";
            for (int i = front; i <= rear; i = (i+1)%SIZE)
            {
                cout << " " << queue[i];
            }
        }
    }

    void makeEmpty(){
        if (isEmpty())
        {
            cout << "\nQueue is already empty";
        }
        else
            front = -1;
            rear = -1;
    }
};

int main(){
    circularQueue q;
    q.enqueue(99);
    q.enqueue(88);
    q.enqueue(77);
    q.dequeue();
    q.display();
    q.makeEmpty();
    q.display();

    return 0;
}


