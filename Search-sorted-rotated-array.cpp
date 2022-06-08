// very very important 



// very very important 

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

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