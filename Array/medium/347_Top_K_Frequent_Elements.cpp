class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>> v(mp.size(),{0,0});
        int j=0;

        for(auto it : mp){
            v[j].first = it.first;
            v[j].second = it.second;
            j++;
        }

        sort(v.begin(),v.end(),[](auto &a, auto &b){
            return a.second>b.second;
        });

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }

        return ans;
    }
};