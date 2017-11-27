#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 100		// �� ���� ������Ű�� ũ��

double *scores = NULL;

int add_score(double new_score);

int main(void) 
{
	int i, size;
	double value, total=0.0;
	
	size = 3;
	
	for(i=0;i<size;i++) 
	{
		printf("����: ");		
		scanf("%lf", &value);
		
		add_score(value);
	}

	for(i=0;i<size;i++)
	{
		total += scores[i];
	}

	printf("���: %f\n", total/size);	free(scores);
	
	return 0;
}

int add_score(double new_score)
{
	static int limit = 0;		// ���� ���� �迭�� �ִ� ũ��
	static int count = 0;		// ���� ���� �迭�� ũ��	
	
	if( count < limit )
	{		
		scores[count++]= new_score;
	} 
	else 
	{
		int new_limit = limit + INCREMENT;
		double *new_array =(double*)realloc(scores, new_limit*sizeof(double));
		
		if( new_array == NULL )
		{
			fprintf(stderr, "�޸� �Ҵ� ����\n");
		}
		else 
		{	
			scores = new_array;
			limit = new_limit;
			scores[count++] = new_score;
		}
		return count;
	}
}