#ifndef ORDERS_CLEAN_H
#define ORDERS_CLEAN_H

#include <bits/stdc++.h>
#include "poi.h"
#include "route.h"
#include "orders.h"

int orders_tot = 0;

void Orders_pick(){
	bool taked = 0;
	order_p.clear();
	for (int i = 1; i <= N; i++){
		if (Route[i].takeoff){
			if (!taked) continue;
			taked = 0;
			poi A = (poi){order_p.s_longitude, order_p.s_latitude};
			poi B = (poi){order_p.t_longitude, order_p.t_latitude};
			if (dist(A, B) > eps){
				++orders_tot;
				order_p.t_longitude = Route[i].longitude;
				order_p.t_latitude = Route[i].latitude;
				order_p.priln(orders_tot);
				printf("-------------------------------\n");
			}
		}
		if (Route[i].takein){
			taked = 1;
			order_p.get_time(Route[i].hour, Route[i].minute, Route[i].second);
			order_p.s_longitude = Route[i].longitude;
			order_p.s_latitude = Route[i].latitude;
		}
	}
}

void orders_clean(){
	freopen(File_orders_Out, "w", stdout);
	for (name = 6961; name <= 12843; name++){
		File_prepare(name);
		Read_in();
		Data_clean();
		Orders_pick();
	}
}

#endif
