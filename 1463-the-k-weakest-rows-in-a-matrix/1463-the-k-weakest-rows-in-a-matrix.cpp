class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> soldiers;
        // Calculate the sum of soldiers for each row and store in the min heap
        for(int row = 0; row < mat.size(); row++) {
            int soldierCount = findSoldierCount(mat[row]);
            soldiers.push_back({soldierCount, row});
        }

        // Extract the k weakest row indices
        sort(soldiers.begin(), soldiers.end());
        vector<int> weakestRows;
        for(int i = 0 ; i < k ; i ++){
            weakestRows.push_back(soldiers[i].second);
        }
        return weakestRows;
    }
    int findSoldierCount(vector<int> &row) {
        int left = 0, right = row.size() - 1;

        // Perform binary search to find the count of soldiers
        while (left <= right) {
            int mid = (left + right) / 2;
            if (row[mid] == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};