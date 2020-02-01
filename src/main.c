#include<stdio.h>

#include"../include/rpos.h"

#define MAX 100

//globle variable
int cn=0;

//main function
int main()
{
	//data loading and initialization
	RPdata *vip;
	vip=rpFileLoad();

	printf("\033[43m\033[30m\n");//retro-style graphic interface
	//orange-ish background and black font color
	//looks like Xiaolingtong


	//data loading and initialization,end
	printf("RetroOS, the best oldschool mobile system\n");
	printf("DJP Presents\nPublished on 1999-11-32\n\n\n");
	printf("RetroOS DJP/pseudoUNIX 1.0 tty1\n\n");


	//loop to display then get and process interface command
	int r=1;
	while(r){
		r=rpUI_Main(vip);
	}
	//jump out of the loop


	printf("\033[0m\n");//this printf just clear the ascii format
	return 0;
}
//main function module end



