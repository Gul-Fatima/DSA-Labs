#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};

class BinarySearchTree {
public:
    int sum = 0;
    TreeNode* root;
    BinarySearchTree() : root(NULL) {}

    void insert(int key) {
        root = insertRec(root, key);
    }
    void deleteNode(int key) {
        root = deleteRec(root, key);
    }
    void printSum() {
        cout << "Sum is:" << Sum(root);
    }
private:
    TreeNode* insertRec(TreeNode* node, int key) {
        if (node == NULL)
            return new TreeNode(key);

        if (key < node->val)
            node->left = insertRec(node->left, key);
        else if (key > node->val)
            node->right = insertRec(node->right, key);

        return node;
    }
    TreeNode* deleteRec(TreeNode* node, int key) {
        if (node == NULL)
            return node;

        if (key < node->val)
            node->left = deleteRec(node->left, key);
        else if (key > node->val)
            node->right = deleteRec(node->right, key);
        else {
            if (node->left == NULL) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteRec(node->right, temp->val);
        }
        return node;
    }
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
    int Sum(TreeNode* root) {
        if (root != NULL) {
            sum += root->val;
            Sum(root->left);
            Sum(root->right);
        }
        return sum;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(6);
    bst.insert(8);
    bst.printSum();
}
