class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!=arr.size()) return false;
        unordered_map<int,int> mp1; 
        unordered_map<int,int> mp2;

        for(int i=0;i<arr.size();i++){
            mp1[target[i]]++;
            mp2[arr[i]]++;
        }

        if(mp1==mp2) return true;
        return false;
    }
};