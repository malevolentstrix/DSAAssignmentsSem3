#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//JITHIN JOHN
//AM.EN.U4AIE20135

string getTheOutputAsString(string input, int n);

int main()
{
    int t, n, num[100];
    string output[100];
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            std::cin >> num[j];
        }

        std::string str;

        for (int i = 0; i < n; ++i)
        {
            str.push_back('0' + num[i]);
        }

        output[i] = getTheOutputAsString(str, n);
    }

    for (int i = 0; i < t; i++)
    {
        std::cout << output[i] << endl;
    }
    return 0;
}

string getTheOutputAsString(string input, int n)
{
    int i, j;

    for (i = n - 1; i > 0; i--)
    {
        if (input[i] < input[i - 1])
        {
            break;
        }
    }

    if (i == 0)
    {
        return "-1";
    }

    int x = input[i - 1], greatest = i;

    for (j = i; j < n; j++)
    {
        if (input[j] < x && input[j] > input[greatest])
        {
            greatest = j;
        }
    }

    swap(input[greatest], input[i - 1]);
    sort(input.begin() + i, input.begin() + n, greater<char>());

    return input;
}