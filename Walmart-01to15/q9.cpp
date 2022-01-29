class Solution {
public:
    int getMoneyAmount(int n) {
         // dp[i][j] represents the minimum number of money to guarantee a win for the number from i to j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int len = 1; len < n; len++){ // actually length = 2 ~ n
            for(int i = 1; i + len <= n; i++){
                int j = i + len;
                dp[i][j] = INT_MAX;
                for(int k = i; k <= j; k++){ // assume guess k, and it is wrong
                    int temp = k + max(k - 1 >= i ? dp[i][k - 1] : 0, k + 1 <= j ? dp[k + 1][j] : 0);
                    dp[i][j] = min(dp[i][j], temp); // try to find the best k (lowest penality) to guess
                }
            }
        }
        return dp[1][n];   
    }
};
