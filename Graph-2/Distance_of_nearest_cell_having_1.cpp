vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    queue<pair<pair<int,int>,int>>q;
	    vector<vector<int>>dist(n,vector<int>(m,0));
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                vis[i][j] = 1;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	    int delrow[] = {-1,0,1,0};
	    int delcol[] = {0,1,0,-1};
	    
	    while(!q.empty())
	    {
	        int Row = q.front().first.first;
	        int Col = q.front().first.second;
	        int moves = q.front().second;
	        q.pop();
	        dist[Row][Col] = moves;
	        
	        for(int i = 0; i < 4; i++)
	        {
	            int newrow = Row + delrow[i];
	            int newcol = Col + delcol[i];
	            
	            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && vis[newrow][newcol]==0)
	            {
	                vis[newrow][newcol]=1;
	                q.push({{newrow,newcol},moves+1});
	            }
	        }
	    }
	    return dist;
	}
