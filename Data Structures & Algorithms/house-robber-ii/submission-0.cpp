class Solution {
public:
    int maxi(vector<int>&arr , int i , vector<int>&dp){
        if(i >= arr.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int c1 = arr[i] + maxi(arr , i+2 ,dp);
        int c2 = maxi(arr , i + 1 , dp);

        return dp[i] = max(c1 , c2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

          vector<int> a1(nums.begin(), nums.end() - 1); 
        vector<int> a2(nums.begin() + 1, nums.end());

           vector<int> dp1(a1.size(), -1);
        vector<int> dp2(a2.size(), -1);


      int x = maxi(a1 , 0 , dp1);
      int y = maxi(a2 , 0, dp2);

      return max(x , y);
    }
};
