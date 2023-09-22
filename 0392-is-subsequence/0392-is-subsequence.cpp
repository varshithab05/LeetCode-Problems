class Solution {
public:
    int isSubs(string& s1, string& s2, int i , int j,vector<vector<int>> &t1)
    {
        if(i == 0 || j == 0)
            return 0;
        if(t1[i][j] != -1)
            return t1[i][j];
        if(s1[i-1] == s2[j-1])
            return t1[i][j] = 1 + isSubs(s1,s2,i-1,j-1,t1);
        else
            return t1[i][j] = isSubs(s1,s2,i,j-1,t1);
    }
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // intialising dp matrix with -1
        
        if(m >  n)
            return false;
        
        vector<vector<int>> t1(m+1,vector<int> (n+1,-1));
    
        if(isSubs(s,t,m,n,t1) == m)
            return true;
        return false;
    }
};