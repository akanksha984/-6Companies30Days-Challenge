// https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        int ni=0, mi=0;
        for (int i=1; i<=n; i++){
            int x=i;
            while (x%2==0){
                x= x>>1;
                ni++;
            }
            while (x%5==0){
                x= x/5;
                mi++;
            }
        }
        return min(mi,ni);
    }
};


// 100% Fastest Solution:
class Solution {
public:
    int trailingZeroes(int n) {
        int mi=0;
        for (int i=5; i<=n; i+=5){
            int x=i;
            while (x%5==0){
                x= x/5;
                mi++;
            }
        }
        return mi;
    }
};
