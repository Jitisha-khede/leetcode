class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {        
        if(n!=0 && m!=0){
            int temp=0;
            for(int i=m;i<nums1.size();i++){   
                nums1[i] = nums2[temp];
                temp++;
            }
        }
        if(m==0){
            nums1 = nums2;
        }
        sort(nums1.begin(),nums1.end());
    }
};