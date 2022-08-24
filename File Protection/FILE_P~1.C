		       /*

			  AUTHOR:- PARTH J. CHAUDHARI
			  PROJECT:-FILE PROTECTION
			    @ COPYRIGHT 2022

		       */





#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

 void filehide();
 void fileshow();
 void filehelp();

   int i,test;
   char ch,FN[20];
   char s[]={"#FILE/FOLDER PROTECTION SOFTWARE !"};

  int main()
  {




   printf( "____________________________________________");
   printf( "____________________________________________");
   printf( "____________________________________________");
   for(i=0;s[i]!='\0';i++)
   {

    printf("%c",s[i]);



   }

    printf(">>>>> EXIT CODE 0 <<<<<");

    printf("1 :HIDE A FILE /FOLDER ");

    printf("2 :SHOW A FILE /FOLDER ");

    printf("3 :HELP ");


    printf("Designed & Developed At code Parth .J Chaudhari  copyright 2022");

    printf("ENTER YOUR CHOICE :->>");
    scanf("%c",ch);

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

     default :

	       printf("PLEASE INPUT CORRECT CHOICE");

	       printf("PRESS ANY KEY: ");




	       main();
	       break;

    case '0' : exit(0);




     }//end of switch

   }//end of while


    return 0;
  }//end of main


   void filehide(){


    printf( "____________________________________________");

    printf( "____________________________________________");

    printf( "____________________________________________");

    printf("Enter file / folder name with correct path !");

    printf(">");
    fflush(stdin);
    gets(FN);
    test = _chmod(FN,1,FA_SYSTEM | FA_HIDDEN | FA_RDONLY);
    if(test==-1)
    {


     printf("Unable to hide file or folder");

     printf("PRESS ANY KEY: ");

    }
    else
    {

     printf("Operation executed Successfully");

     printf("PRESS ANY KEY: ");


    }





   }//end of file hide


    void fileshow(){



    printf( "____________________________________________");

    printf( "____________________________________________");

    printf( "____________________________________________");

    printf("Enter file / folder name with correct path !");

    printf(">");
    fflush(stdin);
    gets(FN);
    test = _chmod(FN,1,0);
    if(test==-1)
    {


     printf("Unable to hide file or folder");

     printf("PRESS ANY KEY: ");


    }
    else
    {

     printf("Operation executed Successfully");

     printf("PRESS ANY KEY: ");


    }

   }//end of fileshow

    void filehelp(){



    printf( "________________________________________________________________");

    printf( "________________________________________________________________");

    printf( "________________________________________________________________");

    printf("ENTER FULL PATH OF FILE / FOLDER IN FOLLOWING FORMAT ");

    printf("Example:- If your file/folder present on E drive ");

    printf("THen E:\\FIle Name or Folder name");

    printf("Note:- Providing the Extension of File is compuslory!");

    printf("PRESS ANY KEY: ");




    }//end of filehelp

















