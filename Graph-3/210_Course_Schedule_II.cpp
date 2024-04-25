class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for (auto i : prerequisites) {
        int course = i[1]; 
        int prereq = i[0];
        adj[course].push_back(prereq); 
    }
        vector<int> indeg(numCourses, 0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
                indeg[it]++;
            }
        }
        queue<int>qu;
        for(int i=0;i<numCourses;i++)
        {
            if( indeg[i]==0)
            {
                qu.push(i);
            }
        }
        vector<int>temp;
        while(!qu.empty())
        {
            int node=qu.front();
            qu.pop();
            temp.push_back(node);
            for(auto it:adj[node])
            {
                indeg[it]--;
                if( indeg[it]==0)
                {
                    qu.push(it);
                }
                
            }
        }
        vector<int>emty;
        if(temp.size()!=numCourses)
        {
            return emty;
        }
        return temp; 
    }
};