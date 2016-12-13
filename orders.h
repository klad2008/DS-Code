#ifndef ORDERS_H
#define ORDERS_H

#include <bits/stdc++.h>

class orders{
	public:
	int time_start;
	poi s, t, sr, tr;
	void clear(){
		memset(this, 0, sizeof(*this));
	}
	void get_time(const int &hour, const int &minute, const int &second){
		this -> time_start = second + minute * 60 + hour * 60 * 60;
	}
	void priln(int num){
		printf("Order No. %d:\n", num);
		printf("time_start : %d\n", this -> time_start);
		printf("s_point : ");
		(this -> s).println();
		printf("t_point : ");
		(this -> t).println();
		printf("sr_point : ");
		(this -> sr).println();
		printf("tr_point : ");
		(this -> tr).println();
	}
}order_p;

vector <orders> order_list[1000010];



#endif
