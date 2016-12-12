#include <bits/stdc++.h>
using namespace std;

int name, N;

const double eps = 1e-3;
const double pi = acos(-1.0);

class route_rec{
	public:
	int id;
	int year, month, date;
	int hour, minute, second;
	double longitude, latitude;
	double speed, direction;
	bool takein, takeoff;
}Route[10010];

class driver_rec{
	public:
	double income, outcome, profit, dis_All, dis_takeIn, dis_takeOff;
}Driver[10010];

double dist(const route_rec &A, const route_rec &B){
	double longitude_delta = fabs(A.longitude - B.longitude);
	double latitude_delta = fabs(A.latitude - B.latitude);
	double longitude_ave_arc = fabs(A.longitude + B.longitude) / 2 / 180 * pi;
	double resx = longitude_delta * cos(longitude_ave_arc) * 6371 * 1000 * 2 * pi / 360;
	double resy = latitude_delta * 6371 * 1000 * 2 * pi / 360;
	double res = sqrt(resx * resx + resy * resy);
	return res;
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

void int2str(const int &x, string &s_tmp){
	stringstream stream;
	stream << x;
	stream >> s_tmp;
}

void Divide(const string &s_in){
	stringstream stream;
	string s;
	char ch;
	int xx;
	
	stream << s;
	++N;
	stream >> Route[N].id >> ch;
	stream >> Route[N].year >> ch;
	stream >> Route[N].month >> ch;
	stream >> Route[N].date >> ch;
	stream >> Route[N].hour >> ch;
	stream >> Route[N].minute >> ch;
	stream >> Route[N].second >> ch;
	stream >> ch;
	stream >> Route[N].longitude >> ch;
	stream >> Route[N].latitude >> ch;
	for (int i = 0; i < 6; i++)
		stream >> xx >> ch;
	stream >> Route[N].speed >> ch;
	stream >> Route[N].direction >> ch;
	stream >> ch >> ch;
	if (ch == 'I'){
		for (int i = 0; i < 9; i++)
			stream >> ch;
		Route[N].takeoff = (ch == 'O');
		Route[N].takein = (ch == 'I');
	}
	else Route[N].takeoff = Route[N].takein = 0;
}

void File_prepare(){
	char[110] File_In, File_Out;
	File_In = "[part-00000][";
	File_Out = "[part-00000][";
	
	int2str(name, name_s);
	File_In =  + name_s + "]Sample.csv";
	File_Out = "[part-00000][" + name_s + "]Sample.out";
	freopen(File_In, "r", stdin);
	freopen(File_Out, "w", stdout);
}

void Read_in(){
	cin >> s;
	N = 0;
	while (cin >> s)
		Divide(s);
}

void Data_clean(){
	for (int i = 2; i < N; i++)
		if (Speed(Route[i - 1], Route[i]) > Speed_limit && 
			Speed(Route[i], Route[i + 1]) > Speed_limit){
			Route[i].longitude = (Route[i - 1].longitude + Route[i + 1].longitude) / 2;
			Route[i].latitude = (Route[i - 1].latitude + Route[i + 1].latitude) / 2;
		}
}

void Work(const int &name){
	bool taked = 0;
	double dis = 0;
	driver_rec * Now;
	(*Now).income = 0;
	(*Now).outcome = 0;
	(*Now).profit = 0;
	(*Now).dis_All = 0;
	(*Now).dis_takeIn = 0;
	(*Now).dis_takeOff = 0;
	double dd = 0;
	for (int i = 1; i <= N; i++){
		if (i > 1) dd = dist(Route[i - 1], Route[i]);
		else dd = 0;
		(*Now).dis_All += dd;
		if (taked == 1){
			dis += dd;
			(*Now).dis_takeIn += dd;
		}
		else (*Now).dis_takeOff += dd;
		(*Now).outcome += 0.5 * dis / 1000;
		if (Route[i].takeoff){
			if (dis > eps){
				double res = 14;
				if (dis > 3000) res = res + (dis - 3000) / 1000 * 2.4;
				(*Now).income += res;
			}
			taked = 0;
			dis = 0;
		}
		if (Route[i].takein){
			taked = 1;
			dis = 0;
		}
	}
}

void Pri(const int &name){
	printf("%lf\n")
}

int main(){
	for (name = 6961; name <= 6961; name++){
		File_prepare();
		Read_in();
		Data_clean();
		Work(name);
		Pri(name);
	}
}
