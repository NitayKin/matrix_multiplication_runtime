#include "multiplication.h"


uint32_t multiply_row_column(uint32_t* row,uint32_t* column,uint32_t length)
{
	uint32_t total = 0;
	for(int i=0;i<length;++i){
		total += (*(row+i)) * (*(column+i));
	}
	return total;
}

void multiply_matrix(uint32_t* first_matrix, uint32_t* second_matrix, uint32_t row_first, uint32_t column_first, uint32_t row_second, uint32_t column_second)
{
    long start, end;
    struct timeval timecheck;
	uint32_t row[column_first];
	uint32_t column[row_second];
	uint32_t* mutiplied_matrix=malloc(sizeof(uint32_t)*row_first*column_second);
	gettimeofday(&timecheck, NULL);
	start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
	for(int i=0;i<row_first;++i){
		get_row(first_matrix, row, i, column_first);
		for(int j=0;j<column_second;++j){
			get_column(second_matrix, column, row_second, column_second, j);
			*(mutiplied_matrix+ i*column_second +j) = multiply_row_column(row,column,column_first);
		}
	}
	print_matrix(mutiplied_matrix, row_first, column_second);
	gettimeofday(&timecheck, NULL);
	end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
	printf("The multiplication took %f seconds to execute without threads.\n", (end - start)/1000.0);
	free(mutiplied_matrix);
}

void get_row(uint32_t* matrix, uint32_t* row, uint32_t n,uint32_t m)
{
	for (int i=0;i<m;++i){
		*(row+i) = *(matrix+ n*m + i);
	}
}
void get_column(uint32_t* matrix, uint32_t* column, uint32_t n,uint32_t m,uint32_t column_picked)
{
	for (int i=0;i<n;++i){
		*(column+i) = *(matrix+ m*i + column_picked);
	}
}

void print_matrix(uint32_t* arr,uint32_t row,uint32_t column)
{
	printf("matrix layout:\n");
	for(int i=0;i<row;++i){
		printf("[");
		for(int j=0;j<column;++j){
			printf("%i",*(arr+i*column+j));
			printf( (j==column-1)? "" : "," );
		}
		printf("]\n");
	}
}
