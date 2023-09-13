class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i=1,j=0;
        vector<string> ans;
        stack<int> stk;
        
        while(i<=n && j<target.size())
        {
            stk.push(i++);
            ans.push_back("Push");
            if(target[j]==stk.top())
            {
                j++;
            }else{
                stk.pop();
                ans.push_back("Pop");
            }
        }
        
        return ans;
    }
};