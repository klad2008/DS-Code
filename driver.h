#ifndef DRIVER_H
#define DRIVER_H

#include <bits/stdc++.h>
using namespace std;

class driver_rec{
	public:
	double income, outcome, profit, dis_All, dis_takeIn, dis_takeOff;
	void clear(){
		memset(this, 0, sizeof(*this));
	}
	void priln(){
		printf("Income : %lf\n", this -> income);
		printf("outcome : %lf\n", this -> outcome);
		printf("profit : %lf\n", this -> profit);
		printf("dis_All : %lf\n", this -> dis_All);
		printf("dis_takeIn : %lf\n", this -> dis_takeIn);
		printf("dis_takeOff : %lf\n", this -> dis_takeOff);
	}
}Driver[20010];

#endif

