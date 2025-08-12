class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea = 0;
        int nse=-1,pse=-1;

        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int elem = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxarea = max(heights[elem]*(nse-pse-1),maxarea);
            }
            st.push(i);
        }

        while(!st.empty()){
            int elem = st.top();
            st.pop();
            nse = heights.size();
            pse = st.empty() ? -1 : st.top();

            maxarea = max(heights[elem]*(nse-pse-1),maxarea);
        }
        return maxarea;
    }
};