class Solution {
  public:
    int c = 0;
    void merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;
        
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                c+=(mid-left+1);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }
  
    void mS(vector<int> &arr, int low, int high){
        if(low>=high) return;
        int mid = (low+high)/2;
        mS(arr,low,mid);
        mS(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    
    int inversionCount(vector<int> &arr) {
        // BRUTE FORCE
        // int maxi = 0;
        
        // for(int i=0;i<arr.size();i++){
        //     int c = 0;
        //     for(int j=i+1;j<arr.size();j++){
        //         if(arr[i]<arr[j]) c++;
        //     }
        //     maxi = max(c,maxi);
        // }
        // return maxi;
        
        //OPTIMAL
        mS(arr,0,arr.size()-1);
        return c;
    }
};