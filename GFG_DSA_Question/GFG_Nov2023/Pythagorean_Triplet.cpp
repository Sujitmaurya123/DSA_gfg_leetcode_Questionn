/*
Pythagorean Triplet

Given an array arr of n integers, write a function that returns true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

Example 1:

Input:
N = 5
Arr[] = {3, 2, 4, 6, 5}
Output: Yes
Explanation: a=3, b=4, and c=5 forms a
pythagorean triplet.
Example 2:

Input:
N = 3
Arr[] = {3, 8, 5}
Output: No
Explanation: No such triplet possible.

Expected Time Complexity: O(n+max(Arr[i])2)
Expected Auxiliary Space: O(max(Arr[i]))

Constraints:
1 <= n <= 105
1 <= arr[i] <= 1000

*/

// User function template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if the
    // Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n)
    {
        // code here
        // code here
        // if(n<3) return false;
        // sort(arr,arr+n);
        // for(int i=0;i<n;i++) arr[i]=arr[i]*arr[i];
        // for(int k=n-1;k>=2;k--){
        //     int i=0,j=k-1;
        // //k=n;k<=2;k--
        //     while(i<j){

        //         if(arr[i]+arr[j]==arr[k]) return true;
        //         else if(arr[i]+arr[j]<arr[k]) i++;
        //         else j--;
        //     }
        // }
        // return false;

        unordered_map<long long, bool> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i] * arr[i]] = true;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long sum = arr[i] * arr[i] + arr[j] * arr[j];
                if (mp[sum])
                {
                    return true;
                }
            }
        }
        return false;
    }
};