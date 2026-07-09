class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
          unordered_map<int,int>mp;
          mp[0] = 1;

          int cnt = 0;
          int psum = 0;

          for(int i=0;i<n;i++){
            psum += nums[i];

            if(mp.find(psum - k) != mp.end()){
                cnt += mp[psum - k];
            }
            mp[psum]++;
          }
          return cnt;
    }
};