#include<iostream>
using namespace std;

class Stack {
    private:
        int top;
        int array[5];

    public:
        Stack()
        {
            top = -1;
            for ( int i=0 ; i < 5 ; i++ )
            {
                array[i] = 0 ;
            }
        }

        bool isEmpty()
        {
            if (top == -1)
                return true;
            else 
                return false;
        }

        bool isFull()
        {
            if (top == 4)
                return true;
            else
                return false;
        }

        void push(int val)
        {
            if (isFull())
            {
                cout << "Stack overflow." << endl ;
            }
            else 
            {
                top ++ ;
                array[top] = val ;
                cout << "Value added in the stack." << endl ;
            }
        }

        int pop()
        {
            if (isEmpty())
            {
                return 0;
            }
            else
            {
                int popValue = array[top];
                array[top] = 0 ;
                top -- ;
                return popValue;
            }
        }

        int count()
        {
            return top+1 ;
        }

        int peek (int position)
        {
            if (isEmpty())
            {
                cout << "Stack underflow." << endl;
                return 0;
            }
            else
            {
                return array[position-1];
            }
        }

        void change (int value, int position)
        {
            if ( array[position-1] != 0 )
            {
                array[position-1] = value;
                cout << "Value changed at the said position." << endl ;
            }
            else
            {
                cout << "There is no value at the said position.\nEnter a value first to change." << endl ;
            }
        }

        void display ()
        {
            cout << "\nThe values stored in the stack are: " << endl ;
            for (int i = 4 ; i >= 0 ; i -- )
            {
                cout << array[i] << endl ;
            }
        }
};

int main()
{
    Stack s1;
    int option, value, position;

    do
    {
        system("cls");
        cout << "\n=====================================\n";
        cout << "            STACK MENU\n";
        cout << "=====================================\n";
        cout << "1.  Push\n";
        cout << "2.  Pop\n";
        cout << "3.  isEmpty\n";
        cout << "4.  isFull\n";
        cout << "5.  Peek\n";
        cout << "6.  Count\n";
        cout << "7.  Change\n";
        cout << "8.  Display\n";
        cout << "9.  Exit\n";
        cout << "=====================================\n";
        cout << "\nEnter your choice: ";
        cin >> option;

        switch (option)
        {
            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                s1.push(value);
                system ("pause");
                break;

            case 2:
                if (s1.isEmpty())
                {
                    cout << "Stack underflow." << endl;
                }
                else
                {
                    cout << "Value popped out." << endl ;
                    cout << "Popped value: " << s1.pop() << endl ;
                }
                system("pause");
                break;

            case 3:
                if (s1.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                system("pause");
                break;

            case 4:
                if (s1.isFull())
                    cout << "Stack is full.\n";
                else
                    cout << "Stack is not full.\n";
                system("pause");
                break;

            case 5:
                cout << "Enter position (1-5): ";
                cin >> position;
                cout << "Value at position " << position << " is " << s1.peek(position) << endl;
                system("pause");
                break;

            case 6:
                cout << "Count of items in the stack: " << s1.count() << endl;
                system("pause");
                break;

            case 7:
                cout << "Enter position (1-5): ";
                cin >> position;
                cout << "Enter new value: ";
                cin >> value;
                s1.change(value, position);
                system("pause");
                break;

            case 8:
                s1.display();
                system("pause");
                break;

            case 9:
                cout << "\nExiting program...\nGoodBye :)" << endl ;
                system("pause");
                break;

            default:
                cout << "Invalid choice. Enter from 1-9.\n";
                system("pause");
                break;
        }

    } while (option != 9);

    return 0;
}
