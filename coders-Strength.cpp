// given  a array of n lenght 
// you can form n(n-1) pairs 
// tell the k'th largest pairs

// one broute full approach  is o(n*n) 
// can we optime it ?? 
// 10^5 lenght array
#include <bits/stdc++.h>
using namespace std;


class BinarySearch{
public:
   int CountPairsGTeqal(vector<int> &nums , int reqSum , int k ){
   	int j = nums.size() -1;

   	for(int i  = 0 ;  i < nums.size()  ; i++){
   		while( i < j and nums[i]+nums[j] < reqSum ) j--;

   		if(j > i ) count+=(j-i);
   	}
   
    // number of pairs that make sum greaterEqual to reqSum(mid) 
   	return count;
   }

	int StrengthCoders(vector<int> &arr , int k){
      // there are n*(n-1) pairs 

	  sort(arr.begin() , arr.end());   
	  reverse(arr.begin() , arr.begin());    // sort is reverse order
   
     // low pair sum is arr[n-1]+arr[n-2]
     // high pair sum is arr[0]+arr[1]

	   int low = arr[n-1]+arr[n-2];
	   int high = arr[0]+arr[1];
       int ans = low;
	   while(low <= high){
       int mid = (low+high) >> 1;
       if(CountPairsGTeqal(arr, mid , k) >= k){
       ans = mid;
       low = mid+1;
       }else{
       	high  = mid -1;
       }
	   }
	}
};




// 


