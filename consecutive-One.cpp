#include <bits/stdc++.h>
using namespace std;

class BinarySearch {
public:
  bool solve(vector<int>&nums , int k , int mid){
   int count = 0;
        for(int i=0;i<mid;i++){
            if(nums[i]==0)
                count++;
        }
        int i=1;
        int j=mid;
        if(count <= k)  return true;
        while(j<nums.size()){
        	if(nums[j]==0)
                count++;
            if(nums[i-1]==0)
                count--;
            if(count <= k)
                return true;            
            i++;
            j++;
        }
        return count<=k;
    }
   
  
    int longestOnes(vector<int>& nums, int k) {
       // nums -- > contains 0 or 1
       // return maximum contiguos 1's
    // you can filp 0 to 1 atmost k times
  
      // atmost their are nums.size() number of
      // 1's of all are ones
      
      int low =k;
      int high = nums.size();
      int ans = high;
      while(low <= high){
        int mid = (low+high)/2;
        if(solve(nums , k , mid) == true){
          ans = mid;
          low = mid+1;
        }else{
          high = mid-1;
        }
      }
      
      return ans;
      
    }
};