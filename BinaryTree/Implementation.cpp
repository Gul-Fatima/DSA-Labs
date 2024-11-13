#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    // Constructor
    BinaryTree() : root(nullptr) {}

    // Methods
    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;  // Assign newNode here
                return;
            }
            else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;  // Assign newNode here
                return;
            }
            else {
                q.push(current->right);
            }
        }
    }

    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        postorderTraversal(root);  // Call the correct function here
        cout << endl;
    }

    bool checkMirror(Node* root) {
        while (root != nullptr) {
            if (root->left != root->right) {
                return false;
            }
            checkMirror(root->left);
            checkMirror(root->right);
        }
        return true;
    }

private:
    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->val << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->val << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->val << " ";
    }


};

int main() {
    BinaryTree tree;

    for (int i = 1; i < 7; i++) {
        tree.insert(i);
    }

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    return 0;
}
