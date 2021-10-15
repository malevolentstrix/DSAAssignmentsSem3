// C++ program for implementation of KMP pattern searching
// algorithm
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int sumval[100];
int longest[100];
int place[100];
int computeLPSArray(string pat, int M, int *lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(string pat, string txt, int iterator)
{
	int M = pat.length();
	int N = txt.length();

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M], sum = 0;

	// Preprocess the pattern (calculate lps[] array)
	sum = computeLPSArray(pat, M, lps);
	int previous = 0, p4 = 0, place = -1, flag = 0;
	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			//printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}
		if (j > previous)
		{

			previous = j;
			place = i - j;
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i])
		{
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	if (place != -1)
	{
		for (int ikr = 0; ikr < M; ikr++)
		{
			if (place + ikr < N)
			{
				if (pat[ikr] == txt[place + ikr])
				{
					p4++;
					flag++;
				}
				else if (flag != 0)
				{
					break;
				}
			}
		}
	}        sumval[iterator] = sum;
        ::longest[iterator] = p4;
        ::place[iterator] = place;
        iterator = iterator + 1;
}

// Fills lps[] for given patttern pat[0..M-1]
int computeLPSArray(string pat, int M, int *lps)
{
	// length of the previous longest prefix suffix
	int len = 0;
	int sum = 0;
	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
			sum = sum + 1;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0)
			{
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	return sum;
}

// Driver program to test above function
int main()
{
	string patternthaa, textthaa, totalnumber;
	getline(cin, totalnumber);
	int numberoflines = stoi(totalnumber);
	for (int i = 0; i < numberoflines; i++)
	{
		getline(cin, textthaa);
		getline(cin, patternthaa);
		std::transform(textthaa.begin(), textthaa.end(), textthaa.begin(), ::toupper);
		std::transform(patternthaa.begin(), patternthaa.end(), patternthaa.begin(), ::toupper);
		KMPSearch(patternthaa, textthaa, i);
	}
	for (int j = 0; j < numberoflines; j++) {
            cout<<::sumval[j] << " ";
            cout<<::longest[j] << " ";
            cout<<::place[j]<< endl;
        }
	return 0;
}
