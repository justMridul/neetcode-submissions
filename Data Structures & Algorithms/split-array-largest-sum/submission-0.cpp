class Solution {
public:
     bool isPossible(int mid , vector<int>&nums , int k){
       int curr = 0;
       int cnt = 1;

       for(int i =0;i<nums.size();i++){
          if(curr + nums[i] <= mid){
            curr += nums[i];
          }
          else{
            cnt++;
            curr = nums[i];
          }
       }
       return cnt <= k;
     }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end() , 0);

        int ans = 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

           if(isPossible(mid , nums , k)){
            ans = mid;
            high = mid - 1;
           }
           else{
            low = mid + 1;
           }
        }
         return ans;
    }
};