#include<stdio.h>
#include<conio.h>
#include <windows.h>
COORD coord= {0,0}; // this is global variable





void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main(){
	
	int boxX=55,boxY=23,candyX=55,candyY=2,i;
	int score=0,lives=15,d=0;
	char c,ch;
	system("color 30");
	start:
		system("cls");
		
		gotoxy(10,2);
		printf("Score=%d",score);
		gotoxy(10,4);
		printf("Lives=%d",lives);
		
		
		gotoxy(candyX,candyY);
		printf("0");
	
	    gotoxy(boxX,boxY); 
		printf("#");
		 
		gotoxy(boxX+7,boxY); 
		printf("#"); 	
	
        gotoxy(boxX,boxY+1); 	
		printf("########");
			  	
	    if(kbhit()){
	    
			
	    	ch=getch();
	    	
	    	switch(ch){
	    		
	    		
	    		case 'a': boxX--;
	    		          break;
	    		          
	    		case 'b': boxX++;
				          break;
				
				case 'x': exit(0);		             
	    		
	    		
			}
	    	
	    
		}   
	 

      Sleep(250);
           
      candyY++;
      goto start;

  
	goto start;
  	
  	
  
    
	
	return 0;
}
