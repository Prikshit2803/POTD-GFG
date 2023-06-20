// iF MATHSTICKS is divisible by 5 and A has first turn A will lose if bith A and B try to win and in other cases A should take N%5 moves as 
// it will leave B to have a turn first with N%5==0 matchsticks hence B will lose no matter what


//If number of matchsticks is divisible by 5, then A will always lose if B plays optimally.

class Solution {
  public:
    int matchGame(long long N) {
        if(N%5==0)
        return -1;
        
        else 
        return N%5;
    }
};
