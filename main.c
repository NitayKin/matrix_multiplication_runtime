#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include "multiplication.h"
#include "multiplication_threads.h"

void generate_matrix(uint32_t*,uint32_t,uint32_t);
void print_matrix(uint32_t*,uint32_t,uint32_t);

int main(int argc, char **argv)
{
	uint8_t user_thread_flag = 0;
	srand(time(NULL));
	uint32_t row_first;
	uint32_t column_first;
	uint32_t row_second;
	uint32_t column_second;
	char row_first_string[10];
	char column_first_string[10];
	char row_second_string[10];
	char column_second_string[10];
	char number_of_threads_string[10];
	uint32_t* first_array;
	uint32_t* second_array;
	while(user_thread_flag!='3'){
		printf("1 - no threads, 2 - with threads,3 - exit:\n");
		scanf("%c",&user_thread_flag);
		if ( (user_thread_flag=='1') || (user_thread_flag=='2')){
			printf("rows of first matrix:\n");
			scanf("%s",row_first_string);
			row_first = atoi(row_first_string);
			printf("columns of first matrix:\n");
			scanf("%s",column_first_string);
			column_first = atoi(column_first_string);
			printf("rows of second matrix:\n");
			scanf("%s",row_second_string);
			row_second = atoi(row_second_string);
			printf("columns of second matrix:\n");
			scanf("%s",column_second_string);
			column_second = atoi(column_second_string);
			if(column_first!=row_second){
				printf("cant multiply...\n");
				continue;
			}
			first_array=malloc(sizeof(uint32_t)*row_first*column_first);
			second_array=malloc(sizeof(uint32_t)*row_second*column_second);
			generate_matrix(first_array,row_first,column_first);
			generate_matrix(second_array,row_second,column_second);
//			print_matrix(first_array,row_first,column_first);
//			print_matrix(second_array,row_second,column_second);
			if (user_thread_flag=='2'){
				printf("how many threads:\n");
				scanf("%s",number_of_threads_string);
				number_of_threads = atoi(number_of_threads_string);
				multiply_matrix_thread(first_array,second_array,row_first,column_first,row_second,column_second);
			}
			else
				multiply_matrix(first_array,second_array,row_first,column_first,row_second,column_second);
			free(first_array);
			free(second_array);
		}
	}
	return 0;
}

void generate_matrix(uint32_t* arr,uint32_t row,uint32_t column)
{
	for(int i=0;i<row*column;++i){
		*(arr+i)=rand()%5;
	}
}






