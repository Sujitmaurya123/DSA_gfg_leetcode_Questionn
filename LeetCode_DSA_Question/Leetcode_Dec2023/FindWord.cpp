/*
1160. Find Words That Can Be Formed by Characters


You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.



Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> counts(26, 0);

        // Step 1: Initialize Character Counts Array
        for (char ch : chars)
        {
            counts[ch - 'a']++;
        }

        int result = 0;

        // Step 3: Check Words
        for (const std::string &word : words)
        {
            if (canForm(word, counts))
            {
                // Step 4: Calculate Lengths
                result += word.length();
            }
        }

        return result;
    }

    bool canForm(const std::string &word, std::vector<int> &counts)
    {
        std::vector<int> c(26, 0);

        // Step 2: Update Counts Array
        for (char ch : word)
        {
            int x = ch - 'a';
            c[x]++;
            if (c[x] > counts[x])
            {
                return false;
            }
        }

        return true;
    }
};