//You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

//You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

//Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.


class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long ss) {
           sort(p.begin() , p.end());
          vector<long long> res(s.size());
          for(int i = 0 ; i< s.size() ; ++i){
              res[i] = (ss/s[i]);
          }
        
        vector<int> ans;
        for(int i = 0 ;  i < s.size() ; ++i){
            
            if(ss <= 1LL*res[i]*s[i] ){
                 int ind = lower_bound(p.begin() , p.end() , res[i])  - p.begin() ;   
                ans.push_back(p.size() - ind);
            }else{
                 int ind = upper_bound(p.begin() , p.end() , res[i])  - p.begin() ;
                      
                ans.push_back(p.size() - ind);
            }                   
           
        }
           
        return ans;
        
    }
};

 
