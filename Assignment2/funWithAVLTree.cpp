#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//JITHIN JOHN
//AM.EN.U4AIE20135

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
Node *performRightRotate(Node *y);
Node *performLeftRotate(Node *x);
Node *insertNewNode(Node *node, int key);
Node *minimumValueNode(Node *node);
Node *maximumValueNode(Node *node);
Node *deleteNode(Node *root, int key);
Node *searchNodeForKey(Node *root, int key);
Node *newNode(int key);

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
                Node *foundObject = searchNodeForKey(root, lastLineInteger);
                if (foundObject != NULL)
                {
                    int heightofkey = heightOfTheNode(foundObject);
                    cout << heightofkey;
                    cout << " " << minimumValueNode(foundObject)->key;
                    cout << " " << maximumValueNode(foundObject)->key;
                    int sum = sumOfKeysCaller(foundObject);
                    int totalNumberOfNodes = totalNumberOfNodesCaller(foundObject);
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

int checkDifferenceBetweenNodeHeights(Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    int difference = heightOfTheNode(N->left) - heightOfTheNode(N->right);
    return difference;
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

int heightOfTheNode(Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    int heightOfTheNode = N->height;
    return heightOfTheNode;
}

Node *performRightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maximumAmongTwo(heightOfTheNode(y->left), heightOfTheNode(y->right)) + 1;
    x->height = maximumAmongTwo(heightOfTheNode(x->left), heightOfTheNode(x->right)) + 1;

    return x;
}

Node *performLeftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maximumAmongTwo(heightOfTheNode(x->left), heightOfTheNode(x->right)) + 1;
    y->height = maximumAmongTwo(heightOfTheNode(y->left), heightOfTheNode(y->right)) + 1;

    return y;
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

    if (balance > 1)
    {
        if (key < node->left->key)
        {
            return performRightRotate(node);
        }
    }
    if (balance < -1)
    {
        if (key > node->right->key)
        {
            return performLeftRotate(node);
        }
    }

    if (balance > 1)
    {
        if (key > node->left->key)
        {
            node->left = performLeftRotate(node->left);
            return performRightRotate(node);
        }
    }

    if (balance < -1)
    {
        if (key < node->right->key)
        {
            node->right = performRightRotate(node->right);
            return performLeftRotate(node);
        }
    }

    return node;
}

Node *minimumValueNode(Node *node)
{
    Node *current = node;

    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *maximumValueNode(Node *node)
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
            Node *temp = minimumValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
    {
        return root;
    }
    root->height = 1 + maximumAmongTwo(heightOfTheNode(root->left), heightOfTheNode(root->right));

    int balance = checkDifferenceBetweenNodeHeights(root);

    if (balance > 1)
    {
        if (checkDifferenceBetweenNodeHeights(root->left) >= 0)
        {
            return performRightRotate(root);
        }
    }

    if (balance > 1)
    {
        if (checkDifferenceBetweenNodeHeights(root->left) < 0)
        {
            root->left = performLeftRotate(root->left);
            return performRightRotate(root);
        }
    }

    if (balance < -1)
    {
        if (checkDifferenceBetweenNodeHeights(root->right) <= 0)
        {
            return performLeftRotate(root);
        }
    }

    if (balance < -1)
    {
        if (checkDifferenceBetweenNodeHeights(root->right) > 0)
        {
            root->right = performRightRotate(root->right);
            return performLeftRotate(root);
        }
    }

    return root;
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

        if (current->key < key)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    return current;
}

Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
