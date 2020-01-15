/*
* Programmer: Mark Blaisdell (Please, call me Marcus)
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Proramming Assignment 1
* Date: September 10, 2014
* Description: Equation Evaluator:
*	1. Calculate total series resistance
*	2. Calculate sales tax
*	3. Volume of a right rectangular pyramid ((l*w*h)/3)
*	4. Calculate total parallel resistance
*	5. Character encoding a la the little orphan Annie decoder ring
*	6. Distance between two points
*	7. Solve the general equation: y = y / (3/17) - z + x / (a % 2) + PI
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159

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
	x = 0.0, y = 0.0, z = 0.0;

char encoded_character = '\0', plaintext_character = '\0';

// Part 1, Total series resistance
printf ("Calculate total series resistance of 3 resistors\n");
printf ("Enter an integer value for Resistor 1 in Ohms: ");
scanf ("%d", &seriesR1);
printf ("Enter an integer value for Resistor 2 in Ohms: ");
scanf ("%d", &seriesR2);
printf ("Enter an integer value for Resistor 3 in Ohms: ");
scanf ("%d", &seriesR3);

// calculate total series resistance
series_resistance = seriesR1 + seriesR2 + seriesR3;

// print the result
printf ("The Total Series Resistance = %lf Ohms.\n", series_resistance);

// print a blank space to make things easier to read
printf ("\n");

// Part 2, Sales tax
printf ("Calculate Sales Tax\n");
printf ("Enter the sales tax rate: ");
scanf ("%lf", &sales_tax_rate);
printf ("Enter the cost of the item: ");
scanf ("%lf", &item_cost);

// calculate the sales tax
total_sales_tax = sales_tax_rate * item_cost;

// print the result
printf ("The total sales tax on a $%lf item at %lf tax rate is: $%lf\n", 
		item_cost, sales_tax_rate, total_sales_tax);

// print a blank space to make things easier to read
printf ("\n");

// Part 3, Volume of a right, rectangular pyramid
printf ("Calculate the volume of a right, rectangular pyramid\n");
printf ("Enter the length of the base of the pyramid: ");
scanf ("%lf", &length);
printf ("Enter the width of the base of the pyramid: ");
scanf ("%lf", &width);
printf ("Enter the height of the pyramid: ");
scanf ("%lf", &height);

// calculate the volume
volume_pyramid = (length * width * height) / 3;

// print the result
printf ("The volume of a pyramid of %lf by %lf base and %lf high\n", length, width, height);
printf ("is: %lf\n", volume_pyramid);

// print a blank space to make things easier to read
printf ("\n");

// Part 4, Total parallel resistance
printf ("Calculate the total parallel resistance of 3 resistors\n");
printf ("Enter the value of resistor 1: ");
scanf ("%d", &parallelR1);
printf ("Enter the value of resistor 2: ");
scanf ("%d", &parallelR2);
printf ("Enter the value of resistor 3: ");
scanf ("%d", &parallelR3);

// calculate the resistance
parallel_resistance = (double) 1 / (((double) 1 / parallelR1) 
									+ ((double) 1 / parallelR2) 
									+ ((double) 1 / parallelR3));

// print the result
printf ("The total parallel resistance is %lf Ohms\n", parallel_resistance);

// print a blank space to make things easier to read
printf ("\n");

// Part 5, character encoding
printf ("Character encoding\n");
printf ("Enter a character: ");
scanf (" %c", &plaintext_character);
printf ("Enter the desired shift level: ");
scanf ("%d", &shift);

// calculate the encoded character
encoded_character = (int) plaintext_character - 'a' + 'A' - shift;

// print the encoded character
printf ("%c encodes to: %c\n",plaintext_character, encoded_character);

// print a blank space to make things easier to read
printf ("\n");

// Part 6, Distance between two points
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
distance = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

// print the result
printf ("The distance between the two given points is: %lf\n", distance);

// print a blank space to make things easier to read
printf ("\n");

// Part 7, Solve the general equation: y=y/(3/17)-z+x/(a%2)+PI
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
printf ("y = (%lf/(3/17)) - %lf + (%lf / (%d%%2)) + PI\n", y, z, x, a);
printf ("is: %lf\n", y = y / ((double) 3 / 17) - z + ( x / (a%2)) + PI);

// print a blank space to make things easier to read
printf ("\n");

// sign off
printf("That's all folks!\n\n");
}