vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int, int>> adjacent[n];

        for (auto x : edges) {
            adjacent[x[0]].push_back({x[1], x[2]});
            adjacent[x[1]].push_back({x[0], x[2]});
        }

        vector<int> ans(n, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (ans[node] != -1 || t >= disappear[node])
                continue;

            ans[node] = t;

            for (auto i : adjacent[node]) {
                int ans1 = i.first;
                int ans2 = i.second;
                if (t + ans2 < disappear[ans1]) {
                    pq.push({t + ans2, ans1});
                }
            }
        }
        return ans;
    }