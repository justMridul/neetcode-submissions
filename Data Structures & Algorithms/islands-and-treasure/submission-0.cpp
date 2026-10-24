class Solution {
public: 
     int drow[4] = {-1 , 0 , 1, 0};
     int dcol[4] = {0 , 1 , 0 , -1};

     long long INF = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

       queue<pair<int,int>>q;

       for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 0){
                q.push({i , j});
            }
        }
       }

       while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i =0;i<4;i++){

          int nrow = row + drow[i];
          int ncol = col + dcol[i];

          if(nrow >= 0 && ncol >= 0 && nrow < n &&
            ncol < m && grid[nrow][ncol] == INF){
                  grid[nrow][ncol] = grid[row][col] + 1;
                q.push({nrow , ncol});
            }
        }
       }
    }
};
