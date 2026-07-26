class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>charindex(256,-1);
        int left =0;
        int maxlen =0;
        for(int r=0;r<s.size();++r){
            char c = s[r];
            if(charindex[c]>=left){
                left = charindex[c]+1;
            }
          charindex[c]=  r ;
          maxlen = max(maxlen,r-left+1);

        }
        return maxlen;
    }
};
