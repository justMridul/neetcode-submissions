class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

     int maxi = nums[0];
     int mini = nums[0];

     int sum1 = nums[0];
     int sum2 = nums[0];

     int total = nums[0];

     for(int i =1;i<n;i++){

      total += nums[i];

        sum1 = max(nums[i] , nums[i] + sum1);
              maxi = max(maxi , sum1);

        sum2 = min(nums[i] , nums[i] + sum2);
             mini = min(mini , sum2);

     }

     if(maxi < 0) return maxi;

     return max(maxi , total - mini);

    }
};