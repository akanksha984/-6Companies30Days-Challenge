#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s=0; int e=nums.size()-1;
        int firstele=INT_MAX, lastele=INT_MIN;
        int n= nums.size();
        for (int i=0; i<n-1; i++){
            if (nums[i]>nums[i+1]){
                firstele=min(nums[i+1], firstele);
                lastele=max(nums[i], lastele);
            }
        }
    if(lastele==INT_MIN){
        return 0;
    }
    for(int i=0; i<n; i++){
        if(nums[i]>firstele){
            s=i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(nums[i]<lastele){
            e=i;
            break;
        }
    }
    return (e-s+1);
    }
};