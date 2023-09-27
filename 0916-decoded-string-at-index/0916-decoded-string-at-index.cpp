class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<long long> charlen;

        charlen.push(0);
        for(size_t i = 0;i<s.length();i++){
            if(isdigit(s[i])){
                long long len = charlen.top()*(s[i]-'0');
                charlen.push(len);
            }else{
                long long len = charlen.top()+1;
                charlen.push(len);
            }
        }

        size_t ln = charlen.size();
        while(!charlen.empty()){
            k %= charlen.top();
            ln--;
            if(k==0 && isalpha(s[ln-1])){
                return string(1,s[ln-1]);
            }
            charlen.pop();
        }

        return "";
    }
};