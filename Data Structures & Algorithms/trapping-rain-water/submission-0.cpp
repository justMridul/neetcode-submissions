class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int low = 0;
        int high = n-1;
        int left = 0;
        int right = 0;
        
        int total = 0;
        while(low < high){
            left = max(left , height[low]);
            right = max(right , height[high]);

            if(left < right){
              total += left - height[low];
              low++;
            }
            else{
                total += right - height[high];
                high--;
            }
        }
        return total;
    }
};
