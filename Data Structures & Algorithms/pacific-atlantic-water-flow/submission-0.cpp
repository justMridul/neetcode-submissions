class Solution {
public:
     int drow[4] = {1, 0, -1, 0};
     int dcol[4] = {0, 1 , 0, -1};
    
      vector<vector<bool>> pacific, atlantic;

    void dfs(int row , int col ,vector<vector<int>>& heights , vector<vector<bool>>& vis){

         vis[row][col] = 1;

         for(int i =0;i<4;i++){

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && ncol >= 0 && nrow < heights.size() && 
            ncol < heights[0].size() && !vis[nrow][ncol] && 
              heights[row][col] <= heights[nrow][ncol]){

                dfs(nrow , ncol , heights , vis);
              }
         }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>ans;

        pacific.assign(n, vector<bool>(m, false));
        atlantic.assign(n, vector<bool>(m, false));

       // Pacific: top row (iterate over columns)
for (int j = 0; j < m; j++)
    dfs(0, j, heights, pacific);

// Pacific: left column (iterate over rows)
for (int i = 0; i < n; i++)
    dfs(i, 0, heights, pacific);

// Atlantic: bottom row (iterate over columns)
for (int j = 0; j < m; j++)
    dfs(n - 1, j, heights, atlantic);

// Atlantic: right column (iterate over rows)

for (int i = 0; i < n; i++)
    dfs(i, m - 1, heights, atlantic);
    
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (pacific[i][j] && atlantic[i][j]) {
            ans.push_back({i, j});
        }
    }
}

        return ans;
        
    }
};
