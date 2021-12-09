#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

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
            //cout<<assignValue;
            adjacencyMatrix[indexForCurrentLine][assignValue] = stoi(eachLineIntoWords[j+1]);
            adjacencyMatrix[assignValue][indexForCurrentLine] = stoi(eachLineIntoWords[j+1]);
            j++;
        }
    }

    // string choiceProceed;
    // getline(cin, choiceProceed);

    for (int i = 65; i <= 64+stoi(numberOfVertices); i++)
    {
        for (int j = 65; j <= 64+stoi(numberOfVertices); j++)
        {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << endl;
    }
    return 0;
}