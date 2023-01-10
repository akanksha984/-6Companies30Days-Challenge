class Solution {
public:
// contraints are small so,
// take any two points and then we want to pass the points through this line only
// and then check how many points satify it
    int maxPoints(vector<vector<int>>& points) {
        int ans=2;
        int n= points.size();
        if (n<=2)return n;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                
                int dx1 = (points[i][0]-points[j][0]);
                int dy1 = (points[i][1]-points[j][1]);
                int y= __gcd(dx1,dy1);
                if(y!=0)dx1/= y;
                if(y!=0)dy1/= y;
                int curr=2;
                for (int k=0; k<n; k++){
                    if (k==i || k==j)continue;
                    int dx2= (points[k][0]-points[j][0]);
                    int dy2= (points[k][1]-points[j][1]);
                    int x= __gcd(dx2,dy2);
                    if(x!=0)dx2= dx2/x;
                    if(x!=0)dy2= dy2/x;
                    if (dx1==dx2 && dy1==dy2)curr++;
                }
                ans= max(ans,curr);
            }
        }
        return ans;
    }
};
