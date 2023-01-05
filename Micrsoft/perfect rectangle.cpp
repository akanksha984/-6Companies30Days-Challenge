#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mp;
        for(auto &it : rectangles){
            mp[{it[0], it[1]}]++;
            mp[{it[2], it[3]}]++;
            mp[{it[0], it[3]}]--;
            mp[{it[2], it[1]}]--;

        }
        int cnt = 0;

        for(auto it: mp){
            if(abs(it.second) == 1){
                cnt++;
            }else if(abs(it.second != 1) && it.second != 0){
                return false;
            }
            
        }
        return cnt == 4;
    }
};