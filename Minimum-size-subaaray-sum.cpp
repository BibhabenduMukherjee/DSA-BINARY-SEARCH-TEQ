// Two approach  for this problem
// one is sliding window and another is bonary search 
// implementation

#include <bits/stdc++.h>
using namespace std;



//& C++ CODE FOR SLIDING WINDOW

class Solution {
public:
    
  
    int minSubArrayLen(int target, vector<int>& nums) {
        int ws=0;
        int min_len=INT_MAX;
        int pre_sum=0;
        for(int we=0;we<nums.size();we++)
        {
            pre_sum+=nums[we];
            while(pre_sum>=target)
            {
                min_len=min(min_len,we-ws+1);
                pre_sum-=nums[ws];
                ws++;
            }
        }
        if(min_len!=INT_MAX)
            return min_len;
        return 0;
    }
};

//& JAVA CODE FOR BINARY SEARCH IMPLEMENTATION

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int low=1;
        int high=nums.length;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(ReqSum(nums,nums.length,mid,target)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    
    public static boolean ReqSum(int []arr,int n,int k,int target){
        int sum=0;
       for(int i=0;i<k;i++){
           sum+=arr[i];
       }
        int maxi=sum;
        int j=-1;
        int i=k;
        for(;i<arr.length;i++){
           j++;
           sum-=arr[j];
           sum+=arr[i];
            maxi=Math.max(maxi,sum);
            
        }
        if(maxi >= target)return true;
        return false;
    }
}