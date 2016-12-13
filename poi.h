#ifndef POI_H
#define POI_H

#include <bits/stdc++.h>
using namespace std;

class poi{
	public:
	double longitude, latitude;
	poi (){}
	poi (const double &x, const double &y){
		longitude = x;
		latitude = y;
	}
};

double dist(const poi &A, const poi &B){
	double longitude_delta = fabs(A.longitude - B.longitude);
	double latitude_delta = fabs(A.latitude - B.latitude);
	double latitude_ave_arc = fabs(A.latitude + B.latitude) / 2 / 180 * pi;
	double resx = longitude_delta * cos(latitude_ave_arc) * 6371 * 2 * pi / 360;
	double resy = latitude_delta * 6371 * 2 * pi / 360;
	double res = sqrt(resx * resx + resy * resy);
	return res * 1000;
}

#endif

