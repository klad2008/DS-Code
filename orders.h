#ifndef ORDERS_H
#define ORDERS_H

#include <bits/stdc++.h>

class orders{
	public:
	int time_start;
	double s_longitude, s_latitude;
	double t_longitude, t_latitude;
	void clear(){
		memset(this, 0, sizeof(*this));
	}
	void get_time(const int &hour, const int &minute, const int &second){
		this -> time_start = second + minute * 60 + hour * 60 * 60;
	}
	void priln(int num){
		printf("Order No. %d:\n", num);
		printf("time_start : %d\n", this -> time_start);
		printf("s_longitude : %lf\n", this -> s_longitude);
		printf("s_latitude : %lf\n", this -> s_latitude);
		printf("t_longitude : %lf\n", this -> t_longitude);
		printf("t_latitude : %lf\n", this -> t_latitude);
	}
}order_p;

vector <orders> order_list[1000010];



#endif
