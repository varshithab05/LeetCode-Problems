class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();

        if(len<3)return false;

        stack<int> decstack;

        int maxThirdEle = INT_MIN;

        for(int i=len-1;i>=0;i--)
        {
            int currNum = nums[i];
            if(currNum<maxThirdEle)return true;

            while(!decstack.empty()&&decstack.top() < currNum){
                maxThirdEle = decstack.top();
                decstack.pop();
            }
            
            decstack.push(currNum);
        }
        return false;
    }
};