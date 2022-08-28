/* You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope. */


// & Example 1:

// Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).


// Constraints:

// 1 <= envelopes.length <= 10^5
// envelopes[i].length == 2
// 1 <= wi, hi <= 10^5


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // comparator sort function 
    // if [a1,b1], and [a2,b2] are the two list if we went to sort this two 
    //list this function will operate like this ---> first compare a1 and a2 if they
    //are not equal (a1>a2) -- convert it like [a2,b2] , [a1 , b1 ] because a2 is small and it a1==a2 then compare with second b1 and b2
    
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0])
            return a[1] > b[1];
        else 
            return a[0] < b[0];
    }
    
    // [4,5][4,7][4,6][5,6]
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int m = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> lis;
        for(int i = 0; i < m; i++) {
            int ele = envelopes[i][1];
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            cout << idx << " ";
            if(idx == lis.size())
                lis.push_back(ele);
            else
                lis[idx] = ele;
          
        }
        
        return lis.size();
    
    }
};
