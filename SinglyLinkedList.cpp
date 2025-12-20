#include <iostream>
using namespace std;

class Node {
    public:
        int key;
        int data;
        Node* next;

        Node() {
            key = 0 ;
            data = 0 ;
            next = NULL ;
        }

        Node(int k, int d) {
            key = k;
            data = d;
            next = NULL;
        }
};

class SinglyLinkedList {
    public:
        Node* head;
    
        SinglyLinkedList() {
            head = NULL;
        }
        SinglyLinkedList(Node *address) {
            head = address;
        }

        Node* nodeExist(int k) {
            Node* temp = NULL;
            Node* ptr = head ;
            while (ptr != NULL) {
                if (ptr->key == k)
                {
                    temp = ptr ;
                }
                ptr = ptr -> next ;
            }
            return temp;
        }

        void appendNode (Node *n) {
            if (nodeExist(n->key) != NULL) {
                cout << "Node already exists, cannot append." << endl ;
            }
            else { 
                if(head == NULL) {
                    head = n ;
                }
                else {
                    Node* temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = n;
                }
                cout << "Node appended." << endl ;
            }    
        }

        void prependNode (Node *n) {
            if (nodeExist(n->key) != NULL) {
                cout << "Node already exists, cannot prepend." << endl ;
            }
            else {
                n->next = head ;
                head = n;
                cout << "Node prepended." << endl ;
            }
        }

        void insertNodeAfterKey (int key, Node *n) {
            Node* temp = nodeExist(key);
            if (temp == NULL) {
                cout << "No node with key " << key << " found, cannot insert." << endl ;
            }
            else {
                if (nodeExist(n->key) != NULL) {
                cout << "Node already exists, cannot insert." << endl ;
                }
                else {
                    n->next = temp->next;
                    temp->next = n;
                    cout << "Node inserted successfully." << endl ;
                }
            }
        }

        void deleteNodeByKey (int key) {
            if (head == NULL) {
                cout << "LinkedList already empty." << endl ;
            }
            else if (nodeExist(key)!= NULL) {
                if (nodeExist(key)==head) { 
                    head = head->next ;
                    cout << "Node unlinked successfully." << endl ;
                }
                else {
                    Node* temp = NULL; 
                    Node* prevPtr = head ;
                    Node* currentPtr = head -> next ;
                    while (currentPtr != NULL) {
                        if (currentPtr->key == key) {
                            temp = currentPtr;
                           break;
                        }
                        else {
                            prevPtr = currentPtr ;
                            currentPtr = currentPtr->next;
                        }
                    }
                    if (temp!= NULL) {
                        prevPtr->next = temp->next ;
                        cout << "Node unlinked successfully." << endl ;
                    }
                    else {
                        cout << "No node exist with the given key value." << endl ;
                    }
                }
            }
        }

        void updateDataByKey (int key, int data) {
            Node* ptr = nodeExist(key) ;
            if (ptr != NULL) {
                ptr->data = data ;
                cout << "Data updated succssfully." << endl ;
            }
            else {
                cout << "No node exist with the given key value." << endl ;
            }
        }

        void printList () {
            if (head==NULL) {
                cout << "\nList is empty." << endl ;
            }
            else {
                Node* temp = head ;
                cout << "\nSingly LinkedList values: " << endl ;
                while (temp != NULL) {
                    cout << "(" << temp->key << "," << temp->data << ") --> " ;
                    temp = temp->next ;
                }
            }
        }
};

int main() {

    SinglyLinkedList s;
    int choice = 0;

    do {
        system("cls");
        cout << "\n===============================" << endl;
        cout << "   Singly Linked List Menu" << endl;
        cout << "===============================" << endl;
        cout << "1. Append Node" << endl;
        cout << "2. Prepend Node" << endl;
        cout << "3. Insert Node After Key" << endl;
        cout << "4. Delete Node By Key" << endl;
        cout << "5. Update Node Data By Key" << endl;
        cout << "6. Print List" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int key, data, afterKey;
        Node* newNode;

        switch (choice) {
        case 1:
            system("cls");
            cout << "===== Append Node =====" << endl;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter data: ";
            cin >> data;
            newNode = new Node(key, data);
            s.appendNode(newNode);
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "===== Prepend Node =====" << endl;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter data: ";
            cin >> data;
            newNode = new Node(key, data);
            s.prependNode(newNode);
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "===== Insert Node After Key =====" << endl;
            cout << "Enter key after which to insert: ";
            cin >> afterKey;
            cout << "Enter new node key: ";
            cin >> key;
            cout << "Enter new node data: ";
            cin >> data;
            newNode = new Node(key, data);
            s.insertNodeAfterKey(afterKey, newNode);
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "===== Delete Node By Key =====" << endl;
            cout << "Enter key of node to delete: ";
            cin >> key;
            s.deleteNodeByKey(key);
            system("pause");
            break;

        case 5:
            system("cls");
            cout << "===== Update Node Data =====" << endl;
            cout << "Enter key of node to update: ";
            cin >> key;
            cout << "Enter new data: ";
            cin >> data;
            s.updateDataByKey(key, data);
            system("pause");
            break;

        case 6:
            system("cls");
            cout << "===== Print List =====" << endl;
            s.printList();
            cout << endl;
            system("pause");
            break;

        case 7:
            system("cls");
            cout << "================================" << endl;
            cout << "  Thanks for using the program!" << endl;
            cout << "================================" << endl;
            system("pause");
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
        }

    } while (choice != 7);

    return 0;
}
