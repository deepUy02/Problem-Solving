bool hasValidPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        if(m==1 and n==1) return true;
        
        vector<vector<int>>dir = {        // Indices   
            {0,-1}, {0, 1}, // street 1  ->  0  1
            {-1,0}, {1, 0}, // street 2  ->  2  3
            {0,-1}, {1, 0}, // street 3  ->  4  5
            {0, 1}, {1, 0}, // street 4  ->  6  7
            {0,-1}, {-1,0}, // street 5  ->  8  9 
            {0, 1}, {-1,0}  // street 6  ->  10  11
        };

        vector<vector<bool>>visited(m, vector<bool>(n, false));
        queue<pair<int,int>>q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) 
        {
            auto cur = q.front(); q.pop();

            int r = cur.first;
            int c = cur.second;
            int val = grid[r][c] - 1; // grid values 1 to 6
            
            if(r==m-1 and c==n-1) return true;
            
            // 2 directions from every cell
            for(int k=0;k<2;k++) 
            {
                int idx = 2*val+k;   // get index
                int newrow = r + dir[idx][0];
                int newcol = c + dir[idx][1];
                if (newrow < 0 or newrow >= m or newcol < 0 or newcol >= n or visited[newrow][newcol]==true) 
                    continue;
            
                for(int x=0;x<2;x++)
                {
                    int i = 2*(grid[newrow][newcol]-1)+x;   // get index
                    if(r == newrow+dir[i][0] and c == newcol+dir[i][1]){
                        visited[newrow][newcol] = true;
                        q.push({newrow, newcol});
                    }       
                }
            }
        }
        return false;
    }