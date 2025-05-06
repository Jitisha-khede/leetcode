//using extra space
class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n = nums.size();
            vector<int> v(n);
            for(int i=0;i<n;i++){
                v[i] = nums[nums[i]];
            }    
            return v;
            
        }
    };  
//using no extra space
class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            nums.resize(nums.size()*2);
            int n = nums.size();
            for(int i=0;i<n/2;i++){            
                nums[i+(n/2)] = nums[nums[i]];
            }    
            nums.erase(nums.begin(),nums.begin()+n/2);
            return nums;
        }
    };