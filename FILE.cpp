#include<stdio.h>
struct  data{
	int roll;
	char name [31];
	int score[5];
	int ts=0;
}student;

int checkroll(int roll)
{
 FILE *fp1;

 fp1 = fopen("Record.txt", "r");
 while (!feof(fp1))
 {
  fread(&student, sizeof(student), 1, fp1);

  if (roll == student.roll)
  {
   fclose(fp1);
   return 1;
  }
 }
 fclose(fp1);
 return 0;
}

void getdata ()
{
	int c;
	FILE *fp;
	fp = fopen ("Record.txt","a");
	printf("Enter the Roll Number :: ");
	scanf ("%d",&student.roll);
      
	printf("Enter the Student Name :: ");
	scanf ("%s",&student.name);
	for (int i=0;i<5;i++)
	{
	  printf("Enter the score in subject %d :: ",i+1);
	  scanf ("%d",&student.score[i]);
	  student.ts += student.score[i];
    }
	fwrite (&student,sizeof(student),1,fp);
    student.ts =0;

	fclose(fp);

}

void display()
{
 FILE *fp;
 fp = fopen("Record.txt", "r");
 printf("\nRoll Number\tName\tTotal Score\n\n");
 while (fread(&student, sizeof(student), 1, fp))
 printf("  %d\t\t%s\t%d\n", student.roll, student.name, student.ts);

 fclose(fp);
}

void search()
{
 FILE *fp2;
 int r, s, avl;
 printf("\nEnter the Roll no you want to search  :");
 scanf("%d", &r);
 avl = checkroll(r);
 if (avl == 0)
  printf("Roll No %d is not available in the file\n",r);
 else
 {
  fp2 = fopen("Record.txt", "r");
  while (fread(&student, sizeof(student), 1, fp2))
  {
   s = student.roll;
   if (s == r)
   {
    printf("\nRoll no = %d", student.roll);
    printf("\nName    = %s", student.name);
    for (int i=0;i<5;i++)
    {
      printf("\nMarks in Subject %d   = %d",i+1, student.score[i]);	
	}
    printf("\nTotal Marks = %d\n",student.score[0] + student.score[1] + student.score[2] +student.score[3] +student.score[4] );
   }
  }
  fclose(fp2);
 }
}

void edit()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter roll number to update:");
 scanf("%d", &r);
 avl = checkroll(r);
 if (avl == 0)
 {
  printf("Roll number %d is not Available in the file\n", r);
 }
 else
 {
  fpo = fopen("Record.txt", "r");
  fpt = fopen("TempFile.txt", "w");
  while (fread(&student, sizeof(student), 1, fpo))
  {
   s = student.roll;
   if (s != r)
    fwrite(&student, sizeof(student), 1, fpt);
   else
   {
   	int ch;
   	printf("\n\t1.Edit Roll Number");
   	printf("\n\t2.Edit Name");
   	printf("\n\t3.Edit Marks of subject");
   	printf("\n\tEnter Choice : ");
   	scanf("%d",&ch);
   	switch(ch)
   	{
   		case 1 :
   			printf("Enter Roll Number : ");
   			scanf("%d",&student.roll);
   			break;
   		
   		case 2 :
   			printf("Enter Name : ");
   			scanf("%s",&student.name);
   			break;
		
   		case 3 :
   			for (int i=0;i<5;i++)
   			{
   		    	printf("Enter Marks of subject %d : ",i+1);
   		    	scanf("%d",&student.score[i]);
   		        student.ts += student.score[i];
			}
   		    student.ts = 0;
			break;	   	
	}
    fwrite(&student, sizeof(student), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record.txt", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&student, sizeof(student), 1, fpt))
  {
   fwrite(&student, sizeof(student), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  }
}

void deleterecord()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Roll no you want to delete :");
 scanf("%d", &r);
 if (checkroll(r) == 0)
  printf("Roll no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record,txt", "r");
  fpt = fopen("TempFile.txt", "w");
  while (fread(&student, sizeof(student), 1, fpo))
  {
   s = student.roll;
   if (s != r)
    fwrite(&student, sizeof(student), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record.txt", "w");
  fpt = fopen("TempFile.txt", "r");
  while (fread(&student, sizeof(student), 1, fpt))
   fwrite(&student, sizeof(student), 1, fpo);
  fclose(fpo);
  fclose(fpt);
 }
}

int menu()
 {
     int choice;
      printf ("\nMenu\n");
      printf ("1.Insert Record\n");
      printf ("2.Edit Record\n");
      printf ("3.Display Record\n");
      printf ("4.Search Record\n");
      printf ("5.Delete Record\n");     
	  printf ("6.Exit\n");
	  scanf ("%d",&choice);     
	 student.ts =0;
	 return choice;
 }

int main ()
{
	struct data s;
	FILE *fptr;
    int choice;
	fptr = fopen("Record.txt","w");
	if (fptr == NULL)
	{
		printf("Error in opening\n");
		return 0;
	}
	else
	{
	do
	{
	    choice = menu();
		switch(choice)
	    {
		case 1 : getdata(); 
		           break;
	    case 2 : edit();
	               break;
	    case 3 : display();
	               break;
	    case 4 : search(); 
		           break;
	    case 5 : deleterecord();
	               break;
	    
		case 6  : printf ("System exit!\n");
	            
					break;
		default : printf("\nPlease try again with a valid choice\n");    
		}
	}
	while (choice != 6);
	}	
	return 0;
}
