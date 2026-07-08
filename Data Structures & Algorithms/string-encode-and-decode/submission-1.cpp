class Solution {
public:

    string encode(vector<string>& strs) {
string encoded;
for(string en:strs){
    encoded += to_string(en.size())+"#"+en;
}
return encoded;
    }

    vector<string> decode(string s) {
int i=0;
vector<string>res;
while( i<s.size()){
    int j =i;
    while(s[j]!='#')j++;
    int len = stoi(s.substr(i,j-i));
    string word  = s.substr(j+1,len);
    res.push_back(word);
i = j+1+len;
}
return res;
    }
};
