class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        unordered_set<int> s ;

        for(int x:nums){
            s.insert(x);
        }

        vector<int> unique(s.begin(),s.end());
        sort(unique.begin(),unique.end());

        int j = 0 ;
        int m = unique.size();

        for(int i = 0; i<m ; i++)
        {
            while(j<m && unique[j] < unique[i]+n){
                j++;
            }
            ans = min(ans,n-j+i);
        }
        return ans;
    }
};