#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 40;
int ids[N] = {
    1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,
    1011,1012,1013,1014,1015,1016,1017,1018,1019,1020,
    1021,1022,1023,1024,1025,1026,1027,1028,1029,1030,
    1031,1032,1033,1034,1035,1036,1037,1038,1039,1040
};



struct Node {
    int key;
    Node *left, *right;

    Node(int value) {
        key = value;
        left = right = nullptr;
    }
};

Node* bstInsert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = bstInsert(root->left, key);
    else if (key > root->key)
        root->right = bstInsert(root->right, key);

    return root;
}

int bstSearch(Node* root, int key) {
    int comparisons = 0;

    while (root != nullptr) {
        comparisons++;

        if (root->key == key)
            return comparisons;

        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }

    return comparisons;
}

int bstHeight(Node* root) {
    if (root == nullptr)
        return 0;

    int left = bstHeight(root->left);
    int right = bstHeight(root->right);

    return 1 + max(left, right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}



struct AVLNode {
    int key, height;
    AVLNode *left, *right;

    AVLNode(int value) {
        key = value;
        height = 1;
        left = right = nullptr;
    }
};

int getHeight(AVLNode* n) {
    return n ? n->height : 0;
}

int balanceFactor(AVLNode* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

void updateHeight(AVLNode* n) {
    n->height = 1 + max(getHeight(n->left),
                        getHeight(n->right));
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* t = x->right;

    x->right = y;
    y->left = t;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* t = y->left;

    y->left = x;
    x->right = t;

    updateHeight(x);
    updateHeight(y);

    return y;
}

AVLNode* avlInsert(AVLNode* root, int key) {
    if (!root)
        return new AVLNode(key);

    if (key < root->key)
        root->left = avlInsert(root->left, key);
    else if (key > root->key)
        root->right = avlInsert(root->right, key);
    else
        return root;

    updateHeight(root);

    int balance = balanceFactor(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

   
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int avlSearch(AVLNode* root, int key) {
    int comparisons = 0;

    while (root != nullptr) {
        comparisons++;

        if (root->key == key)
            return comparisons;

        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }

    return comparisons;
}

void avlInorder(AVLNode* root) {
    if (!root) return;
    avlInorder(root->left);
    cout << root->key << " ";
    avlInorder(root->right);
}



const int SIZE = 53;

int hashTable[SIZE];
bool occupied[SIZE] = {false};
int collisions = 0;

int hashFunction(int key) {
    return key % 17;
}

void hashInsert(int key) {
    int index = hashFunction(key);

    while (occupied[index]) {
        collisions++;
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
    occupied[index] = true;
}

int hashSearch(int key) {
    int index = hashFunction(key);
    int comparisons = 0;

    for (int i = 0; i < SIZE; i++) {
        if (!occupied[index])
            return comparisons;

        comparisons++;

        if (hashTable[index] == key)
            return comparisons;

        index = (index + 1) % SIZE;
    }

    return comparisons;
}



int main() {

    Node* bstRoot = nullptr;
    AVLNode* avlRoot = nullptr;

    cout << "STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "=================================\n";

    for (int i = 0; i < N; i++) {
        bstRoot = bstInsert(bstRoot, ids[i]);
        avlRoot = avlInsert(avlRoot, ids[i]);
        hashInsert(ids[i]);
    }

    cout << "\nTotal records inserted: " << N << endl;

    cout << "\nBST INORDER: ";
    inorder(bstRoot);

    cout << "\nBST PREORDER: ";
    preorder(bstRoot);

    cout << "\nBST POSTORDER: ";
    postorder(bstRoot);

    cout << "\n\nAVL INORDER: ";
    avlInorder(avlRoot);

    
    int successfulKey = 1020;

    cout << "\n\nSUCCESSFUL SEARCH: " << successfulKey << endl;

    cout << "BST comparisons: "
         << bstSearch(bstRoot, successfulKey) << endl;

    cout << "AVL comparisons: "
         << avlSearch(avlRoot, successfulKey) << endl;

    cout << "Hash comparisons: "
         << hashSearch(successfulKey) << endl;


    int unsuccessfulKey = 9999;

    cout << "\nUNSUCCESSFUL SEARCH: " << unsuccessfulKey << endl;

    cout << "BST comparisons: "
         << bstSearch(bstRoot, unsuccessfulKey) << endl;

    cout << "AVL comparisons: "
         << avlSearch(avlRoot, unsuccessfulKey) << endl;

    cout << "Hash comparisons: "
         << hashSearch(unsuccessfulKey) << endl;

    cout << "\nEXPERIMENTAL RESULTS\n";
    cout << "BST Height: " << bstHeight(bstRoot) << endl;
    cout << "AVL Height: " << getHeight(avlRoot) << endl;
    cout << "Hashing Collisions: " << collisions << endl;

    cout << "\nINSERTING NEW STUDENT ID: 1050\n";

    bstRoot = bstInsert(bstRoot, 1050);
    avlRoot = avlInsert(avlRoot, 1050);
    hashInsert(1050);

    cout << "New student inserted successfully!\n";

    cout << "BST search comparisons: "
         << bstSearch(bstRoot, 1050) << endl;

    cout << "AVL search comparisons: "
         << avlSearch(avlRoot, 1050) << endl;

    cout << "Hash search comparisons: "
         << hashSearch(1050) << endl;

    cout << "\nPROGRAM COMPLETED SUCCESSFULLY!\n";

    return 0;
}
