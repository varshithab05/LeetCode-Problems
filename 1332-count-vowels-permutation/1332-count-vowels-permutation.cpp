class Solution {
public:
    int countVowelPermutation(int n) {
        long long preva = 1 , preve = 1 , previ = 1 , prevo = 1 , prevu = 1;
        int mod = 1e9 + 7 ;

        for(int length = 2; length <= n ; length++)
        {
           long long Nexta = (preve+prevu+previ)%mod;
           long long Nexte = (preva+previ) %mod;
           long long Nexti = (preve+prevo)%mod;
           long long Nexto = previ;
           long long Nextu = (prevo+previ)%mod;

           preva = Nexta;
           preve = Nexte;
           previ = Nexti;
           prevo = Nexto;
           prevu = Nextu;
        }
        return (preva+preve+previ+prevo+prevu)%mod;
    }
};