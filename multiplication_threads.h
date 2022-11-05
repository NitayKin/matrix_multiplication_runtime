#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include "multiplication.h"


extern uint32_t number_of_threads;

typedef struct {
	uint32_t* mutiplied_matrix;
	uint32_t* second_matrix;
	uint32_t* first_matrix;
	uint32_t row_second;
	uint32_t* row;
	uint32_t column_first;
	uint32_t i;
	uint32_t column_second;
} args_for_multiply;

void multiply_row_column_thread(args_for_multiply* );

void multiply_matrix_thread(uint32_t* , uint32_t* , uint32_t , uint32_t, uint32_t , uint32_t );
