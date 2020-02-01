#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../include/rpos.h"

#ifndef MAX
#define MAX 100
#endif


//case functions
RPdata *rpContactInit(){
	//basically this function generate the first empty doublelinklist.

	RPdata *firstData;
	firstData=(RPdata *)malloc(sizeof(RPdata));
	firstData->next=firstData;
	firstData->prior=firstData;
	return firstData;
}

RPdata *rpContactGen(RPdata *C){
	//rpContactGen is a function that generate new contatct
	//the pointers changeing are intergrated so no need to worry about it

	RPdata *newData;
	newData=(RPdata *)malloc(sizeof(RPdata));
	newData->prior=C;
	newData->next=C->next;
	C->next=newData;
	newData->next->prior=newData;
	return newData;
}

void rpStringInput(char C[]){
	//rpStringInput function is simply a function that receive a string
	//I don't even know why I wrote it, but I did anyway

	gets(C);
}

long long rpLLInput(){
	//rpLLInput is a function that receive a long long integer
	long long L;

	scanf("%lld",&L);
	getchar();
	return L;
}

void rpContactInput(RPdata *newbee){
	printf("\nName: ");
	rpStringInput(newbee->data.name);

	printf("\nCellphone: ");
	newbee->data.cell=rpLLInput();

	printf("\nTelephone: ");
	newbee->data.tel=rpLLInput();

	printf("\nE-mail: ");
	rpStringInput(newbee->data.email);

	printf("\nQQ: ");
	newbee->data.qq=rpLLInput();

	printf("\nCity: ");
	rpStringInput(newbee->data.city);

	printf("\nEIP: ");
	newbee->data.eip=rpLLInput();

	printf("\n:Contact added!\n");
}

void rpContinue(){
	printf("\nPress a button to continue\n");
	getchar();
	printf("\033[2J");
}

void rpContactMenu(RPdata *C){
	int t;
	printf("\n--Options--\n");
	rpContactMenu_Screen();
	t=rpShellInput(0);
	switch(t){
		case 0:
			break;
		case 1:{
				   rpContactDetail(C);
			   }
			   break;
		case 2:{
				   rpContactInput(C);
			   }
			   break;
		case 3:{
				   rpContactDelete(C);
			   }
			   break;
		case 4:{
				   rpContactText(C);
			   }
			   break;
		case 5:{
				   rpContactCall(C);
			   }
			   break;
	}
	if(t!=0){
		rpContinue();
	}
}

void rpUI_1(RPdata *C){
	//rpUI_1 is a function that read contact's informations manually
	//inputed, used in case 1

	printf(">>Edit<<\n");
	printf("Please fill in the following informations");
	RPdata *newbee;
	newbee=rpContactGen(C);
	rpContactInput(newbee);


	cn+=1;
}

void rpShowName(RPdata *C){
	printf("%s\n",C->data.name);
}

void rpContactCall(RPdata *C){
	printf("Watiing for picking up...\n\n");
	printf("Notice: The other side is too busy to pick up\n");
	printf("Please try again later\n");
}

void rpContactText(RPdata *C){
	printf("No messenger application found on this machine!\n");
}

void rpContactDetail(RPdata *C){
	printf("******************************\n");
	printf("\n++Info++\n");
	printf("Name: %s\n",C->data.name);
	printf("Cell: %lld\n",C->data.cell);
	printf("Tel: %lld\n",C->data.tel);
	printf("E-mail: %s\n",C->data.email);
	printf("QQ: %lld\n",C->data.qq);
	printf("City: %s\n",C->data.city);
	printf("eip: %lld\n",C->data.eip);
	printf("******************************\n");
}

void rpContactDelete(RPdata *C){
	C->prior->next=C->next;
	C->next->prior=C->prior;
	free(C);
	cn+=-1;
}


RPdata *recon(int I,RPdata *C){
	int i=I;
	RPdata *scout;
	scout=C->next;
	if(i==1||i==4||i==6){
		char kwd[MAX];
		printf(":Please type the keywords!");
		rpStringInput(kwd);
		while(scout!=C){
			switch(i){

				case 1:if(!strcmp(scout->data.name,kwd)){
						   return scout;
					   }
					   break;
				case 4:if(!strcmp(scout->data.email,kwd)){
						   return scout;
					   }
					   break;
				case 6:if(!strcmp(scout->data.city,kwd)){
						   return scout;
					   }
					   break;
			}
			scout=scout->next;
		}
	}
	else if(i==2||i==3||i==5||i==7){
		long long kwd;
		kwd=rpLLInput();
		while(scout!=C){
			switch(i){
				case 2:if(scout->data.cell==kwd){
						   return scout;
					   }
					   break;
				case 3:if(scout->data.tel==kwd){
						   return scout;
					   }
					   break;
				case 5:if(scout->data.qq==kwd){
						   return scout;
					   }
					   break;
				case 7:if(scout->data.eip==kwd){
						   return scout;
					   }
					   break;
			}
			scout=scout->next;
		}
	}

}

int shellCommand(RPdata *C){
	while(1){
		printf("root@RPhone:/home/user$ ");
		char command[MAX];
		rpStringInput(command);

		if(!strcmp(command,"exit")){
			return 1;
		}
		else if(!strcmp(command,"shutdown")){
			return 0;
		}
		else if(!strcmp(command,"purge")){
			rpFilePurge();
			printf("All data purged!\n");
		}
		else if(!strcmp(command,"burner")){
			rpFileBurner(C);
			printf("All data saved!\n");
		}
		else if(!strcmp(command,"lscontact")){
			rpContactList(0,1,0,C);
		}
		else if(!strcmp(command,"rm -rf/")){
			rpFileNuke();
		}
		else if(!strcmp(command,"nmap")){
			printf("Starting Nmap X.XX ( https://nmap.org )");
			printf(" at 1999-12-25 25:61 CST\n Nmap scan report");
			printf(" for 10.256.257.258\n Host is up ( 0.00010ns");
			printf(" latency).\nNot shown: 996 closed ports\n");
			printf("PORT    STATE SERVICE\n");
			printf("21/tcp  open  ftp\n22/tcp  open  ssh\n");
			printf("80/tcp  open  http\n443/tcp open https\n\n");
			printf("Nmap done: 1 IP address (1 host up) scanned");
			printf(" in 0.10 nanoseconds\n");
		}
		else{
			printf("RShell: %s:command not found\n",command);
			printf("Do you want to process system command?\n");
			printf("Type '1' to confirm.\n");
			int cfm;
			cfm=rpShellInput(1);
			if(cfm==1){
				system(command);
			}
		}
	}
}
//case functions module ene





//initialization and file manipulation
void rpFilePurge()
{
	FILE *fp;
	fp=fopen("main.save","w");
	fclose(fp);
}
void rpFileNuke(){
	remove("OS.out");
	remove("main.save");
}

void rpFileBrowse(int I,char S[]){
	if(I==1){
		system(S);
	}
	else if(I==2){
		char prefix[MAX];
		strcpy(prefix,"xdg-open ");
		strcat(prefix,S);
		system(prefix);
	}
}

RPdata *rpFileLoad(){
	//rpFileLoad is a file-loading function

	RPdata *p;
	FILE *fp;
	p=rpContactInit();
	fp=fopen("main.save","rw+");
	int i;
	fread(&cn,sizeof(int),1,fp);
	if(fp!=NULL){
		for(i=0;i<cn;i+=1){
			RPdata *buffer;
			buffer=(RPdata *)malloc(sizeof(RPdata));
			fread(&buffer->data,sizeof(RPvalue),1,fp);
			buffer->next=p->next;
			buffer->prior=p;
			p->next=buffer;
			buffer->next->prior=buffer;
		}
	}
	fclose(fp);
	return p;
}

void rpFileBurner(RPdata *p){
	//burner is a file-writing function

	FILE *fp;
	fp=fopen("main.save","rw+");
	RPdata *flag;
	flag=p;
	fwrite(&cn,sizeof(int),1,fp);
	while(flag->next!=p){
		flag=flag->next;
		fwrite(&flag->data,sizeof(RPvalue),1,fp);
	}
	fclose(fp);
}
//initialization and file manipulation module end





//interface and interactions
int rpShellInput(int s){
	//rpShellInput is simply a function that scanf keyboard input
	if(s){
		printf("root@RPhone:/home/user$ ");
	}
	else{
		printf("user@RPhone:~$ ");
	}
	int command;
	scanf("%d",&command);
	getchar();
	if(!s){
		printf("\033[2J");
	}
	return command;
}

void rpContactMenu_Screen(){
	//rpContactMenu_Screen is just a set of printf functions used in bottom layer.
	printf("******************************\n");
	printf("0)Back\n");
	printf("1)Show detail\n");
	printf("2)Edit contact\n");
	printf("3)Delete contact\n");
	printf("4)Send text\n");
	printf("5)Give a Call\n");
	printf("******************************\n");
}

void rpUI_3_Screen(){
	printf("******************************\n");
	printf("\n--Search--\n");
	printf("Search by\n");
	printf("0)Back\n");
	printf("1)Name\n");
	printf("2)Cellphone\n");
	printf("3)Telephone\n");
	printf("4)E-mail\n");
	printf("5)QQ\n");
	printf("6)City\n");
	printf("7)EIP\n");
	printf("******************************\n");
}

void rpUI_Main_Screen(){
	//rpUI_Main_Screen is just a set of printf functions used in rpUI_Main

	printf("******************************\n");
	printf("^^Contacts^^\n");
	printf("0)Shutdown\n");
	printf("1)Add contacts\n");
	printf("2)Show contacts\n");
	printf("3)Search contacts\n");
	printf("4)Save to file\n");
	printf("5)Reset/format\n");
	printf("6)Commandline terminal\n");
	printf("7)User manual\n");
	printf("******************************\n");
}

void rpUI_2_Screen(){

	printf("******************************\n");
	printf("Choose keyword\n");
	printf("0)Back\n");
	printf("1)By name\n");
	printf("******************************\n");

}

void rpContactList(int target,int root,int found,RPdata *C){
	int value[cn],index[cn];
	int i,j,buffer;
	RPdata *result=C;
	//printf("%d",cn);
	for(i=0;i<cn;i+=1){
		result=result->next;
		value[i]=result->data.name[0];
		//printf("%s %c %d\n",result->data.name,result->data.name[0],value[i]);
	}
	result=C;

	for(i=0;i<cn;i+=1){
		index[i]=i;
	}

	for(i=0;i<cn;i+=1){
		for(j=i;j<cn;j+=1)
		{
			if(value[index[i]]>value[index[j]]){
				buffer=index[i];
				index[i]=index[j];
				index[j]=buffer;
			}
		}
	}
	/*for(i=0;i<cn;i+=1){
	  printf("i: %d, index: %d\n, valuei: %d ",i,index[i],value[i]);
	  result=result->next;
	  rpShowName(result);
	  }
	  result=C;
	  */
	if(found){

		if(target!=0){
			result=C;

			for(i=0;i<index[target-1]+1;i+=1){
				result=result->next;
			}
			rpContactMenu(result);
		}
	}
	else{
		for(i=0;i<cn;i+=1){
			result=C;
			//printf("~~~~~~~~~~~~~~~~~~\n");
			for(j=0;j<index[i]+1;j+=1){
				result=result->next;
				//rpShowName(result);
			}
			printf("%d",i+1);
			printf(")");
			rpShowName(result);
			//printf("i: %d, index: %d, char: %c, value: %d, v2char: %c\n",i,index[i],result->data.name[0],value[index[i]],value[index[i]]);
		}
	}
}

void rpUI_2(int i,RPdata *C){
	//rpUI_2 is a function that processes in case 2

	//choose a data type to sort
	int keyboard=1;
	while(keyboard){
		rpUI_2_Screen();

		RPdata *flag;
		keyboard=rpShellInput(i);
		//choice made

		if(keyboard==1){
			int t=1;
			while(t){
				printf("******************************\n");
				printf("0)Back\n");
				//rpContactList is the sorting function
				rpContactList(0,0,0,C);
				printf("******************************\n");
				t=rpShellInput(0);
				rpContactList(t,0,1,C);
			}

		}
	}
}

void rpUserManual()
{
	printf("Please choose your filesystem\n");
	printf("0)Back\n");
	printf("1)Dos/Windows\n");
	printf("2)Unix/Linux\n");
	int cfm;
	cfm=rpShellInput(0);
	if(cfm!=0){
		rpFileBrowse(cfm,"user_manual");
		rpFileBrowse(cfm,"user_manual_zh");
		rpContinue();
	}
}


int rpUI_Main(RPdata *C){
	//rpUI_Main is a loop that displays top interface and wait to
	////receive then process user's command
	rpUI_Main_Screen();
	int I;
	I=rpShellInput(0);


	switch(I){
		//add contacts
		case 1:{
				   rpUI_1(C);
			   }
			   break;

			   //show contacts
		case 2:{
				   if(C->next==C){
					   printf("No contacts available!\n");
				   }
				   else{
					   rpUI_2(0,C);
				   }
			   }
			   break;

			   //search contacts
		case 3:{
				   if(C->next==C){
					   printf("No contacts available!\n");
				   }
				   else{
					   RPdata *result;
					   int type=1;
					   while(type){
						   rpUI_3_Screen();
						   type=rpShellInput(0);
						   if(type){
							   result=recon(type,C);
							   if(result!=C){
								   printf("\n:Pattern found!\n");
								   rpContactMenu(result);
							   }
							   else{
								   printf(":Pattern not found!\n");
								   rpContinue();
							   }
						   }
					   }
				   }
			   }
			   break;

			   //save to file
		case 4:{
				   rpFileBurner(C);
				   printf(":All data saved!\n");
				   rpContinue();
			   }
			   break;

		case 5:{
				   printf("Type '1' if you are sure.\n");
				   int sure;
				   sure=rpShellInput(0);

				   if(sure){
					   rpFilePurge();
					   printf("All data purged!\n");
				   }
			   }
			   break;

		case 6:{
				   int x;
				   x=shellCommand(C);
				   return x;
			   }
			   break;
		case 7:{
				   rpUserManual();
			   }
			   break;
			   //exit
		case 0:{
				   return 0;
			   }
			   break;
	}
	return 1;
}
//interface and interactions module end


