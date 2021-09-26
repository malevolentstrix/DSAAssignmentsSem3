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

int sumvariable = 0, numbervariable = 0;
int maximumAmongTwo(int a, int b);
int checkDifferenceBetweenNodeHeights(Node *N);
int sumOfKeys(Node *root);
int sumOfKeysCaller(Node *root);
int totalNumberOfNodes(Node *root);
int totalNumberOfNodesCaller(Node *root);
int heightOfTheNode(Node *N);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
Node *insertNewNode(Node *node, int key);
Node *minValueNode(Node *node);
Node *maxValueNode(Node *node);
Node *deleteNode(Node *root, int key);
Node *searchNodeForKey(Node *root, int key);

int main()
{
    Node *root = NULL;
    string numberOfLines, eachLine;
    int integerInsert, integerDelete, lastLineInteger;
    getline(cin, numberOfLines);
    int numberOfLinesInteger = stoi(numberOfLines);
    for (int i = 0; i < numberOfLinesInteger; i++)
    {
        getline(cin, eachLine);
        stringstream ss(eachLine);
        string wordSplitter;
        string eachLineSplitIntoWords[1000];
        for (int j = 0; ss >> wordSplitter; j++)
        {
            eachLineSplitIntoWords[j] = wordSplitter;
        }

        if ((eachLineSplitIntoWords[0].compare("A")) == 0)
        {
            for (int iterator = 1; eachLineSplitIntoWords[iterator].compare("\0") != 0; iterator++)
            {

                integerInsert = stoi(eachLineSplitIntoWords[iterator]);
                root = insertNewNode(root, integerInsert);
            }
        }
        else if ((eachLineSplitIntoWords[0].compare("R")) == 0)
        {
            for (int iterator = 1; eachLineSplitIntoWords[iterator].compare("\0") != 0; iterator++)
            {

                integerDelete = stoi(eachLineSplitIntoWords[iterator]);
                root = deleteNode(root, integerDelete);
            }
        }
        else
        {
            for (int iterator = 0; eachLineSplitIntoWords[iterator].compare("\0") != 0; iterator++)
            {
                lastLineInteger = stoi(eachLineSplitIntoWords[iterator]);
                Node *thisisit = searchNodeForKey(root, lastLineInteger);
                if (thisisit != NULL)
                {
                    int heightofkey = heightOfTheNode(thisisit);
                    cout << heightofkey;
                    cout << " " << minValueNode(thisisit)->key;
                    cout << " " << maxValueNode(thisisit)->key;
                    int sum = sumOfKeysCaller(thisisit);
                    int totalNumberOfNodes = totalNumberOfNodesCaller(thisisit);
                    double average = (sum * 1.0) / totalNumberOfNodes;
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

int heightOfTheNode(Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    int heightOfTheNode = N->height;
    return heightOfTheNode;
}

int maximumAmongTwo(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
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

    y->height = maximumAmongTwo(heightOfTheNode(y->left), heightOfTheNode(y->right)) + 1;
    x->height = maximumAmongTwo(heightOfTheNode(x->left), heightOfTheNode(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maximumAmongTwo(heightOfTheNode(x->left), heightOfTheNode(x->right)) + 1;
    y->height = maximumAmongTwo(heightOfTheNode(y->left), heightOfTheNode(y->right)) + 1;

    return y;
}

int checkDifferenceBetweenNodeHeights(Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return heightOfTheNode(N->left) - heightOfTheNode(N->right);
}

Node *insertNewNode(Node *node, int key)
{

    if (node == NULL)
    {
        return (newNode(key));
    }

    if (key < node->key)
    {
        node->left = insertNewNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insertNewNode(node->right, key);
    }
    else
    {
        return node;
    }

    node->height = 1 + maximumAmongTwo(heightOfTheNode(node->left), heightOfTheNode(node->right));

    int balance = checkDifferenceBetweenNodeHeights(node);

    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

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
    {
        current = current->left;
    }
    return current;
}

Node *maxValueNode(Node *node)
{
    Node *current = node;

    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node *deleteNode(Node *root, int key)
{

    if (root == NULL)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
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
    {
        return root;
    }
    root->height = 1 + maximumAmongTwo(heightOfTheNode(root->left), heightOfTheNode(root->right));

    int balance = checkDifferenceBetweenNodeHeights(root);

    if (balance > 1 && checkDifferenceBetweenNodeHeights(root->left) >= 0)
    {
        return rightRotate(root);
    }

    if (balance > 1 && checkDifferenceBetweenNodeHeights(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && checkDifferenceBetweenNodeHeights(root->right) <= 0)
    {
        return leftRotate(root);
    }

    if (balance < -1 && checkDifferenceBetweenNodeHeights(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int sumOfKeys(Node *root)
{
    if (root != NULL)
    {
        sumvariable = sumvariable + root->key;

        sumOfKeys(root->left);
        sumOfKeys(root->right);
    }
    return sumvariable;
}

int sumOfKeysCaller(Node *root)
{
    sumvariable = 0;
    return sumOfKeys(root);
}

int totalNumberOfNodes(Node *root)
{
    if (root != NULL)
    {
        numbervariable = numbervariable + 1;

        totalNumberOfNodes(root->left);
        totalNumberOfNodes(root->right);
    }
    return numbervariable;
}

int totalNumberOfNodesCaller(Node *root)
{
    numbervariable = 0;
    return totalNumberOfNodes(root);
}

Node *searchNodeForKey(Node *root, int key)
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
