// https://leetcode.com/problems/custom-sort-string/description/

string order1;
static bool cmp(char& a, char& b){
    return order1.find(a)<order1.find(b);
}
class Solution {
public:
    string customSortString(string order, string s) {
        /* for (int i=0; i<26; i++)v.push_back(0);
        int start= 26;
        for (auto ch : order){
            v[ch-'a']= start;
            start--;
        } */
        order1= order;
        sort(s.begin(),s.end(),cmp);
        return s;

    }
};
