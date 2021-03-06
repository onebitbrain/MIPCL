// MakeTest.cpp : Defines the entry point for the console application.
//
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>

int main(int argc, char* argv[])
{
	int i, c,p,r,d,H,H2,n2, 
		n=atoi(argv[1]), 
		prc=atoi(argv[2]), max_dur=atoi(argv[3]);
	char FileName[256];
	std::strcpy(FileName,argv[4]);
//	sprintf(FileName,"%d_%d_%d/%s",n,prc,max_dur,argv[4]);
	std::ofstream fout(FileName);
	srand((unsigned int)time(NULL));

	int *ipProcTime=new int[n];

	p=0;
	for (i=0; i < n; i++) {
		p+=(ipProcTime[i]=1+ rand()%max_dur);
	}
	H2=(H=(p*prc)/100)/2;
	fout << "// n=" << n << ", Prc=" << prc << ", H=" << H << ", Pmax=" << max_dur << std::endl;
	fout << n <<std:: endl;
	n2=n/2;
	for (i=0; i < n2; i++) {
		r=rand()%H2;
		p=ipProcTime[i];
		d=r+p*(1+rand()%10);
		if (d > H)
			d=H;
		c=(rand() % 10) + 1;
		fout << r << " " << d << " " << p << " " << c << std::endl;
	}
	for (; i < n; i++) {
		d=H-rand()%H2;
		p=ipProcTime[i];
		r=d-p*(1+rand()%10);
		if (r < 0)
			r=0;
		c=(rand() % 10) + 1;
		fout << r << " " << d << " " << p << " " << c << std::endl;
	}
	fout.close();
	delete[] ipProcTime;
	return 0;
}

