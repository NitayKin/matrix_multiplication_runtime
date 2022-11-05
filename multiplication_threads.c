#include "multiplication_threads.h"


uint32_t number_of_threads = 0;

void multiply_row_column_thread(args_for_multiply* args)
{
	uint32_t column[args->row_second];
	uint32_t total;
	get_row(args->first_matrix, args->row, args->i, args->column_first);
	for(int j=0;j<args->column_second;++j){
		get_column(args->second_matrix, column, args->row_second, args->column_second, j);
		total = 0;
		for(int ii=0;ii<args->column_first;++ii){
			total += (*(args->row+ii)) * (*(column+ii));
		}
		*(args->mutiplied_matrix+ args->i*args->column_second +j) = total;
	}
	free(args);
}

void multiply_matrix_thread(uint32_t* first_matrix, uint32_t* second_matrix, uint32_t row_first, uint32_t column_first, uint32_t row_second, uint32_t column_second)
{
    long start, end;
    struct timeval timecheck;
	args_for_multiply* args;
	pthread_t* thr = malloc(sizeof(pthread_t)*row_first);
	uint32_t row[column_first];
//	uint32_t column[row_second];
	uint32_t* mutiplied_matrix=malloc(sizeof(uint32_t)*row_first*column_second);
	printf("starting the process with %u threads...\n",number_of_threads);
	gettimeofday(&timecheck, NULL);
	start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
	for(int i=0;i<row_first;++i){
//		get_row(first_matrix, row, i, column_first);
//		get_column(second_matrix, column, row_second, column_second, j);
		args = malloc(sizeof(args_for_multiply));
		args->mutiplied_matrix =mutiplied_matrix;
		args->second_matrix = second_matrix;
		args->first_matrix = first_matrix;
		args->row =row;
		args->row_second = row_second;
		args->column_first =column_first;
		args->i =i;
		args->column_second =column_second;
		if(pthread_create(&thr[i], NULL, multiply_row_column_thread, args)){
			printf("could not create a thread... aborting\n");
			exit(1);
		}
		if( (i % number_of_threads == 0) && (i!=0)){ // create max {number_of_threads} threads, wait for rest...
			for(int np=i-number_of_threads;np<i ;++np)
				pthread_join(thr[np], NULL);
		}
	}
	for(int tp=0;tp<row_first;++tp)
		pthread_join(thr[tp], NULL);
	gettimeofday(&timecheck, NULL);
	end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
	print_matrix(mutiplied_matrix, row_first, column_second);
	printf("The multiplication took %f seconds to execute with threads.\n", (end - start)/1000.0);
	free(mutiplied_matrix);
	free(thr);
}
