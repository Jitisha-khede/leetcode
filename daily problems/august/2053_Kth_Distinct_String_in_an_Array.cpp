class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> s;

        for(int i=0;i<arr.size();i++){
            s[arr[i]]++;
        }
        
        for(int i=0;i<arr.size();i++){
            if(s.count(arr[i]) && k==1 && s[arr[i]]==1) return arr[i];
            else if(s.count(arr[i]) && k!=1 && s[arr[i]]==1) k--;
        }

        return "";
    }
};