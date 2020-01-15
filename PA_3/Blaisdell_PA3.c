#include "Blaisdell_PA3.h"

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Function Description: Reads one double from the input file.
* Preconditions: Input file must exist and be opened
* Postcondition: A double value is returned to main
*/
double read_double (FILE *infile)
{
	double the_double = 0.0;
	fscanf(infile, "%lf", &the_double);

	return the_double;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Function Description: Reads one integer number from the input file.
* Preconditions: Input file must exist and be opened
* Postcondition: An integer value is returned to main
*/
int read_integer (FILE *infile)
{
	int the_integer = 0;
	fscanf (infile, "%d", &the_integer);

	return the_integer;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Function Description: Finds the sum of:
* number1, number2, number3, number4, and number5
* and returns the result.
* Precondition: number1-5 must be defined
* Postcondition: a sum of the 5 numbers is returned to main
*/
double calculate_sum (double number1, double number2, double number3, 
					  double number4, double number5)
{
	double sum = 0.0;
	sum = number1 + number2 + number3 + number4 + number5;

	return sum;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Function Description: Determines the mean through the calculation: (sum / number)
* and returns the result. Checks to make sure that 
* number is not 0. If it is 0 the function returns -1.0 
* otherwise it returns the mean.
* Precondition: A sum must be already calculated, a number to divide by must
*				be provided.
* Postcondition: An average or mean is returned to main
*/
double calculate_mean (double sum, int number)
{
	double mean = 0.0;
	if (number == 0)
	{
		mean = -1.0;
	}
	else
	{
	mean = sum / number;
	}

	return mean;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Function Description: Determines the deviation of number from the mean
* and returns the result.
* The deviation may be calculated as number - mean.
* Precondition: A gpa must be provided, the already calculated mean
*				of the gpa's must be provided
* Postcondition: The deviation of the provided gpa from the mean is returned
*/
double calculate_deviation (double number, double mean)
{
	double deviation = 0.0;
	deviation = mean - number;

	return deviation;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Function Description: Determines the variance through the calculation:
* ((deviation1)^2 + (deviation2)^2 + (deviation3)^2 + (deviation4)^2 + (deviation5)^2)
* / number and returns the result. Hint: you may call your
* calculate_mean ( ) function to determine the result!
* Precondition: gpa deviations must be already calculated and provided,
*				a number to divide the total by must be provided
* Postcondition: A variance of gpa's is returned.
*/
double calculate_variance (double deviation1, double deviation2, double deviation3,
						   double deviation4, double deviation5, int number)
{
	double variance = 0.0;
	variance = ((deviation1 * deviation1) + (deviation2 * deviation2) + 
		(deviation3 * deviation3) + (deviation4 * deviation4) + 
		(deviation5 * deviation5)) / number;

	return variance;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Function Description: Calculates the standard deviation as sqrt (variance)
* and returns the result.
* Precondition: A variance must have already been calculated and provided
* Postcondition: A standard deviation is returned.
*/
double calculate_standard_deviation (double variance)
{
	double standard_deviation = 0.0;
	standard_deviation = sqrt(variance);

	return standard_deviation;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Function Description: Determines the maximum number out of the five input parameters
* passed into the function, returning the max.
* Precondition: 5 numbers must be provided
* Postcondition: The lowest value of the 5 numbers is returned
*/
double determine_max (double number1, double number2, double number3, double number4,
				 double number5)
{
	double max = 0.0;
	max = number1;
	if (number2 > max)
	{
		max = number2;
	}
	if (number3 > max)
	{
		max = number3;
	}
	if (number4 > max)
	{
		max = number4;
	}
	if (number5 > max)
	{
		max = number5;
	}

	return max;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Function Description: Determines the minimum number out of the five input parameters
* passed into the function, returning the min.
* Precondition: 5 numbers must be provided
* Postcondition: The highest value of the 5 numbers is returned
*/
double determine_min (double number1, double number2, double number3, double number4,
				 double number5)
{
	double min = 0.0;
	min = number1;
	if (number2 < min)
	{
		min = number2;
	}
	if (number3 < min)
	{
		min = number3;
	}
	if (number4 < min)
	{
		min = number4;
	}
	if (number5 < min)
	{
		min = number5;
	}

	return min;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 3
* Date: September 24, 2014
* Function Description: Prints a double precision number (to the hundredths place)
* to an output file.
* Precondition: An output file must be defined and opened.
*				a number to output to a file of type double
*				must be provided
* Postcondition: The provided value will be written to the provided
*				output file as a double with precision to the hundredths place
*/
void print_double (FILE *outfile, double number)
{
	fprintf (outfile, "%.2lf\n", number);
}