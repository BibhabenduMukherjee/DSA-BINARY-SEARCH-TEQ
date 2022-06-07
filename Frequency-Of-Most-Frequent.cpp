#include <bits/stdc++.h>
using namespace std;

// You are given an integer array nums and an integer k
// in one operation you can increase any nums[i] by 1 
// return the maximum possible frequency of a element after performing 
// this operation 

class BinarySearch{
public:
 bool check(vector<int> &nums  , int k , int mid){
   // mid is the freqency that would make 
  
   int Sum = 0;
   for(int i = 0 ; i < mid ; i++){
   	Sum+=nums[i];
   }

   int reqOperation = nums[mid-1]*mid - Sum;

   if(reqOperation <= k) return true;

   for(int i = mid  ; i < nums.size() ; i++){
   	Sum = Sum + nums[i];
   	Sum  = Sum - nums[i-mid];
   	reqOperation = nums[mid-1]*mid - Sum;

   	if(reqOperation <= k) return true;
   }
   return false;

 }

 int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int l=1,r=nums.size();
        
        
        
        // here mid  => Let's check that mid can be max frequency element or not
        
        while(r>l){
            int mid = l + (r - l + 1)/2;
            
            if(check(nums,k,mid)){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        
        return l;
}
};
