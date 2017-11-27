#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_SIZE 50

typedef struct NODE {
	char title[S_SIZE];
	int year;
	struct NODE *link;
} NODE;

int main(void)
{	
	NODE *list = NULL;
	NODE *prev, *p, *next;
	char buffer[S_SIZE];
	int year;

while(1)	
{
	printf("책의 제목을 입력하시오: (종료하려면 엔터)");
	gets(buffer);		
	if( buffer[0] == '\0' ) 	
		break;
	p = (NODE *)malloc(sizeof(NODE));
	strcpy(p->title, buffer);
	printf("책의 출판 연도를 입력하시오: ");
	gets(buffer);
	year = atoi(buffer);		
	p->year = year;
	if( list == NULL )      // 리스트가 비어 있으면 
	     list = p;	       // 새로운 노드를 첫번째 노드로 만든다.
	else	       // 리스트가 비어 있지 않으면
	     prev->link = p;        // 새로운 노드를 이전 노드의 끝에
	p->link = NULL;  // 새로운 노드의 링크 필드를 NULL로 설정
	prev = p;
}
	
printf("\n");

	// 연결 리스트에 들어 있는 정보를 모두 출력한다.
	p = list;
	while( p != NULL )
	{
	     printf("책의 제목:%s 출판 연도:%d \n", 
                                                       p->title, p->year);
	     p = p->link;
	}

	// 동적 할당을 반납한다.	
	p = list;
	while( p != NULL )
	{
		next = p->link;
		free(p);
		p = next;
	}
	return 0;
}