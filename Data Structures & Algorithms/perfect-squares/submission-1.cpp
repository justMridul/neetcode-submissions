class Solution {
public:
 
    int numSquares(int n) {
       int maxI = sqrt(n);

        vector<vector<int>> dp(
            n + 1,
            vector<int>(maxI + 2, 1e9)
        );

        // target = 0
        for (int i = 1; i <= maxI + 1; i++) {
            dp[0][i] = 0;
        }

        // i from large -> small
        for (int i = maxI; i >= 1; i--) {

            // target from small -> large
            for (int target = 1; target <= n; target++) {

                int sq = i * i;

                // Pick i²
                int c1 = 1e9;

                if (sq <= target) {
                    c1 = 1 + dp[target - sq][i];
                }

                // Don't pick i²
                int c2 = dp[target][i + 1];

                dp[target][i] = min(c1, c2);
            }
        }

        return dp[n][1];
    }
};