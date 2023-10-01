class Solution {
public:
    string reverseWords(string s) {
        int strt = 0;
        for(int e=0;e<s.length();++e){
            if(s[e]==' '){
                reverse(s.begin()+strt,s.begin()+e);
                strt = e+1;
            }
        }
        reverse(s.begin()+strt,s.end());
        return s;
    }
};