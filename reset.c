#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fps=NULL,*fpi=NULL,*fpc=NULL;
	fps=fopen("students.txt","w+");
	fputc('0',fps);
	fclose(fps);
	free(fps);
	fpi=fopen("instructors.txt","w+");
	fputc('0',fpi);
	fclose(fpi);
	free(fpi);
    	fpc=fopen("courses.txt","w+");
	fputc('0',fpc);
	fclose(fpc);
	free(fpc);
	printf("Reset Succesful!\n");
}
