#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

class unionfind
{
private:
    std::vector<int> parent;
    std::vector<int> childern;
    std::vector<int> rank;

public:
    unionfind(int size);
    virtual int numberofnodes(int nodesinthiselement);
    virtual int findtheroot(int nodesinthiselement);
    virtual int numberoftrees(std::vector<int> &elements);
    virtual int find(int p);
    virtual int depth(int p);
    virtual int siblings(int p, std::vector<int> &elements);
    virtual void union_Keyword(int p, int q);
};

unionfind::unionfind(int size)
{
    parent = std::vector<int>(size);
    childern = std::vector<int>(size);
    rank = std::vector<int>(size);
    for (int i = 0; i < size; i++)
    {
        parent[i] = i;
        childern[i] = 1;
        rank[i] = 0;
    }
}

int unionfind::numberofnodes(int nodesinthiselement)
{
    return childern[find(nodesinthiselement)];
}

int unionfind::findtheroot(int nodesinthiselement)
{
    return find(nodesinthiselement);
}

int unionfind::numberoftrees(std::vector<int> &elements)
{
    int countofthedisjointsets = 0;
    for (int i = 0; i < elements.size(); i++)
    {
        if (find(elements[i]) == elements[i])
        {
            countofthedisjointsets = countofthedisjointsets + 1;
        }
    }
    return countofthedisjointsets;
}

int unionfind::find(int p)
{
    while (p != parent[p])
    {
        p = parent[p];
    }
    return p;
}

int unionfind::depth(int p)
{
    int depthcount = 0;
    while (p != find(p))
    {
        depthcount = depthcount + 1;
        p = parent[p];
    }
    return depthcount;
}

int unionfind::siblings(int p, std::vector<int> &elements)
{
    int siblno = 0;
    for (int i = 0; i < elements.size(); i++)
    {
        if (find(p) == find(elements[i]) && depth(p) == depth(elements[i]))
        {
            siblno = siblno + 1;
        }
    }
    return (siblno - 1);
}

void unionfind::union_Keyword(int p, int q)
{
    int i = find(p);
    int j = find(q);
    if (i == j)
    {
        return;
    }
    else if (rank[i] < rank[j])
    {
        parent[i] = j;
        childern[j] += childern[i];
    }
    else if (rank[i] > rank[j])
    {
        parent[j] = i;
        childern[i] += childern[j];
    }
    else
    {
        if (j > i)
        {
            int tempvar = j;
            j = i;
            i = tempvar;
        }
        parent[j] = i;
        childern[i] += childern[j];
        rank[i]++;
    }
}

int main()
{
    unionfind *object = new unionfind(200);
    std::string line1;
    std::string wordSplitter;
    getline(std::cin, line1);
    std::string line2;
    getline(std::cin, line2);
    std::stringstream ssline1(line1);
    std::string arrOfStr1[1000];

    for (int j = 0; ssline1 >> wordSplitter; j++)
    {
        arrOfStr1[j] = wordSplitter;
    }

    std::stringstream ssline2(line2);
    std::string arrOfStr2[1000];

    for (int j = 0; ssline2 >> wordSplitter; j++)
    {
        arrOfStr2[j] = wordSplitter;
    }
    int siz = std::stoi(arrOfStr1[0]);
    std::vector<int> elements(siz);
    for (int i = 1; arrOfStr1[i] != "\0"; i++)
    {
        elements[i - 1] = std::stoi(arrOfStr1[i]);
    }
    for (int i = 1; arrOfStr2[i] != "\0"; i = i + 2)
    {
        object->union_Keyword(std::stoi(arrOfStr2[i]), std::stoi(arrOfStr2[i + 1]));
    }
    std::string eachline;
    getline(std::cin, eachline);

    std::stringstream sseachLine(eachline);
    std::string eachLineIntoWords[1000];

    for (int j = 0; sseachLine >> wordSplitter; j++)
    {
        eachLineIntoWords[j] = wordSplitter;
    }
    if (eachLineIntoWords[0] == "N")
    {
        std::wcout << object->numberoftrees(elements) << std::endl;
    }
    else if (eachLineIntoWords[0] == "Z")
    {
        for (int i = 2; eachLineIntoWords[i] != "\0"; i++)
        {
            std::wcout << object->numberofnodes(std::stoi(eachLineIntoWords[i]));
            std::wcout << L" ";
        }
    }
    else if (eachLineIntoWords[0] == "F")
    {
        for (int i = 2; eachLineIntoWords[i] != "\0"; i++)
        {
            std::wcout << object->find(std::stoi(eachLineIntoWords[i]));
            std::wcout << L" ";
        }
    }
    else if (eachLineIntoWords[0] == "D")
    {
        for (int i = 2; eachLineIntoWords[i] != "\0"; i++)
        {
            std::wcout << object->depth(std::stoi(eachLineIntoWords[i]));
            std::wcout << L" ";
        }
    }
    else if (eachLineIntoWords[0] == "S")
    {
        for (int i = 2; eachLineIntoWords[i] != "\0"; i++)
        {
            std::wcout << object->siblings(std::stoi(eachLineIntoWords[i]), elements);
            std::wcout << L" ";
        }
    }

    return 0;
}