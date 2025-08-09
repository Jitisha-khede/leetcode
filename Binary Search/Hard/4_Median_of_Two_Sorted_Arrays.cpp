class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //BRUTE FORCE
        // double ans =0;
        // vector<int> v;
        // int l=0,r=0;
        

        // while(l<nums1.size() && r<nums2.size()){
        //     if(nums1[l]<=nums2[r]) {
        //         v.push_back(nums1[l]);
        //         l++;
        //     }
        //     else{
        //         v.push_back(nums2[r]);
        //         r++;
        //     }
        // }
        // while(l<nums1.size()){
        //     v.push_back(nums1[l]);
        //     l++;
        // }
        // while(r<nums2.size()){
        //     v.push_back(nums2[r]);
        //     r++;
        // }
        // int n = v.size();
        // if(n%2!=0) return v[n/2];
        // ans = (v[n/2]+v[(n/2)-1])/2.0;
        // return ans;
        
        //OPTIMAL
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();

        int low =0, high = n1;

        while(low<=high){
            int cut1 = (low+high)/2;
            int cut2 = (n1+n2+1)/2-cut1;

            int left1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];

            int right1 = cut1==n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2==n2 ? INT_MAX : nums2[cut2];

            if(left1<=right2 && right1>=left2){
                if((n1+n2)%2==0){
                    return (max(left1,left2) + min(right1,right2))/2.0;
                }
                else return max(left1,left2);
            }
f
            else if(left1>right2){
                high = cut1-1;
            }
            else{
                low = cut1 +1;
            }
        }
        return 0.0;
    }
};