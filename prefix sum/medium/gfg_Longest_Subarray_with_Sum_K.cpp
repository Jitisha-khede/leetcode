class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        //BRUTE FORCE
        // int len = 0;
        // for(int i=0;i<arr.size();i++){
        //     int sum = 0;
        //     for(int j=i;j<arr.size();j++){
        //         sum+=arr[j];
        //         if(sum==k){
        //             len = max(j-i+1,len);
        //         }
        //     }
        // }
        // return len;
        
        //BETTER - PREFIX SUM(optimal for -ves)
        unordered_map<int,int> mp;
        long long sum = 0;
        int maxLen = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k){
                maxLen = max(maxLen,i+1);
            }
            int rem = sum-k;
            if(mp.find(rem)!=mp.end()){
                int len = i - mp[rem];
                maxLen = max(maxLen,len);
            }
            if(mp.find(sum)==mp.end()) mp[sum] = i;
        }
        return maxLen;
        
        //OPTIMAL - TWO POINTERS(only fot +ves and zeros)
        // int l = 0, r = 0;
        // int sum = 0;
        // int maxLen = 0;
        // while(l<=r && r<arr.size()){
        //     sum+=arr[r];
        //     if(sum==k){
        //         maxLen = max(maxLen,r-l+1);
        //     }
        //     else if(sum>k){
        //         sum-=arr[l];
        //         l++;
        //         if(sum==k){
        //             maxLen = max(maxLen,r-l+1);
        //         }
        //     }
        //     r++;
        // }
        // return maxLen;
    }
};