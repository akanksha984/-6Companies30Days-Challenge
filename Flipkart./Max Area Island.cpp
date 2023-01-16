//https://leetcode.com/problems/max-area-of-island/description/

// dfs

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int& cnt,int dx[], int dy[]){
        vis[i][j]=1;
        cnt++;
        for (int it=0; it<4; it++){
            int nr= i+dx[it];
            int nc= j+dy[it];
            if (nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1 && !vis[nr][nc])dfs(nr,nc,grid,vis,cnt,dx,dy);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        int n= grid.size(); int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[]= {1,0,-1,0};
        int dy[]= {0,1,0,-1};
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]==1 && !vis[i][j]){
                    int cnt=0;
                    dfs(i,j,grid,vis,cnt,dx,dy);
                    maxi= max(cnt,maxi);
                }
            }
        }
        return maxi;
    }
}; 





//bfs

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        int n= grid.size(); int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[]= {1,0,-1,0};
        int dy[]= {0,1,0,-1};
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]==1 && !vis[i][j]){
                    int cnt=0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=1;
                    while (!q.empty()){
                        int x= q.front().first;
                        int y= q.front().second;
                        cnt++;
                        q.pop();
                        for (int k=0; k<4; k++){
                            int nr= x+ dx[k];
                            int nc= y+ dy[k];
                            if (nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                            }
                        }
                    }
                    maxi= max(cnt,maxi);
                }
            }
        }
        return maxi;
    }
};
