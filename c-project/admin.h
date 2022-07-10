
int k;
struct bank
{
   int cid;
   char name[30];
   char uname[30];
   char pass[30];
   long int balance;
   long int *add;
   int active;
   //int id;
   
}str;





void heading(){
	
	gotoxy(45,1);
	puts(">>List Of Contact<<");
	printf("\n");
	for(j=1; j<121;j++){
    printf("_");
     }	
    gotoxy(10,5);
	printf("CidNo.");
	gotoxy(30,5);
	printf("Name");
	gotoxy(50,5);
	printf("Uname");
	gotoxy(70,5);
	printf("Amount"); 
	printf("\n");
  	for(j=1; j<121;j++){
    printf("_");
     }			
	
}
void listdata(){
	
 
	gotoxy(10,k);
	printf("%d",str.cid);
   
    gotoxy(30,k);
	printf("%s",str.name);
	
    gotoxy(50,k);
	printf("%s",str.uname);
	 			
    gotoxy(70,k);
	printf("%ld",str.balance);	



}







void write(){
	gotoxy(45,3);
	puts(">>Welcome To Admin Dashboard<<");
	for(j=1; j<121;j++){
    printf("=");
     }
	FILE *fp;
	gotoxy(45,6);
	fp=fopen("data.txt","ab");
	printf("Enter the value of cid no:");
	scanf("%d",&str.cid);
	gotoxy(45,8);
	printf("Enter the name:");
	scanf("%s",&str.name);	
	gotoxy(45,10);	
	printf("Enter the username:");
	scanf("%s",&str.uname);
	gotoxy(45,12);	
	printf("Enter the password:");
	scanf("%s",&str.pass);
	gotoxy(45,14);	
	printf("Enter the first deposit amount:");
	scanf("%ld",&str.balance);
	fwrite(&str,sizeof(str),1,fp);
    gotoxy(45,16);	
	printf("file is successfully saved:");
	gotoxy(45,18);
	printf("Press enter key:");	
	str.active=1;
	fclose(fp);
	
}


void read(){
	FILE *fp;
    fp=fopen("data.txt","rb");
    heading();
    k=7;
	while(fread(&str,sizeof(str),1,fp)){
    listdata();
	k++;	 				
}


	fclose(fp);
}


void search(){
	
	FILE *fp;
	int id;
	int flag=0;
    fp=fopen("data.txt","rb");
    gotoxy(45,10);
    printf("Enter the cid no:");
    scanf("%d",&id);
    system("cls");
    heading();
    k=7;
   while(fread(&str,sizeof(str),1,fp)){
   	if(str.cid==id){
   		
   		  listdata();
		  flag++;
		  gotoxy(46,15);
		  printf("press enter key!");
		  getch();	  
		
		 
	   	
	   }
			 				  
	   }
	   
	   if(flag==0)
	   {
	   	  gotoxy(46,15);
	   	  printf("--data not found--!");
	   	
}


 fclose(fp);


}//end search




void edit(){
	
	
    FILE *fp;
    int pos;
	int id;
	int flag=0;
    fp=fopen("data.txt","r+b");
    gotoxy(45,10);
    printf("Enter the edit cid no:");
    scanf("%d",&id);
    system("cls");
    heading();
    k=7;
   while(fread(&str,sizeof(str),1,fp)){
   	if(str.cid==id){
   		  listdata();
		  flag++;
		  gotoxy(46,15);
		  printf("press enter key to edit!");
		  getch();
		  break;
		   
}



	   if(flag==0)
	   {
	   	  gotoxy(46,15);
	   	  printf("--data not found--!");
	   	  
	   }
	
	



}

      if(flag==1){
	  
        
   pos=ftell(fp);
    fseek(fp,pos-sizeof(str),SEEK_SET);
	system("cls");   
	gotoxy(45,3);
	puts(">>Welcome To Admin Dashboard<<");
	for(j=1; j<121;j++){
		
        printf("=");
    
     }
	  gotoxy(45,6);
	printf("Enter the value of cid no:");
	scanf("%d",&str.cid);
	gotoxy(45,8);
	printf("Enter the name:");
	scanf("%s",&str.name);	
	gotoxy(45,10);	
	printf("Enter the username:");
	scanf("%s",&str.uname);
	gotoxy(45,12);	
	printf("Enter the password:");
	scanf("%s",&str.pass);
	gotoxy(45,14);	
	printf("Enter the first deposit amount:");
	scanf("%ld",&str.balance);
	fwrite(&str,sizeof(str),1,fp);
    gotoxy(45,16);	
	printf("file is successfully saved:");
	gotoxy(45,18);
	printf("Press enter key:");	
	fclose(fp); 
	   
	  	   
}

}

void delete(){
	
	
	
	
    FILE *fp,*fp1,*fp2;
	int id;
	int flag=0;
    fp=fopen("data.txt","r+b");
    fp1=fopen("temp.txt","a+b");
    fp2=fopen("trash.txt","a+b");
    gotoxy(45,10);
    printf("Enter the edit cid no:");
    scanf("%d",&id);
    system("cls");
    heading();
    k=7;
   while(fread(&str,sizeof(str),1,fp)){
   	if(str.cid==id){
   		  listdata();
		  flag++;
		  gotoxy(46,15);
		  printf("press enter key to delete!");
		  fwrite(&str,sizeof(str),1,fp1);
		  getch();
		  

		   
}else
   {
   	
   	fwrite(&str,sizeof(str),1,fp2);
   }
	
   
}
	 
	  fclose(fp);
	  fclose(fp1);
	  fclose(fp2);


	   if(flag==0)
	   {
	   	  gotoxy(46,15);
	   	  printf("--data not found--!");
	   	  
	   }	
	
     remove("data.txt");
	 rename("trash.txt","data.txt");	  
	
		
}//end delete




void view_del_data(){
	
	
	FILE *fp1;
    fp1=fopen("temp.txt","rb");
    heading();
    k=7;
	while(fread(&str,sizeof(str),1,fp1)){
    listdata();
	k++;
	gotoxy(46,15);
    printf("press enter key!");
  	  
		
		 				
}


	fclose(fp1);
	   	
		
}//end view delete data


void restore_delete(){
	
	
	
	
    FILE *fp,*fp1,*fp2;
	int id;
	int flag=0;
    fp=fopen("data.txt","a+b");
    fp1=fopen("temp.txt","rw");
    fp2=fopen("trash.txt","a+b");
    gotoxy(45,10);
    printf("Enter the edit cid no:");
    scanf("%d",&id);
    system("cls");
    heading();
    k=7;
   while(fread(&str,sizeof(str),1,fp1)){
   	if(str.cid==id){
   		  listdata();
		  flag++;
		  gotoxy(46,15);
		  printf("press enter key to restore delete data!");
		  fwrite(&str,sizeof(str),1,fp);
		  getch();
		  

		   
}else
   {
   	
   	fwrite(&str,sizeof(str),1,fp2);
   }
	
   
}
	 
	  fclose(fp);
	  fclose(fp1);
	  fclose(fp2);


	   if(flag==0)
	   {
	   	  gotoxy(46,15);
	   	  printf("--data not found--!");
	   	  
	   }	
	
     remove("temp.txt");
	 rename("trash.txt","temp.txt");	  
	
		
}//end delete


void permanently_delete(){
	
	
	
	
    FILE *fp,*fp1,*fp2;
	int id;
	int flag=0;
    fp=fopen("del.txt","a+b");
    fp1=fopen("temp.txt","rw");
    fp2=fopen("trash.txt","a+b");
    gotoxy(45,10);
    printf("Enter the edit cid no:");
    scanf("%d",&id);
    system("cls");
    heading();
    k=7;
   while(fread(&str,sizeof(str),1,fp1)){
   	if(str.cid==id){
   		  listdata();
		  flag++;
		  gotoxy(46,15);
		  printf("press enter key to permanently delete!");
		  fwrite(&str,sizeof(str),1,fp);
		  getch();
		  

		   
}else
   {
   	
   	fwrite(&str,sizeof(str),1,fp2);
   }
	
   
}
	 
	  fclose(fp);
	  fclose(fp1);
	  fclose(fp2);


	   if(flag==0)
	   {
	   	  gotoxy(46,15);
	   	  printf("--data not found--!");
	   	  
	   }	
	
     remove("del.txt");
     remove("temp.txt");
	 rename("trash.txt","temp.txt");	  
	
		
}//end delete









void admin(){
	FILE *fp;
	int achoice,i,k;
	char us,pss;
	char pass1[60];
	char user1[60];
	char user[60];
	char pass[60];
	
	system("cls");
	for(i=0; i<=180;i++){
		
        printf("");
    
    }
    
    gotoxy(0,1);
    for(j=1; j<121;j++)
	{
         printf("=");
         
     }
     
	
	gotoxy(42,3);
	puts(">>Welcome To Admin Login<<");
	for(j=1; j<121;j++){
		
         printf("=");
    
    
     }
     
     
    gotoxy(45,8);
    puts("Enter User Name:");
    gotoxy(61,8);
    //fflush(stdin);
    while(1){
    	
    us=getch();
    
    if(us==13){//if start
			 	
    	user[i]='\0';
    	break;
		
	}//if end
    	
    user[i++]=us;
    printf("*");
	}
   
	
   
    fflush(stdin);
    gotoxy(45,10);
    puts("Enter User Password:");
    gotoxy(65,10);
    while(1){
    	
    pss=getch();
    if(pss==13){//if start
			 	
	   pass[k]='\0';
	   break; 
	
	}//if end
	
	
    pass[k++]=pss;
    printf("*");
	}
	
	
    fp=fopen("user.dat","r");
    fgets(user1,6,fp);
    fclose(fp);
    
    fp=fopen("pass.dat","r");
    fgets(pass1,5,fp);
    fclose(fp);
    
    gotoxy(45,12);
    if(!strcmp(user1,user)==0 && !strcmp(pass1,pass)==0){
    puts("Access Denied!");	
    getch();
	}
	
	
	else{
	system("cls");	
	gotoxy(42,3);
    puts(">>Bank Management System<<");
    gotoxy(42,5);
	puts(">>Version no. :1.0<<");
  	gotoxy(42,7);	
	puts(">>Developed by :Pc-Parth J Chaudhari<<");
  	gotoxy(43,10);		
    puts("Please Wait");
    gotoxy(55,10);
  
	for(i=0; i<=50;i++){        
	
	   printf("%c",254);
	   Sleep(5);
	
    }
			
	system("cls");
	for(i=0; i<=180;i++){
       
	   printf("");
    }
    
    gotoxy(0,1);
    for(j=1; j<121;j++){
    	
       printf("=");
     }
     
     
	while(1){
	system("cls");
	gotoxy(45,3);
	puts(">>Welcome To Admin Dashboard<<");
	for(j=1; j<121;j++){
		
        printf("=");
     }
     
    gotoxy(47,6);
	puts("[1]------Creat Customer");
	gotoxy(47,8);
	puts("[2]------Display Customer");
	gotoxy(47,10);
	puts("[3]------Edit Customer");
	gotoxy(47,12);
	puts("[4]------Search Id");
	gotoxy(47,14);
	puts("[5]------Delete Id");
	gotoxy(47,16);
	puts("[6]------View Delete Id");
	gotoxy(47,18);	
	puts("[7]------Restore Delete Id");	
	gotoxy(47,20);
	puts("[8]------permanently Delete Id");	
	gotoxy(47,22);				
	puts("[9]------Logout");

	
	gotoxy(0,24);
    for(j=1; j<121;j++){
    	
      printf("_");
      
     }
     
    gotoxy(47,26);
    
    printf("Enter Your Choice?:");
    scanf("%d",&achoice);
    
    for(j=1; j<121;j++)
	{
		
    printf("_");
    
     }
     

	 
   
    
    switch(achoice){
    	          
    	case 1 : system("cls");
		         write();
    	         getch();
    	         break;
    		          
    	case 2 : system("cls");
		         read();
    	         getch();
    	         break;
    	 
		case 3 : system("cls");
		         edit();
    	         getch();
    	         break;	         
    			          
    	case 4 : system("cls");
		         search();
    	         getch();
    	         break;
    	         
    	case 5 : system("cls");
		         delete();
    	         getch();
    	         
    	case 6 : system("cls");
		         view_del_data();
    	         getch();
    	         break;	
				 
		case 7 : system("cls");
		         restore_delete();
    	         getch();
    	         break;	       	                 
    
		case 8 : system("cls");
		         permanently_delete();
    	         getch();
    	         break;	       	         			        	         	                  
    	         
    	case 9 : exit(0);         
    	         
    	
	}
   
}
     
	}//else end
     
}//end of admin





                                                             //-------------- // coustomer menu //-------------------------//










void deposit(){
	

			 				  
	
    FILE *fp;
    int pos;
	int id;
	int flag=0;
    fp=fopen("data.txt","r+b");
    gotoxy(45,10);
    printf("Enter the deposit cid no:");
    scanf("%d",&id);
    system("cls");
    heading();
    k=7;
   while(fread(&str,sizeof(str),1,fp)){
   	if(str.cid==id){
   		  listdata();
		  flag++;
		  gotoxy(46,15);
		  printf("press enter key to edit!");
		  getch();
		  break;
		   
}



	   if(flag==0)
	   {
	   	  gotoxy(46,15);
	   	  printf("--data not found--!");
	   	  
	   }
	
	



}

      if(flag==1){
	  
        
   pos=ftell(fp);
    fseek(fp,pos-sizeof(str),SEEK_SET);
	system("cls");   
	gotoxy(45,3);
	puts(">>Welcome To Admin Dashboard<<");
	for(j=1; j<121;j++){
		
        printf("=");
    
     }
	gotoxy(45,6);
	printf("Enter the first deposit amount:");
	scanf("%ld",&str.add);
	fwrite(&str,sizeof(str),1,fp);
    gotoxy(45,16);	
	printf("file is successfully saved:");
	gotoxy(45,18);
	printf("Press enter key:");	
	fclose(fp); 
	   
	  	
}

}//end deposit




void balance(){
	
	FILE *fp;
	int id;
	int flag=0;
    fp=fopen("data.txt","rb");
    gotoxy(45,10);
    printf("Enter the cid no:");
    scanf("%d",&id);
    system("cls");
    heading();
    k=7;
   while(fread(&str,sizeof(str),1,fp)){
   	if(str.cid==id){
   		
   		  listdata();
		  flag++;
		  gotoxy(46,15);
		  printf("press enter key!");
		  getch();	  
		
		 
	   	
	   }
			 				  
	   }
	   
	   if(flag==0)
	   {
	   	  gotoxy(46,15);
	   	  printf("--data not found--!");
	   	
}


 fclose(fp);

}//end balance






void customer(){
	int choice;
	while(1){
		
	system("cls");
	for(i=0; i<=180;i++){
    printf("");
    }
    gotoxy(0,1);
    for(j=1; j<121;j++){
    printf("=");
     }
	
	gotoxy(42,3);
	puts(">>Welcome To Customer Dashboard<<");
	for(j=1; j<121;j++){
    printf("=");
     }
	gotoxy(47,6);
	puts("[1]------Check Balance");
	gotoxy(47,8);
	puts("[2]------Deposit Cash");
	gotoxy(47,10);
	puts("[3]------Exit");
	gotoxy(0,12);
	for(j=0; j<120;j++){
		
        printf("_");
     }
    gotoxy(47,13);
	puts("Enter the your choice:");
	gotoxy(0,14);
	for(j=0; j<120;j++){
		
        printf("_");
     }	
	gotoxy(69,13);
	scanf("%d",&choice);
	
	gotoxy(0,14);
	for(j=0; j<120;j++){
		
        printf("_");
     }
     
     
     
     
     
      switch(choice){
    	
    	case 1 : system("cls");
		         balance();
		         getch();
    	         break;
		
		case 2 : system("cls");
		         deposit();
		         getch();
		         break;
				 
		case 3 : exit(0);
		
		default: puts("Invalid Key!");		 		 
				  	
	}


	
}//end of while
		
}//end of customer




