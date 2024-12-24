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
    TreeNode* findLCA(TreeNode *root, int n1, int n2) {
        if (root == nullptr )
        {
            return nullptr;
        }
        if (n1 < root->val && n2 < root->val) {
            return findLCA(root->left, n1, n2);
        }
        if (n1 > root->val && n2 > root->val) {
            return findLCA(root->right, n1, n2);
        }
        return root;
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
    int n1 = 2, n2 = 4;
    TreeNode* lca = bst.findLCA(bst.root, n1, n2);

    if (lca != nullptr) {
        cout << "The LCA of " << n1 << " and " << n2 << " is: " << lca->val << endl;
    }
    else {
        cout << "LCA not found." << endl;
    }

 }
