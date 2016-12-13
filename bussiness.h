#ifndef BUSSINESS_H
#define BUSSINESS_H

#include <bits/stdc++.h>
using namespace std;

class business_rec{
	public:
	int hour, minute, second;
	double s_longitude, s_latitude;
	double t_longitude, t_latitude;
	double income, outcome, profit, dis_takeIn;
	void priln(){
		printf("hour : %d\n", this -> hour);
		printf("minute : %d\n", this -> minute);
		printf("second : %d\n", this -> second);
		printf("s_longitude : %lf\n", this -> s_longitude);
		printf("s_latitude : %lf\n", this -> s_latitude);
		printf("t_longitude : %lf\n", this -> t_longitude);
		printf("t_latitude : %lf\n", this -> t_latitude);
		printf("income : %lf\n", this -> income);
		printf("outcome : %lf\n", this -> outcome);
		printf("profit : %lf\n", this -> profit);
		printf("dis_takeIn : %lf\n", this -> dis_takeIn);
	}
	void clear(){
		memset(this, 0, sizeof(*this));
	}
}busi_p;

vector <business_rec> Business;

void Pri_Business(){
	int len = Business.size();
	for (int i = 0; i < len; i++){
		printf("###No.%d####################\n", i);
		Business[i].priln();
	}
}

#endif

