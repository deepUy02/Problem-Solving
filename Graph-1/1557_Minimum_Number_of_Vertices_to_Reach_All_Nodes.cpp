vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
     vector<int> indrg(n);
     for (auto& e : edges) {
        indrg[e[1]]++;
     }
     vector<int> ans;
     for (int i = 0; i < n; i++) {
        if (indrg[i] == 0) ans.push_back(i);
     }
     return ans; 
}