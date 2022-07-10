#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "title.h"
#include "menu.h"
#include "admin.h"


//COORD coord={0,0}; // this is global variable 





                        

int main(){
int choice;
char ch;
    system("cls");
    while(1){
    system("color 30");
  //  title();
    menu();
  //admin();
  //customer();

	gotoxy(0,12);
    for(j=1; j<121;j++){
    	
       printf("_");
     }
     
    gotoxy(41,14);
    puts("Enter Your Choice?:");
     for(j=1; j<121;j++){
     	
        printf("_");
     }
    gotoxy(60,14);
    scanf("%d",&choice);
	
    switch(choice){
    	
    	case 1 : 
		         admin();
    	         break;
		
		case 2 : customer();
		         getch();
		         break;
				 
		case 3 : exit(0);
		
		default: puts("Invalid Key!");		 		 
				  	
	}
	
}



return 0; 
}
