#include "promotions.h"

using namespace std;

/*If you spend over £60, then you get 10% off your purchase*/
int total_rule(map<int, int>& basket, map<int, item>& products)
{
    int total = 0;

	for(map<int,int>::iterator item = basket.begin(); item != basket.end(); item++)
		total += item->second * products[item->first].price; //number of product in basket * unit price
    
	if(total > 6000)
		return total/10;
	else
		return 0;
}

/*
If you buy 2 or more chocolate gift sets then the price drops to £8.50. (from £9.25)

Although not explicitly stated, the test data implies that the promotional rules must be
applied consecutively (and in order). i.e. in this case, the total rule must be applied AFTER the lavender
rule such that the total rule is applied to the already reduced price. The implication is 
that this rule must modify the price of the products, rather than simply returning the
discount that this rule would effect (£0.75 per item):
	return 0.75*products[item][1] if basket[item] >= 2 else 0
*/
int chocolate_rule(map<int, int>& basket, map<int, item>& products)
{
    if(basket[001] >= 2)
        products[001].price = 850;

	//The price of the product has been adjusted
    return 0;
}