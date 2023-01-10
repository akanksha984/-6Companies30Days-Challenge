class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int> pq;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                pq.push(grid[i][j]);
        }
        for(int k=1; k<min(m, n); k++){
            for(int i=0; i+2*k<m; i++){
                for(int j=0; j+2*k<n;j++){
                    int sum=0;
                    for(int x=0; x<k; x++){
                        sum+=grid[i+k-x][j+x]; //left to up
                        sum+=grid[i+x][j+k+x]; //top to right
                        sum+=grid[i+k+x][j+2*k-x]; //right to down
                        sum+=grid[i+2*k-x][j+k-x]; //bottom to left
                    }
                    pq.push(sum);
                }
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            if(ans.empty()||ans.back()!=pq.top()) //for distinct values
                ans.push_back(pq.top());
            if(ans.size()==3)
                return ans;
            pq.pop();
        }
        return ans;
    }
};
