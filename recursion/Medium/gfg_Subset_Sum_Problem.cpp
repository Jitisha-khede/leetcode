class Solution {
  public:
  
    bool check(vector<int> &arr, int target, int sum,int i){
        if(sum==target) return true;
        if(i==arr.size() || sum > target) return false;
        
        return check(arr,target,sum+arr[i],i+1) || check(arr,target,sum,i+1);
        
    }
    bool isSubsetSum(vector<int>& arr, int target) {

        return check(arr,target,0,0);

    }
};