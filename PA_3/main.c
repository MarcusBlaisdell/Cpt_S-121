/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Description: This program performs the following:
*
* 1. Opens an input file "input.dat" for reading;
*
* 2. Opens an output file "output.dat" for writing;
*
* 3. Reads five records from the input file (input.dat);
*
* 4. Calculates the sum of the GPAs;
*
* 5. Calculates the sum of the class standings;
*
* 6. Calculates the sum of the ages;
*
* 7. Calculates the mean of the GPAs, writing the result to the output file (output.dat);
*
* 8. Calculates the mean of the class standings,
*    writing the result to the output file (output.dat);
*
* 9. Calculates the mean of the ages, writing the result to the output file (output.dat);
*
* 10. Calculates the deviation of each GPA from the mean;
*
* 11. Calculates the variance of the GPAs;
*
* 12. Calculates the standard deviation of the GPAs,
*     writing the result to the output file (output.dat);
*
* 13. Determines the min of the GPAs, writing the result to the output file (output.dat);
*
* 14. Determines the max of the GPAs, writing the result to the output file (output.dat);
*
* 15. Closes the input and output files (i.e. input.dat and output.dat)
*/

#include "Blaisdell_PA3.c"

int main (void)
{
	// Declare all variables:
	int student_id_1 = 0, student_id_2 = 0, student_id_3 = 0, student_id_4 = 0,
		student_id_5 = 0, class_standing_1 = 0, class_standing_2 = 0,
		class_standing_3 = 0, class_standing_4 = 0, class_standing_5 = 0,
		standing_sum = 0;

	double gpa_1 = 0.0, gpa_2 = 0.0, gpa_3 = 0.0, gpa_4 = 0.0, gpa_5 = 0.0,
		number1 = 0.0, number2 = 0.0, number3 = 0.0, number4 = 0.0, number5 = 0.0,
		mean = 0.0, deviation = 0.0, variance = 0.0, gpa_sum = 0.0,
		deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0, deviation4 = 0.0,
		deviation5 = 0.0, standard_deviation = 0.0, gpa_max = 0.0, gpa_min = 0.0,
		age_1 = 0.0, age_2 = 0.0, age_3 = 0.0, age_4 = 0.0, age_5 = 0.0, age_sum = 0.0,
		gpa_mean = 0.0, age_mean, standing_mean = 0.0;

	FILE *input_file = NULL, *output_file = NULL;

	// steps 1 & 2: open the input and output files:
	input_file = fopen ("input.dat", "r"); // Open the input file as "read"

	output_file = fopen ("output.dat", "w"); // Open the output file as "write"

	// Step 3: read the 5 records:

	// read record 1
	student_id_1 = read_integer (input_file);
	gpa_1 = read_double (input_file);
	class_standing_1 = read_integer (input_file);
	age_1 = read_double (input_file);

	// read record 2
	student_id_2 = read_integer (input_file);
	gpa_2 = read_double (input_file);
	class_standing_2 = read_integer (input_file);
	age_2 = read_double (input_file);

	// read record 3
	student_id_3 = read_integer (input_file);
	gpa_3 = read_double (input_file);
	class_standing_3 = read_integer (input_file);
	age_3 = read_double (input_file);

	// read record 4
	student_id_4 = read_integer (input_file);
	gpa_4 = read_double (input_file);
	class_standing_4 = read_integer (input_file);
	age_4 = read_double (input_file);

	// read record 5
	student_id_5 = read_integer (input_file);
	gpa_5 = read_double (input_file);
	class_standing_5 = read_integer (input_file);
	age_5 = read_double (input_file);

	// Step 4: Calculate the sum of the GPA's
	gpa_sum = calculate_sum (gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);

	// Step 5: Calculate the sum of the class standings
	standing_sum = calculate_sum (class_standing_1, class_standing_2, class_standing_3,
		class_standing_4, class_standing_5);

	// Step 6: Calculate the sum of the ages
	age_sum = calculate_sum (age_1, age_2, age_3, age_4, age_5);

	// Step 7: Calculate the mean of the gpa's
	// and write to output file (output.dat)
	gpa_mean = calculate_mean (gpa_sum, 5);
	print_double (output_file, gpa_mean);

	// Step 8: Calculate the mean of the class standings
	// and write to output file (output.dat)
	standing_mean = calculate_mean (standing_sum, 5);
	print_double (output_file, standing_mean);

	// Step 9: Calculate the mean of the ages
	// and write to output file (output.dat)
	age_mean = calculate_mean (age_sum, 5);
	print_double (output_file, age_mean);

	// Add a blank line as seen in the assignment output example
	fprintf (output_file, "\n");

	// Step 10: Calculate the deviation of each GPA from the mean
	deviation1 = calculate_deviation (gpa_1, gpa_mean);
	deviation2 = calculate_deviation (gpa_2, gpa_mean);
	deviation3 = calculate_deviation (gpa_3, gpa_mean);
	deviation4 = calculate_deviation (gpa_4, gpa_mean);
	deviation5 = calculate_deviation (gpa_5, gpa_mean);

	// Step 11: Calculate the variance
	variance = calculate_variance (deviation1, deviation2, deviation3, deviation4,
		deviation5, 5);

	// Step 12: Calculate the standard deviation
	// and write to output file (output.dat)
	standard_deviation = calculate_standard_deviation (variance);
	print_double (output_file, standard_deviation);

	// Steps 13 & 14: Determine the minimum and maximum gpas
	// and write to output file (output.dat)
	gpa_min = determine_min (gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);
	print_double (output_file, gpa_min);

	gpa_max = determine_max (gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);
	print_double (output_file, gpa_max);

	// Step 15: Close the files
	fclose(input_file);
	fclose(output_file);

	return 0;
}
