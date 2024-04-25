int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<vector<pair<int,bool>>> list(n+1);
            
            for(vector<int>& edge : edges){
                int u = edge[0], v = edge[1];
                list[u].push_back({v, false});
                list[v].push_back({u, true});
            }
            
            deque<pair<int,int>> dq;
            vector<int> dist(n+1, INT_MAX);
            
            dq.push_back({0, src});
            dist[src] = 0;
            
            while(not dq.empty()){
                pair<int,int> front = dq.front();
                dq.pop_front();
                
                int d = front.first;
                int u = front.second;
                
                if(u == dst){
                    return d;
                }
                
                for(pair<int,bool>& it : list[u]){
                    int v = it.first;
                    bool isRev = it.second;
                    
                    if(dist[v] > dist[u] + isRev){
                        dist[v] = dist[u] + isRev;
                        
                        if(isRev){
                            dq.push_back({dist[v], v});
                        }
                        else{
                            dq.push_front({dist[v], v});
                        }
                    }
                }
            }
            return -1;  
        }