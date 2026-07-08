class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
    unordered_map<int,int>count;
    for(int ar:a){
        count[ar]++;
    }
    vector<pair<int,int>>arr;
    for(const auto& p:count){
        arr.push_back({p.second,p.first});
    }
    sort(arr.rbegin(),arr.rend());
    vector<int>res;
    for(int i=0;i<k;i++){
        res.push_back(arr[i].second);
    }
    return res;
    }
};
