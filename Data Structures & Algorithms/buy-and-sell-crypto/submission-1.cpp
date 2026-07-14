class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //optimised

        int low = 0;
        int high = 0;

        int maxi = 0;

        while(high < n){

            if(prices[low] <= prices[high]){

               int money = prices[high] - prices[low];
               maxi = max(maxi , money);
               high++;
            }
            else{
                  low = high;
            } 
        }
        return maxi;
        
        }
};
