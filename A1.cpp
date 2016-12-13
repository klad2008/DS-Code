#include <bits/stdc++.h>
using namespace std;

int name, N;

const double Speed_limit = 200.0 / 3.6;
const double eps = 1e-3;
const double pi = acos(-1.0);

const char File_Name_Pre[20] = "[part-00000][";
const char File_Name_Suc[20] = "]Sample";
const char File_std_Out[20] = "DSA1.out";

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

class driver_rec{
	public:
	double income, outcome, profit, dis_All, dis_takeIn, dis_takeOff;
	void clear(){
		memset(this, 0, sizeof(*this));
	}
	void priln(){
		printf("Income : %lf\n", this -> income);
		printf("outcome : %lf\n", this -> outcome);
		printf("profit : %lf\n", this -> profit);
		printf("dis_All : %lf\n", this -> dis_All);
		printf("dis_takeIn : %lf\n", this -> dis_takeIn);
		printf("dis_takeOff : %lf\n", this -> dis_takeOff);
	}
}Driver[20010];

class business_rec{
	public:
	int hour, minute, second;
	double longitude, latitude;
	double income, outcome, profit, dis_takeIn;
	void priln(){
		printf("hour : %d\n", this -> hour);
		printf("minute : %d\n", this -> minute);
		printf("second : %d\n", this -> second);
		printf("longitude : %lf\n", this -> longitude);
		printf("latitude : %lf\n", this -> latitude);
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

void Divide(const string &s_in){
	stringstream stream;
	char ch;
	int xx;
	
	stream << s_in;
	++N;
	Route[N].clear();
	stream >> Route[N].id >> ch;
	if (Route[N].id == 0){
		N--;
		return;
	}
	stream >> Route[N].year >> ch;
	stream >> Route[N].month >> ch;
	stream >> Route[N].date;
	stream >> Route[N].hour >> ch;
	stream >> Route[N].minute >> ch;
	stream >> Route[N].second >> ch;
	stream >> ch;
	stream >> Route[N].longitude >> ch;
	stream >> Route[N].latitude >> ch;
	for (int i = 0; i < 5; i++)
		stream >> xx >> ch;
	stream >> Route[N].speed >> ch;
	stream >> Route[N].direction >> ch;
	stream >> Route[N].satellite >> ch;
	stream >> ch;
	stream >> ch;
	if (ch == 'I'){
		for (int i = 0; i < 9; i++)
			stream >> ch;
		Route[N].takeoff = (ch == 'O');
		Route[N].takein = (ch == 'I');
	}
	else Route[N].takeoff = Route[N].takein = 0;
}

void File_prepare(const int name){
	char File_In[110], File_Out[110];
	char ss[10];
	memset(File_In, 0, sizeof(File_In));
	memset(File_Out, 0, sizeof(File_Out));
	memset(ss, 0, sizeof(ss));
	int r = 0;
	for (int i = 0; i < 13; i++){
		File_In[r] = File_Out[r] = File_Name_Pre[i];
		r++;
	}
	int l = 0;
	for (int x = name; x; x /= 10)
		ss[l++] = x % 10 + '0';
	for (int i = 0; i < l - i - 1; i++)
		swap(ss[i], ss[l - i - 1]);
	for (int i = 0; i < l; i++){
		File_In[r] = File_Out[r] = ss[i];
		r++;
	}
	for (int i = 0; i < 7; i++){
		File_In[r] = File_Out[r] = File_Name_Suc[i];
		r++;
	}
	File_In[r] = '.';
	File_In[r+1] = 'c';
	File_In[r+2] = 's';
	File_In[r+3] = 'v';
	File_Out[r] = '.';
	File_Out[r+1] = 'o';
	File_Out[r+2] = 'u';
	File_Out[r+3] = 't';
	r += 4;
	File_In[r] = File_Out[r] = 0;
	freopen(File_In, "r", stdin);
//	freopen(File_Out, "w", stdout);
}

void Read_Line(string &s){
	s = "";
	char ch = -1;
	ch = getchar();
	while (ch != '\n' && ch != -1){
		s = s + ch;
		ch = getchar();
	}
}

void Read_in(){
	string s;
	Read_Line(s);
	N = 0;
	while (1){
		Read_Line(s);
		if (s == "")
			break;
		Divide(s);
	}
}

void Data_clean(){
	int len = 1;
	for (int i = 2; i < N; i++)
		if (Speed(Route[len], Route[i]) > Speed_limit && Speed(Route[i], Route[i + 1]) > Speed_limit)
			Merge(Route[len], Route[i]);
		else if (dist_time(Route[i - 1], Route[i]) < 1)
			Merge(Route[i - 1], Route[i]);
		else Route[++len] = Route[i];
	Route[++len] = Route[N];
	N = len;
}

void Work(const int &name){
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
				busi_p.dis_takeIn = dis;
				busi_p.income = res;
				busi_p.outcome = dis * 0.5 / 1000;
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
			busi_p.longitude = Route[i].longitude;
			busi_p.latitude = Route[i].latitude;
		}
	}
	Now.outcome += 0.5 * Now.dis_All / 1000;
	Now.profit = Now.income - Now.outcome;
}

void Pri_Business(){
	int len = Business.size();
	for (int i = 0; i < len; i++){
		printf("###No.%d####################\n", i);
		Business[i].priln();
	}
}

void Pri(const int &name){
	printf("Driver %d:\n", name);
	Driver[name].priln();
	Pri_Business();
	printf("-------------------------------\n");
}

int main(){
	freopen(File_std_Out, "w", stdout);
	for (name = 6961; name <= 12843; name++){
		File_prepare(name);
		Read_in();
		Data_clean();
		Work(name);
		Pri(name);
	}
}
