class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod=1e9+7;
        vector<long> v(n+1,0l);
        v[1]=1l;
        for(int i=2; i<=n; i++){
            if(i>forget)
                v[i-forget]=0;
            for(int j=1; j<=i-delay; j++){
                v[i]=(v[i]%mod+v[j]%mod)%mod;
            }
        }
        return accumulate(v.begin(),v.end(),0l)%mod;
    }
};
