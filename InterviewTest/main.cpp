#include <iostream>
#include "Checkout.h"
#include "promotions.h"


bool test1()
{
	list<rule> promotional_rules;
	promotional_rules.push_back(chocolate_rule);
	promotional_rules.push_back(total_rule);

	Checkout *co = new Checkout(promotional_rules);
	co->scan(001);
	co->scan(002);
	co->scan(003);
	float total = co->total();

	cout << "The total is: " << total << endl;
	return total > 66.77 && total < 66.79;
}

bool test2()
{
	list<rule> promotional_rules;
	promotional_rules.push_back(chocolate_rule);
	promotional_rules.push_back(total_rule);
	Checkout *co = new Checkout(promotional_rules);
	co->scan(001);
	co->scan(003);
	co->scan(001);
	float total = co->total();

	cout << "The total is: " << total << endl;
	return total > 36.94 && total < 36.96;
}

bool test3()
{
	list<rule> promotional_rules;
	promotional_rules.push_back(chocolate_rule);
	promotional_rules.push_back(total_rule);

	Checkout *co = new Checkout(promotional_rules);
	co->scan(001);
	co->scan(002);
	co->scan(001);
	co->scan(003);

	float total = co->total();
	cout << "The total is: " << total << endl;
	return total > 73.75 && total < 73.77;
}


int main()
{
	cout << "Test 1 " << (test1() ? "Passed" : "Failed") << endl;
	cout << "Test 2 " << (test2() ? "Passed" : "Failed") << endl;
	cout << "Test 3 " << (test3() ? "Passed" : "Failed") << endl;

	system("pause");
	return 0;
}


