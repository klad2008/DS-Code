#ifndef ROUTE_H
#define ROUTE_H

#include <bits/stdc++.h>
using namespace std;

class route_rec{
	public:
	int id;
	int year, month, date;
	int hour, minute, second;
	double longitude, latitude;
	double speed, direction, satellite;
	bool takein, takeoff;
	void clear(){
		memset(this, 0, sizeof(*this));
	}
}Route[10010];

void Merge(route_rec &A, route_rec B){
	if (B.takein){
		A.takein = 1;
		A.takeoff = 0;
	}
	if (B.takeoff){
		A.takein = 0;
		A.takeoff = 1;
	}
}

double dist(const route_rec &A, const route_rec &B){
	double longitude_delta = fabs(A.longitude - B.longitude);
	double latitude_delta = fabs(A.latitude - B.latitude);
	double latitude_ave_arc = fabs(A.latitude + B.latitude) / 2 / 180 * pi;
	double resx = longitude_delta * cos(latitude_ave_arc) * 6371 * 2 * pi / 360;
	double resy = latitude_delta * 6371 * 2 * pi / 360;
	double res = sqrt(resx * resx + resy * resy);
	return res * 1000;
}

double dist_time(const route_rec &A, const route_rec &B){
	double s = 0;
	s += (B.second - A.second);
	s += (B.minute - A.minute) * 60;
	s += (B.hour - A.hour) * 60 * 60;
	return s;
}

double Speed(const route_rec &A, const route_rec &B){
	return dist(A, B) / dist_time(A, B);
}

#endif

