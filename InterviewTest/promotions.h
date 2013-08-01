#pragma once

#include <list>
#include <vector>
#include <map>

#include "Checkout.h"

using namespace std;

int total_rule(map<int, int>& basket, map<int, item>& products);
int chocolate_rule(map<int, int>& basket, map<int, item>& products);