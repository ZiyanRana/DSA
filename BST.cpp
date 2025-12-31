#include <iostream>
#define SPACE 10;
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode() {
            data = 0;
            left = NULL;
            right = NULL;
        }

        TreeNode(int d) {
            data = d ;
            left = NULL;
            right = NULL;
        }
};

class BST {
    public:
        TreeNode* root;

        bool isEmpty() {
            if (root == NULL) {
                return true;
            }
            else {
                return false;
            }
        }

        void insertNode(TreeNode *newNode) {
            if (isEmpty()) {
                root = newNode ;
                cout << "Node inserted as root." ;
            }
            else {
                TreeNode* temp = root;
                while (temp != NULL) {
                    if (newNode->data == temp->data) {
                        cout << "Node with same value already exists, try a different one.";
                        return;
                    }
                    else if (newNode->data < temp->data && temp->left == NULL) {
                        temp->left = newNode;
                        break;
                    }
                    else if (newNode->data < temp->data) {
                        temp = temp->left;
                    }
                     else if (newNode->data > temp->data && temp->right == NULL) {
                        temp->right = newNode;
                        break;
                    }
                    else {
                        temp = temp->right;
                    }
                }
                cout << "Value inserted." << endl ;
            }
        }

        void printPreOrder (TreeNode *root) {
            if (isEmpty()) {
                cout << "Tree is empty." << endl;
                return;
            }
            else {
                cout << root->data << " ";
                printPreOrder (root->left);
                printPreOrder (root->right);
            }
        }       
        
        void printInOrder (TreeNode *root) {
            if (isEmpty()) {
                cout << "No values in tree." << endl;
                return;
            }
            else {
                printInOrder (root->left);
                cout << root->data << " " ;
                printInOrder (root->right);
            }
        }

        void printPostOrder (TreeNode *root) {
            if (isEmpty()) {
                cout << "No values in tree." << endl;
                return;
            }
            else {
                printPostOrder (root->left) ;
                printPostOrder (root->right) ;
                cout << root->data << " " ;
            }
        }

        TreeNode* searchByValue (int val) {
            if (isEmpty()) {
                return NULL;
            }
            else {
                TreeNode* temp = root ;
                while (temp != NULL) {
                    if (temp->data == val) {
                        return temp;
                    }
                    else if (val < temp->data) {
                        temp = temp->left ;
                    }
                    else if (val > temp->data) {
                        temp = temp->right;
                    }
                    else {
                        return NULL;
                    }
                }
            }
        }

        int treeHeight (TreeNode *root) {
            if (root == NULL) {
                return -1;
            }
            else {
                int lheight = treeHeight (root->left) ;
                int rheight = treeHeight (root->right);
                if (lheight > rheight) 
                    return lheight+1 ;
                else 
                    return rheight+1 ;
            }
        }
        
        void printBFS (TreeNode *root) {
            int height = treeHeight(root);
            for (int i=0 ; i <= height ; i++ ) {
                printCurrentLevel (root, i);
            }
        }

        void printCurrentLevel (TreeNode *root, int level) {
            if (root == NULL) {
                return;
            }
            else if (level == 0) {
                cout << root->data << " " ;
            }
            else {
                printCurrentLevel (root->left, level-1);
                printCurrentLevel (root->right, level-1);
            }
        }

        TreeNode* minNode (TreeNode *root) {
            TreeNode* temp = root ;
            while (temp != NULL) {
                temp = temp->left ;
            }
            return temp;
        }
        
        TreeNode* deleteNodeByVal(TreeNode* root, int val) {
            if (root == NULL)
                return NULL;

            if (val < root->data) {
                root->left = deleteNodeByVal(root->left, val);
            }
            else if (val > root->data) {
                root->right = deleteNodeByVal(root->right, val);
            }
            else {
                if (root->left == NULL && root->right == NULL) {
                    delete root;
                    return NULL;
                }
                else if (root->left == NULL) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == NULL) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                else {
                    TreeNode* successor = root->right;
                    while (successor->left != NULL)
                        successor = successor->left;

                    root->data = successor->data;
                    root->right = deleteNodeByVal(root->right, successor->data);
                }
            }
        return root;
    }

};

int main() {

    BST bst;
    bst.root = NULL;   // IMPORTANT: initialize root

    int option;
    int value;

    do {
        cout << "\n====== Binary Search Tree Menu ======\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Print Preorder\n";
        cout << "5. Print Inorder\n";
        cout << "6. Print Postorder\n";
        cout << "7. Print BFS (Level Order)\n";
        cout << "8. Tree Height\n";
        cout << "0. Exit\n";
        cout << "====================================\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insertNode(new TreeNode(value));
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.root = bst.deleteNodeByVal(bst.root, value);
                cout << "Delete operation completed.\n";
                break;

            case 3: {
                cout << "Enter value to search: ";
                cin >> value;
                TreeNode* result = bst.searchByValue(value);
                if (result != NULL)
                    cout << "Value found in tree.\n";
                else
                    cout << "Value not found.\n";
                break;
            }

            case 4:
                cout << "Preorder Traversal: ";
                bst.printPreOrder(bst.root);
                cout << endl;
                break;

            case 5:
                cout << "Inorder Traversal: ";
                bst.printInOrder(bst.root);
                cout << endl;
                break;

            case 6:
                cout << "Postorder Traversal: ";
                bst.printPostOrder(bst.root);
                cout << endl;
                break;

            case 7:
                cout << "BFS Traversal: ";
                bst.printBFS(bst.root);
                cout << endl;
                break;

            case 8:
                cout << "Tree Height: " << bst.treeHeight(bst.root) << endl;
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (option != 0);

    return 0;
}