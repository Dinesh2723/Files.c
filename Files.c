#include<stdio.h>
#include<stdlib.h>
struct student
{
int id;
char name[30];
float mark;
}student;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
FILE *fp;
fp = fopen("Record", "a");
printf("Enter the id:");
scanf("%d", &student.id);
printf("Enter the name:");
scanf("%s",student.name);
printf("Enter the marks:");
scanf("%f", &student.mark);
fwrite(&student, sizeof(student), 1, fp);
fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void disp()
{
FILE *fp1;
fp1 = fopen("Record", "r");
printf("\nId\tName\t\tMark\n\n");
while (fread(&student, sizeof(student), 1, fp1))
printf(" %d\t%s\t\t%.2f\n", student.id, student.name, student.mark);
fclose(fp1);
}
int avlid(int id)
{
FILE *fp;
int c = 0;
fp = fopen("Record", "r");
while (!feof(fp))
{
fread(&student, sizeof(student), 1, fp);
if (id == student.id)
{
fclose(fp);
return 1;
}
}
fclose(fp);
return 0;
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void search()
{
FILE *fp2;
int r, s, avl;
printf("\nEnter the Id you want to search  :");
scanf("%d", &r);
avl = avlid(r);
if (avl == 0)
printf("Id %d is not available in the file\n",r);
else
{
fp2 = fopen("Record", "r");
while (fread(&student, sizeof(student), 1, fp2))
{
s = student.id;
if (s == r)
{
printf("\nId = %d", student.id);
printf("\nName    = %s", student.name);
printf("\nMark    = %.2f\n", student.mark);
}
}
fclose(fp2);
}
}
//  FUNCTION TO DELETE A RECORD
void deletefile()
{
FILE *fpo;
FILE *fpt;
int r, s;
printf("Enter the Id you want to delete :");
scanf("%d", &r);
if (avlid(r) == 0)
printf("Id %d is not available in the file\n", r);
else
{
fpo = fopen("Record", "r");
fpt = fopen("TempFile", "w");
while (fread(&student, sizeof(student), 1, fpo))
{
s = student.id;
if (s != r)
fwrite(&student, sizeof(student), 1, fpt);
}
fclose(fpo);
fclose(fpt);
fpo = fopen("Record", "w");
fpt = fopen("TempFile", "r");
while (fread(&student, sizeof(student), 1, fpt))
fwrite(&student, sizeof(student), 1, fpo);
printf("\nRECORD DELETED\n");
fclose(fpo);
fclose(fpt);
}
}
//    FUNCTION TO UPDATE THE RECORD
void update()
{
int avl;
FILE *fpt;
FILE *fpo;
int s, r, ch;
printf("Enter Id to update:");
scanf("%d", &r);
avl = avlid(r);
if (avl == 0)
{
printf("Id %d is not Available in the file", r);
}
else
{
fpo = fopen("Record", "r");
fpt = fopen("TempFile", "w");
while (fread(&student, sizeof(student), 1, fpo))
{
s = student.id;
if (s != r)
fwrite(&student, sizeof(student), 1, fpt);
else
{
printf("\n\t1. Update Name of Id %d", r);
printf("\n\t2. Update Mark of Id %d", r);
printf("\n\t3. Update both Name and Mark of Id %d", r);
printf("\nEnter your choice:");
scanf("%d", &ch);
switch (ch)
{
case 1:
printf("Enter Name:");
scanf("%s",student.name);
break;
case 2:
printf("Enter Mark : ");
scanf("%f", &student.mark);
break;
case 3:
printf("Enter Name: ");
scanf("%s",student.name);
printf("Enter Mark: ");
scanf("%f", &student.mark);
break;
default:
printf("Invalid Selection");
break;
}
fwrite(&student, sizeof(student), 1, fpt);
}
}
fclose(fpo);
fclose(fpt);
fpo = fopen("Record", "w");
fpt = fopen("TempFile", "r");
while (fread(&student, sizeof(student), 1, fpt))
{
fwrite(&student, sizeof(student), 1, fpo);
}
fclose(fpo);
fclose(fpt);
printf("RECORD UPDATED");
}
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT//
int empty()
{
int c = 0;
FILE *fp;
fp = fopen("Record", "r");
while (fread(&student, sizeof(student), 1, fp))
c = 1;
fclose(fp);
return c;
}
// MAIN PROGRAM
void main()
{
int c, emp;
do
{
printf("\n\t======Select your choice======\n");
printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. EXIT");
printf("\nEnter your choice:");
scanf("%d", &c);
printf("\n");
switch (c)
{
case 1:
insert();
break;
case 2:
emp = empty();
if (emp == 0)
printf("\nThe file is EMPTY\n");
else
disp();
break;
case 3:
search();
break;
case 4:
deletefile();
break;
case 5:
update();
break;
case 6:
exit(1);
break;
default:
printf("\nYour choice is wrong\nPlease try again...\n");
break;
}
} while (c != 6);
}
