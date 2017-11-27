#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book {
	int number;
	char title[20];
};

int main(void)
{
	struct Book *p;

	p = (struct Book *)malloc(2 * sizeof(struct Book));

	if(p == NULL){	
	  printf("메모리 할당 오류\n") ;
	  exit(1);
	} 

	p->number = 1;
	strcpy(p->title,"C Programming");
	printf("%d %s\n",p->number,p->title);

	(p+1)->number = 2;
	strcpy((p+1)->title,"Data Structure");
	printf("%d %s\n",(p+1)->number,(p+1)->title);

	free(p);
	return 0;
}