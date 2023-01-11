//https://leetcode.com/problems/increasing-triplet-subsequence/description/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)return false;
        int i=INT_MAX; int j= INT_MAX;
        for (auto val : nums){
            if (val<= i){
                i= val;
            }
            else if (val<=j){
                j= val;
            }
            else return true;
        }
        return false;
    }
};
