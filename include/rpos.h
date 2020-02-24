#ifndef __RPOS_H__
#define __RPOS_H__

#ifndef MAX
#define MAX 100
#endif

extern int cn;
extern char user[];
extern char domain[];

//data structure block
//********************
typedef struct {
	char name[MAX];
	long long cell;
	long long tel;
	char email[MAX];
	long long qq;
	char city[MAX];
	long long eip;
}RPvalue;//was named contact

typedef struct RPdata{
	RPvalue data;
	struct RPdata *prior;
	struct RPdata *next;
}RPdata;//was named cabin
//********************
//data structure block end


//functions
//********************
RPdata *rpContactInit();

RPdata *rpContactGen(RPdata *C);

void rpStringInput(char C[]);

long long rpLLInput();

void rpContactInput(RPdata *newbee);

void rpContinue();

void rpContactMenu(RPdata *C);

void rpUI_1(RPdata *C);

RPdata *rpUI_3(int I, RPdata *C);

void rpShowName(RPdata *C);

void rpContactCall(RPdata *C);

void rpContactText(RPdata *C);

void rpContactDetail(RPdata *C);

void rpContactDelete(RPdata *C);

int rpShellInput(int s);

void rpContactMenu_Screen();

void rpUI_3_Screen();

void rpUI_Main_Screen();

void rpUI_2_Screen();

void rpContactList(int target,int root,int found,RPdata *C);

void rpUI_2(int i,RPdata *C);

void rpUserManual();

int rpUI_Main(RPdata *C);

void rpFilePurge();

RPdata *rpFileLoad();

void rpFileBurner();

void rpFileNuke();

void rpFileBrowse();
//********************
//funcion block end

#endif

