class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n+1 , vector<int>(n+1 ,0));
        
        for(int i = 0;i<n+1;i++){
            dp[n][i] = 0;
        }

        for(int i = n-1;i>=0;i--){
            for(int prev =i-1;prev >= -1;prev-- ){
                
                int c1 = dp[i+1][prev +1];
                int c2 = 0;

                if(prev == -1 || nums[i] > nums[prev]){
                    c2 = 1 + dp[i+1][i+1];
                }

                dp[i][prev+1] = max(c1 , c2);
            }
        }

        return dp[0][0];
    }
};
