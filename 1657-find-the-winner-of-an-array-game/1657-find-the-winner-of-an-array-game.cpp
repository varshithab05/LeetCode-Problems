class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0];
        int winCount = 0 ;
        int n = arr.size();

        for(int i = 1 ; i < n ; i++){
            if(arr[i] > winner){
                winner = arr[i];
                winCount = 1 ;
            }else{
                winCount++;
            }
            if(winCount == k)
                return winner;
        }
        return winner;
    }
};