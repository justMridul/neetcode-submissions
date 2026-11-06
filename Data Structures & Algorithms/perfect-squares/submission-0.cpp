class Solution {
public:
   int find(int target , int i , vector<vector<int>>&dp){
      if(target == 0) return 0;

     int sq = i*i;
    
     if(sq > target) return 1e9;

     if(dp[target][i] != 1e9) return dp[target][i];
    

     int c1 = 1 + find(target - sq, i , dp);

     int c2 = find(target , i+1 ,dp);

     return dp[target][i] = min(c1 , c2 );
   }
    int numSquares(int n) {
        int maxi = sqrt(n);

        vector<vector<int>>dp(n+1 , vector<int>(maxi+2 , 1e9));

        int ans = find(n , 1 , dp);
        return ans;
        
    }
};