#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string wordSplitter;
    string sizeOfMatrices;
    string JC;
    string CP;
    string IR;
    string NUM;
    string ssJCIntoWords[1000];
    string ssCPIntoWords[1000];
    string ssIRIntoWords[1000];
    string ssNUMIntoWords[1000];
    getline(cin, sizeOfMatrices);
    stringstream sssizeOfMatrices(sizeOfMatrices);
    string sssizeOfMatricesIntoWords[1000];
    for (int j = 0; sssizeOfMatrices >> wordSplitter; j++)
    {
        sssizeOfMatricesIntoWords[j] = wordSplitter;
    }
    int rowA = stoi(sssizeOfMatricesIntoWords[0]) + 1;
    int rowB = stoi(sssizeOfMatricesIntoWords[1]) + 1;
    int colA = stoi(sssizeOfMatricesIntoWords[1]) + 1;
    int colB = stoi(sssizeOfMatricesIntoWords[2]) + 1;
    int numberOfElementsInRow, starting = 0;
    int matA[rowA][colA];
    int matB[rowB][colB];
    int outProduct[colA][rowB][rowB];
    for (int matrixinfo = 0; matrixinfo < 2; matrixinfo++)
    {
        getline(cin, JC);
        getline(cin, CP);
        getline(cin, IR);
        getline(cin, NUM);

        stringstream ssJC(JC);
        stringstream ssCP(CP);
        stringstream ssIR(IR);
        stringstream ssNUM(NUM);

        for (int j = 0; ssJC >> wordSplitter; j++)
        {
            ssJCIntoWords[j] = wordSplitter;
        }

        for (int j = 0; ssCP >> wordSplitter; j++)
        {
            ssCPIntoWords[j] = wordSplitter;
        }

        for (int j = 0; ssIR >> wordSplitter; j++)
        {
            ssIRIntoWords[j] = wordSplitter;
        }

        for (int j = 0; ssNUM >> wordSplitter; j++)
        {
            ssNUMIntoWords[j] = wordSplitter;
        }

        if (matrixinfo == 0)
        {
            for (int i = 1; i < rowA; i++)
            {
                for (int j = 1; j < colA; j++)
                {
                    matA[i][j] = 0;
                }
            }
        }
        else
        {
            for (int i = 1; i < rowB; i++)
            {
                for (int j = 1; j < colB; j++)
                {
                    matB[i][j] = 0;
                }
            }
        }
        if (matrixinfo == 0)
        {
            starting = 0;
            for (int i = 0; ssCPIntoWords[i + 1].compare("\0") != 0; i++)
            {
                numberOfElementsInRow = stoi(ssCPIntoWords[i + 1]) - stoi(ssCPIntoWords[i]);
                //cout<< stoi(ssCPIntoWords[i + 1]) <<" - "<< stoi(ssCPIntoWords[i])<<endl;
                for (int j = 0; j < numberOfElementsInRow; j++)
                {
                    matA[stoi(ssIRIntoWords[starting + j])][(stoi(ssJCIntoWords[i]))] = stoi(ssNUMIntoWords[starting + j]);

                    //cout <<"pdpti"<<stoi(ssJCIntoWords[i])<<" jdi " << stoi(ssIRIntoWords[starting+j])<<endl;
                    starting++;
                }
            }
        }
        else
        {
            starting = 0;
            for (int i = 0; ssCPIntoWords[i + 1].compare("\0") != 0; i++)
            {
                numberOfElementsInRow = stoi(ssCPIntoWords[i + 1]) - stoi(ssCPIntoWords[i]);
                //cout<< stoi(ssCPIntoWords[i + 1]) <<" - "<< stoi(ssCPIntoWords[i])<<endl;
                for (int j = 0; j < numberOfElementsInRow; j++)
                {
                    matB[stoi(ssIRIntoWords[starting + j])][(stoi(ssJCIntoWords[i]))] = stoi(ssNUMIntoWords[starting + j]);

                    // cout<<endl<<matB[stoi(ssIRIntoWords[starting + j])][(stoi(ssJCIntoWords[i]))]<< endl<<endl<<stoi(ssIRIntoWords[starting + j])<<" "<<(stoi(ssJCIntoWords[i]))<<endl ;
                    //cout <<"pdpti"<<stoi(ssJCIntoWords[i])<<" jdi " << stoi(ssIRIntoWords[starting+j])<<endl;
                    starting++;
                }
            }
        }
    }

    int i, j;
    int matAT[colA][rowA];
    int matBT[colB][rowB];
    for (i = 1; i <= rowB; i++)
    {
        for (j = 1; j <= colB; j++)
        {

            matBT[i][j] = matB[j][i];
        }
    }

    for (i = 1; i <= rowA; i++)
    {
        for (j = 1; j <= colA; j++)
        {
            matAT[i][j] = matA[j][i];
        }
    }

    for (int i = 1; i < colA; i++)
    {
        for (int j = 1; j < rowA; j++)
        {
            cout << matAT[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i < colB; i++)
    {
        for (int j = 1; j < rowB; j++)
        {
            // cout<<"ele"<<i<<" "<< j;
            cout << matBT[i][j] << " ";
        }
        cout << endl;
    }
    int colAT = rowA;
    int colBT = rowB;
    int rowAT = colA;
    int rowBT = colB;
    int sumofprod = 0;

    for (int k = 1; k < colBT; k++)
    {
        for (i = 1; i < rowBT; i++)
        {
            for (j = 1; j <= colBT; j++)
            {
                sumofprod = sumofprod + (matBT[i][k] * matAT[k][j]);
                outProduct[i][j][k] = sumofprod;
                //cout<<"kollam value"<<sumofprod<<endl;
                sumofprod = 0;
            }
            //outProduct[i][j] = sumofprod;
        }
        cout << endl;
        //sumofprod =0;
    }

    for (int k = 1; k < colBT; k++)
    {
        for (i = 1; i < rowBT; i++)
        {
            for (j = 1; j <= colBT; j++)
            {
                cout << outProduct[i][j][k];
                //cout<<"kollam value"<<sumofprod<<endl;
            }
            cout << endl;
            //outProduct[i][j] = sumofprod;
        }
        cout << endl;
    }
    return 0;
}