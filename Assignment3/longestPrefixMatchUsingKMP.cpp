#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// JITHIN JOHN
// AM.EN.U4AIE20135

//global arrays for storing the failures, longest prefix match and the start locations.
int nonZeroValues[100];
int lengthOfLongestPrefixMatch[100];
int startLocationOfFirstMatch[100];

int formLPSArray(string patternString, int lengthOfThePattern, int *lps);
void searchUsingKMPAlgorithm(string patternString, string textString, int iterator);

int main()
{
	string patternP, textT, totalnumber;
	getline(cin, totalnumber);
	int numberoflines = stoi(totalnumber);
	for (int i = 0; i < numberoflines; i++)
	{
		getline(cin, textT);
		getline(cin, patternP);
		std::transform(textT.begin(), textT.end(), textT.begin(), ::toupper);
		std::transform(patternP.begin(), patternP.end(), patternP.begin(), ::toupper);
		searchUsingKMPAlgorithm(patternP, textT, i);
	}

	for (int iteratorForPatternString = 0; iteratorForPatternString < numberoflines; iteratorForPatternString++)
	{
		cout << ::nonZeroValues[iteratorForPatternString] << " ";
		cout << ::lengthOfLongestPrefixMatch[iteratorForPatternString] << " ";
		cout << ::startLocationOfFirstMatch[iteratorForPatternString] << endl;
	}
	return 0;
}

int formLPSArray(string patternString, int lengthOfThePattern, int *lpsArray)
{

	int lengthTracker = 0;
	int nonZeroValues = 0;
	lpsArray[0] = 0;

	int iteratorForPatternString = 1;
	while (iteratorForPatternString < lengthOfThePattern)
	{
		if (patternString[iteratorForPatternString] == patternString[lengthTracker])
		{
			lengthTracker++;
			lpsArray[iteratorForPatternString] = lengthTracker;
			iteratorForPatternString++;
			nonZeroValues = nonZeroValues + 1;
		}
		else
		{

			if (lengthTracker != 0)
			{
				lengthTracker = lpsArray[lengthTracker - 1];
			}
			else
			{
				lpsArray[iteratorForPatternString] = 0;
				iteratorForPatternString++;
			}
		}
	}
	return nonZeroValues;
}

void searchUsingKMPAlgorithm(string patternString, string textString, int iterator)
{
	int lengthOfThePattern = patternString.length();
	int lengthOfTheText = textString.length();

	int lpsArray[lengthOfThePattern], nonZeroValues = 0;

	nonZeroValues = formLPSArray(patternString, lengthOfThePattern, lpsArray);
	int previous = 0, lengthOfLongestPrefixTracker = 0;
	int startLocationOfFirstMatch = -1, flag = 0;
	int flagForRecurringPattern = 0;
	int iteratorForTextString = 0, iteratorForPatternString = 0;

	while (iteratorForTextString < lengthOfTheText)
	{
		if (patternString[iteratorForPatternString] == textString[iteratorForTextString])
		{
			iteratorForPatternString++;
			iteratorForTextString++;
			if (flagForRecurringPattern == 0)
			{
				startLocationOfFirstMatch = 0;
				flagForRecurringPattern++;
			}
		}

		if (iteratorForPatternString == lengthOfThePattern)
		{
			iteratorForPatternString = lpsArray[iteratorForPatternString - 1];
		}

		if (iteratorForPatternString > previous)
		{
			previous = iteratorForPatternString;
			startLocationOfFirstMatch = iteratorForTextString - iteratorForPatternString;
		}

		else if (iteratorForTextString < lengthOfTheText && patternString[iteratorForPatternString] != textString[iteratorForTextString])
		{

			if (iteratorForPatternString != 0)
			{
				iteratorForPatternString = lpsArray[iteratorForPatternString - 1];
			}
			else
			{
				iteratorForTextString = iteratorForTextString + 1;
			}
		}
	}

	if (startLocationOfFirstMatch != -1)
	{
		for (int lengthOfLongestPrefixIterator = 0; lengthOfLongestPrefixIterator < lengthOfThePattern; lengthOfLongestPrefixIterator++)
		{
			if (startLocationOfFirstMatch + lengthOfLongestPrefixIterator < lengthOfTheText)
			{
				if (patternString[lengthOfLongestPrefixIterator] == textString[startLocationOfFirstMatch + lengthOfLongestPrefixIterator])
				{
					lengthOfLongestPrefixTracker++;
					flag++;
				}
				else if (flag != 0)
				{
					break;
				}
			}
		}
	}
	::nonZeroValues[iterator] = nonZeroValues;
	::lengthOfLongestPrefixMatch[iterator] = lengthOfLongestPrefixTracker;
	::startLocationOfFirstMatch[iterator] = startLocationOfFirstMatch;
	iterator = iterator + 1;
}