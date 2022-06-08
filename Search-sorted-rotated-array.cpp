// very very important 

#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = 0;
        int r = n-1;
        
        while(r>=l)
        {
            
            int m = (l+r)/2;
            
            if(nums[m] == target) return m;
             
            // if the left part is sorted
            
            if(nums[l] <= nums[m])
            {
                
                // if target lies in this section
                
                if(nums[l] <= target &&  nums[m] >= target)
                {
                    r = m-1;
                }else{
                    l = m+1;
                }
                
                 
                
            } /// right part is sorted
            else{
                if(nums[m] <= target && target <= nums[r])
                {
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
            
        }
        return -1;
    }
};