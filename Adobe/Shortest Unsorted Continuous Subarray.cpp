// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i=0; int j= nums.size()-1;
        vector<int> demo(nums);
        sort(demo.begin(),demo.end());
         while (i<=j){
            if (demo[i]!=nums[i])break;
            i++;
        }
        while (i<j){
            if (demo[j]!=nums[j])break;
            j--;
        }
        return j-i+1;
    }
};
