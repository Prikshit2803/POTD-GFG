// Greedy Approach (Correct Solution):
// Intuition:
// Use a greedy algorithm to solve the problem.
// Not exactly maxima-minima but close.
// Buy the stock when the price is lower than the next price.
// Sell the stock when the price is higher than the next price.
// Add the difference to the profit for each transaction.

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &price) {
        
        //greedy approach where we sell as soon as we find a price larger than current
        int profit=0;
        
        for(int i=1;i<n;i++){
            if(price[i]>price[i-1]){
                profit+=price[i]-price[i-1];
            }
        }
        return profit;
    }
};


// Pure Local Maxima and Local Minima Approach (Alternative Approach):
// Intuition: 
// Find local minima and maxima in the price array
// Local minima: price lower than previous and next days
// Local maxima: price higher than previous and next days
// Buy at local minima, sell at next local maxima
// Profit maximization vroom vroom

class Solution {
public:
    int stockBuyAndSell(int n, vector<int> &price) {
        int i = 0, buy = 0, sell = 0, profit = 0;
        while (i < n - 1) {
            // Find next local minima
            while (i < n - 1 && price[i + 1] <= price[i])
                i++;
            buy = i++;
            // Find next local maxima
            while (i < n && price[i] >= price[i - 1])
                i++;
            sell = i - 1;
            // Add profit
            profit += price[sell] - price[buy];
        }
        return profit;
    }
};
