class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int low = 0;
        int high = n-1;

        int maxi = 0;
    

        while(low < high){

         int h = min(heights[low] , heights[high]);
         int water = (high - low) * h;
         maxi = max(maxi , water);
        
        if(heights[low] < heights[high]) low++;
        else high--;
        }
        return maxi;
    }
};
