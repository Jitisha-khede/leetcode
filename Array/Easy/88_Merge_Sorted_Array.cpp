class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {        
        // if(n!=0 && m!=0){
        //     int temp=0;
        //     for(int i=m;i<nums1.size();i++){   
        //         nums1[i] = nums2[temp];
        //         temp++;
        //     }
        // }
        // if(m==0){
        //     nums1 = nums2;
        // }
        // sort(nums1.begin(),nums1.end());

        int left = m-1, right = 0;
        int l = m, r=n;
        while(m>0 && n>0){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--;
                right++;
            }
            m--;
            n--;
        }
        sort(nums1.begin(),nums1.begin()+l);
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<r;i++){
            nums1[l+i] = nums2[i];
        }
    }
};