class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

      int currmax = nums[0];
      int currmin = nums[0];

      int gmax = nums[0];
      int gmin = nums[0];

      int total = nums[0];

      for(int i =1;i<n;i++){

        currmax = max(currmax + nums[i] , nums[i]);
        currmin = min(currmin + nums[i] , nums[i]);

        gmax = max(gmax , currmax);
        gmin = min(gmin , currmin);

        total += nums[i];
      }

      if(gmax < 0) return gmax;

      return max(gmax , total - gmin);

    }
};