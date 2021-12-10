#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

// function to add edge to the graph
void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

// Function to perform BFS on the graph
void bfs(int start)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);

    // Set source as visited
    visited[start] = true;

    int vis;
    while (!q.empty())
    {
        vis = q[0];

        // Print the current node
        cout << vis << " ";
        q.erase(q.begin());

        // For every adjacent vertex to the current vertex
        for (int i = 0; i < adj[vis].size(); i++)
        {
            if (adj[vis][i] == 1 && (!visited[i]))
            {

                // Push the adjacent node to the queue
                q.push_back(i);

                // Set
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int vertexPairOne;
    int vertexPairTwo;
    string numberOfVertices;
    string eachLine;
    string wordSplitter;
    string optionArguments;
    int degree = 0;
    getline(cin, numberOfVertices);
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
        // cout << "lsk" << eachLineIntoWords[5] << " " << eachLineIntoWords[4] << " " << eachLineIntoWords[3];
        for (int j = 2; eachLineIntoWords[j] != "\0"; j++)
        {
            // cout<<"kolam"<<eachLineIntoWords[j];
            int assignValue = eachLineIntoWords[j][0];
            // cout<<assignValue;
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
                // cout << i - 64 << "     " << j - 64 << "     " << adjacencyMatrix[i][j] << endl;
                addEdge(i - 65, j - 65);
            }
        }
    }
    cout << endl;
    bfs(0);
    cout << endl;
    cout <<endl;
    // string choiceProceed;
    // getline(cin, choiceProceed);

    for (int i = 65; i <= 64 + stoi(numberOfVertices); i++)
    {
        for (int j = 65; j <= 64 + stoi(numberOfVertices); j++)
        {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << endl;
    }
    return 0;
}