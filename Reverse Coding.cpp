//You will be given an integer n, your task is to return the sum of all natural number less than or equal to n.

//As the answer could be very large, return answer modulo 10^9+7.

class Solution {
  public:
    int sumOfNaturals(int n) {
          long long temp = (pow(10,9)+7);
        long long sum= (((n%temp)*((n+1)%temp))/2);
        sum = sum%temp;
        return sum;
    }
};
