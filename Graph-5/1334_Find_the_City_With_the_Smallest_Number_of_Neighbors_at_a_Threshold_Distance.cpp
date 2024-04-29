int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n,vector<int>(n,1e9));
        for(auto nd : edges){
            distance[nd[0]][nd[1]] = nd[2];
            distance[nd[1]][nd[0]] = nd[2];

        } 
        for(int i=0;i<n;i++) distance[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                 if((distance[i][j] > distance[i][k] + distance[k][j]) && distance[i][k] !=1e9 && distance[k][j] !=1e9){
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
        vector<int> NumberOFreachableCITIES(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(distance[i][j]<=distanceThreshold){
                     NumberOFreachableCITIES[i]++;  
                }
            }
        }

        int mn=1e9;
        for(int i=0;i<n;i++){ 
            mn = min(mn,NumberOFreachableCITIES[i]);
        }
        int mx=-1;
        //finding  city with the greatest number If there are multiple such cities
        for(int i=0;i<n;i++){
            if(NumberOFreachableCITIES[i] == mn) mx = max(mx,i);  
        }
        return mx;
    }