#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    
    int minPrice = prices[0],maxProfit = 0,diff;

    for (int i = 1; i < prices.size(); i++) {
        diff = prices[i]-minPrice;
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }else if (diff > maxProfit) {
            maxProfit = diff;
        }
    }
    
    return maxProfit;
}
    
int main() {
    vector<int> prices ={7,1,5,3,6,4};
    cout<<maxProfit(prices);
    
    return 0;
}