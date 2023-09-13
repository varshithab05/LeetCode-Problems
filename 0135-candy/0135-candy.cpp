class Solution {
public:
    int candy(vector<int>& ratings) {
      int n=ratings.size();
      int up = 0;
      int down = 0;
      int peak = 0;
      int total = 1;

      for(int i=1;i<n;i++)
      {
        if(ratings[i]>ratings[i-1])
        {
          down=0;
          up+=1;
          peak=up+1;
          total+=peak;
        }
        else if(ratings[i-1]==ratings[i])
        {
          down=0;
          up=0;
          peak=0;
          total+=1;
        }
        else{
          down+=1;
          up=0;
          total+=down+1-(peak>down);
        }
      }
      return total;
    }
};