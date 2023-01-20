class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u][v] = wt;
            adj[v][u] = wt;
        }
        for(int i=0;i<n;i++){
            adj[i][i] = 0;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k] == INT_MAX || adj[k][j] == INT_MAX)
                        continue;
                    if(i == k || j == k)
                        continue;
                    
                    if(adj[i][k] + adj[k][j] < adj[i][j])
                        adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
        
        
        int ans = -1;
        int s = INT_MAX;
        for(int i=0;i<n;i++){
            int temp = 0;
            for(int j=0;j<n;j++){
                if(adj[i][j] <= distanceThreshold)
                    temp++;
            }
            if(temp <= s){
                s = temp;
                ans = i;
            }
        }
        return ans;
    }
};
