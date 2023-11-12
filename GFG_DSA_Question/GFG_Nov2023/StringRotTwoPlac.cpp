/*
Check if string is rotated by two places

Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating (in any direction) string 'a' by exactly 2 places.

Example 1:

Input:
a = amazon
b = azonam
Output:
1
Explanation:
amazon can be rotated anti-clockwise by two places, which will make it as azonam.
Example 2:

Input:
a = geeksforgeeks
b = geeksgeeksfor
Output:
0
Explanation:
If we rotate geeksforgeeks by two place in any direction, we won't get geeksgeeksfor.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public :
        // Function to check if a string can be obtained by rotating
        // another string by exactly 2 places.
        bool isRotated(string str1, string str2){
            // Your code here
            // Reverse clockwise 1st
            reverse(str1.begin(), str1.end());
reverse(str1.begin(), str1.begin() + 2);
reverse(str1.begin() + 2, str1.end());

if (str1 == str2) // If its equal then return
    return true;

// Reverse anticlockwise by 4 times as it was rotated twice in clockwise
reverse(str1.begin(), str1.begin() + 4);
reverse(str1.begin() + 4, str1.end());
reverse(str1.begin(), str1.end());

return str1 == str2;
}
}
;