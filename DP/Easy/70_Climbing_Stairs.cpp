class Solution {
public:
    //SIMPLE RECURSION
    int climbStairs(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;

        return climbStairs(n-1) + climbStairs(n-2);
    }

    //MEMOIZATION
    int climb(int n, vector<int> &dp){
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n]!=-1) return dp[n];
        return dp[n] = climb(n-1,dp) + climb(n-2,dp);
    }

    int climbStairs(int n) {
        vector<int>  dp(n+1,-1);
        return climb(n,dp);
    }

    //TABULATION
    int climbStairs(int n) {
        vector<int>  dp(n+1,-1);
        dp[0] = 1, dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    //SPACE OPTIMIZED
    int climbStairs(int n) {
        int curri = 1, prev1 = 1, prev2 = 1;
        for(int i=2;i<=n;i++){
            curri = prev1 + prev2;
            prev1 = prev2;
            prev2 = curri;
        }
        return curri;
    }
};