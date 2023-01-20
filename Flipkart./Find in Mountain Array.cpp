
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length(),lo=0,hi=len-1,mid;
        while(lo< hi){
            mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid+1))
                hi=mid;
            else
                lo=mid+1;
        }
        int pk_idx=lo;
        if(mountainArr.get(pk_idx)==target) return pk_idx;
        lo=0,hi=pk_idx;
        while(lo< hi){
            mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)>=target)
                hi=mid;
            else
                lo=mid+1;   
        }
        if(mountainArr.get(lo)==target)
            return lo;
        lo=pk_idx,hi=mountainArr.length()-1;
        while(lo< hi){
            mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)<=target)
                hi=mid;
            else
                lo=mid+1;
                
        }
        if(mountainArr.get(lo)==target)
            return lo;
        return -1;
    }

};
