#include <stdio.h>
#include <stdlib.h>
#define size 100

int main(void) 
{ 
	int *score; 	
	int i;				
	
	score = (int *)malloc( 100*sizeof(int) ); 	


	if( score == NULL )		// ��ȯ���� NULL���� �˻�
	{
		printf("���� �޸� �Ҵ� ����\n");
		exit(1);	
	}
	
	for(i=0 ; i<100 ; i++)	
	{
		score[i] = 0;
		printf("%d\n",score[i]);
	}
	

		free(score); 	
	return 0;
} 