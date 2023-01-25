#define ll                 long long

class Solution {
public:

    // brute force // accepted
    int distinctEchoSubstrings(string& s) {
        unordered_set<string> st;
        for (int i = 0; i < s.size(); i++) {
            for (int len = 1; i + 2 * len <= s.size(); len++) {
                if (s.compare(i, len, s, i + len, len) == 0) st.insert(s.substr(i, len));
            }
        }
        return st.size();
    }
};
