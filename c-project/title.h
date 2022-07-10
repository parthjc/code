
COORD coord={0,0}; // this is global variable 

int i,j;

void gotoxy(int x,int y) 
{ 
    coord.X=x; 
    coord.Y=y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); 
} 


void title(){
	
	
	system("cls");
gotoxy(50,3);

 // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
  for(i=0; i<=180;i++){
         printf("");
     }
      gotoxy(0,1);
      for(j=1; j<121;j++){
         printf("_");
     }

     gotoxy(38,3);
    Sleep(1000);
   // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
    printf(">>Welcome");
    Sleep(1000);
    printf(" To");
    Sleep(1000);
    printf(" Royal ");
    Sleep(1000);
    printf("International");
    Sleep(1000);
    printf(" Bank<<\n");
    

for(i=0; i<=119;i++){
         printf("_");
     }


	
	
	
}
