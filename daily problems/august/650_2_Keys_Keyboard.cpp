class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;

        return 1+solve(1,1,n);
    }

    int solve(int currA, int clipA, int n){
        if(currA==n) return 0;

        else if(currA>n) return 1000;

        int cp = 2+solve(currA*2, currA, n);
        int p = 1+solve(currA+clipA,clipA,n);

        return min(cp,p);
    }
};