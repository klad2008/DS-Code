#ifndef A1_H
#define A1_H

void A1_Work(const int &name){
	bool taked = 0;
	double dis = 0;
	double dd = 0;
	driver_rec &Now = Driver[name];
	Now.clear();
	Business.clear();
	for (int i = 1; i <= N; i++){
		if (i > 1) dd = dist(Route[i - 1], Route[i]);
		else dd = 0;
		if (taked == 1){
			dis += dd;
			Now.dis_takeIn += dd;
		}
		else Now.dis_takeOff += dd;
		Now.dis_All += dd;
		if (Route[i].takeoff){
			if (dis > eps){
				double res = 14;
				if (dis > 3000) res = res + (dis - 3000) / 1000 * 2.4;
				Now.income += res;
				busi_p.t_longitude = Route[i].longitude;
				busi_p.t_latitude = Route[i].latitude;
				busi_p.dis_takeIn = dis;
				busi_p.income = res;
				busi_p.outcome = dis * 0.5 / 1000;
				busi_p.profit = busi_p.income - busi_p.outcome;
				Business.push_back(busi_p);
				busi_p.clear();
			}
			taked = 0;
			dis = 0;
		}
		if (Route[i].takein){
			taked = 1;
			dis = 0;
			busi_p.hour = Route[i].hour;
			busi_p.minute = Route[i].minute;
			busi_p.second = Route[i].second;
			busi_p.get_time();
			busi_p.s_longitude = Route[i].longitude;
			busi_p.s_latitude = Route[i].latitude;
		}
	}
	Now.outcome = 0.5 * Now.dis_All / 1000;
	Now.profit = Now.income - Now.outcome;
}

void A1_Pri(const int &name){
	printf("Driver %d:\n", name);
	Driver[name].priln();
	Pri_Business();
	printf("-------------------------------\n");
}

void A1(){
	freopen(File_A1_Out, "w", stdout);
	for (name = No_low; name <= No_high; name++){
		File_prepare(name);
		Route_Read_in();
		Data_clean();
		A1_Work(name);
		A1_Pri(name);
	}
}

#endif
