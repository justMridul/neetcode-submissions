class Solution {
public:
     int drow[4] = {1 , 0 , -1, 0};
   int  dcol[4] = {0 , 1 , 0 , -1};

     int dfs(int row , int col , vector<vector<int>>&vis
            , vector<vector<int>>&grid){
           
           vis[row][col] = 1;

           int area = 1;

           for(int i =0;i<4;i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;

            if(nrow >= 0 && ncol >= 0 && nrow < grid.size() && 
             ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
               area += dfs(nrow , ncol , vis , grid);
             }
           }
           return area;
            }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n , vector<int>(m , 0));
         int cnt = 0;
         int maxi = 0;

        for(int i =0;i<n;i++){
          for(int j = 0;j<m;j++){
            if(grid[i][j] == 1 && !vis[i][j]){
               int cnt =  dfs(i , j , vis , grid);
                maxi = max(maxi , cnt);
            }
          }
        }
          return maxi;
    }
};
