class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        vector<int> charcount(128, 0);
        for (int c : t) {
            charcount[c]++;
        }
        int left = 0, right = 0;
        int required = t.length();
        int minlen = INT_MAX;
        int startindex = 0;

        while (right < s.length()) {
            if (charcount[s[right]] > 0) {
                required--;
            }
            charcount[s[right]]--;
            right++;
            while (required == 0) {
                if (right - left < minlen) {
                    minlen = right - left;
                    startindex = left;
                }
                charcount[s[left]]++;

                if(charcount[s[left]]>0){
                    required++;
                }
                left++;
            }
        }
        return minlen ==INT_MAX?"":s.substr(startindex,minlen);
    }
};
