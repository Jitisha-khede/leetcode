//TLE
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v.push_back(abs(nums[i]-nums[j]));
            }
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }
};

//METHOD 1
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v.push_back(abs(nums[i]-nums[j]));
            }
        }
        nth_element(v.begin(),v.begin()+(k-1),v.end());
        return v[k-1];
    }
};

//METHOD 2
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end()); // used to find maximum element in array;
        vector<int> v(maxi+1,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = abs(nums[i]-nums[j]);
                v[d]++;
            }
        }
        
        for(int i=0;i<v.size();i++){
            k-=v[i];
            if(k<=0) return i;
        }
        return -1;
    }
};