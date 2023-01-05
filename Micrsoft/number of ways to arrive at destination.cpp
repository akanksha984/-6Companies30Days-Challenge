#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod = (1e9+7);
        vector<pair<long,long>>adj[n];
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long>ways(n,0);
        vector<long>dis(n,LONG_MAX);
        ways[0] = 1;
        dis[0]= 0;
        
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            long node = pq.top().second;
            long dist = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node])
            {
                long adjnode = it.first;
                long wt = it.second;
                
                if(dist+wt<dis[adjnode])
                {
                    dis[adjnode] = dist+wt;
                    ways[adjnode]=ways[node];
                    
                    pq.push({wt+dist,adjnode});
                }
                else if(dist+wt==dis[adjnode])
                {
                    ways[adjnode]=( ways[adjnode]+ways[node])%mod;
                }
            }
        }
        for(auto it: ways)
        {
            cout<<it<<" ";
        }
        return ways[n-1];
    }
};