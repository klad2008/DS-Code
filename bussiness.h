#ifndef BUSSINESS_H
#define BUSSINESS_H

#include <bits/stdc++.h>
using namespace std;

class business_rec{
	public:
	int hour, minute, second;
	int time_start;
	double s_longitude, s_latitude;
	double t_longitude, t_latitude;
	double income, outcome, profit, dis_takeIn;
	void get_time(){
		this -> time_start = (this -> second);
		this -> time_start += (this -> minute) * 60;
		this -> time_start += (this -> hour) * 3600;
	}
	void priln(){
//		printf("hour : %d\n", this -> hour);
//		printf("minute : %d\n", this -> minute);
//		printf("second : %d\n", this -> second);
		printf("time_start : %d\n", this -> time_start);
		printf("s_point : ");
		(this -> s).println();
		printf("t_point : ");
		(this -> t).println();
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

