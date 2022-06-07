#include <bits/stdc++.h>
using namespace std;


	class BinarySearch {
public:
    
    int binarySearchOnRow(vector<vector<int>>& matrix , int target)
    { 
        int l = 0;
        int r = matrix.size()-1;
        int c = matrix[0].size()-1;
        
        while(l<=r){
            int m = (l+r)/2;
            
            if(matrix[m][0] <= target && matrix[m][c] >= target)
            {
                return m;
            }else if(matrix[m][0] > target)
            {
                r= m-1;
            }else{
                l = m+1;
            }
        } 
        return -1;
        
    }
    
     bool find(vector<vector<int>>& matrix, int mid, int target)
     {
             int l =0;
             int r = matrix[0].size()-1;
         
         while(l<=r
              )
         {
             int m = (l+r)/2;
             if(matrix[mid][m] == target){
                 return true;
             }else if(matrix[mid][m] > target)
             {
                 r = m-1;
             }else{
                 l = m+1;
             }
         }
         return false;
     }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      
       int r = binarySearchOnRow(matrix , target);
       if(r==-1){return false;}
       bool isFound =  find(matrix , r , target);
        
        return isFound;
    }
};

