all: process_memory parallel_sum sum_func_a parallel_min_max_time
process_memory: process_memory.c
	gcc process_memory.c -o process_memory
sum_func_a: sum_func.c sum_func.h
	gcc -c sum_func.c sum_func.h
	ar rcs libsum_func.a sum_func.o
parallel_sum: parallel_sum.c
	gcc parallel_sum.c utils.h utils.c -L. -lsum_func -pthread -o parallel_sum
parallel_min_max_time: parallel_min_max.c
	gcc utils.h utils.c find_min_max.h find_min_max.c parallel_min_max.c -o parallel_min_max_time