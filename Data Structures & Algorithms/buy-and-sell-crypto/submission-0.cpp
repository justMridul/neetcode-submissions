class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //brute force
        int maxi = 0;

        for(int i =0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int money = prices[j] - prices[i];

                maxi = max(maxi , money);
            }
        }
        return maxi;
    }
};
