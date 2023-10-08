class Solution {
public:
    vector<vector<int>> mem;

    int dp(int i,int j,vector<int> &nums1 , vector<int> &nums2)
    {
        if(i==nums1.size() || j==nums2.size())return 0;

        if(mem[i][j] != 0)return mem[i][j];

        int use = nums1[i] * nums2[j] + dp(i+1,j+1,nums1,nums2);

        mem[i][j] = max(use , max(dp(i+1,j,nums1,nums2),dp(i,j+1,nums1,nums2)));

        return mem[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(int num:nums1){
            max1 = max(max1,num);
            min1 = min(min1,num);
        }
        for(int num:nums2){
            max2 = max(max2,num);
            min2 = min(min2,num);
        }

        if(max1<0 && min2 >0)return max1*min2;

        if(min1>0 && max2<0)return min1*max2;

        mem = vector(nums1.size(),vector(nums2.size(),0));
        return dp(0,0,nums1,nums2);
    }
};