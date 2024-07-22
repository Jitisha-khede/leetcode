class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vect;
        int front=0,back=0;
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum = nums[i];
            for(int j=i;j<n;j++){
                if(i==j){
                    vect.push_back(nums[i]);
                }
                else{
                    sum+=nums[j];
                    vect.push_back(sum);
                }   
            }
        }
        sort(vect.begin(),vect.end());     
        sum=0;
        if(right>vect.size()) right = vect.size();
        for(int i=left-1;i<right;i++){
            sum+=vect[i];
        }
        return sum%1000000007;
    }
};