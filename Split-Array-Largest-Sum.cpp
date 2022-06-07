// hard 

//Given an array nums which consists of non-negative integers and
//an integer m, you can split the array into m non-empty continuous subarrays.

//Write an algorithm to minimize the largest sum among these m subarrays.

#include <bits/stdc++.h>
using namespace std;


class BinarySearch{
public:
	bool solve(vector<int> &nums , int mid , int k){
		int sum = 0 ; 
		 int c = 1;

		 for(int i = 0 ; i < nums.size() ;  i++){
		 	if(nums[i] > mid) return false;

		 	if(sum + nums[i] > mid){
		 		c++;
		 		sum = nums[i];
		 	}else{
		 		sum+=nums[i];
		 	}
		 }
		 return c<=k;
	}

	 int splitArray(vector<int>& nums, int m) {
        
        int h =0;
        for(int i =0 ; i<nums.size() ; i++) h+=nums[i];
         int l = *max_element(nums.begin() , nums.end());
         int ans = h;
      while(l<=h){
        int mid = (l+h)/2;
        if(solve(nums , mid , m)==true){
           ans = mid;
          h = mid-1;
        }else{
         
          l = mid+1;
        }
      }
      
      return ans;

}
};