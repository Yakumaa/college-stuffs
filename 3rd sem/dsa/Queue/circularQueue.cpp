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
    int queue[SIZE], front, rear, count;
public:
    circularQueue(){
        front = -1;
        rear = -1;
        count = 0;
    }

    void enqueue(int item){
    if (rear == SIZE - 1)
    {
        cout << ("Queue is full");
    }
    else
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        cout << "Inserted -> " << item;

    }

    void dequeue(){
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty";
        }
        else
            cout << "Deleted -> " << queue[front];
            front++;
        
    }

    void display(){
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty";
        }
        else
            cout << "\nQueue: ";
            for (int i = front; i <= rear; i++)
            {
                cout << " " << queue[i];
            }
        
    }

    void makeEmpty(){
        if (front == -1 && rear == -1)
        {
            cout << "Queue is already empty";
        }
        else
            front = -1;
            rear = -1;
    }
};

void main(){
    int item, choice;
    char ch;
    do
    {
        cout << "*********MENU***********\n";
        cout << " 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Make Empty\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter item to be inserted: ";
            cin >> item;
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            makeEmpty();
            break;
        default:
            cout << "\nwrong selection!";
        }
        cout << "\nDo you want to continue?(y/n): ";
        cin >> ch;
        
        if (ch == 'y' && choice == 1)
        {
            count = 1;
        }
        
    } while (ch == 'y');

}


