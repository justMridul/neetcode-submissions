class Solution {
public:
   
    int combinationSum4(vector<int>& nums, int target) {
    
          vector<unsigned int> dp(target + 1, 0);

    dp[0] = 1;

    for(int t = 1; t <= target; t++) {
        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] <= t) {
                dp[t] += dp[t - nums[i]];
            }
        }
    }

    return dp[target];
        
    }
};