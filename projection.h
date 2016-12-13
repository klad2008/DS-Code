#ifndef ORDERS_CLEAN_H
#define ORDERS_CLEAN_H

#include <bits/stdc++.h>

void orders_clean(){
	freopen(File_orders_Out, "r", stdin);
	freopen(File_orders_opt_Out, "w", stdout);
	for (name = No_low; name <= No_high; name++){
		File_prepare(name);
		Data_clean();
		Orders_pick();
	}
}

#endif
