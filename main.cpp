#include <ctime>
#include <cstdlib>
#include <iostream>


using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* insert_node(Node* node, int value) {
        if (node == NULL) {
            node = new Node;
            node->value = value;
            node->left = NULL;
            node->right = NULL;
        } else if (value < node->value) {
            node->left = insert_node(node->left, value);
        } else {
            node->right = insert_node(node->right, value);
        }
        return node;
    }

    void inorder_traversal(Node* node) {
        if (node != NULL) {
            inorder_traversal(node->left);
            cout << node->value << " ";
            inorder_traversal(node->right);
        }
    }

    void preorder_traversal(Node* node) {
        if (node != NULL) {
            cout << node->value << " ";
            preorder_traversal(node->left);
            preorder_traversal(node->right);
        }
    }

    void postorder_traversal(Node* node) {
        if (node != NULL) {
            postorder_traversal(node->left);
            postorder_traversal(node->right);
            cout << node->value << " ";
        }
    }

    int find_depth(Node* node) {
        if (node == NULL) {
            return 0;
        } else {
            int left_depth = find_depth(node->left);
            int right_depth = find_depth(node->right);
            if (left_depth > right_depth) {
                return (left_depth + 1);
            } else {
                return (right_depth + 1);
            }
        }
    }

    Node* search_node(Node* node, int value) {
        if (node == NULL || node->value == value) {
            return node;
        }
        if (value < node->value) {
            return search_node(node->left, value);
        } else {
            return search_node(node->right, value);
        }
    }

public:
    BST() {
        root = NULL;
    }

    void preorder_traversal() {
        preorder_traversal(root);
    }

    void postorder_traversal() {
        postorder_traversal(root);
    }

    int find_depth() {
        return find_depth(root);
    }
    
    void insert(int value) {
        root = insert_node(root, value);
    }

    void inorder_traversal() {
        inorder_traversal(root);
    }

    Node* search(int value) {
        return search_node(root, value);
    }
};

int main() {
    srand(time(NULL));

    BST tree;
    int n;

    cout << "Введите количество узлов в дереве: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value = rand() % 100;
        tree.insert(value);
    }

    cout << "Прямой обход: ";
    tree.inorder_traversal();
    cout << endl;

    cout << "Обратный обход: ";
    tree.preorder_traversal();
    cout << endl;

    cout << "Симметричный обход: ";
    tree.postorder_traversal();
    cout << endl;

    cout << "Глубинa дерева: " << tree.find_depth();
    int value;
    cout << "Введите элемент для поиска: ";
    cin >> value;
    Node* node = tree.search(value);
    if (node != NULL) {
        cout << "Элемент найден: " << node->value << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
}

