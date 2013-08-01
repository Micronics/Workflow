#pragma once

#include <list>
#include <vector>
#include <map>

using namespace std;

struct item
{
	string name;
	int price;
};

typedef int (*rule)(map<int, int>& basket, map<int, item>& products);

class Checkout
{
public:
	Checkout(list<rule> promotional_rules)
	{
		promotions = promotional_rules;
		
		//Create some items and add them to the list of products
		item chocolate = {"Chocolate Gift Set", 925};
		item whiskey = {"whiskey", 4500};
		item tshirt = {"Kids T-Shirt", 1995};

		products[001] = chocolate;
		products[002] = whiskey;
		products[003] = tshirt;

		//Initialise the basket
		basket[001] = 0;
		basket[002] = 0;
		basket[003] = 0;
	}

	void scan(int item_code)
	{
		basket[item_code]++;
	}

	float total()
	{
		int discount = 0, total = 0;
		for(list<rule>::iterator promotion = promotions.begin(); promotion != promotions.end(); promotion++)
			discount += (*promotion)(basket, products);
        
		for(map<int, int>::iterator item = basket.begin(); item != basket.end(); item++)
            total += products[item->first].price * item->second;
        
        return float((total - discount)/100.0);
	}

private:
	list<rule> promotions;
	map<int, item> products;
	map<int, int> basket;

};
