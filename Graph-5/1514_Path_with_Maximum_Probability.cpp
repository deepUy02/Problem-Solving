double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> adjacent(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adjacent[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adjacent[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }
        vector<double> prob(n, 0);
        vector<int> parent(n, -1);
        priority_queue<pair<double, int>> pq;
        prob[start_node] = 1;
        pq.push({1, start_node});
        while (!pq.empty())
        {
            pair<double, int> it = pq.top();
            pq.pop();
            double pro = it.first;
            int v = it.second;
            for (auto i : adjacent[v])
            {
                int adj_Node = i.second;
                double w = i.first;
                if (prob[adj_Node] < prob[v] * w)
                {
                    prob[adj_Node] = prob[v] * w;
                    parent[adj_Node] = v;
                    pq.push({prob[adj_Node], adj_Node});
                }
            }
        }
        return prob[end_node];
    }