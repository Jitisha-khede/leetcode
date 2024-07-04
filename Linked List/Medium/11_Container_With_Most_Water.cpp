class Solution {
public:
    int maxArea(vector<int>& height) {
        int currArea = 0, maxArea = 0;
        int left = 0, right = height.size()-1;
        int width = 0;
        while(left<right){
            width = right-left;
            currArea = min(height[left],height[right])*width;
            maxArea = max(currArea,maxArea);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};