// You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are 
//also given an integer k that denotes the number of children to distribute all the bags of cookies to. 
//All the cookies in the same bag must go to the same child and cannot be split up.

// The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

// Return the minimum unfairness of all distributions.



class Solution {
public:
    bool solve(vector<int>& nums, int mid, int k){
        int count = 0, sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > mid) return false;
            sum += nums[i];
            if(sum > mid){
                count++;
                sum = nums[i];
            }
        }
        count++;
        if(count <= k) return true;
        return false;
    }
    int bSearch(vector<int>& cookies, int low, int high, int k){
        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(solve(cookies, mid, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(), cookies.end());
        int low = *max_element(cookies.begin(), cookies.end());
        int high = accumulate(cookies.begin(), cookies.end(), 0);
        int ans = INT_MAX;
        do{
            ans = min(ans, bSearch(cookies, low, high, k));
        }while(next_permutation(cookies.begin(), cookies.end()));
        return ans;
    }
};




// Another Back-traking approach
class Solution {
public:
    int ans = INT_MAX;
    void solve(int start, vector<int>& nums, vector<int>& v, int k){
        if(start==nums.size()){
            int maxm = INT_MIN;
            for(int i=0;i<k;i++){
                maxm = max(maxm,v[i]);
            }
            ans = min(ans,maxm);
            return;
        }
        for(int i=0;i<k;i++){
            v[i] += nums[start];
            solve(start+1,nums,v,k);
            v[i] -= nums[start];
        }
    }
    
    int distributeCookies(vector<int>& nums, int k) { // nums is the cookies vector
        int n = nums.size();
        vector<int> v(k,0); // v is to store each sum of the k subsets
        solve(0,nums,v,k);
        return ans;
    }
};










