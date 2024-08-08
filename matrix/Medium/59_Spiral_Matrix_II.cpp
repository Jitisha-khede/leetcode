class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> vect(n,vector<int> (n,0));
        int left=0, right = n;
        int top = 0, bottom = n;

        while(left<right && top<bottom){

            for(int i=left;i<right;i++){
                vect[top][i] = num;
                num++;
            }
            top++;

            for(int i=top;i<bottom;i++){
                vect[i][right-1]=num;
                num++;
            }
            right--;

            if(left<right){
                for(int i=right-1;i>=left;i--){
                vect[bottom-1][i]=num;
                num++;
            }
            bottom--;
            }            

            if(top<bottom){
                for(int i=bottom-1;i>=top;i--){
                vect[i][left]=num;
                num++;
            }
            left++;
            }    
        }
        return vect;
    }
};