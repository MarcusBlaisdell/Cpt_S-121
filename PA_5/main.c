/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Description: This program performs the following:
* Reads information from a file, Sequences.txt and if it is flagged as N for normal,
* it stores it in an array to be compared to later data that will be stored in another
* array denoted as Sample and then compares the Sample array to the Normal array to
* evaluate and note differences and store that information in an output file, mutations.txt.
*/

#include "Blaisdell_PA5.c"

int main (void)
{
	// declare variables
	FILE *outfile = NULL;
	char normal_top_pair[15] = {'\0'}, normal_bottom_pair[15] = {'\0'},
		sample_top_pair[15] = {'\0'}, sample_bottom_pair[15] = {'\0'},
		flag = '\0', base = '\0', *flag_ptr = NULL,
		random_top_pair[15] = {'\0'}, random_bottom_pair[15] = {'\0'};
	int array_size = 0, array_size_s = 0, *array_size_ptr = NULL, *array_size_s_ptr = NULL,
		pass_count = 1, *pass_ptr = NULL, loop_count = 0, *loop_ptr = NULL, loop_init = 0,
		missing[15] = {0}, count = 0;

	// set the pointers
	flag_ptr = &flag;
	array_size_ptr = &array_size;
	array_size_s_ptr = &array_size_s;
	pass_ptr = &pass_count;
	loop_ptr = &loop_count;

	// erase any pre-existing mutations.txt file data to get a clean slate
	outfile = fopen ("mutations.txt", "w");
	fclose (outfile);

	// run a loop counter to count the instances of '\n' in the file
	// between N and S, subtract 1, divide by 3 to determine
	// how many times to read the file to get all of the data
	loop_counter (loop_ptr);
	loop_count = (loop_count - 1) / 3;

	// read data from the file

	for (loop_init = 0; loop_init < loop_count; loop_init++)
	{ // begin read for loop

	// read the normal information:
	read_file_normal (normal_top_pair, normal_bottom_pair, sample_top_pair, sample_bottom_pair,
		flag_ptr, array_size_ptr, pass_ptr);

	// read the sample information
	read_file_sample (normal_top_pair, normal_bottom_pair, sample_top_pair, sample_bottom_pair,
		flag_ptr, array_size_s_ptr, pass_ptr);

	// print results to mutations.txt
	print_normal (normal_top_pair, normal_bottom_pair, array_size, pass_ptr);
	print_sample (sample_top_pair, sample_bottom_pair, array_size, pass_ptr);

	// compare the sample data to the normal data, output any differences to mutations.txt
	compare_sample (normal_top_pair, normal_bottom_pair, sample_top_pair, sample_bottom_pair,
		flag_ptr, array_size_ptr, array_size_s_ptr, pass_ptr, missing);

	// increment the pass counter
	pass_count++;
	flag = '\0';

	} // end read for loop

	// generate and insert random data into Sequences.txt
	make_temp();
	populate_random (random_top_pair, random_bottom_pair);
	insert_random (random_top_pair, random_bottom_pair);

	return 0;
}
