#define pp pair< int , pair<int , int >>
int dfs(vector<int> adj[] , int sv , int &vis1 , int &vis2 , int par , int root_nd , int &ans)
{
    if(adj[sv].size()==1 && sv!=root_nd)
    {
        return 1;
    }
   
    int l1=0 , l2=0 , value=INT_MIN ;
   
    for(auto i : adj[sv])
    {
        if(par!=i)
        {
            int temp = dfs(adj , i , vis1 , vis2 , sv , root_nd ,ans );
           
            value = max(value , temp);
           
            if(temp >= l1)
            {
                l2=l1;
                l1=temp;
            }
            else
            if(temp>l2)
            {
                l2=temp;
            }
           
        }
    }
   
    if(ans < (l1+l2))
    {
        ans=l1+l2;
    }
   
    return value + 1;
}

int Solution::solve(vector<int> &nums) {
   
    int n=nums.size();
   
    vector<int> adj[n];
   
    int root_nd;
   
    for(int i=0;i<n;i++)
    {
        if(nums[i]==-1)
        {
            root_nd=i;
        }
        else
        {
            adj[nums[i]].push_back(i);
            adj[i].push_back(nums[i]);
        }
    }
   
    int ans=0;
    int vis1 , vis2 ;
   
    dfs(adj , root_nd , vis1 , vis2 , -1 , root_nd , ans);
   
    return ans;
}