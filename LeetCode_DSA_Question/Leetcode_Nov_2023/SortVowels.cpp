/*
2785. Sort Vowels in a String

Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.



Example 1:

Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
Example 2:

Input: s = "lYmpH"
Output: "lYmpH"
Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".
*/

#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
class Solution
{
public:
    const string vowels = "AEIOUaeiou";
    int freq[10] = {0};
    vector<int> pos;
    void isVowel(char c, int idx)
    {
        int i = vowels.find(c);
        if (i != -1)
        {
            freq[i]++;
            pos.push_back(idx);
        }
    }
    void print(auto &c)
    {
        for (int i : c)
            cout << i << ", ";
        cout << endl;
    }

    string sortVowels(string s)
    {
        int n = s.size();
#pragma unroll
        for (int i = 0; i < n; i++)
            isVowel(s[i], i);
        //    print(pos);
        int count = 0, v = freq[0], j = 0;
#pragma unroll
        for (int i : pos)
        {
            while (count >= v)
                v += freq[++j];
            s[i] = vowels[j];
            count++;
        }
        return s;
    }
};
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();