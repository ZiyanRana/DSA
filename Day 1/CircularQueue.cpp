#include <iostream>
using namespace std;

class CircularQueue {
    private:
        int rear ;
        int front ;
        int array [5];
        int itemCount = 0 ;

    public:
        CircularQueue()
        {
            rear = -1 ;
            front = -1 ;
            for ( int i = 0 ; i < 5 ; i++ )
            {
                array[i] = 0 ;
            }
        }

        bool isEmpty()
        {
            if ( rear == -1 && front == -1 )
                return true;
            else
                return false;
        }

        bool isFull()
        {
            if ( (rear+1) % 5 == front )
                return true;    
            else
                return false;
        }

        void enqueue( int val )
        {
            if ( isFull() )
            {
                cout << "Queue is full, cannot enqueue value." << endl ;
                return;
            }
            else if ( isEmpty() )
                rear = front = 0 ;
            else
                rear = (rear+1)%5 ;

            array[rear] = val ;
            itemCount ++ ;
        }

        int dequeue () 
        {
            int x = 0 ;
            if ( isEmpty() )
            {
                cout << "Queue is empty, cannot dequeue." << endl ;
                return 0;
            }
            else if ( rear == front )
            {
                x = array[front];
                array[front] = 0 ;
                rear = front = -1 ;
            }
            else 
            {
                x = array[front];
                array[front] = 0 ;
                front = (front+1)%5 ;
            }
            itemCount -- ;
            return x ;
        }

        void count ()
        {
            if(!isEmpty())
            {
                cout << "Number of items: " << itemCount << endl ;
            }
            else 
                cout << "Queue is empty." << endl ;
        }

        void display()
        {
            for (int i=0 ; i<5 ; i++ )
            {
                cout << array[i] << "\t" ;
            }
            cout << endl ;
        }
};

int main()
{
    CircularQueue q1;
    int option, value;

    do 
    {
        system("cls");
        cout << "\nSelect an option number:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Count" << endl;
        cout << "6. Display" << endl ;
        cout << "7. Exit" << endl << endl ;
        cout << "Enter option: ";
        cin >> option;

        switch (option) 
        {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q1.enqueue(value);
                system("pause");
                break;
            
            case 2:
                cout << "Dequeued value: " << q1.dequeue() << endl;
                system("pause");
                break;
            
            case 3:
                if (q1.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                system("pause");
                break;
            
            case 4:
                if (q1.isFull())
                    cout << "Queue is full." << endl;
                else
                    cout << "Queue is not full." << endl;
                system("pause");    
                break;
            
            case 5:
                q1.count();
                system("pause");
                break;
            
            case 6:
                cout << "Queue contains the elements: " << endl ;
                q1.display();
                system("pause");
                break;
            
            case 7:
                cout << "Exiting..." << endl;
                system("pause");
                break;
            
            default:
                cout << "Invalid option. Enter from 1-7." << endl;
                system("pause");
        }
    } 
    while (option != 7);

    return 0;
}
