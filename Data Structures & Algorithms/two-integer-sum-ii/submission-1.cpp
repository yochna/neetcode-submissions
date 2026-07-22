class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
     int l=0, r= a.size()-1;
     while(l<r){
        int cur = a[l]+a[r];
        if(cur>target){
            r--;
        }
        else if(cur<target){
            l++;
        }
        else{
            return {l+1,r+1};
        }
     }
        return {};
    }
};
