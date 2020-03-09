#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char* getbranch(int a){
		if(a==0)
			return "CSE";
		else if(a==1)
			return "EE";
		else if(a==2)
			return "ME";
		else
			return "NaN";
}
struct student {
    char rollno[MAX];
    char fname[MAX];
    char lname[MAX];
    int branch;
    int semester;
    int ncourses;
    char **course_codes;
};
struct instructor{
    char rollno[MAX];
    char fname[MAX];
    char lname[MAX];
    int ncourses;
    char **course_codes;
};
struct course {
    char codeno[MAX];
	int cc;
    char name[MAX];
    char lname[MAX];
    int nins;
    char **ins_codes;
    int nstd;
    char **std_codes;
};
struct student *students=NULL;
struct instructor *instructors=NULL;
struct course *courses=NULL;
FILE *fps=NULL,*fpi=NULL,*fpc=NULL;
int nstudents=0,ninstructors=0,ncourses=0;
void as1(struct student s){
    students=realloc(students,(nstudents+1)*sizeof(struct student));
    students[nstudents++]=s;
}
void as2(struct instructor s){
    instructors=realloc(instructors,(ninstructors+1)*sizeof(struct instructor));
    instructors[ninstructors++]=s;
}
void as3(struct course s){
    courses=realloc(courses,(ncourses+1)*sizeof(struct course));
    courses[ncourses++]=s;
}
void ls1(){
    fps=fopen("students.txt", "r+");
    nstudents=0;
    int nstudent;
    char buf[MAX];
    struct student s;
    fscanf(fps,"%d",&nstudent);
    for(int i=0;i<nstudent;i++){
        fgets(buf,MAX,fps);
        fscanf(fps,"%s",s.rollno);
        fscanf(fps,"%s",s.fname);
        fscanf(fps,"%s",s.lname);
       fscanf(fps,"%u",&s.branch);
       fscanf(fps,"%d",&s.semester);
       fscanf(fps,"%d",&s.ncourses);
        s.course_codes=malloc(s.ncourses*sizeof(char *));
       for(int j=0;j<s.ncourses;j++){
        s.course_codes[j]=malloc(MAX*sizeof (char));
         fscanf(fps,"%s",s.course_codes[j]);
    	}
        as1(s);
	}
fclose(fps);
}
void ls2() {
    fpi=fopen("instructors.txt", "r+");
    ninstructors=0;
    int ninstructor;
    char buf[MAX];
    struct instructor s;
    fscanf(fpi,"%d",&ninstructor);
    for(int i=0;i<ninstructor;i++){
        fgets(buf,MAX,fpi);
        fscanf(fpi,"%s",s.rollno);
        fscanf(fpi,"%s",s.fname);
        fscanf(fpi,"%s",s.lname);
       fscanf(fpi,"%d",&s.ncourses);
        s.course_codes=malloc(s.ncourses*sizeof(char *));
       for(int j=0;j<s.ncourses;j++){
        s.course_codes[j]=malloc(MAX*sizeof (char));
         fscanf(fpi,"%s",s.course_codes[j]);
        }
        as2(s);
   }
fclose(fpi);
}
void ls3(){
    fpc=fopen("courses.txt", "r+");
    ncourses=0;
    int ncourse;
    char buf[MAX];
    struct course s;
    fscanf(fpc,"%d",&ncourse);
    for(int i=0;i<ncourse;i++){
        fgets(buf,MAX,fpc);
        fscanf(fpc,"%s",s.codeno);
        fscanf(fpc,"%s",s.name);
        fscanf(fpc,"%s",s.lname);
       fscanf(fpc,"%d",&s.cc);
       fscanf(fpc,"%d",&s.nins);
        s.ins_codes=malloc(s.nins*sizeof(char *));
       for(int j=0;j<s.nins;j++){
        s.ins_codes[j]=malloc(MAX*sizeof (char));
         fscanf(fpc,"%s",s.ins_codes[j]);}
       fscanf(fpc,"%d",&s.nstd);
        s.std_codes=malloc(s.nstd*sizeof(char *));
       for(int j=0;j<s.nstd;j++){
        s.std_codes[j]=malloc(MAX*sizeof (char));
         fscanf(fpc,"%s",s.std_codes[j]);
        }
        as3(s);
   }
fclose(fpc);
}
void ldm(int a){
	switch(a)
	{	
		case 1:ls1();
		break;
		case 2:ls2();
		break;
		case 3: ls3();
		break;
		default : ls1();
		ls2();
		ls3();
		break;
	}
}
void p1s1(struct student s){
	printf("Roll no.: %s\t",s.rollno);
	printf("Name: %s %s\t",s.fname,s.lname);
	printf("Branch: %s\t",getbranch(s.branch));
	printf("Semester: %d\t",s.semester);
	printf("List of coures:\t");
    for(int i=0; i<s.ncourses; i++)
        printf("%s\t",s.course_codes[i]);
	printf("\n");
}
void p1s2(struct instructor s){
    printf("Faculty ID.: %s\t",s.rollno);
    printf("Name: %s %s\t",s.fname,s.lname);
	printf("List of coures:\t");
    for(int i=0; i<s.ncourses; i++)
        printf("%s\t",s.course_codes[i]);
	printf("\n");
}
void p1s3(struct course s){
    printf("Course no.: %s\t",s.codeno);
    printf("Name: %s %s\t",s.name,s.lname);
    printf("Course Credits.: %d\t",s.cc);
	printf("List of Instructors:\t");
    for(int i=0; i<s.nins; i++)
        printf("%s\t",s.ins_codes[i]);
	printf("List of Students:\t");
    for(int i=0; i<s.nstd; i++)
        printf("%s\t",s.std_codes[i]);
	printf("\n");
}
void pas1(){
    for(int i=0;i<nstudents;i++)
        p1s1(students[i]);
}
void pas2(){
    for(int i=0;i<ninstructors;i++)
        p1s2(instructors[i]);
}
void pas3(){
    for(int i=0;i<ncourses;i++)
        p1s3(courses[i]);
}
void padm(int a){
	switch(a)
	{
		case 1:pas1();
		break;
		case 2:pas2();
		break;
		case 3:pas3();
		break;
		default:pas1();
				putchar('\n');
		pas2();
				putchar('\n');
		pas3();  
				putchar('\n');
		break;
	}
}
void sS(int k)
{
	fps=fopen("students.txt", "w");
	int tmpo=nstudents;
	if(k!=-1)
		nstudents-=1;
	fprintf(fps,"%d\n",nstudents);
	for(int i=0;i<tmpo;i++){
  		if(i!=k){
        fprintf(fps,"\n%s",students[i].rollno);
        fprintf(fps,"\n%s",students[i].fname);
        fprintf(fps," %s",students[i].lname);
  	 	fprintf(fps,"\n%u",students[i].branch);
   		fprintf(fps,"\n%d",students[i].semester);
   		fprintf(fps,"\n%d",students[i].ncourses);
   		fprintf(fps,"\n");
       	for(int j=0;j<students[i].ncourses;j++)
        	 fprintf(fps,"%s ",students[i].course_codes[j]);
       	fprintf(fps,"\n");
     	}
	}
fclose(fps);
	ldm(1);
}
void sI(int k){
	fpi=fopen("instructors.txt", "w");
	int tmpo=ninstructors;
	if(k!=-1)
		ninstructors-=1;
	fprintf(fpi,"%d\n",ninstructors);
	for(int i=0;i<tmpo;i++){
  		if(i!=k){
  	 	    fprintf(fpi,"\n%s",instructors[i].rollno);
		    fprintf(fpi,"\n%s",instructors[i].fname);
   		    fprintf(fpi," %s",instructors[i].lname);
			   fprintf(fpi,"\n%d",instructors[i].ncourses);
		   fprintf(fpi,"\n");
    	   for(int j=0;j<instructors[i].ncourses;j++)
         fprintf(fpi,"%s ",instructors[i].course_codes[j]);
       fprintf(fpi,"\n");
     }
}
fclose(fpi);
     ldm(2);
}
void sC(int k){
	fpc=fopen("courses.txt", "w");
	int tmpo=ncourses;
	if(k!=-1)
		ncourses-=1;
	fprintf(fpc,"%d\n",ncourses);
	for(int i=0;i<tmpo;i++){
  		if(i!=k){
 		   fprintf(fpc,"\n%s",courses[i].codeno);
    		fprintf(fpc,"\n%s",courses[i].name);
    		fprintf(fpc," %s",courses[i].lname);
   			fprintf(fpc,"\n%d",courses[i].cc);
       		fprintf(fpc,"\n%d",courses[i].nins);
       		fprintf(fpc,"\n");
       		for(int j=0;j<courses[i].nins;j++)
         	fprintf(fpc,"%s ",courses[i].ins_codes[j]);
       		fprintf(fpc,"\n%d",courses[i].nstd);
      		 fprintf(fpc,"\n");
      		 for(int j=0;j<courses[i].nstd;j++)
         	fprintf(fpc,"%s ",courses[i].std_codes[j]);
      	 	fprintf(fpc,"\n");
     	}
	}
fclose(fpc);
	ldm(3);
}
void link(){
	ldm(-1);
	for(int i=0;i<nstudents;i++)
	{
    	for(int j=0;j<students[i].ncourses;j++)
    	{
	int cf=-1,tmp[3];
	for(int k=0;k<ncourses;k++)
	{   
	if(strcmp(students[i].course_codes[j],courses[k].codeno)==0)
	{
	for(int l=0;l<courses[k].nstd;l++)
	{   
	if(strcmp(students[i].rollno,courses[k].std_codes[l])==0)	
	{
	cf=i,tmp[0]=j,tmp[1]=k,tmp[2]=l;
	break;
	}
	}
	if(cf==-1)
	{
	courses[k].nstd+=1;
	courses[k].std_codes=realloc(courses[k].std_codes,courses[k].nstd*sizeof(char *));
	courses[k].std_codes[courses[k].nstd-1]=malloc(MAX*sizeof(char));
	strcpy(courses[k].std_codes[courses[k].nstd-1],students[i].rollno);
	cf=i;
	break;
	}
	}	
	}
	if(cf==-1)
	{
	struct course s;
	strcpy(s.codeno,students[i].course_codes[j]);
	strcpy(s.name,"Modify");
	strcpy(s.lname,"Me");
	s.cc=0;
	s.nins=0;
	for(int m=0;m<ninstructors;m++)
	{
	for(int n=0;n<instructors[m].ncourses;n++)
	{
	if(strcmp(instructors[m].course_codes[n],students[i].course_codes[j])==0)
	{
	s.nins++;
	if(s.nins!=1)
              s.ins_codes=realloc(s.ins_codes,s.nins*sizeof(char *));
              else
              s.ins_codes=malloc(s.nins*sizeof(char *));
              s.ins_codes[s.nins-1]=malloc(MAX*sizeof(char));
              strcpy(s.ins_codes[s.nins-1],instructors[m].rollno);
              break;
	}
	}
	}
	if(s.nins==0)
	{
	struct instructor f;
	strcpy(f.rollno,"FC_Modify");
	strcpy(f.fname,"Modify");
	strcpy(f.lname,"Me");
	f.ncourses=1;
	f.course_codes=malloc(sizeof(char *));
	f.course_codes[0]=malloc(MAX*sizeof(char));
	strcpy(f.course_codes[0],students[i].course_codes[j]);
	as2(f);
	s.nins++;
              s.ins_codes=malloc(sizeof(char *));
              s.ins_codes[0]=malloc(MAX*sizeof(char));
              strcpy(s.ins_codes[0]=malloc(MAX*sizeof(char)),f.rollno);
	}
	s.nstd=1;
	s.std_codes=malloc(sizeof(char *));
	s.std_codes[0]=malloc(MAX*sizeof(char));
	strcpy(s.std_codes[0],students[i].rollno);
	as3(s);
	break;
	}
	}
	}
	sS(-1);	
	sI(-1); 
	sC(-1);
	for(int i=0;i<ncourses;i++)
	{
		courses[i].nstd=0;
		int fnd=-1;
		for(int j=0;j<nstudents;j++)
		{
			for(int k=0;k<students[j].ncourses;k++)
			{
				if(strcmp(courses[i].codeno,students[j].course_codes[k])==0)
				{
					courses[i].nstd+=1;
				        courses[i].std_codes=realloc(courses[i].std_codes,courses[i].nstd*sizeof(char *));
			                courses[i].std_codes[courses[i].nstd-1]=malloc(MAX*sizeof(char));
			                strcpy(courses[i].std_codes[courses[i].nstd-1],students[j].rollno);
			                fnd=i;
			                break;
				}
			}
		}
		if(fnd==-1)
		{	
			for(int j=0;j<ninstructors;j++)
			{
				for(int k=0;k<instructors[j].ncourses;k++)
				{
					if(strcmp(courses[i].codeno,instructors[j].course_codes[k])==0)
					{
						instructors[j].ncourses-=1;
						if(instructors[j].ncourses!=0){
					        char **course_cods=malloc(instructors[j].ncourses*sizeof(char *));
					        int z=0;
				        	for(int l=0;l<instructors[j].ncourses+1;l++){
       							 course_cods[z]=malloc(MAX*sizeof (char));
         						 if(strcmp(instructors[j].course_codes[l],courses[i].codeno)!=0)
         						 	strcpy(course_cods[z++],instructors[j].course_codes[l]);
        					}
					        instructors[j].course_codes=realloc(instructors[j].course_codes,instructors[j].ncourses*sizeof(char *));
					        for(int l=0;l<instructors[j].ncourses;l++){
       							 instructors[j].course_codes[z]=malloc(MAX*sizeof (char));
         						 strcpy(instructors[j].course_codes[l],course_cods[l]);
        					}}
        					else
        						sI(j);
        					break;
					}
				}
			}
			sC(i);
		}
	}
	sS(-1);
	sI(-1);
	sC(-1);
	ldm(-1);
}
void menu(){
	printf("Welocme to Dhruv Programs Roll No. :- 180020006\n");
	printf("1. Students Info.\n");
	printf("2. Instructors Info.\n");
	printf("3. Courses Info.\n");
	printf("4. All Info..\n");
	printf("5. Reset All Data\n");
	printf("6. Exit\n");
	printf("Select 1-6 : ");
}
void ex(){
	scanf("%*c");
	printf("Press Enter to Continue : ");
	char tp[1];
	fgets(tp,2,stdin);
        fflush(stdin); 
	system("clear");
}
void student(){
	void smodimenu(){
	system("clear");
	printf("Student Modification Panel  :- \n");
	printf("1. Modify Roll No.\n");
	printf("2. Modify 1st Name\n");
	printf("3. Modify Last Name\n");
	printf("4. Modify Branch No.\n");
	printf("5. Modify Sem no.\n");
	printf("6. Modify Courses List.\n");
	printf("7. Batch Modify.\n");
	printf("Select 1-7 : \n");
	}
	void modify(int flag3){
		int choice;
		smodimenu();
		fflush(stdin);
		scanf("%d",&choice);	
		switch(choice){
			case 1:printf("New Roll no. (Prev Value : %s) : \n",students[flag3].rollno);
					char *tc=malloc(100*sizeof(char));
					scanf("%s",tc);
					int flag=-1;
					for(int i=0;i<nstudents;i++)
					{
						if(strcmp(students[i].rollno,tc)==0){
							flag=i;
							break;}
					}
					if((strcmp(students[flag3].rollno,tc)!=0)&&(flag==-1))
						strcpy(students[flag3].rollno,tc);
					else
						printf("Roll No. Already Exists, Cant Change it \n");
			       break;
			case 2:printf("New 1st Name no. (Prev Value : %s) : \n",students[flag3].fname);
				scanf("%s",students[flag3].fname);
			       break;
			case 3:printf("New Last Name no. (Prev Value : %s) : \n",students[flag3].lname);
				scanf("%s",students[flag3].lname);
			       break;
			case 4:printf("New branch no. (0=CSE,1=EE,2=ME) (Prev Value : %u) : \n",students[flag3].branch);
				scanf("%u",&students[flag3].branch);
			       break;
			case 5:printf("New Sem (Prev Value : %d) : \n",students[flag3].semester);
				scanf("%d",&students[flag3].semester);
			       break;
			case 6:printf("New No. of Courses (Prev Value : %d) : \n",students[flag3].ncourses);
			int tmp=students[flag3].ncourses;
			scanf("%d",&students[flag3].ncourses);
			printf("New list of all courses like MH101 CS905 (Prev Value : ");
			for(int j=0;j<tmp;j++)
	   			printf("%s ",students[flag3].course_codes[j]);
			printf(") : ");
			students[flag3].course_codes=malloc(students[flag3].ncourses*sizeof(char *));
			for(int j=0;j<students[flag3].ncourses;j++){
				students[flag3].course_codes[j]=malloc(MAX*sizeof(char));
				scanf("%s",students[flag3].course_codes[j]);
			}
			       break;
		       case 7:
			      printf("New 1st Name no. (Prev Value : %s) : \n",students[flag3].fname);
			      scanf("%s",students[flag3].fname);
			      printf("New Last Name no. (Prev Value : %s) : \n",students[flag3].lname);
			      scanf("%s",students[flag3].lname);
			      printf("New branch no. (0=CSE,1=EE,2=ME) (Prev Value : %u) : \n",students[flag3].branch);
			      scanf("%u",&students[flag3].branch);
			      printf("New Sem (Prev Value : %d) : \n",students[flag3].semester);
			      scanf("%d",&students[flag3].semester); 
			      printf("New No. of Courses (Prev Value : %d) : \n",students[flag3].ncourses);
			int tm=students[flag3].ncourses;
			scanf("%d",&students[flag3].ncourses);
			printf("New list of all courses like MH101 CS905 (Prev Value : ");
			for(int j=0;j<tm;j++)
	   			printf("%s",students[flag3].course_codes[j]);
			printf(") : ");
			students[flag3].course_codes=malloc(students[flag3].ncourses*sizeof(char *));
			for(int j=0;j<students[flag3].ncourses;j++){
				students[flag3].course_codes[j]=malloc(MAX*sizeof(char));
				scanf("%s",students[flag3].course_codes[j]);
			}
	       			break;
			default :printf("Wrong Input, try again!\n");
			         ex();
			         break;
		}
		printf("Modification Succesfull \n");
		ex();
		sS(-1);
		//link();
	}
	void add()
	{
		system("clear");
		printf("Student Add Panel :- \n");
		char ro[MAX];
		printf("Enter Roll no.: ");
		scanf("%s",ro);
		int fl=-1;
	        for(int i=0;i<nstudents;i++)
	            if(strcmp(students[i].rollno,ro)==0){
	            	fl=i;
	            	break;
	            }
            	if(fl!=-1){
	      		printf("User Alreday Found\n");
			printf("His Deatils :- \n");
			p1s1(students[fl]);
			char cob;
		printf("Do u want to modify him ? (y/n) ");
			getchar();
			scanf("%c",&cob);
			if(cob=='y'||cob=='Y')
			modify(fl);
		}
		else{
		struct student s;
		strcpy(s.rollno,ro);
		printf("Enter his 1st Name: ");
	  	scanf("%s",s.fname);
		printf("Enter his last Name: ");
	  	scanf("%s",s.lname);
		printf("Enter his branch no. (0=CSE,1=EE,2=ME): ");
	  	scanf("%u",&s.branch);
		printf("In which sem: ");
	  	scanf("%d",&s.semester);
		printf("No. of courses he has: ");
	 	scanf("%d",&s.ncourses);		
		printf("Enter All Courses Codes like MH101 CS905 : ");
	  	s.course_codes=malloc(s.ncourses*sizeof(char *));
	  	for(int j=0;j<s.ncourses;j++){
	   		s.course_codes[j]=malloc(MAX*sizeof (char));
	   		scanf("%s",s.course_codes[j]);
	  	}
	  	as1(s);		
		printf("Entery Save Succesfully\n");
		sS(-1);
		//link();
		printf("Do u want to add more ? (y/n) ");
		char col;
		getchar();
		scanf("%c",&col);
		if(col=='y'||col=='Y')
			add();
		}
	}
	void smenu(){
	system("clear");
	printf("Students Info :\n");
	printf("1. Display All entries\n");
	printf("2. Display entry\n");
	printf("3. Add entry\n");
	printf("4. Delete entry\n");
	printf("5. Modify entry\n");
	printf("6. Back\n");
	printf("Select 1-6 : ");
	}
	int scase(){
		system("clear");
		int sc=0;
		while(sc!=6)
		{
			smenu();
			fflush(stdin);
			scanf("%d",&sc);
			switch(sc)
			{
				case 1:padm(1);
				       ex();
				       break;
				case 2:	printf("Enter Roll No. : ");
					char tmp1[MAX];
					int flag1=0;
		               	        scanf("%s",tmp1);
				        for(int i=0;i<nstudents;i++)
				            if(strcmp(students[i].rollno,tmp1)==0){
				            	p1s1(students[i]);
				            	flag1=1;
				            	break;
				            }
			            	if(flag1==0){
			            		printf("Respective Entries Not Found\n");
					printf("Do u want to add him ? (y/n) ");
					char cod;
					getchar();
					scanf("%c",&cod);
					if(cod=='y'||cod=='Y')
						add();}
				        ex();
				        break;
				case 3:add();
				       break;
				case 4:printf("Enter Roll No. : ");
					char tmp2[MAX];
					int flag2=-1;
		               	        scanf("%s",tmp2);
		               	        printf("%s\n",tmp2);
				        for(int i=0;i<nstudents;i++)
				            if(strcmp(students[i].rollno,tmp2)==0)
				            	flag2=i;
			            	if(flag2==-1)
			            		printf("User to be deleted not found\n");
		            		else
			            		printf("User deleted successfully \n");
		            		sS(flag2);
;				       ex();
				       break;
				case 5:printf("Enter Roll No. : ");
					char tmp3[MAX];
					int flag3=-1;
		               	        scanf("%s",tmp3);
				        for(int i=0;i<nstudents;i++)
				            if(strcmp(students[i].rollno,tmp3)==0)
				            	flag3=i;
			            	if(flag3==-1){
			            		printf("User to be modified not found\n");
			            		printf("Do u want to add him ? (y/n) :  ");
						char co;
						getchar();
						scanf("%c",&co);
						if(co=='y'||co=='Y')
							add();}
		            		else{
						modify(flag3);
					}
					sS(-1);	
				       break;
				case 6:	break;
				default :printf("Wrong Input, try again!\n");
				         ex();
				         break;
			}
		}
	}
	ldm(1);
	scase();
	sS(-1);
	link();
}
void instructor(){
	void smodimenu(){
	system("clear");
	printf("Instructor Modification Panel  :- \n");
	printf("1. Modify Faculty ID\n");
	printf("2. Modify 1st Name\n");
	printf("3. Modify Last Name\n");
	printf("4. Modify Courses List.\n");
	printf("5. Batch Modify.\n");
	printf("Select 1-5 : \n");
	}	
	void modify(int flag3){
		int choice;
		smodimenu();
		fflush(stdin);
		scanf("%d",&choice);	
		switch(choice){
			case 1:printf("New Faculty ID (Prev Value : %s) : \n",instructors[flag3].rollno);
					char *tc=malloc(100*sizeof(char));
					scanf("%s",tc);
					int flag=-1;
					for(int i=0;i<ninstructors;i++)
					{
						if(strcmp(instructors[flag3].rollno,tc)==0){
							flag=i;
							break;}
					}
					if((strcmp(instructors[flag3].rollno,tc)!=0)&&(flag==-1))
						strcpy(instructors[flag3].rollno,tc);
					else
						printf("Faculty No. Already Exists, Cant Change it \n");
			       break;
			case 2:printf("New 1st Name no. (Prev Value : %s) : \n",instructors[flag3].fname);
				scanf("%s",instructors[flag3].fname);
			       break;
			case 3:printf("New Last Name no. (Prev Value : %s) : \n",instructors[flag3].lname);
				scanf("%s",instructors[flag3].lname);
			       break;
			case 4:printf("New No. of Courses (Prev Value : %d) : \n",instructors[flag3].ncourses);
			int tmp=instructors[flag3].ncourses;
			scanf("%d",&instructors[flag3].ncourses);
			printf("New list of all courses like MH101 CS905 (Prev Value : ");
			for(int j=0;j<tmp;j++)
	   			printf("%s ",instructors[flag3].course_codes[j]);
			printf(") : ");
			instructors[flag3].course_codes=malloc(instructors[flag3].ncourses*sizeof(char *));
			for(int j=0;j<instructors[flag3].ncourses;j++){
				instructors[flag3].course_codes[j]=malloc(MAX*sizeof(char));
				scanf("%s",instructors[flag3].course_codes[j]);
			}
			       break;
		       case 5:
			      printf("New 1st Name no. (Prev Value : %s) : \n",instructors[flag3].fname);
			      scanf("%s",instructors[flag3].fname);
			      printf("New Last Name no. (Prev Value : %s) : \n",instructors[flag3].lname);
			      scanf("%s",instructors[flag3].lname);
			      printf("New No. of Courses (Prev Value : %d) : \n",instructors[flag3].ncourses);
			int tm=instructors[flag3].ncourses;
			scanf("%d",&instructors[flag3].ncourses);
			printf("New list of all courses like MH101 CS905 (Prev Value : ");
			for(int j=0;j<tm;j++)
	   			printf("%s",instructors[flag3].course_codes[j]);
			printf(") : ");
			instructors[flag3].course_codes=malloc(instructors[flag3].ncourses*sizeof(char *));
			for(int j=0;j<instructors[flag3].ncourses;j++){
				instructors[flag3].course_codes[j]=malloc(MAX*sizeof(char));
				scanf("%s",instructors[flag3].course_codes[j]);
			}
	       			break;
			default :printf("Wrong Input, try again!\n");
			         ex();
			         break;
		}
		printf("Modification Succesfull \n");
		ex();
		sI(-1);
		//link();
	}
	void add()
	{
		system("clear");
		printf("Instructor Add Panel :- \n");
		char ro[MAX];
		printf("Enter Faculty ID: ");
		scanf("%s",ro);
		int fl=-1;
	        for(int i=0;i<ninstructors;i++)
	            if(strcmp(instructors[i].rollno,ro)==0){
	            	fl=i;
	            	break;
	            }
            	if(fl!=-1){
	      		printf("User Alreday Found\n");
			printf("His Deatils :- \n");
			p1s2(instructors[fl]);
			char cob;
		printf("Do u want to modify him ? (y/n) ");
			getchar();
			scanf("%c",&cob);
			if(cob=='y'||cob=='Y')
			modify(fl);
		}
		else{
		struct instructor s;
		strcpy(s.rollno,ro);
		printf("Enter his 1st Name: ");
	  	scanf("%s",s.fname);
		printf("Enter his last Name: ");
	  	scanf("%s",s.lname);
		printf("No. of courses he has: ");
	 	scanf("%d",&s.ncourses);		
		printf("Enter All Courses Codes like MH101 CS905 : ");
	  	s.course_codes=malloc(s.ncourses*sizeof(char *));
	  	for(int j=0;j<s.ncourses;j++){
	   		s.course_codes[j]=malloc(MAX*sizeof (char));
	   		scanf("%s",s.course_codes[j]);
	  	}
	  	as2(s);		
		printf("Entery Save Succesfully\n");
		sI(-1);
		//link();
		printf("Do u want to add more ? (y/n) ");
		char col;
		getchar();
		scanf("%c",&col);
		if(col=='y'||col=='Y')
			add();
		}
	}
	void smenu(){
	system("clear");
	printf("Instructor Info :\n");
	printf("1. Display All entries\n");
	printf("2. Display entry\n");
	printf("3. Add entry\n");
	printf("4. Delete entry\n");
	printf("5. Modify entry\n");
	printf("6. Back\n");
	printf("Select 1-6 : ");
	}
	int scase(){
		system("clear");
		int sc=0;
		while(sc!=6)
		{
			smenu();
			fflush(stdin);
			scanf("%d",&sc);
			switch(sc)
			{
				case 1:padm(2);
				       ex();
				       break;
				case 2:	printf("Enter Roll No. : ");
					char tmp1[MAX];
					int flag1=0;
		               	        scanf("%s",tmp1);
				        for(int i=0;i<ninstructors;i++)
				            if(strcmp(instructors[i].rollno,tmp1)==0){
				            	p1s2(instructors[i]);
				            	flag1=1;
				            	break;
				            }
			            	if(flag1==0){
			            		printf("Respective Entries Not Found\n");
					printf("Do u want to add him ? (y/n) ");
					char cod;
					getchar();
					scanf("%c",&cod);
					if(cod=='y'||cod=='Y')
						add();}
				        ex();
				        break;
				case 3:add();
				       break;
				case 4:printf("Enter Faculty ID. : ");
					char tmp2[MAX];
					int flag2=-1;
		               	        scanf("%s",tmp2);
		               	        printf("%s\n",tmp2);
				        for(int i=0;i<ninstructors;i++)
				            if(strcmp(instructors[i].rollno,tmp2)==0)
				            	flag2=i;
			            	if(flag2==-1)
			            		printf("User to be deleted not found\n");
		            		else
			            		printf("User deleted successfully \n");
		            		sI(flag2);
;				       ex();
				       break;
				case 5:printf("Enter Faculty ID. : ");
					char tmp3[MAX];
					int flag3=-1;
		               	        scanf("%s",tmp3);
				        for(int i=0;i<ninstructors;i++)
				            if(strcmp(instructors[i].rollno,tmp3)==0)
				            	flag3=i;
			            	if(flag3==-1){
			            		printf("User to be modified not found\n");
			            		printf("Do u want to add him ? (y/n) :  ");
						char co;
						getchar();
						scanf("%c",&co);
						if(co=='y'||co=='Y')
							add();}
		            		else{
						modify(flag3);
					}
					sI(-1);	
				       break;
				case 6:	break;
				default :printf("Wrong Input, try again!\n");
				         ex();
				         break;
			}
		}
	}
	ldm(2);
	scase();
	sI(-1);
	link();
}
void course(){
	void smodimenu(){
	system("clear");
	printf("course Modification Panel  :- \n");
	printf("1. Modify Course Code No.\n");
	printf("2. Modify 1st Name\n");
	printf("3. Modify Last Name\n");
	printf("4. Modify Course Credits\n");
	printf("5. Modify Instrustor List.\n");
	printf("6. Modify Student List.\n");
	printf("7. Batch Modify.\n");
	printf("Select 1-7 : \n");
	}	
	void modify(int flag3){
		int choice;
		smodimenu();
		fflush(stdin);
		scanf("%d",&choice);	
		switch(choice){
			case 1:printf("New Course no. (Prev Value : %s) : ",courses[flag3].codeno);
					char *tc=malloc(100*sizeof(char));
					scanf("%s",tc);
					int flag=-1;
					for(int i=0;i<ncourses;i++)
					{
						if(strcmp(courses[flag3].codeno,tc)==0){
							flag=i;
							break;}
					}
					if((strcmp(courses[flag3].codeno,tc)!=0)&&(flag==-1))
						strcpy(courses[flag3].codeno,tc);
					else
						printf("Course Code. Already Exists, Cant Change it \n");
			       break;
			case 2:printf("New 1st Name no. (Prev Value : %s) : ",courses[flag3].name);
				scanf("%s",courses[flag3].name);
			       break;
			case 3:printf("New Last Name no. (Prev Value : %s) : ",courses[flag3].lname);
				scanf("%s",courses[flag3].lname);
			       break;
			case 4:printf("New Course Credits. (Prev Value : %d) : ",courses[flag3].cc);
				scanf("%d",&courses[flag3].cc);
			       break;
			case 5:printf("New No. of Instructors (Prev Value : %d) : ",courses[flag3].nins);
			int tmp=courses[flag3].nins;
			scanf("%d",&courses[flag3].nins);
			printf("New list of all courses like MH101 CS905 (Prev Value : ");
			for(int j=0;j<tmp;j++)
	   			printf("%s ",courses[flag3].ins_codes[j]);
			printf(") : ");
			courses[flag3].ins_codes=malloc(courses[flag3].nins*sizeof(char *));
			for(int j=0;j<courses[flag3].nins;j++){
				courses[flag3].ins_codes[j]=malloc(MAX*sizeof(char));
				scanf("%s",courses[flag3].ins_codes[j]);
			}
			break;
			case 6:printf("New No. of Instructors (Prev Value : %d) : \n",courses[flag3].nstd);
			int tm=courses[flag3].nstd;
			scanf("%d",&courses[flag3].nstd);
			printf("New list of all courses like MH101 CS905 (Prev Value : ");
			for(int j=0;j<tm;j++)
	   			printf("%s ",courses[flag3].std_codes[j]);
			printf(") : ");
			courses[flag3].std_codes=malloc(courses[flag3].nstd*sizeof(char *));
			for(int j=0;j<courses[flag3].nins;j++){
				courses[flag3].std_codes[j]=malloc(MAX*sizeof(char));
				scanf("%s",courses[flag3].std_codes[j]);
			}
			break;
		       case 7:
			      printf("New 1st Name no. (Prev Value : %s) : ",courses[flag3].name);
			      scanf("%s",courses[flag3].name);
			      printf("New Last Name no. (Prev Value : %s) : ",courses[flag3].lname);
			      scanf("%s",courses[flag3].lname);
			      printf("New Course Credits. (Prev Value : %d) : ",courses[flag3].cc);
				scanf("%d",&courses[flag3].cc);
				printf("New No. of Instructors (Prev Value : %d) : \n",courses[flag3].nins);
			int t=courses[flag3].nins;
			scanf("%d",&courses[flag3].nins);
			printf("New list of all Faculty members like FC_101 FC_905 (Prev Value : ");
			for(int j=0;j<t;j++)
	   			printf("%s ",courses[flag3].ins_codes[j]);
			printf(") : ");
			courses[flag3].ins_codes=malloc(courses[flag3].nins*sizeof(char *));
			for(int j=0;j<courses[flag3].nins;j++){
				courses[flag3].ins_codes[j]=malloc(MAX*sizeof(char));
				scanf("%s",courses[flag3].ins_codes[j]);
			}
			printf("New No. of Students (Prev Value : %d) : ",courses[flag3].nstd);
			int tmpp=courses[flag3].nstd;
			scanf("%d",&courses[flag3].nstd);
			printf("New list of all students like 180020006 180020039 (Prev Value : ");
			for(int j=0;j<tmpp;j++)
	   			printf("%s ",courses[flag3].std_codes[j]);
			printf(") : ");
			courses[flag3].std_codes=malloc(courses[flag3].nstd*sizeof(char *));
			for(int j=0;j<courses[flag3].nins;j++){
				courses[flag3].std_codes[j]=malloc(MAX*sizeof(char));
				scanf("%s",courses[flag3].std_codes[j]);
			}
	       			break;
			default :printf("Wrong Input, try again!\n");
			         ex();
			         break;
		}
		printf("Modification Succesfull \n");
		ex();
		sC(-1);
		//link();
	}
	void add()
	{
		system("clear");
		printf("Course Add Panel :- \n");
		char ro[MAX];
		printf("Enter Course no.: ");
		scanf("%s",ro);
		int fl=-1;
	        for(int i=0;i<ncourses;i++)
	            if(strcmp(courses[i].codeno,ro)==0){
	            	fl=i;
	            	break;
	            }
            	if(fl!=-1){
	      		printf("Course Alreday Found\n");
			printf("Its Deatils :- \n");
			p1s3(courses[fl]);
			char cob;
		printf("Do u want to modify it ? (y/n) ");
			getchar();
			scanf("%c",&cob);
			if(cob=='y'||cob=='Y')
			modify(fl);
		}
		else{
		struct course s;
		strcpy(s.codeno,ro);
		printf("Enter its 1st Name: ");
	  	scanf("%s",s.name);
		printf("Enter its last Name: ");
	  	scanf("%s",s.lname);	
		printf("Enter Course Credits: ");
	  	scanf("%d",&s.cc);	
		printf("Enter no. of instructors: ");
	  	scanf("%d",&s.nins);	
		printf("Enter All Instructors Codes like FC101 FC905 : ");
	  	s.ins_codes=malloc(s.nins*sizeof(char *));
	  	for(int j=0;j<s.nins;j++){
	   		s.ins_codes[j]=malloc(MAX*sizeof (char));
	   		scanf("%s",s.ins_codes[j]);}	
		printf("Enter no. of students: ");
	  	scanf("%d",&s.nstd);	
		printf("Enter All Student Codes like 180010001 : ");
	  	s.std_codes=malloc(s.nstd*sizeof(char *));
	  	for(int j=0;j<s.nstd;j++){
	   		s.std_codes[j]=malloc(MAX*sizeof (char));
	   		scanf("%s",s.std_codes[j]);
	  	}
	  	as3(s);		
		printf("Entry Save Succesfully\n");
		sC(-1);
		//link();
		printf("Do u want to add more ? (y/n) ");
		char col;
		getchar();
		scanf("%c",&col);
		if(col=='y'||col=='Y')
			add();
		}
	}
	void smenu(){
	system("clear");
	printf("Courses Info :\n");
	printf("1. Display All entries\n");
	printf("2. Display entry\n");
	printf("3. Add entry\n");
	printf("4. Delete entry\n");
	printf("5. Modify entry\n");
	printf("6. Back\n");
	printf("Select 1-6 : ");
	}
	int scase(){
		system("clear");
		int sc=0;
		while(sc!=6)
		{
			smenu();
			fflush(stdin);
			scanf("%d",&sc);
			switch(sc)
			{
				case 1:padm(3);
				       ex();
				       break;
				case 2:	printf("Enter Course No. : ");
					char tmp1[MAX];
					int flag1=0;
		               	        scanf("%s",tmp1);
				        for(int i=0;i<ncourses;i++)
				            if(strcmp(courses[i].codeno,tmp1)==0){
				            	p1s3(courses[i]);
				            	flag1=1;
				            	break;
				            }
			            	if(flag1==0){
			            		printf("Respective Entries Not Found\n");
					printf("Do u want to add it ? (y/n) ");
					char cod;
					getchar();
					scanf("%c",&cod);
					if(cod=='y'||cod=='Y')
						add();}
				        ex();
				        break;
				case 3:add();
				       break;
				case 4:printf("Enter Course No. : ");
					char tmp2[MAX];
					int flag2=-1;
		               	        scanf("%s",tmp2);
		               	        printf("%s\n",tmp2);
				        for(int i=0;i<ncourses;i++)
				            if(strcmp(courses[i].codeno,tmp2)==0)
				            	flag2=i;
			            	if(flag2==-1)
			            		printf("Course to be deleted not found\n");
		            		else
			            		printf("Course deleted successfully \n");
		            		sC(flag2);
					       ex();
						link();
						ldm(-1);
				       break;
				case 5:printf("Enter Course No. : ");
					char tmp3[MAX];
					int flag3=-1;
		               	        scanf("%s",tmp3);
				        for(int i=0;i<ncourses;i++)
				            if(strcmp(courses[i].codeno,tmp3)==0)
				            	flag3=i;
			            	if(flag3==-1){
			            		printf("Course to be modified not found\n");
			            		printf("Do u want to add it ? (y/n) :  ");
						char co;
						getchar();
						scanf("%c",&co);
						if(co=='y'||co=='Y')
							add();}
		            		else{
						modify(flag3);
					}
					sC(-1);	
				       break;
				case 6:	break;
				default :printf("Wrong Input, try again!\n");
				         ex();
				         break;
			}
		}
	}
	ldm(3);
	scase();
	sC(-1);
	link();
}
int reset()
{
	fps=fopen("students.txt","w+");
	fputc('0',fps);
	fclose(fps);
	fpi=fopen("instructors.txt","w+");
	fputc('0',fpi);
	fclose(fpi);
    	fpc=fopen("courses.txt","w+");
	fputc('0',fpc);
	fclose(fpc);
	printf("Reset Succesful!\n");
}
int fcase(){
	system("clear");
	int c=0;
	while(c!=6)
	{
		menu();
		scanf("%d",&c);
		switch(c)
		{
			case 1:student();
			       ex();
			       break;
			case 2:instructor();
			       ex();
			       break;
			case 3:course();
			       ex();
			       break;
			case 4:printf("All Linked Proper Finished Details :- Students/Instructors/Courses :\n\n");
					link();
					ldm(-1);
					padm(-1);
					printf("Plz note all waste nd useless information is already filtered out nd u r seeing the best fit data.\n\n");
					printf("Plz try to soon fill the unspecified default values to their respective values nd\n delete the extra unwanted information accordindgly for the program to look neat.\n\n");
			       ex();
			       break;
			case 5:reset();
			       ex();
			       break;
			case 6:printf("Bye Bye!\n");	
			       exit(0);
			       break;
			default :printf("Wrong Input, try again!\n");
			         ex();
			         break;
		}
		link();
		ldm(-1);
	}
}
int main(){
	fcase();
	return 0;
}
