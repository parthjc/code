		       /*

			  AUTHOR:- PARTH J. CHAUDHARI
			  PROJECT:-FILE PROTECTION
			    @ COPYRIGHT 2022

		       */





#include<stdio.h>
#include<conio.h>
#include<dos.h>

 void filehide();
 void fileshow();
 void filehelp();

   int i,test;
   char ch,FN[20];
   char s[]={"#FILE/FOLDER PROTECTION SOFTWARE !"};

  void main()
  {

   clrscr();
   gotoxy(14,5);
   textcolor(2);
   cprintf( "____________________________________________");
   gotoxy(14,6);
   cprintf( "____________________________________________");
   gotoxy(14,10);
   cprintf( "____________________________________________");
   gotoxy(18,8);
   textcolor(10);
   for(i=0;s[i]!='\0';i++)
   {
    _setcursortype(1);
    cprintf("%c",s[i]);
    delay(50);
  //  sound(1500);
    delay(50);
    nosound();

   }
    textcolor(2);
    gotoxy(22,11);
    cprintf(">>>>> EXIT CODE 0 <<<<<");
    gotoxy(22,13);
    cprintf("1 :HIDE A FILE /FOLDER ");
    gotoxy(22,15);
    cprintf("2 :SHOW A FILE /FOLDER ");
    gotoxy(22,17);
    cprintf("3 :HELP ");

    gotoxy(10,24);
    cprintf("Designed & Developed At code Parth .J Chaudhari  copyright 2022");
    gotoxy(16,19);
    cprintf("ENTER YOUR CHOICE :->>");
    ch=getch();

    while(1){

     switch(ch)
     {
     case '1': filehide();
	       main();
	       break;

     case '2': fileshow();
	       main();
	       break;

     case '3': filehelp();
	       main();
	       break;

     default : clrscr();
	       sound(1000);
	       delay(200);
	       gotoxy(19,9);
	       textcolor(2);
	       cprintf("PLEASE INPUT CORRECT CHOICE");
	       gotoxy(19,11);
	       printf("PRESS ANY KEY: ");
	       getch();

	       getch();
	       nosound();
	       main();
	       break;

    case '0' : exit(0);




     }//end of switch

     delay(500);
   }//end of while

 //  getch();

  }//end of main


   void filehide(){

    clrscr();
    gotoxy(15,6);
    textcolor(2);
    cprintf( "____________________________________________");
    gotoxy(15,7);
    cprintf( "____________________________________________");
    gotoxy(15,12);
    cprintf( "____________________________________________");
    gotoxy(17,9);
    cprintf("Enter file / folder name with correct path !");
    gotoxy(17,11);
    cprintf(">");
    fflush(stdin);
    gets(FN);
    test = _chmod(FN,1,FA_SYSTEM | FA_HIDDEN | FA_RDONLY);
    if(test==-1)
    {
     clrscr();
     gotoxy(19,9);
     sound(1000);
     delay(200);
     cprintf("Unable to hide file or folder");
     gotoxy(19,11);
     printf("PRESS ANY KEY: ");
     getch();
    }
    else
    {
     clrscr();
     gotoxy(19,9);
     cprintf("Operation executed Successfully");
     gotoxy(19,11);
     printf("PRESS ANY KEY: ");
     getch();

    }

    nosound();



   }//end of file hide


    void fileshow(){

    clrscr();
    gotoxy(15,6);
    textcolor(2);
    cprintf( "____________________________________________");
    gotoxy(15,7);
    cprintf( "____________________________________________");
    gotoxy(15,12);
    cprintf( "____________________________________________");
    gotoxy(17,9);
    cprintf("Enter file / folder name with correct path !");
    gotoxy(17,11);
    cprintf(">");
    fflush(stdin);
    gets(FN);
    test = _chmod(FN,1,0);
    if(test==-1)
    {
     clrscr();
     gotoxy(19,9);
     sound(1000);
     delay(200);
     cprintf("Unable to hide file or folder");
     gotoxy(19,11);
     printf("PRESS ANY KEY: ");
     getch();

    }
    else
    {
     clrscr();
     gotoxy(19,9);
     cprintf("Operation executed Successfully");
     gotoxy(19,11);
     printf("PRESS ANY KEY: ");
     getch();

    }

    nosound();

   }//end of fileshow

    void filehelp(){

    clrscr();
    gotoxy(9,6);
    textcolor(2);
    cprintf( "________________________________________________________________");
    gotoxy(9,7);
    cprintf( "________________________________________________________________");
    gotoxy(9,16);
    cprintf( "________________________________________________________________");
    gotoxy(14,9);
    cprintf("ENTER FULL PATH OF FILE / FOLDER IN FOLLOWING FORMAT ");
    gotoxy(16,11);
    cprintf("Example:- If your file/folder present on E drive ");
    gotoxy(24,13);
    cprintf("THen E:\\FIle Name or Folder name");
    gotoxy(12,15);
    cprintf("Note:- Providing the Extension of File is compuslory!");
    gotoxy(12,18);
    printf("PRESS ANY KEY: ");

    getch();
    //textcolor(2);

    }//end of filehelp

















