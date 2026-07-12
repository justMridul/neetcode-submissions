class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

     //rotate an array = reverse it accordingly

     k = k% n;

     reverse(nums.begin() , nums.end());
     reverse(nums.begin() , nums.begin() + k );
     reverse(nums.begin() + k , nums.end());

    }
};