class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> traversal;
        vector<bool> visited(V,false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            traversal.push_back(u);
            for(auto neighbour : adj[u]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        
        return traversal;
    }
};
