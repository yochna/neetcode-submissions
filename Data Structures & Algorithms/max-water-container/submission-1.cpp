class Solution {
public:
    int maxArea(vector<int>& a) {
        int l =0, r= a.size()-1,res =0;
        while(l<r){
            int area = (r-l)*min(a[r],a[l]);
            res = max(res,area);
            if(a[l]<=a[r]){
                l++;
            }
            else{
                r--;
            }

        }
        return res;
    }
};
