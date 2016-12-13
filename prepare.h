#ifndef PREPARE_H
#define PREPARE_H

#include <bits/stdc++.h>

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

#endif
