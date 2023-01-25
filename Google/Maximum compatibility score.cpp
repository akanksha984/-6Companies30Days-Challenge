class Solution {
public:
    int count(int i,int j,vector<vector<int>>&s,vector<vector<int>>&m){
        int ct=0;
        for(int k=0;k<s[i].size();k++){
            if(s[i][k]==m[j][k])ct++;
        }
        
        return ct;
    }
    
    int func(int i,vector<int>&vis,vector<vector<int>>&st,vector<vector<int>>&men){
        if(i==st.size())return 0;
        
        int ans=0;
        for(int j=0;j<vis.size();j++){
            int comp=0;
            if(!vis[j]){
                vis[j]=1;
                comp=count(i,j,st,men)+func(i+1,vis,st,men);
                
                vis[j]=0;
            }
            ans=max(ans,comp);
        }
        
        return ans;
    }
    
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        int n=students.size(),m=students[0].size();
        vector<int>vis(n);
        
        return func(0,vis,students,mentors);
    }
};
