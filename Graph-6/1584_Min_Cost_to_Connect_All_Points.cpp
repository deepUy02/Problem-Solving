int spanningTree(int V, vector<vector<vector<int>>> adjacent)
    {
       int ans = 0;
       vector<int> visited(V, 0);
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push({0, 0});
       while(!pq.empty()){
           int wt = pq.top().first;
           int node = pq.top().second;
           pq.pop();
           
           if(visited[node]) continue;
           else visited[node] = 1;
           ans+=wt;
           
           for(auto it: adjacent[node]){
               if(!visited[it[0]]){
                   pq.push({it[1], it[0]});
               }
           }
       }
       return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<vector<int>>> adjacent(points.size());
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                if(j!=i){
                    int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    adjacent[i].push_back({j, dist});
                }
            }
        }
        return spanningTree(points.size(), adjacent);
    }