//.h file code:

#include <string>
#include <vector>
#include <iostream>

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
	static void main(std::vector<std::wstring> &args);
};

//Helper class added by Java to C++ Converter:

#include <string>
#include <vector>

int main(int argc, char **argv)
{
    std::vector<std::wstring> args(argv + 1, argv + argc);
    unionfind::main(args);
}

//.cpp file code:

#include "snippet.h"

using Scanner = java::util::Scanner;

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

void unionfind::main(std::vector<std::wstring> &args)
{
	unionfind *object = new unionfind(200);
	Scanner *in = new Scanner(System::in);
	std::wstring line1 = in->nextLine();
	std::wstring line2 = in->nextLine();
	std::vector<std::wstring> arrOfStr1 = line1.split(L" ");
	std::vector<std::wstring> arrOfStr2 = line2.split(L" ");
	int siz = std::stoi(arrOfStr1[0]);
	std::vector<int> elements(siz);
	for (int i = 1; i <= arrOfStr1.size() - 1; i++)
	{
		elements[i - 1] = std::stoi(arrOfStr1[i]);
	}
	for (int i = 1; i <= arrOfStr2.size() - 1; i = i + 2)
	{
		object->union_Keyword(std::stoi(arrOfStr2[i]), std::stoi(arrOfStr2[i + 1]));
	}
	std::wstring eachline;
	eachline = in->nextLine();
	std::vector<std::wstring> line = eachline.split(L" ");
	if (line[0] == L"N")
	{
		std::wcout << object->numberoftrees(elements) << std::endl;
	}
	else if (line[0] == L"Z")
	{
		for (int i = 2; i < line.size(); i++)
		{
			std::wcout << object->numberofnodes(std::stoi(line[i]));
			std::wcout << L" ";
		}
	}
	else if (line[0] == L"F")
	{
		for (int i = 2; i < line.size(); i++)
		{
			std::wcout << object->find(std::stoi(line[i]));
			std::wcout << L" ";
		}
	}
	else if (line[0] == L"D")
	{
		for (int i = 2; i < line.size(); i++)
		{
			std::wcout << object->depth(std::stoi(line[i]));
			std::wcout << L" ";
		}
	}
	else if (line[0] == L"S")
	{
		for (int i = 2; i < line.size(); i++)
		{
			std::wcout << object->siblings(std::stoi(line[i]), elements);
			std::wcout << L" ";
		}
	}

	delete in;
	delete object;
}