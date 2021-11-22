#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string numberOfVertices;
    string eachLine;
    string wordSplitter;
    int degree = 0;
    int adjacencyMatrix[100][100];
    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }

    getline(cin, numberOfVertices);
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
    switch (stoi(choiceProceed))
    {
    case 1:
        string optionArguments;
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
            for (int k = 1; k < 100; k++)
            {
                if (adjacencyMatrix[k][stoi(argumentsIntoWords[j])] != 0)
                {
                    degree = degree + 1;
                }
            }
            cout << degree << " ";
            degree = 0;
        }
    }

    cout << endl;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}