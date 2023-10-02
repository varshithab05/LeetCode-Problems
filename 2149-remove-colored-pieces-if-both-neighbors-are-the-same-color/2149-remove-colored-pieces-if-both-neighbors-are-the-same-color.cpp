class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceScore = 0 ;
        int bobScore = 0 ;
        int n = colors.size();

        for(int i = 1 ; i < colors.size()-1;i++)
        {
            if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A')aliceScore++;
            else if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B')bobScore++;
        }

        return aliceScore>bobScore;
        
    }
};