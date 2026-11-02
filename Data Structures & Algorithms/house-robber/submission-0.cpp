class Solution {
public:
   int tot(vector<int>&nums , int i , vector<int>&dp){

    if(i >= nums.size()) return 0;

    if(dp[i] != -1) return dp[i];
     
       int c1  = nums[i] + tot(nums , i + 2 , dp);
       int c2  = tot(nums , i + 1 , dp);

       return dp[i] = max(c1 , c2);
   }
    int rob(vector<int>& nums) {
        int n = nums.size();

         vector<int>dp(n + 1 , -1);
      
      int ans = tot(nums , 0 , dp);
      return ans;
    }
};
