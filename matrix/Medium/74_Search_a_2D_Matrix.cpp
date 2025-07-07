class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int h = len-1;
        
        while(l<=h){
            int m = (h+l)/2;
            int low = 0;
            int high = n-1;
            
            while(low<=high){
                int mid = (high+low)/2;
                if(matrix[m][mid]==target) return true;
                else if(low!=high && matrix[m][mid]<target) low = mid+1;
                else if(low!=high && matrix[m][mid]>target ) high = mid-1;
                else{
                    break;
                } 
            }
            
            if(matrix[m][low]>target){
                h=m-1;
            }
            else {
                l=m+1;
            }
        }
        return false; 
    }
};