#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        int buy = prices[0],sell,profit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]-buy>0){
              sell = prices[i]-buy;
              profit+=sell;
            }
            buy = prices[i];
        }
      return profit;
}

int main(){
	vector<int> prices = {7,1,5,3,6,4};	
	cout<<"maxProfit: "<<maxProfit(prices);
	return 0;
}
