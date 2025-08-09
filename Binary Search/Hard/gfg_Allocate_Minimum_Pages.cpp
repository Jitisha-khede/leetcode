class Solution {
  public:
    int countStudents(vector<int> arr,int mid){
        int c=1;
        long long pageCount = 0;
        for(int i=0;i<arr.size();i++){
            if(pageCount + arr[i] <= mid){
                pageCount+=arr[i];
            }
            else{
                c++;
                pageCount = arr[i];
            }
        }
        return c;
    }
    
    int findPages(vector<int> &arr, int k) {
        if(k>arr.size()) return -1;
        long long sum =0;
        int low = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            low = max(low, arr[i]);
        }
        int high = sum; 
        
        while(low<=high){
            int mid = (low+high)/2;
            int students = countStudents(arr,mid);
            if(students>k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};