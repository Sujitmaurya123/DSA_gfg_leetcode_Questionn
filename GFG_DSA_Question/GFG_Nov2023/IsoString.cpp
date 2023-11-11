/*
Isomorphic Strings


GfG Weekly + You = Perfect Sunday Evenings!
Register for free now

banner
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.

If the characters in str1 can be changed to get str2, then two strings, str1 and str2, are isomorphic. A character must be completely swapped out for another character while maintaining the order of the characters. A character may map to itself, but no two characters may map to the same character.

Example 1:

Input:
str1 = aab
str2 = xxy
Output:
1
Explanation:
There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.
Example 2:

Input:
str1 = aab
str2 = xyz
Output:
0
Explanation:
There are two different characters in aab but there are three different charactersin xyz. So there won't be one to one mapping between str1 and str2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {

        // Your code here
        if (str1.length() != str2.length())
            return false;

        unordered_map<char, char> mp1, mp2;

        for (int i = 0; i < 26; i++)
            mp1[i + 'a'] = i + 'a';

        for (int i = 0; i < str1.length(); i++)
        {

            char v1 = mp1[str1[i]];

            char v2 = str2[i];

            if (v1 != v2)
            {

                if (v1 == str1[i])
                {

                    if (mp2.find(v2) != mp2.end())
                        return false; // as every letter can be used once only

                    mp1[v1] = v2;

                    mp2[v2]++;
                }

                else
                {

                    return false;
                }
            }
        }

        return true;
    }
};