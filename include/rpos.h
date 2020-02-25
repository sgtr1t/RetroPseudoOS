#ifndef __RPOS_H__
#define __RPOS_H__

#ifndef MAX
#define MAX 100
#endif

extern int cn;
/* "cn" is the contact number we've got in the current process,
 * it's not the number stored in the .save file int the storage,
 * it's -1 when there is no user account.
 */

extern char user[];
/* "user" is the username of the current account,
 * it better be unique
 */

extern char domain[];
/* "domain" is the name of the current RPhone,
 * it also better be unique
 */


/* data structures */

typedef struct {
	char name[MAX];
	long long cell;
	long long tel;
	char email[MAX];
	long long qq;
	char city[MAX];
	long long eip;

	/* The following elements are new, and may not be compatible with the data
	 * from previous versions, but add them anyway.
	 */
	char username[MAX];
	char domainname[MAX];
}RPvalue; /* It used to be "contact" */

typedef struct RPdata{
	RPvalue data;
	struct RPdata *prior;
	struct RPdata *next;
}RPdata; /* It used to be "cabin" */

/* data structure block end */


/* functions are below */

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
/* well, that's all */

#endif

