class Solution {
public:
 
    int numSquares(int n) {
      vector<int>dp(n+1 , 1e9);

      dp[0] = 0;

      for(int target = 1;target<=n;target++){
        for(int i = 1;i*i<=target;i++){
            int sq = i*i;

           dp[target] = min(dp[target] , 1 + dp[target-sq]);
        }
      }
      return dp[n];
    }
};