/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 2
* Date: September 17, 2014
* Description: Equation Evaluator Version 2, Top Down Programming, 3 file format:
*	1. Calculate total series resistance
*	2. Calculate sales tax
*	3. Volume of a right rectangular pyramid ((l*w*h)/3)
*	4. Calculate total parallel resistance
*	5. Character encoding a la the little orphan Annie decoder ring
*	6. Distance between two points
*	7. Solve the general equation: y = y / (3/17) - z + x / (a % 2) + PI
*/

#include "Equations.c"

int main(void)
{
// declare variables

int seriesR1 = 0, seriesR2 = 0, seriesR3 = 0, 
	parallelR1 = 0, parallelR2 = 0, parallelR3 = 0, 
	a = 0, shift = 0;

double series_resistance = 0.0, total_sales_tax = 0.0, sales_tax_rate = 0.0, item_cost = 0.0, 
	volume_pyramid = 0.0, length = 0.0, width = 0.0, height = 0.0, 
	parallel_resistance = 0.0, distance = 0.0, 
	x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, 
	x = 0.0, y = 0.0, z = 0.0, solution = 0.0;

char encoded_character = '\0', plaintext_character = '\0';

// Part 1, Total series resistance
// Get the inputs
printf ("Calculate total series resistance of 3 resistors\n");
printf ("Enter an integer value for Resistor 1 in Ohms: ");
scanf ("%d", &seriesR1);
printf ("Enter an integer value for Resistor 2 in Ohms: ");
scanf ("%d", &seriesR2);
printf ("Enter an integer value for Resistor 3 in Ohms: ");
scanf ("%d", &seriesR3);

// calculate total series resistance
	// series_resistance = seriesR1 + seriesR2 + seriesR3;
series_resistance = calculate_series_resistance (seriesR1, seriesR2, seriesR3);

// print the result
printf ("The Total Series Resistance = %.2lf Ohms.\n", series_resistance);

// print a blank space to make things easier to read
printf ("\n");

// Part 2, Sales tax
// Get the inputs
printf ("Calculate Sales Tax\n");
printf ("Enter the sales tax rate: ");
scanf ("%lf", &sales_tax_rate);
printf ("Enter the cost of the item: ");
scanf ("%lf", &item_cost);

// calculate the sales tax
// total_sales_tax = sales_tax_rate * item_cost;
total_sales_tax = calculate_total_sales_tax (sales_tax_rate, item_cost);

// print the result
printf ("The total sales tax on a $%.2lf item at %.2lf tax rate is: $%.2lf\n", 
		item_cost, sales_tax_rate, total_sales_tax);

// print a blank space to make things easier to read
printf ("\n");

// Part 3, Volume of a right, rectangular pyramid
// Get the inputs
printf ("Calculate the volume of a right, rectangular pyramid\n");
printf ("Enter the length of the base of the pyramid: ");
scanf ("%lf", &length);
printf ("Enter the width of the base of the pyramid: ");
scanf ("%lf", &width);
printf ("Enter the height of the pyramid: ");
scanf ("%lf", &height);

// calculate the volume
// volume_pyramid = (length * width * height) / 3;
	volume_pyramid = calculate_volume_pyramid (length, width, height);

// print the result
printf ("The volume of a pyramid of %.2lf by %.2lf base and %.2lf high\n", length, width, height);
printf ("is: %.2lf\n", volume_pyramid);

// print a blank space to make things easier to read
printf ("\n");

// Part 4, Total parallel resistance
// Get the inputs
printf ("Calculate the total parallel resistance of 3 resistors\n");
printf ("Enter the value of resistor 1: ");
scanf ("%d", &parallelR1);
printf ("Enter the value of resistor 2: ");
scanf ("%d", &parallelR2);
printf ("Enter the value of resistor 3: ");
scanf ("%d", &parallelR3);

// calculate the resistance
parallel_resistance = calculate_parallel_resistance (parallelR1, parallelR2, parallelR3);

// print the result
printf ("The total parallel resistance is %.2lf Ohms\n", parallel_resistance);

// print a blank space to make things easier to read
printf ("\n");

// Part 5, character encoding
// Get the inputs
printf ("Character encoding\n");
printf ("Enter a character: ");
scanf (" %c", &plaintext_character);
printf ("Enter the desired shift level: ");
scanf ("%d", &shift);

// calculate the encoded character
// encoded_character = (int) plaintext_character - 'a' + 'A' - shift;
encoded_character = perform_character_encoding (plaintext_character, shift);

// print the encoded character
printf ("%c encodes to: %c\n",plaintext_character, encoded_character);

// print a blank space to make things easier to read
printf ("\n");

// Part 6, Distance between two points
// Get the inputs
printf ("Calculate the distance between two points\n");
printf ("Enter the x value of the first point: ");
scanf ("%lf", &x1);
printf ("Enter the y value of the first point: ");
scanf ("%lf", &y1);
printf ("Enter the x value of the second point: ");
scanf ("%lf", &x2);
printf ("Enter the y value of the second point: ");
scanf ("%lf", &y2);

// calculate the distance
// distance = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	distance = calculate_distance_between_2pts (x1, x2, y1, y2);

// print the result
printf ("The distance between the two given points is: %.2lf\n", distance);

// print a blank space to make things easier to read
printf ("\n");

// Part 7, Solve the general equation: y=y/(3/17)-z+x/(a%2)+PI
// Get the inputs
printf ("Solve the general equation: y=y/(3/17)-z+x/(a%%2)+PI\n");
printf ("Enter a value for x: ");
scanf ("%lf", &x);
printf ("Enter a value for y: ");
scanf ("%lf", &y);
printf ("Enter a value for z: ");
scanf ("%lf", &z);
printf ("Enter a value for a: ");
scanf ("%d", &a);

// print the equation and then the solution
printf ("The solution to the general equation:\n");
printf ("y = (%.2lf/(3/17)) - %.2lf + (%.2lf / (%d%%2)) + PI\n", y, z, x, a);
	solution = calculate_general_equation (a, x, y, z);
	printf ("is: %.2lf\n", solution);

// print a blank space to make things easier to read
printf ("\n");

// sign off
printf("That's all folks!\n\n");
}
