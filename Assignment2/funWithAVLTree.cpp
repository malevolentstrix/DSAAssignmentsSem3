
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b);

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}

Node *insert(Node *node, int key)
{

    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *maxValueNode(Node *node)
{
    Node *current = node;

    while (current->right != NULL)
        current = current->right;

    return current;
}

Node *deleteNode(Node *root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {

        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {

            Node *temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int sumvariable = 0;
int sumofnodes(Node *root)
{
    if (root != NULL)
    {
        sumvariable = sumvariable + root->key;
        //cout <<"added"<<sumvariable <<"kazhinju";
        sumofnodes(root->left);
        sumofnodes(root->right);
    }
    return sumvariable;
}
int sumwrap(Node *root)
{
    sumvariable = 0;
    return sumofnodes(root);
}
int numbervariable = 0;
int numberofnodes(Node *root)
{
    if (root != NULL)
    {
        numbervariable = numbervariable + 1;
        //cout <<"added"<<sumvariable <<"kazhinju";
        numberofnodes(root->left);
        numberofnodes(root->right);
    }
    return numbervariable;
}
int numberofnodeswrap(Node *root)
{
    numbervariable = 0;
    return numberofnodes(root);
}
Node *search(Node *root, int key)
{
    Node *current = root;
    while (current != NULL)
    {
        if (current->key == key)
        {
            break;
        }
        current = current->key < key ? current->right : current->left;
    }
    return current;
}
int main()
{
    Node *root = NULL;

    // root = insert(root, 9);
    // root = insert(root, 5);
    // root = insert(root, 10);
    // root = insert(root, 0);
    // root = insert(root, 6);
    // root = insert(root, 11);
    // root = insert(root, -1);
    // root = insert(root, 1);
    // root = insert(root, 2);

    // cout << "Preorder traversal of the "
    //         "constructed AVL tree is \n";
    // preOrder(root);

    // root = deleteNode(root, 10);
    // cout << "\nPreorder traversal after"
    //      << " deletion of 10 \n";
    // preOrder(root);

    string numberOfLines, eachLine;
    int integerInsert, integerDelete, lastLineInteger;
    getline(cin, numberOfLines);
    int numberOfLinesInteger = stoi(numberOfLines);
    for (int i = 0; i < numberOfLinesInteger; i++)
    {
        getline(cin, eachLine);
        stringstream ss(eachLine);
        string word;
        string eachword[1000];
        for (int j = 0; ss >> word; j++)
        {
            eachword[j] = word;
        }

        if ((eachword[0].compare("A")) == 0)
        {
            for (int iterator = 1; eachword[iterator].compare("\0") != 0; iterator++)
            {
                //cout << eachword[iterator];
                integerInsert = stoi(eachword[iterator]);
                root = insert(root, integerInsert);
            }
        }
        else if ((eachword[0].compare("R")) == 0)
        {
            for (int iterator = 1; eachword[iterator].compare("\0") != 0; iterator++)
            {
                //cout << eachword[iterator];
                integerDelete = stoi(eachword[iterator]);
                root = deleteNode(root, integerDelete);
            }
        }
        else
        {
            for (int iterator = 0; eachword[iterator].compare("\0") != 0; iterator++)
            {
                lastLineInteger = stoi(eachword[iterator]);
                Node *thisisit = search(root, lastLineInteger);
                if (thisisit != NULL)
                {
                    int heightofkey = height(thisisit);
                    cout << heightofkey;
                    //preOrder(thisisit);
                    cout << " " << minValueNode(thisisit)->key;
                    cout << " " << maxValueNode(thisisit)->key;
                    int sum = sumwrap(thisisit);
                    int numberofnodes = numberofnodeswrap(thisisit);
                    double average = (sum * 1.0) / numberofnodes;
                    float value = (int)(average * 10 + .5);
                    cout << " " << (float)value / 10 << endl;
                }
                else
                {
                    cout << "-1" << endl;
                }
            }
        }
    }
    return 0;
}