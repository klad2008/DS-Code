#include <bits/stdc++.h>
using namespace std;

void int2str(const int &x, string &s_tmp){
	stringstream stream;
	stream << x;
	stream >> s_tmp;
}

void Divide(const string &s_in){
	stringstream stream;
	char ch;
	int xx;
	
	stream << s;
	++N;
	stream >> Driver[N].id;
	stream >> ch >> year;
	stream >> ch >> month;
	stream >> ch >> date;
	stream >> Driver[N].Hour >> ch;
	stream >> Driver[N].Minute >> ch;
	stream >> ch;
	stream >> Driver[N].longitude >> ch;
	stream >> Driver[N].latitude >> ch;
	for (int i = 0; i < 6; i++)
		stream >> xx >> ch;
	stream >> Driver[N].speed >> ch;
	stream >> Driver[N].direction >> ch;
	stream >> ch >> ch;
	if (ch == 'I'){
		for (int i = 0; i < 9; i++)
			stream >> ch;
		Driver[N].takeoff = (ch == 'O');
		Driver[N].takein = (ch == 'I');
	}
	else Driver[N].takeoff = Driver[N].takein = 0;
}

void File_prepare(){
	string File_In, File_Out;
	string name_s = int2str(name);
	File_In = "[part-00000][" + name_s + "]Sample.csv"
	File_Out = "[part-00000][" + name_s + "]Sample.out"
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
	int len = 0;//same time select the Average
	vector <int > Q;
	for (int i = 1; i <= N; i++){
		int j = i;
		while (j <= N && Same_time(i, j))
			j++;
		for (int k = i; k < j; k++)
			if (dist())
			Q.push_back(k);
		bool flag = 1;
		while (flag){
			flag = 0;
			for (int k = 0; k < Q.size() && !flag; k++){
				int s = 0;
				for (int t = 0; t < Q.size(); t++)
					if (dist(Driver[k], Driver[t]) > Dist_Limit)
						s++;
				if (2 * s > Q.size()){
					flag = 1;
					for (int t = k; t + 1 < Q.size(); t++)
						Q[t] = Q[t + 1];
					Q.pop_back();
				}
			}
		}
		for (int k = 0; k < Q.size(); k++)
			
	}
	
}

void Work(){
	for (int i = 1; i <= N; i++)
		
}

int main(){
	for (int name = 6961; name <= 6961; name++){
		File_prepare();
		Read_in();
		Data_clean();
		work();
	}
}
