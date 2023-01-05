#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> stk;
        for (auto val: tokens){
            if (val=="+"|| val=="-"|| val=="*"|| val=="/"){
                long long int b= stk.top();
                stk.pop();
                long long int a= stk.top();
                stk.pop();
                if (val == "+"){
                    stk.push(a+b);
                }
                else if (val=="*"){
                    stk.push(a*b);
                }
                else if (val== "-"){
                    stk.push(a-b);    
                }
                else if (val=="/"){
                    stk.push(a/b);
                }
            }
            else {
                long long int num=0;
                for (int i=0; i<val.size(); i++){
                    if (i==0 && val[i]=='-'){continue;}
                    num*= 10;
                    num+= (val[i]-'0');
                }
                if (val[0]=='-')num*=-1;
                    stk.push(num);
                }
        }
        return stk.top();
    }
};
