//#include<iostream>
//#define SPACE 10
//
//using namespace std;
//
//class TreeNode {
//public:
//    int value;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode() {
//        value = 0;
//        left = NULL;
//        right = NULL;
//    }
//    TreeNode(int v) {
//        value = v;
//        left = NULL;
//        right = NULL;
//    }
//};
//
//class BST {
//public:
//    TreeNode* root;
//    BST() {
//        root = NULL;
//    }
//    bool isTreeEmpty() {
//        if (root == NULL) {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//
//    void insertNode(TreeNode* new_node) {
//        if (root == NULL) {
//            root = new_node;
//            cout << "\tValue Inserted as root node!" << endl;
//        }
//        else {
//            TreeNode* temp = root;
//            while (temp != NULL) {
//                if (new_node->value == temp->value) {
//                    cout << "\tValue Already exist," <<
//                        "\tInsert another value!" << endl;
//                    return;
//                }
//                else if ((new_node->value < temp->value) && (temp->left == NULL)) {
//                    temp->left = new_node;
//                    cout << "\tValue Inserted to the left!" << endl;
//                    break;
//                }
//                else if (new_node->value < temp->value) {
//                    temp = temp->left;
//                }
//                else if ((new_node->value > temp->value) && (temp->right == NULL)) {
//                    temp->right = new_node;
//                    cout << "\tValue Inserted to the right!" << endl;
//                    break;
//                }
//                else {
//                    temp = temp->right;
//                }
//            }
//        }
//    }
//    TreeNode* getParent(TreeNode* r, int val) {
//        if (r == nullptr || r->value == val)
//            return nullptr;
//
//        TreeNode* Parent = nullptr;
//        while (r != nullptr) {
//            if (val < r->value) {
//                Parent = r;
//                r = r->left;
//            }
//            else if (val > r->value) {
//                Parent = r;
//                r = r->right;
//            }
//            else {
//                return Parent;
//            }
//        }
//    }
//    void print2D(TreeNode* r, int space) {
//        if (r == NULL)
//            return;
//        space += SPACE;
//        print2D(r->right, space); // Process right child first 3 
//        cout << endl;
//        for (int i = SPACE; i < space; i++) // 5 
//            cout << " "; // 5.1  
//        cout << r->value << "\n";
//        print2D(r->left, space);
//    }
//
//    void inorder(TreeNode* r) {
//        if (r == nullptr) {
//            return;
//        }
//        inorder(r->left);
//        cout << r->value;
//        inorder(r->right);
//    }
//
//    TreeNode* iterativeSearch(int v) {
//        if (root == NULL) {
//            return root;
//        }
//        else {
//            TreeNode* temp = root;
//            while (temp != NULL) {
//                if (v == temp->value) {
//                    return temp;
//                }
//                else if (v < temp->value) {
//                    temp = temp->left;
//                }
//                else {
//                    temp = temp->right;
//                }
//            }
//            return NULL;
//        }
//    }
//
//    TreeNode* recursiveSearch(TreeNode* r, int val) {
//        if (r == NULL || r->value == val)
//            return r;
//
//        else if (val < r->value)
//            return recursiveSearch(r->left, val);
//
//        else
//            return recursiveSearch(r->right, val);
//    }
//
//
//    TreeNode* minNode(TreeNode* node) {
//        TreeNode* current = node;
//        while (current->left != NULL) {
//            current = current->left;
//        }
//        return current;
//    }
//
//    TreeNode* deleteNode(TreeNode* r, int v) {
//        // base case 
//        if (r == NULL) {
//            return NULL;
//        }
//        // If the key to be deleted is smaller than the root's key, 
//        // then it lies in left subtree 
//        else if (v < r->value) {
//            r->left = deleteNode(r->left, v);
//        }
//        // If the key to be deleted is greater than the root's key, 
//        // then it lies in right subtree 
//        else if (v > r->value) {
//            r->right = deleteNode(r->right, v);
//        }
//        // if key is same as root's key, then This is the node to be deleted 
//        else {
//            // node with only one child or no child 
//            if (r->left == NULL) {
//                TreeNode* temp = r->right;
//                delete r;
//                return temp;
//            }
//            else if (r->right == NULL) {
//                TreeNode* temp = r->left;
//                delete r;
//                return temp;
//            }
//            else {
//                // node with two children: Get the inorder successor (smallest 
//                // in the right subtree) 
//                TreeNode* temp = minNode(r->right);
//                // Copy the inorder successor's content to this node 
//                r->value = temp->value;
//                // Delete the inorder successor 
//                r->right = deleteNode(r->right, temp->value);
//                //deleteNode(r->right, temp->value); 
//            }
//        }
//        return r;
//    }
//
//};
//
//int main() {
//    BST obj;
//    int option, val;
//
//    do {
//        cout << "\tWhat operation do you want to perform? " <<
//            " \n\tSelect Option number. Enter 0 to exit." << endl;
//        cout << "\t1. Insert Node" << endl;
//        cout << "\t2. Search Node" << endl;
//        cout << "\t3. Delete Node" << endl;
//        cout << "\t4. Print" << endl;
//        cout << "\t5. Minimum" << endl;
//        cout << "\t6. Find Parent:" << endl;
//        cout << "\t7. Clear Screen" << endl;
//        cout << "\t0. Exit Program" << endl;
//
//        cout << "\n\tEnter Option:";
//        cin >> option;
//        //Node n1;
//        TreeNode* new_node = new TreeNode();
//
//        switch (option) {
//        case 0:
//            break;
//        case 1:
//            cout << "\tINSERT" << endl;
//            cout << "\tEnter VALUE of TREE NODE to INSERT in BST: ";
//            cin >> val;
//            new_node->value = val;
//            obj.insertNode(new_node);
//            cout << endl;
//            break;
//
//        case 2:
//            cout << "\tSEARCH" << endl;
//            cout << "\tEnter VALUE of TREE NODE to SEARCH in BST: ";
//            cin >> val;
//            //new_node = obj.iterativeSearch(val);
//            new_node = obj.recursiveSearch(obj.root, val);
//            if (new_node != NULL) {
//                cout << "\tValue found" << endl;
//            }
//            else {
//                cout << "\tValue NOT found" << endl;
//            }
//            break;
//        case 3:
//            cout << "\tDELETE" << endl;
//            cout << "\tEnter VALUE of TREE NODE to DELETE in BST: ";
//            cin >> val;
//            new_node = obj.iterativeSearch(val);
//            if (new_node != NULL) {
//                obj.deleteNode(obj.root, val);
//                cout << "\tValue Deleted" << endl;
//            }
//            else {
//                cout << "\tValue NOT found" << endl;
//            }
//            break;
//        case 4:
//            cout << "\tPRINT 2D: " << endl;
//            obj.print2D(obj.root, 5);
//            cout << endl;
//            cout << "\tINORDER: \n";
//            obj.inorder(obj.root);
//            cout << endl;
//            break;
//        case 5:
//            cout << "\tMINIMUM:" << endl;
//            new_node = obj.minNode(obj.root);
//            cout << new_node->value << endl;
//            break;
//        case 6:
//            cout << "\tPARENT:" << endl;
//            new_node = obj.getParent(obj.root, val);
//            if (new_node != nullptr) {
//                cout << "\tParent found:" << new_node->value << endl;
//            }
//            else {
//                cout << "\tParent not found." << endl;
//            }
//            break;
//        case 7:
//            system("cls");
//            break;
//        default:
//            cout << "\tEnter Proper Option number " << endl;
//        }
//
//    } while (option != 0);
//
//    return 0;
//}
