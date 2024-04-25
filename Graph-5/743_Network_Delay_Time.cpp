int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> distance(N + 1, INT_MAX);
        distance[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> edge : times) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, distance[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }