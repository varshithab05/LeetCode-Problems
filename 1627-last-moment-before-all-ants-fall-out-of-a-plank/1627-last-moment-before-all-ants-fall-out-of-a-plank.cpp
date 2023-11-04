class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());

        int l = left.size()-1;
        int r = right.size()-1;

        if(left.size()==0 && right.size()==0)
            return n;
        if(left.size()==0){
            return n-right[0];
        }
        if(right.size()==0){
            return left[l];
        }

        
        return max(left[l],n-right[0]);
    }
};