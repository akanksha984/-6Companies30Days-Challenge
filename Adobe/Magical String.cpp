class Solution {
public:
int magicalString(int n) {

    string s="122";
    int c=2;int m=1;
    if (n<=3)return 1;
    int count=0;
    while(c<n && s.size()<n)
    {
        int ac=s[c]-'0';
        //if(ac==1)count++;
        if (m==1)
        {
            if(ac==2)
            s+="11";
            else
            s+='1';

        }
        else
        {
            if(ac==2)
            s+="22";
            else
            s+='2';
        }
        c++;
        m=(m==2)?1:2;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')count++;
    }
    return count;
}
};
