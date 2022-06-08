

// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
       bool search(vector<int>& nums, int target) {
     
     int start = 0;
     int end = nums.size()-1;
    
            while(start <= end)   
            {
                int mid = (start+end)/2;
                if(nums[mid]== target) return true;

                while(nums[mid] == nums[start] and start != mid) start++;
                while(nums[mid] == nums[end] and end != mid) end--;

                if(nums[start] <= nums[mid])
                    (target>=nums[start] and target<nums[mid]) ? end = mid-1 : start = mid+1;
                else
                    (target<=nums[end] and target>nums[mid]) ? start = mid+1 : end = mid-1;
            }

        return false;
        
    }
        
    
};