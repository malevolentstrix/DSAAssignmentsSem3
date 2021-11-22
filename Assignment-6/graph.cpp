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
    int adjacencyMatrix[stoi(numberOfVertices) + 1][stoi(numberOfVertices) + 1];
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
        int indexForCurrentLine = stoi(eachLineIntoWords[0]);
        //cout << "lsk" << eachLineIntoWords[5] << " " << eachLineIntoWords[4] << " " << eachLineIntoWords[3];
        for (int j = 2; eachLineIntoWords[j] != "\0"; j++)
        {
            //cout<<"kolam"<<eachLineIntoWords[j];
            adjacencyMatrix[indexForCurrentLine][stoi(eachLineIntoWords[j])] = stoi(eachLineIntoWords[j + 1]);
            adjacencyMatrix[stoi(eachLineIntoWords[j])][indexForCurrentLine] = stoi(eachLineIntoWords[j + 1]);
            j++;
        }
    }

    string choiceProceed;
    getline(cin, choiceProceed);
    //std::cout << "choice" << stoi(choiceProceed) << endl;
    if (stoi(choiceProceed) == 1)
    {

        getline(cin, optionArguments);
        stringstream ssArguments(optionArguments);
        string argumentsIntoWords[1000];

        for (int j = 0; ssArguments >> wordSplitter; j++)
        {
            argumentsIntoWords[j] = wordSplitter;
        }
        for (int j = 1; argumentsIntoWords[j] != "\0"; j++)
        {
            //cout<<argumentsIntoWords[j]<<endl;
            for (int k = 1; k <= stoi(numberOfVertices); k++)
            {
                if (adjacencyMatrix[k][stoi(argumentsIntoWords[j])] != 0)
                {
                    degree = degree + 1;
                }
            }
            std::cout << degree << " ";
            degree = 0;
        }
    }

    else if (stoi(choiceProceed) == 2)
    {
        getline(cin, optionArguments);
        stringstream ssArguments(optionArguments);
        string argumentsIntoWords[1000];

        for (int j = 0; ssArguments >> wordSplitter; j++)
        {
            argumentsIntoWords[j] = wordSplitter;
        }
        for (int j = 1; argumentsIntoWords[j] != "\0"; j = j + 2)
        {
            vertexPairOne = stoi(argumentsIntoWords[j]);
            vertexPairTwo = stoi(argumentsIntoWords[j + 1]);
            std::cout << adjacencyMatrix[vertexPairOne][vertexPairTwo] << " ";
        }
    }

    else if (stoi(choiceProceed) == 3)
    {
        int nonZeroLowerTriangle = 0;
        int i, j;
        for (i = 1; i <= stoi(numberOfVertices); i++)
        {
            for (j = 1; j <= stoi(numberOfVertices); j++)
            {
                if (i >= j)
                {
                    if (adjacencyMatrix[i][j] != 0)
                    {
                        nonZeroLowerTriangle++;
                    }
                }
            }
        }
        cout << nonZeroLowerTriangle;
    }

    else if (stoi(choiceProceed) == 4)
    {
        int cumulativeEdges = 0;
        int i, j;
        for (i = 1; i <= stoi(numberOfVertices); i++)
        {
            for (j = 1; j <= stoi(numberOfVertices); j++)
            {
                if (i >= j)
                {
                    if (adjacencyMatrix[i][j] != 0)
                    {
                        //cout << adjacencyMatrix[i][j]<<endl;
                        cumulativeEdges = cumulativeEdges + adjacencyMatrix[i][j];
                    }
                }
            }
        }
        cout << cumulativeEdges;
    }

    else if (stoi(choiceProceed) == 5)
    {
        int i, j;

        for (i = 1; i <= stoi(numberOfVertices); i++)
        {
            for (j = 1; j <= stoi(numberOfVertices); j++)
            {
                if (i <= j)
                {
                    if (adjacencyMatrix[i][j] != 0)
                    {
                        cout << i << " " << j << " " << adjacencyMatrix[i][j]<<endl;
                    }
                    //cout << endl;
                }
            }
        }
    }
    // std::cout << endl;
    // for (int i = 1; i <= stoi(numberOfVertices); i++)
    // {
    //     for (int j = 1; j <= stoi(numberOfVertices); j++)
    //     {
    //         std::cout << adjacencyMatrix[i][j] << " ";
    //     }
    //     std::cout << endl;
    // }
    return 0;
}