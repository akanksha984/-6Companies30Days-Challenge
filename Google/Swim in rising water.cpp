class Solution {
private:
    bool isValid(int index, int lim){
        return index >= 0 && index < lim;
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({(-1)*grid[0][0], {0, 0}});
        grid[0][0] = -grid[0][0];
        
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        
        int res = 0;
        while(!pq.empty()){
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int elevation = (-1)*pq.top().first;
            pq.pop();
            
            res = max(res, elevation);
            if(i == m-1 && j == n-1) return res;
                
            for(int k=0; k<4; k++){
                int x = i+dx[k];
                int y = j+dy[k];
                
                if(isValid(x, m) && isValid(y, n) && grid[x][y] >= 0){
                    pq.push({(-1)*grid[x][y], {x, y}});
                    grid[x][y] = -grid[x][y];
                }
            }
        }
        return -1;
    }
};
