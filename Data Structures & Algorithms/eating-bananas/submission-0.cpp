class Solution {
public:
     bool isPossible(int hours , vector<int>&piles , int h , int& ans){
         int num = 0;
          for(int i =0;i<piles.size();i++){

              num += (piles[i] + hours - 1) / hours;
          }

          if(num > h) return false;
          else {
            ans  = hours;
          }
          return true;
     }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
           
          int high = *max_element(piles.begin(), piles.end()); 

        int ans = 0;

        while(low <= high){

            int mid = (low + high) / 2;

            if(isPossible(mid , piles , h , ans)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
