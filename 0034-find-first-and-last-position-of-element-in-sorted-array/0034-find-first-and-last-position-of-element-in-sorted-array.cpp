class Solution {
    int searchFirst(vector<int> &nums,int target)
    {
        int s = 0 , e = nums.size()-1 ;
        int first = -1;

        while(s <= e)
        {
            int mid = s + (e - s)/2 ;

            if(nums[mid] == target)
            {
                first = mid;
                e = mid - 1;
            }else if(nums[mid] < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return first;
    }
    int searchLast(vector<int> &nums,int target)
    {
        int s = 0 , e = nums.size()-1 ;
        int end = -1;

        while(s <= e)
        {
            int mid = s + (e - s)/2 ;

            if(nums[mid] == target)
            {
                end = mid;
                s = mid + 1;
            }else if(nums[mid] < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return end;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int strt = searchFirst(nums,target);
        int end = searchLast(nums,target);

        return {strt,end};
    }
};