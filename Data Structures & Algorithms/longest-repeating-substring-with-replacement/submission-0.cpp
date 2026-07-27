class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>count(26,0);
        int left =0;
        int maxcount=0;
        int maxlength =0;
        for(int right =0;right<s.length();++right){
            count[s[right]-'A']++;
            maxcount = max(maxcount,count[s[right]-'A']);

            if((right-left+1)-maxcount>k){
                count[s[left]-'A']--;
                left++;
            }
            maxlength = max(maxlength,right-left+1);
        }
        return maxlength;
    }
};
