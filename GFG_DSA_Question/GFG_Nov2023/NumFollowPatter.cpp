/*
Number following a pattern

Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.

Example 1:

Input:
D
Output:
21
Explanation:
D is meant for decreasing, so we choose the minimum number among all possible numbers like 21,31,54,87,etc.
Example 2:

Input:
IIDDD
Output:
126543
Explanation:
Above example is self- explanatory,
1 < 2 < 6 > 5 > 4 > 3
  I - I - D - D - D

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string printMinNumberForPattern(string s)
    {
        // code here
        string str;
        stack<int> st;
        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == 'D')
                st.push(i + 1);
            else if (s[i] == 'I' || i == s.length())
            {
                st.push(i + 1);
                while (!st.empty())
                {
                    str.push_back(st.top() + '0');
                    st.pop();
                }
            }
        }
        return str;
    }
};