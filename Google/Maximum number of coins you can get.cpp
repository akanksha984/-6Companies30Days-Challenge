//https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        sort(piles.begin(),piles.end());
        int cnt=0;
        for (int i= piles.size()-2; i>cnt; i-=2){
            ans+= piles[i];
            cnt++;
        }
        return ans;
    }
};
