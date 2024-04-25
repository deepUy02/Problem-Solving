class Solution {
public:
    bool isCycle(vector<vector<int>> &adj, vector<int> &visited, int &vertex){
        if(visited[vertex] == 1){
            return true;
        }
        visited[vertex] = 1; // Mark the node as processing

        for(auto &i: adj[vertex]){
                if(visited[i] != 2){
                if(isCycle(adj, visited, i)) return true;
            }
        }
        visited[vertex] = 2; // Mark it as processed
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        if(numCourses == 0 or numCourses == 1) return true;

        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);

        for(int i = 0; i < n; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int vertex = 0; vertex < numCourses; vertex++){
            if(visited[vertex] == 0){
                if(isCycle(adj, visited, vertex)) return false;
            }
        }
        return true;
    }
};