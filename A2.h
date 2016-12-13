#ifndef A2_H
#define A2_H



void A2(){
	freopen(File_std_Out, "w", stdout);
	for (name = 6961; name <= 12843; name++){
		File_prepare(name);
		Read_in();
		Data_clean();
		A1_Work(name);
		A1_Pri(name);
	}
}

#endif
