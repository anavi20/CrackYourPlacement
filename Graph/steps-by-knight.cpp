class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int x[8] = {-2,-2,-1,-1,1,1,2,2};
	    int y[8] = {-1,1,-2,2,-2,2,-1,1};
	    unordered_map<int, unordered_map<int, bool>> vis;
	    queue<vector<int>> q;
	    vis[KnightPos[0]][KnightPos[1]] = true;
	    q.push(KnightPos);
	    int steps = 0;
	    while(!q.empty()){
	        int sz = q.size();
	        while(sz--){
	            vector<int> currPos = q.front();
	            q.pop();
	            int x_c = currPos[0], y_c = currPos[1];
	            if(x_c == TargetPos[0] && y_c  == TargetPos[1]){
	                return steps;
	            }
	            for(int i=0; i<8; i++){
	                int new_x = x_c + x[i], new_y = y_c + y[i];
	                if(new_x >=1 && new_y >=1 && new_x <= N && new_y <= N && vis[new_x][new_y] == false){
	                    vis[new_x][new_y] = true;
	                    q.push({new_x,new_y});
	                }
	            }
	            
	        }
	        steps++;
	    }
	    
	    return -1;
	    
	}
};
