#include <bits/stdc++.h>

using namespace std;
// JITHIN JOHN
// AM.EN.U4AIE20135

int numberOfSuggestions = 0;
unordered_set<string> stringSet;
void ruleOne(string);
void ruleTwo(string);
void ruleThree(string);
void ruleFour(string);
void ruleFive(string);
void ruleEntryFunction(string);

void ruleEntryFunction(string stringToBeChecked)
{
    if (stringSet.find(stringToBeChecked) != stringSet.end())
        cout << "Y ";
    else
    {
        ruleOne(stringToBeChecked);
        ruleTwo(stringToBeChecked);
        ruleThree(stringToBeChecked);
        ruleFour(stringToBeChecked);
        ruleFive(stringToBeChecked);
        cout << numberOfSuggestions << " ";
        numberOfSuggestions = 0;
    }
}

void ruleOne(string stringToBeChecked)
{
    for (int i = 0; i < stringToBeChecked.length(); i++)
    {
        for (char j = 'a'; j <= 'z'; j++)
        {
            string s(1, j);

            if (stringSet.find(stringToBeChecked.substr(0, i).append(s).append(stringToBeChecked.substr(i + 1))) != stringSet.end())
            {

                numberOfSuggestions++;
            }
        }
    }
}

void ruleTwo(string stringToBeChecked)
{
    for (int i = 0; i < stringToBeChecked.length() + 1; i++)
    {
        for (char j = 'a'; j <= 'z'; j++)
        {
            string s(1, j);

            if (stringSet.find(stringToBeChecked.substr(0, i).append(s).append(stringToBeChecked.substr(i))) != stringSet.end())
            {
                numberOfSuggestions++;
            }
        }
    }
}

void ruleThree(string stringToBeChecked)
{
    {
        for (int i = 0; i < stringToBeChecked.length(); i++)
        {
            if (stringSet.find(stringToBeChecked.substr(0, i).append(stringToBeChecked.substr(i + 1))) != stringSet.end())
            {
                numberOfSuggestions++;
            }
        }
    }
}

void ruleFour(string stringToBeChecked)
{
    for (int i = 0; i < stringToBeChecked.length() - 1; i++)
    {
        string s(1, stringToBeChecked[i + 1]);
        string t(1, stringToBeChecked[i]);

        if (stringSet.find(stringToBeChecked.substr(0, i).append(s).append(t).append(stringToBeChecked.substr(i + 2))) != stringSet.end())
        {
            numberOfSuggestions++;
        }
    }
}

void ruleFive(string stringToBeChecked)
{
    for (int i = 0; i < stringToBeChecked.length() + 1; i++)
    {
        if (stringSet.find(stringToBeChecked.substr(0, i)) != stringSet.end())
        {
            if (stringSet.find(stringToBeChecked.substr(i)) != stringSet.end())
            {
                numberOfSuggestions++;
            }
        }
    }
}

int main()
{
    string eachLine;
    for (int i = 0; i < 3; i++)
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
            for (int iterator = 2; eachLineSplitIntoWords[iterator].compare("\0") != 0; iterator++)
            {
                stringSet.insert(eachLineSplitIntoWords[iterator]);
            }
        }
        else if ((eachLineSplitIntoWords[0].compare("D")) == 0)
        {
            for (int iterator = 2; eachLineSplitIntoWords[iterator].compare("\0") != 0; iterator++)
            {
                stringSet.erase(eachLineSplitIntoWords[iterator]);
            }
        }
        else if ((eachLineSplitIntoWords[0].compare("F")) == 0)
        {
            for (int iterator = 2; eachLineSplitIntoWords[iterator].compare("\0") != 0; iterator++)
            {
                ruleEntryFunction(eachLineSplitIntoWords[iterator]);
            }
        }
    }
}