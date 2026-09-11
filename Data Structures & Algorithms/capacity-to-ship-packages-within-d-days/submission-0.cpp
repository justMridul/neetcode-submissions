class Solution {
public:
     bool isPossible(int mid , vector<int>&weights , int days){
        
        int days_need = 1;
        int curr_wt = 0;

        for(int i =0;i<weights.size();i++){

            if(weights[i] > mid) return false;

            if(curr_wt + weights[i] <= mid){
                curr_wt += weights[i];
            }
            else{
                days_need++;
                curr_wt = weights[i];
            }
        }
             return days_need <= days;
     }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin() , weights.end());

        int high = accumulate(weights.begin() , weights.end() , 0);
        int ans = high;

        while(low <= high){
          int mid = (low + high) / 2;

          if(isPossible(mid , weights , days)) {
            ans = mid;
            high = mid -1;
          }

          else low = mid + 1;
        }
        return ans;
    }
};