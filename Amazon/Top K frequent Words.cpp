// https://leetcode.com/problems/top-k-frequent-words/description/

class comp{
    public:
        bool operator()(pair<int,string>& a, pair<int,string>& b){
            if (a.first!= b.first){
                return b.first < a.first;
            }
            return b.second > a.second;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for (auto word: words){
            mp[word]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        for (auto val: mp){
            cout<<val.first<<" : "<<val.second<<endl;
            pair<int,string> value= {val.second,val.first};
            pq.push(value);
            if (pq.size()>k){
                pq.pop();
            }
        }
        vector<string> ans;
        while (!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
