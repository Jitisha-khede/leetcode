class KthLargest {
public:
    vector<int> v;
    int kl = 0;
    KthLargest(int k, vector<int>& nums) {
        v = nums;
        kl = k;
        sort(v.begin(),v.end());
    }
    
    int add(int val) {
        int index = getIndex(val);
        v.insert(v.begin()+index,val);
        return v[v.size()-kl];
    }

    int getIndex(int val){
        int low = 0;
        int high = v.size()-1;
        

        while(low<=high){
            int mid = (low+high)/2;
            if(v[mid]==val) return mid;
            else if(v[mid]>val) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */