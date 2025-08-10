class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        int n = nums.size();

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        int f = k-1; 

        while(f--){
            pq.pop();
        }

        return pq.top();
    }
};