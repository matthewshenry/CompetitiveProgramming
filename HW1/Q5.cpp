class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int sell=1;
        int maxDiff=0;
        while(sell<prices.size()){
            if(prices[buy]<prices[sell]){
                int currentDiff=prices[sell]-prices[buy];
                maxDiff=max(currentDiff, maxDiff);
            }else{
                buy=sell;
            }
            sell++;
        }
        return maxDiff;
    }