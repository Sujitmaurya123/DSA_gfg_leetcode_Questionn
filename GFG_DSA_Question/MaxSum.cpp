/*
  Q. Maximum Sum Combination
__________________________________________________________________________________________________________________________________________

Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.

Example 1:

Input:
N = 2
K = 2
A [ ] = {3, 2}
B [ ] = {1, 4}
Output: {7, 6}
Explanation:
7 -> (A : 3) + (B : 4)
6 -> (A : 2) + (B : 4)
Example 2:

Input:
N = 4
K = 3
A [ ] = {1, 4, 2, 3}
B [ ] = {2, 5, 1, 6}
Output: {10, 9, 9}
Explanation:
10 -> (A : 4) + (B : 6)
9 -> (A : 4) + (B : 5)
9 -> (A : 3) + (B : 6)
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCombinations() which takes the interger N,integer K and two integer arrays A [ ] and B [ ] as parameters and returns the maximum K valid distinct sum combinations .

Expected Time Complexity: O(Nlog(N))
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤  105
1 ≤ K ≤  N
1 ≤ A [ i ] , B [ i ] ≤ 104



*/


#include<bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
{
    // code here
    vector<int> ans;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;
    pq.push({A[N - 1] + B[N - 1], {N - 1, N - 1}});
    st.insert({N - 1, N - 1});

    while (K--)
    {
        auto p = pq.top();
        int sum = p.first;
        int i = p.second.first;
        int j = p.second.second;

        ans.push_back(sum);
        pq.pop();
        if (st.find({i - 1, j}) == st.end())
        {
            pq.push({A[i - 1] + B[j], {i - 1, j}});
            st.insert({i - 1, j});
        }
        if (st.find({i, j - 1}) == st.end())
        {
            pq.push({A[i] + B[j - 1], {i, j - 1}});
            st.insert({i, j - 1});
        }
    }
    return ans;
}
