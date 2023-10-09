class Solution {
    int search(vector<int> &nums,int target,bool findFirst)
    {
        int s = 0 , e = nums.size()-1 ;
        int index = -1;

        while(s <= e)
        {
            int mid = s + (e - s)/2 ;

            if(nums[mid] == target)
            {
                index = mid;
                if(findFirst){
                    e = mid - 1;
                }else
                    s = mid + 1;
            }else if(nums[mid] < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int strt = search(nums,target,1);
        int end = search(nums,target,0);

        return {strt,end};
    }
};