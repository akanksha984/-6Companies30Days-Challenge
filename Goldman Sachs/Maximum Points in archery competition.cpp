class Solution {
public:
    vector<int> ans;
    int Max=-1;
    int solve(int n,vector<int>&nums,vector<int>&a,int i,int M){
        if(i>=nums.size()){
            if(M>Max){
                Max = M;
                ans = a;
                ans[11] += n;
            }
            return M;
        }
        int t1 = 0;
        if(n>=nums[i]+1){
            a[i] = nums[i]+1;
            t1 += i +solve(n-nums[i]-1,nums,a,i+1,M+i);
            a[i] = 0;
        }
        t1 = max(t1,solve(n,nums,a,i+1,M));
        return t1;
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> a(12,0);
        int x = solve(numArrows,aliceArrows,a,0,0);
        return ans;
    }
};
