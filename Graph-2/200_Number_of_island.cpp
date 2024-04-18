vector<pair<int,int>> movements{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<bool>> visited;
    int n;
    int m;

    bool isRight(int x,int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    void dfs(int i,int j,vector<vector<char>>& grid){
        visited[i][j] = true;
        for(auto& mmt : movements){
            int x = i+ mmt.first, y = j+ mmt.second;
            if(!isRight(x,y) || visited[x][y] || grid[x][y]=='0') 
                continue;
            dfs(x,y,grid);
        }
    }
 int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.resize(n,vector<bool>(m,false));
        int isLand = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]=='1' && !visited[i][j]){
                    isLand++;
                    dfs(i,j,grid);
                }
            }
        }
        return isLand;
    }