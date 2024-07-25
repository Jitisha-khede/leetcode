class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> temp;
        vector<int> vect;
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            string ans;
            for(int j=0;j<s.size();j++){
                ans += to_string(mapping[s[j]-'0']); 
            }
            temp.push_back({stoi(ans),i});
        }
        sort(temp.begin(),temp.end());

        for(auto& pair : temp){
            vect.push_back(nums[pair.second]);
        }
        return vect;
    }
};