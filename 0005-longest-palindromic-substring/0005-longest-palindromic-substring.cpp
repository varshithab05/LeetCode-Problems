class Solution {
public:
    string longestPalindrome(string s) {
        string snew = "^#";
        for(auto c:s){
            snew+=c;
            snew+="#";
        }
        snew+= "#$";

        int n = snew.size();
        vector<int> p(n,0);
        int c = 0 , r = 0;

        for(int i=1;i<n-1;i++){
            p[i] = (r>i) ? min(r-i,p[2*c-i]):0;

            while(snew[i+1+p[i]]==snew[i-1-p[i]])
                p[i]++;

            if(i+p[i]>r){
                c = i;
                r = i +p[i];
            }
        }

        int len = *max_element(p.begin(), p.end());
        int indx = distance(p.begin(),find(p.begin(),p.end(),len));

        return s.substr((indx-len)/2,len);
    }
};