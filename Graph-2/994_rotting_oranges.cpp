int orangesRotting(vector<vector<int>>& grid) {
        int total=0;
        int count=0;
        int days=0;

        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) 
                    total++;
                if(grid[i][j]==2) 
                    q.push({i,j});
            }
        }

        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};

        while(!q.empty()){
            int temp = q.size();
            count += temp;
            while(temp--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x + delRow[i];
                    int ny = y + delCol[i];
                    if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]!=1) 
                        continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) days++;
        }
     return total==count ? days:-1;
 }