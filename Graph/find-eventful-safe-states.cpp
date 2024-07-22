class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph , vector<bool>& vis, vector<bool>& inStack){
        if(inStack[node]){
            return true;
        }

        if(vis[node]){
            return false;
        }


        vis[node] = true;
        inStack[node] = true;
         for(auto n: graph[node]){
            if(dfs(n, graph, vis, inStack)){
                return true;
            }
        }

        inStack[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        int n = graph.size();
        vector<bool> visited(n, false), inStack(n, false) ;
        for(int i=0; i<n; i++){
            dfs(i, graph, visited, inStack);
        }

        for(int i=0; i<n; i++){
if(!inStack[i]){
    result.push_back(i);
}
        }

        return result;
    }
};
