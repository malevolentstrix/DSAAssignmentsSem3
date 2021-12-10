#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
// JITHIN JOHN
// AM.EN.U4AIE20135

string numberOfVertices;
int currentNodeBFSAlgo[100];
void addEdge(int x, int y);
void bfs(int start);
int sumOfCurrentLevel = 0;

vector<vector<int>> adj;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

struct Node *newNode(int value)
{
    Node *n = new Node;
    n->key = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void printLeafNodes(Node *root);
void printCurrentLevel(Node *root, int level);
int height(Node *node);

struct Node *insertValue(struct Node *root, int value,
                         queue<Node *> &q)
{
    Node *node = newNode(value);
    if (root == NULL)
        root = node;

    else if (q.front()->left == NULL)
        q.front()->left = node;

    else
    {
        q.front()->right = node;
        q.pop();
    }

    q.push(node);
    return root;
}

Node *createTree(int arr[], int n)
{
    Node *root = NULL;
    queue<Node *> q;
    for (int i = 0; i < n; i++)
        root = insertValue(root, arr[i], q);
    return root;
}
void printLevelOrder(Node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
int height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {

        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}
void printCurrentLevel(Node *root, int level)
{

    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        ::sumOfCurrentLevel = ::sumOfCurrentLevel + 1;
    }
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
/////////////////////////////////////////////MAIN///////////////////////////////////////////
int main()
{
    int vertexPairOne;
    int vertexPairTwo;

    string eachLine;
    string wordSplitter;
    string optionArguments;
    int degree = 0;
    getline(cin, numberOfVertices);
    ::currentNodeBFSAlgo[stoi(numberOfVertices)] = 32700;
    int v = stoi(numberOfVertices);
    adj = vector<vector<int>>(v, vector<int>(v, 0));
    int adjacencyMatrix[1000][1000];
    for (int i = 1; i <= stoi(numberOfVertices); i++)
    {
        for (int j = 1; j <= stoi(numberOfVertices); j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < stoi(numberOfVertices); i++)
    {

        getline(cin, eachLine);
        stringstream sseachLine(eachLine);
        string eachLineIntoWords[1000];

        for (int j = 0; sseachLine >> wordSplitter; j++)
        {
            eachLineIntoWords[j] = wordSplitter;
        }
        int indexForCurrentLine = eachLineIntoWords[0][0];

        for (int j = 2; eachLineIntoWords[j] != "\0"; j++)
        {

            int assignValue = eachLineIntoWords[j][0];

            adjacencyMatrix[indexForCurrentLine][assignValue] = stoi(eachLineIntoWords[j + 1]);
            adjacencyMatrix[assignValue][indexForCurrentLine] = stoi(eachLineIntoWords[j + 1]);
            j++;
        }
    }

    adj = vector<vector<int>>(stoi(numberOfVertices), vector<int>(stoi(numberOfVertices), 0));

    for (int i = 65; i <= 64 + stoi(numberOfVertices); i++)
    {
        for (int j = 65; j <= 64 + stoi(numberOfVertices); j++)
        {

            if (adjacencyMatrix[i][j] != 0)
            {

                addEdge(i - 65, j - 65);
            }
        }
    }
    bfs(0);
    // for (int i = 0; ::currentNodeBFSAlgo[i] != 32700; i++)
    // {
    //     std::cout << currentNodeBFSAlgo[i];
    // }

    // std::cout << endl;

    // for (int i = 65; i <= 64 + stoi(numberOfVertices); i++)
    // {
    //     for (int j = 65; j <= 64 + stoi(numberOfVertices); j++)
    //     {
    //         std::cout << adjacencyMatrix[i][j] << " ";
    //     }
    //     std::cout << endl;
    // }

    Node *root = createTree(currentNodeBFSAlgo, stoi(numberOfVertices));

    string choiceProceed;
    getline(cin, choiceProceed);
    if (stoi(choiceProceed) == 1)
    {
        std::cout << height(root) - 1 << " ";
        for (int i = 2; i <= height(root); i++)
        {
            ::sumOfCurrentLevel = 0;

            printCurrentLevel(root, i);
            std::cout << ::sumOfCurrentLevel << " ";
        }
    }
    if (stoi(choiceProceed) == 2)
    {
        // OPTION 2
        printLeafNodes(root);
    }
    // OPTION 3

    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printLeafNodes(Node *root)
{

    if (!root)
        return;

    if (!root->left && !root->right)
    {
        int asciivalofalpha = (root->key)+65;
        char alphatypecast = asciivalofalpha;
        cout << alphatypecast << " ";
        return;
    }

    if (root->left)
        printLeafNodes(root->left);

    if (root->right)
        printLeafNodes(root->right);
}

void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void bfs(int start)
{

    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);

    visited[start] = true;

    int vis;
    int nodeIterator = 0;
    while (!q.empty())
    {
        vis = q[0];

        currentNodeBFSAlgo[nodeIterator] = vis;

        q.erase(q.begin());

        for (int i = 0; i < adj[vis].size(); i++)
        {
            if (adj[vis][i] == 1 && (!visited[i]))
            {

                q.push_back(i);

                visited[i] = true;
            }
        }
        nodeIterator++;
    }
}
