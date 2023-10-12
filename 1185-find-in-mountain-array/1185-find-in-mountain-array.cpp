/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeakIndex(int low , int high , MountainArray &mountainArr)
    {
        while(low != high){
            int mid = low + (high - low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low = mid + 1 ;
            }else{
                high = mid;
            }
        }
        return low;
    }
    int binarySearch(int low, int high, int target, MountainArray &mountainArr, bool reversed) {
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (reversed) {
                if (mountainArr.get(mid) > target)
                    low = mid + 1; 
                else
                    high = mid; 
            } else {
                if (mountainArr.get(mid) < target)
                    low = mid + 1; 
                else
                    high = mid;
            }
        }
        return low;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peakIndex = findPeakIndex(1,n-2,mountainArr);

        int incIndx = binarySearch(0,peakIndex,target,mountainArr,false);
        if (mountainArr.get(incIndx) == target) 
            return incIndx;

        int decIndx = binarySearch(peakIndex + 1,n - 1, target, mountainArr, true);
        if (mountainArr.get(decIndx) == target) 
            return decIndx; 

        return -1; 
    }
};