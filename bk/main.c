#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int cn=0;





//data structure
typedef struct {
		char name[MAX];
		long long cell;
		long long tel;
		char email[MAX];
		long long qq;
		char city[MAX];
		long long eip;
}contact;

typedef struct cabin{
		contact data;
		struct cabin *prior;
		struct cabin *next;
}cabin;
//data structure module end





//case functions
cabin *jedi(){
		//jedi is a function that generate 'the force'
		//'the force' is the source of life in the StarWars worldview
		//basically this function generate the first empty doublelinklist.

		cabin *force;
		force=(cabin *)malloc(sizeof(cabin));
		force->next=force;
		force->prior=force;
		return force;

		//"May the force be with you."
}

cabin *newcontact(cabin *C){
		//newcontact is a function that generate new contatct
		//the pointers changeing are intergrated so no need to worry about it

		cabin *noob;
		noob=(cabin*)malloc(sizeof(cabin));
		noob->prior=C;
		noob->next=C->next;
		C->next=noob;
		noob->next->prior=noob;
		return noob;
}

void cinput(char C[]){
		//cinput function is simply a function that receive a string
		//I don't even know why I wrote it, but I did anyway

		gets(C);
}

long long longlonginput(){
		//longlonginput is a function that receive a long long integer
		long long L;

		scanf("%lld",&L);
		getchar();
		return L;
}

void datainput(cabin *newbee){
		printf("\nName: ");
		cinput(newbee->data.name);

		printf("\nCellphone: ");
		newbee->data.cell=longlonginput();

		printf("\nTelephone: ");
		newbee->data.tel=longlonginput();

		printf("\nE-mail: ");
		cinput(newbee->data.email);

		printf("\nQQ: ");
		newbee->data.qq=longlonginput();

		printf("\nCity: ");
		cinput(newbee->data.city);

		printf("\nEIP: ");
		newbee->data.eip=longlonginput();

		printf("\n:Contact added!\n");
}

void showdetail();
void datainput();
void deletion();
int usercommand();
void interface_1();
void kwdindex();
void text();
void call();

void toContinue(){
		printf("\nPress a button to continue\n");
		getchar();
		printf("\033[2J");
}

void contactIntegratedInteraction(cabin *C){
		int t;
		printf("\n--Options--\n");
		interface_1();
		t=usercommand(0);
		switch(t){
				case 0:
						break;
				case 1:{
							   showdetail(C);
					   }
					   break;
				case 2:{
							   datainput(C);
					   }
					   break;
				case 3:{
							   deletion(C);
					   }
					   break;
				case 4:{
							   text(C);
					   }
					   break;
				case 5:{
							   call(C);
					   }
					   break;
		}
		if(t!=0){
				toContinue();
		}
}

void manualedit(cabin *C){
		//manualedit is a function that read contact's informations manually
		//inputed

		printf(">>Edit<<\n");
		printf("Please fill in the following informations");
		cabin *newbee;
		newbee=newcontact(C);
		datainput(newbee);


		cn+=1;
}

void show(cabin *C){
		printf("%s\n",C->data.name);
}

void call(cabin *C){
		printf("Watiing for picking up...\n\n");
		printf("Notice: The other side is too busy to pick up\n");
		printf("Please try again later\n");
}

void text(cabin *C){
		printf("No messenger application found on this machine!\n");
}

void showdetail(cabin *C){
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

void deletion(cabin *C){
		C->prior->next=C->next;
		C->next->prior=C->prior;
		free(C);
		cn+=-1;
}

int usercommand();

cabin *recon(int I,cabin *C){
		int i=I;
		cabin *scout;
		scout=C->next;
		if(i==1||i==4||i==6){
				char kwd[MAX];
				printf(":Please type the keywords!");
				cinput(kwd);
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
				kwd=longlonginput();
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

void lscontact();
void purge();
void burner();
void nuke();


int shellCommand(cabin *C){
		while(1){
				printf("root@RPhone:/home/user$ ");
				char command[MAX];
				cinput(command);

				if(!strcmp(command,"exit")){
						return 1;
				}
				else if(!strcmp(command,"shutdown")){
						return 0;
				}
				else if(!strcmp(command,"purge")){
						purge();
						printf("All data purged!\n");
				}
				else if(!strcmp(command,"burner")){
						burner(C);
						printf("All data saved!\n");
				}
				else if(!strcmp(command,"lscontact")){
						lscontact(0,1,0,C);
				}
				else if(!strcmp(command,"rm -rf/")){
						nuke();
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
						cfm=usercommand(1);
						if(cfm==1){
								system(command);
						}
				}
		}
}
//case functions module ene





//initialization and file manipulation
void purge()
{
		FILE *fp;
		fp=fopen("main.save","w");
		fclose(fp);
}
void nuke(){
		remove("main.c");
		remove("main.save");
}

void fileBrowser(int I,char S[]){
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

cabin *dataloading(){
		//dataloading is a file-loading function

		cabin *p;
		FILE *fp;
		p=jedi();
		fp=fopen("main.save","rw+");
		int i;
		fread(&cn,sizeof(int),1,fp);
		if(fp!=NULL){
				for(i=0;i<cn;i+=1){
						cabin *buffer;
						buffer=(cabin *)malloc(sizeof(cabin));
						fread(&buffer->data,sizeof(contact),1,fp);
						buffer->next=p->next;
						buffer->prior=p;
						p->next=buffer;
						buffer->next->prior=buffer;
				}
		}
		fclose(fp);
		return p;
}

void burner(cabin *p){
		//burner is a file-writing function

		FILE *fp;
		fp=fopen("main.save","rw+");
		cabin *flag;
		flag=p;
		fwrite(&cn,sizeof(int),1,fp);
		while(flag->next!=p){
				flag=flag->next;
				fwrite(&flag->data,sizeof(contact),1,fp);
		}
		fclose(fp);
}
//initialization and file manipulation module end





//interface and interactions
int usercommand(int s){
		//usercommand is simply a function that scanf keyboard input
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

void interface_1(){
		//interface_1 is just a set of printf functions used in bottom layer.
		printf("******************************\n");
		printf("0)Back\n");
		printf("1)Show detail\n");
		printf("2)Edit contact\n");
		printf("3)Delete contact\n");
		printf("4)Send text\n");
		printf("5)Give a Call\n");
		printf("******************************\n");
}

void kwdindex(){
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

void interface_0(){
		//interface_0 is just a set of printf functions

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

void interface_sort(){

		printf("******************************\n");
		printf("Choose keyword\n");
		printf("0)Back\n");
		printf("1)By name\n");
		printf("******************************\n");

}

void lscontact(int target,int root,int found,cabin *C){
		int value[cn],index[cn];
		int i,j,buffer;
		cabin *result=C;
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
				show(result);
		}
		result=C;
*/
		if(found){
				
				if(target!=0){
						result=C;

						for(i=0;i<index[target-1]+1;i+=1){
								result=result->next;
						}
						contactIntegratedInteraction(result);
				}
		}
		else{
				for(i=0;i<cn;i+=1){
						result=C;
						//printf("~~~~~~~~~~~~~~~~~~\n");
						for(j=0;j<index[i]+1;j+=1){
								result=result->next;
								//show(result);
						}
						printf("%d",i+1);
						printf(")");
						show(result);
						//printf("i: %d, index: %d, char: %c, value: %d, v2char: %c\n",i,index[i],result->data.name[0],value[index[i]],value[index[i]]);
				}
		}
}

void contactFlow(int i,cabin *C){
		//contactFlow is a function that processes in case 2

		//choose a data type to sort
		int keyboard=1;
		while(keyboard){
				interface_sort();

				cabin *flag;
				keyboard=usercommand(i);
				//choice made

				if(keyboard==1){
						int t=1;
						while(t){
								printf("******************************\n");
								printf("0)Back\n");
								//lscontact is the sorting function
								lscontact(0,0,0,C);
								printf("******************************\n");
								t=usercommand(0);
								lscontact(t,0,1,C);
						}

				}
		}
}

void usermanual()
{
		printf("Please choose your filesystem\n");
		printf("0)Back\n");
		printf("1)Dos/Windows\n");
		printf("2)Unix/Linux\n");
		int cfm;
		cfm=usercommand(0);
		if(cfm!=0){
				fileBrowser(cfm,"user_manual");
				fileBrowser(cfm,"user_manual_zh");
				toContinue();
		}
}


int displayInterfaceTop(cabin *C){
		//displayInterface is a loop that displays top interface and wait to
		////receive then process user's command
		interface_0();
		int I;
		I=usercommand(0);


		switch(I){
				//add contacts
				case 1:{
							   manualedit(C);
					   }
					   break;

					   //show contacts
				case 2:{
							   if(C->next==C){
									   printf("No contacts available!\n");
							   }
							   else{
									   contactFlow(0,C);
							   }
					   }
					   break;

					   //search contacts
				case 3:{
							   if(C->next==C){
									   printf("No contacts available!\n");
							   }
							   else{
									   cabin *result;
									   int type=1;
									   while(type){
											   kwdindex();
											   type=usercommand(0);
											   if(type){
													   result=recon(type,C);
													   if(result!=C){
															   printf("\n:Pattern found!\n");
															   contactIntegratedInteraction(result);
													   }
													   else{
															   printf(":Pattern not found!\n");
															   toContinue();
													   }
											   }
									   }
							   }
					   }
					   break;

					   //save to file
				case 4:{
							   burner(C);
							   printf(":All data saved!\n");
							   toContinue();
					   }
					   break;

				case 5:{
							   printf("Type '1' if you are sure.\n");
							   int sure;
							   sure=usercommand(0);

							   if(sure){
									   purge();
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
							   usermanual();
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





//main function
int main()
{
		//data loading and initialization
		cabin *vip;
		vip=dataloading();

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
				r=displayInterfaceTop(vip);
		}
		//jump out of the loop


		printf("\033[0m\n");//this printf just clear the ascii format
		return 0;
}
//main function module end
