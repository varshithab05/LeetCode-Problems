class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int limit = n / 4;
        int count = 1;
        int ans = arr[0];
        for (int i = 1 ; i < n ; i++) {

            if ( ans == arr[i]) count++;
            else count = 1;
            
            if (count > limit) return arr[i];
            
            ans = arr[i];
        }

        return ans; 
    }
};