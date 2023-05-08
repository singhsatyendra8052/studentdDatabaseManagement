#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


// Defining The Functions of Our Program :-
void addstudent();
void studentrecord();
void searchstudent();
void delete();
void marksheet();



struct student
{
    char first_name[30];
    char last_name[30];
    int roll_no;
    char Class[30];
    char vill[20];
    float per;
    float marks[10];
    float total;
    float avg;
    int sub_opted;
    int sj[15];       
};

const char *subjects[15]={"ENTR      ","ENGLISH   ","IRH       ","ENVER     ","DATA STR  ","S.ST.     ","MATHS     ","CHEMISTRY ","PHYSICS   ", "BIOLOGY   ","CS        ","ACCOUNTING","ECONOMICS ","HISTORY   ","BUSINESS  "};  





// Main Function Heading Of Our Program :-
void main()
{
	int choice;
    while (choice != 6)
    {
		printf("\n\t\t\t\t\t\t\t  ================================================");
        printf("\n\t\t\t\t\t\t\t      SRM-AP STUDENT DATABASE MANAGEMENT SYSTEM");
        printf("\n\t\t\t\t\t\t\t  ================================================");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t\t\t         1. ADD STUDENT\n");
        printf("\t\t\t\t\t\t\t\t         2. DISPLAY RECORDS\n");
        printf("\t\t\t\t\t\t\t\t         3. SEARCH RECORD\n");
        printf("\t\t\t\t\t\t\t\t         4. DELETE RECORD\n");
        printf("\t\t\t\t\t\t\t\t         5. MARKSHEET\n");
        printf("\t\t\t\t\t\t\t\t         6. EXIT\n");
        printf("\n\n\t\t\t\t\t\t\t   ENTER OPTION- ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            addstudent();			//Calling Function "addstudent()" to add record of student
            system("cls");
            break;
            
        case 2:
            system("cls");
            studentrecord();			//Calling Function "studentrecord()" to display records of student
            printf("\n\t\t\t\t\t\t\t         PRESS ANY KEY TO EXIT... ");
            getch();
            system("cls");
            break;
            
        case 3:
            system("cls");
            searchstudent();			//Calling Function "searchstudent()" to display record of a particular student
            printf("\n\t\t\t\t\t\t\t         PRESS ANY KEY TO EXIT... ");
            getch();
            system("cls");
            break;
            
        case 4:
            system("cls");
            delete ();			//Calling Function "delete()" to remove record of a particular student
            printf("\n\t\t\t\t\t\t\t             PRESS ANY KEY TO EXIT... ");
            getch();
            system("cls");
            break; 
			      
        case 5:
            system("cls");
            marksheet();
						//Calling Function "marksheet()" to print marksheet of a student
			printf("\n");
            printf("\n\t\t\t\t\t\t\t         PRESS ANY KEY TO EXIT... ");
            getch();
            system("cls");
            break; 
			        
        case 6:
            system("cls");
            printf("\n\n\n\t\t\t\t\t\t\t  ================================================");
            printf("\n\t\t\t\t\t\t\t      !! THANK YOU FOR USING OUR APPLICATION !!");
            printf("\n\t\t\t\t\t\t\t  ================================================\n\n\n\n");
            exit(0);
            break;
        default:
            system("cls");
            getch();
            printf("\n\t\t\t\t\t\t\t         PLEASE ENTER A VALID INPUT");
            printf("\n\t\t\t\t\t\t\t         PRESS ANY KEY TO EXIT... ");
            getch();
            system("cls");
            break;
        }
    }
    getch();
}





void addstudent()
{
    char another;
    FILE *fp;
    int n, i;
    int m;
    int z;
    float total=0;
    float sum;
    float per;
    struct student info;
    do
    {
        system("cls");
        printf("\n\t\t\t\t\t\t\t  ================================================");
        printf("\n\t\t\t\t\t\t\t                 ADD STUDENT RECORD");
        printf("\n\t\t\t\t\t\t\t  ================================================\n\n");
        fp = fopen("record.txt", "a");
        printf("\n\t\t\t\t\t\t\t       ENTER FIRST NAME  : ");
        scanf("%s", &info.first_name);
        printf("\n\t\t\t\t\t\t\t       ENTER LAST NAME  : ");
        scanf("%s", &info.last_name);
        printf("\n\t\t\t\t\t\t\t       ENTER REGIS NO.  : ");
        scanf("%d", &info.roll_no);
        printf("\n\t\t\t\t\t\t\t       ENTER BRANCH     : ");
        scanf("%s", &info.Class);
        printf("\n\t\t\t\t\t\t\t       ENTER ADDRESS    : ");
        scanf("%s", &info.vill);    	
     	printf("\n\t\t\t\t\t\t\t  ------------------------------------------------");
     	printf("\n\t\t\t\t\t\t\t  SUBJECTS ARE : \n");
     	printf("\n\t\t\t\t\t\t\t  ");
     	for(i=1;i<=14;i++){
        	printf("%d.	%s ",i,subjects[i]);
         	if(i==3 || i==6 || i==9 || i==12){
            	printf("\n\t\t\t\t\t\t\t  ");
         	}
     	}
     	printf("\n\t\t\t\t\t\t\t  ------------------------------------------------\n");
     	printf("\n\n\t\t\t\t\t\t\t         TOTAL SUBJECTS OPTED     :  ");
    	scanf("%d", &info.sub_opted);
     	printf("\n\t\t\t\t\t\t\t         CHOOSE SUBJECT CODE : ");
    	for(i=0;i<info.sub_opted;i++) {
        	scanf("%d",&info.sj[i]);
     	}
		printf("\n\n\t\t\t\t\t\t\t         ENTER OBTAINED MARKS : \n");
    	for(m=0;m<info.sub_opted;m++){
    	    int s=info.sj[m];
    	    printf("\n\t\t\t\t\t\t\t         %d. %s : ",m+1, subjects[s]);
    	    scanf("%f",&info.marks[m]);
    	}
     	
		for(m=0;m<info.sub_opted;++m){
			int s = info.marks[m];
			total += s;
    	}
    	info.total = total;
    	info.avg = total / info.sub_opted;
   		int MaxMarks = info.sub_opted*100;
    	info.per = (info.total*100)/MaxMarks;		
        printf("\n\t\t\t\t\t\t\t  --------------------------------------------------\n");
        if (fp == NULL)
        {
            fprintf(stderr, "\t\t\t\t\t\t\t   CAN'T OPEN FILE");
        }
        else
        {
            printf("\n\t\t\t\t\t\t\t   RECORD ADDED SUCCESSFULLY");
        }
        fwrite(&info, sizeof(struct student), 1, fp);
        fclose(fp);
        printf("\n\t\t\t\t\t\t\t   DO YOU TO ADD ANOTHER RECORD? [y/n] : ");
        scanf("%s", &another);
    } while (another == 'y' || another == 'Y');
}





void studentrecord()
{
    FILE *fp;
    int m;
    struct student info;
    fp = fopen("record.txt", "r");
    printf("\n\t\t\t\t\t\t\t  ================================================");
	printf("\n\t\t\t\t\t\t\t                 STUDENT'S RECORD");
	printf("\n\t\t\t\t\t\t\t  ================================================\n\n");

    if (fp == NULL)
    {
        fprintf(stderr, "\n\t\t\t\t\t\t\t         CAN'T OPEN FILE\n");
        exit(0);
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t         STUDENT RECORDS ARE :\n");
        printf("\t\t\t\t\t\t\t         ________________________________\n");
    }
    while (fread(&info, sizeof(struct student), 1, fp))
    {
        printf("\n\t\t\t\t\t\t\t         STUDENT NAME   :  %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\t\t\t\t         REGIS NO       :  %d", info.roll_no);
        printf("\n\t\t\t\t\t\t\t         BRANCH         :  %s", info.Class);
        printf("\n\t\t\t\t\t\t\t         VILLAGE/CITY   :  %s", info.vill);
        printf("\n\t\t\t\t\t\t\t         SUBJECTS OPTED :  %d", info.sub_opted);
        printf("\n\n\t\t\t\t\t\t\t         SUBJECTS          MARKS");
        for(m=0;m<info.sub_opted;m++){
        	int s=info.sj[m];
        	printf("\n\t\t\t\t\t\t\t         %s\t   %.1f",subjects[s],info.marks[m]);
    	}
    	printf("\n\n\t\t\t\t\t\t\t         TOTAL    \t:  %.1f / %d", info.total,(info.sub_opted*100));
    	printf("\n\t\t\t\t\t\t\t         AVERAGE    \t:  %.1f", info.avg);
		printf("\n\t\t\t\t\t\t\t         PERCENTAGE    \t:  %.2f%%", info.per);
        printf("\n\t\t\t\t\t\t\t         ________________________________");
    }
    fclose(fp);
    getch();
}





void searchstudent()
{
    struct student info;
    FILE *fp;
    int m;
    int roll_no, found = 0;
    fp = fopen("record.txt", "r");
    printf("\n\t\t\t\t\t\t\t  ================================================");
    printf("\n\t\t\t\t\t\t\t                 SEARCH STUDENT RECORD");
    printf("\n\t\t\t\t\t\t\t  ================================================\n\n");
    printf("\n\t\t\t\t\t\t                ENTER REGIS NO. : ");
    scanf("%d", &roll_no);
    while (fread(&info, sizeof(struct student), 1, fp) > 0)
    {
        if (info.roll_no == roll_no)
        {
            found = 1;
            printf("\n");
            printf("\n\t\t\t\t\t\t\t         STUDENT NAME   :  %s %s", info.first_name, info.last_name);
        	printf("\n\t\t\t\t\t\t\t         REGIS NO       :  %d", info.roll_no);
        	printf("\n\t\t\t\t\t\t\t         BRANCH         :  %s", info.Class);
        	printf("\n\t\t\t\t\t\t\t         VILLAGE/CITY   :  %s", info.vill);
        	printf("\n\t\t\t\t\t\t\t         SUBJECTS OPTED :  %d", info.sub_opted);
        	printf("\n\n\t\t\t\t\t\t\t         SUBJECTS       :  MARKS");
        	for(m=0;m<info.sub_opted;m++){
        		int s=info.sj[m];
        		printf("\n\t\t\t\t\t\t\t         %s\t   %.1f",subjects[s],info.marks[m]);
    		}
    		printf("\n\n\t\t\t\t\t\t\t         TOTAL    \t:  %.1f / %d", info.total,(info.sub_opted*100));
    		printf("\n\t\t\t\t\t\t\t         AVERAGE    \t:  %.1f", info.avg);
			printf("\n\t\t\t\t\t\t\t         PERCENTAGE    \t:  %.2f%%", info.per);
        	printf("\n\t\t\t\t\t\t\t         ________________________________");
        }
    }
    if (!found)
    {
        printf("\n\n\t\t\t\t\t\t\t               ** RECORD NOT FOUND **\n");
    }
    fclose(fp);
    getch();
}





void delete()
{
    struct student info;
    FILE *fp, *fp1;
    int roll_no, found = 0;
    printf("\n\t\t\t\t\t\t\t  ================================================");
	printf("\n\t\t\t\t\t\t\t                DELETE STUDENTS RECORD");
	printf("\n\t\t\t\t\t\t\t  ================================================\n");
    fp = fopen("record.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("\n\t\t\t\t\t\t\t                ENTER REGIS NO. : ");
    scanf("%d", &roll_no);
    if (fp == NULL)
    {
        fprintf(stderr, "\n\t\t\t\t\t\t\t         CAN'T OPEN FILE\n");
        exit(0);
    }
    while (fread(&info, sizeof(struct student), 1, fp))
    {
        if (info.roll_no == roll_no)
        {
            found = 1;
        }
        else
        {
            fwrite(&info, sizeof(struct student), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    if (!found)
    {
        printf("\n\n\t\t\t\t\t\t\t               ** RECORD NOT FOUND **\n\n");
    }
    if (found)
    {
        remove("record.txt");
        rename("temp.txt", "record.txt");
        printf("\n\n\t\t\t\t\t\t\t             RECORD DELETED SUCCESSFULLY\n");
    }
    getch();
}





void marksheet()
{
    struct student info;
    FILE *fp;
    int roll_no, found = 0;
    int n, i;
    int m;
    int z,check;
    int total=0;
    float per;
    fp = fopen("record.txt", "r");
    printf("\n\t\t\t\t\t\t\t  ================================================");
	printf("\n\t\t\t\t\t\t\t             STUDENT MARKSHEET PROGRAM");
	printf("\n\t\t\t\t\t\t\t  ================================================\n\n");
    printf("\n\t\t\t\t\t\t                ENTER REGIS NO. : ");
    scanf("%d", &roll_no);
    while (fread(&info, sizeof(struct student), 1, fp) > 0)
    {
        if (info.roll_no == roll_no)
        {
            found = 1;
            printf("\n");
            printf("\n\t\t\t\t\t\t\t         STUDENT NAME   :  %s %s", info.first_name, info.last_name);
        	printf("\n\t\t\t\t\t\t\t         REGIS NO       :  %d", info.roll_no);
        	printf("\n\t\t\t\t\t\t\t         BRANCH         :  %s", info.Class);
        	printf("\n\t\t\t\t\t\t\t         VILLAGE/CITY   :  %s", info.vill);
        	printf("\n\t\t\t\t\t\t\t         SUBJECTS OPTED :  %d", info.sub_opted);
        	printf("\n\n\t\t\t\t\t\t\t         SUBJECTS          MARKS");
        	for(m=0;m<info.sub_opted;m++){
        		int s=info.sj[m];
        		printf("\n\t\t\t\t\t\t\t         %s\t   %.1f",subjects[s],info.marks[m]);
    		}
    		printf("\n\n\t\t\t\t\t\t\t         TOTAL    \t:  %.1f / %d", info.total,(info.sub_opted*100));
    		printf("\n\t\t\t\t\t\t\t         AVERAGE    \t:  %.1f", info.avg);
			printf("\n\t\t\t\t\t\t\t         PERCENTAGE    \t:  %.2f%%", info.per);
        	printf("\n\t\t\t\t\t\t\t         ________________________________");
        	for (m=0;m<info.sub_opted;m++)
    		{
        		if(info.marks[m]<35) 
           			check=1;
     		}
    		if(check==1){
    			printf("\n\t\t\t\t\t\t\t         RESULT    \t   FAILED");
    			printf("\n\t\t\t\t\t\t\t         ________________________________");
        		check=0;
			}
			else{
			printf("\n\t\t\t\t\t\t\t         RESULT    \t   PASSED");
			printf("\n\t\t\t\t\t\t\t         ________________________________");
        	check=0;
			}

    		if(info.per>=85){
    			printf("\n\n\t\t\t\t\t\t\t         CONGRATULATIONS %s %s,", info.first_name, info.last_name);
    			printf("\n\t\t\t\t\t\t\t         YOU ACHIEVED %0.0f%%",info.per);
			}
			else if(info.per>=60 && per<85){
    			printf("\n\n\t\t\t\t\t\t\t         VERY NICE %s %s,", info.first_name, info.last_name);
    			printf("\n\t\t\t\t\t\t\t         YOU ACHIEVED %0.0f%%",info.per);
			}
			else if(info.per>=33 && per<60){
    			printf("\n\n\t\t\t\t\t\t\t         NOT BAD %s %s,", info.first_name, info.last_name);
    			printf("\n\t\t\t\t\t\t\t         YOU ACHIEVED %0.0f%%",info.per);
			}
    		else if(info.per<33){
    			printf("\n\n\t\t\t\t\t\t\t         NO PROBLEM %s %s,", info.first_name, info.last_name);
    			printf("\n\t\t\t\t\t\t\t         TRY NEXT TIME...",info.per);
        		printf("\n\t\t\t\t\t\t\t         YOUR RESULT IS %0.0f%%",info.per);
			}    	
        }
    }
    if (!found)
    {
        printf("\n\n\t\t\t\t\t\t\t               ** RECORD NOT FOUND **\n");
    }
    fclose(fp);
    getch();
}
