int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>>adjacent[n];
        for(auto i:flights)
        {
            adjacent[i[0]].push_back({i[1],i[2]});
        }
        queue<pair<int,pair<int,int>>>qu;
        qu.push({0,{src,0}});
        vector<int>distance(n,INT_MAX);
        distance[src]=0;
        while(!qu.empty())
        {
            auto it=qu.front();
            qu.pop();
            int stops=it.first;
            int node=it.second.first;
            int weight=it.second.second;
            if(stops>K)
                continue;
            for(auto i:adjacent[node])
            {
                int adj_Node=i.first;
                int adj_Wt=i.second;
                if(weight+adj_Wt<distance[adj_Node])
                {
                    qu.push({stops+1,{adj_Node,weight+adj_Wt}});
                    distance[adj_Node]=weight+adj_Wt;
                }
            }
        }
        if(distance[dst]==INT_MAX)
            return -1;
        return distance[dst];  
    }