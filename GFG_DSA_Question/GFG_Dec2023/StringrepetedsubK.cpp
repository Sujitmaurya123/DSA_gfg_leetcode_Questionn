/*
Check if a string is repetition of its substring of k-length

Given a string s, check if it is possible to convert it into a string that is the repetition of a substring of length k. Conversion has to be done by following the steps mentioned below only once:

Select two indices i and j (zero-based indexing, i could be equal to j), such that i and j are divisible by k.
Select substrings of length k starting from indices i and j.
Replace substring starting at index i with substring starting at index j within the string.
Example 1:

Input:
N = 4
K = 2
S = "bdac"
Output: 1
Explanation: We can replace either
"bd" with "ac" or "ac" with "bd"
Example 2:

Input: 
N = 5
K = 2
S = "abcde"
Output: 0
Explanation: Since n % k != 0, it's not 
possible to convert s into a string which
is a concatanation of a substring with 
length k.
*/
//User function template for C++

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    if(n%k)return 0;
	    map<string,int>mp;
	     string temp="";
	     temp+=s[0];
	     for(int i=1;i<n;i++){
	         if(i%k==0){
	             mp[temp]++;
	             temp="";
	         }
	         temp+=s[i];
	     }
	     mp[temp]++;
	     if(mp.size()>2)
	        return 0;
	    return 1;     
	}
};
