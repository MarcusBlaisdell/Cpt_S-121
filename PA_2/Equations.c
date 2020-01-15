#include "Equations.h"

int calculate_series_resistance (int r1, int r2, int r3)
{
	int series_resistance = 0;
	series_resistance = r1 + r2 + r3;
	return series_resistance;
}

double calculate_total_sales_tax (double sales_tax_rate, double item_cost)
{
	double total_sales_tax = 0.0;
	total_sales_tax = sales_tax_rate * item_cost;
	return total_sales_tax;
}
double calculate_volume_pyramid (double l, double w, double h)
{
	double volume_pyramid = 0.0;
	volume_pyramid = (l * w * h) / 3;
	return volume_pyramid;
}

double calculate_parallel_resistance (int r1, int r2, int r3)
{
	double parallel_resistance = 0;
	parallel_resistance = (double) 1 / (((double) 1 / r1) 
									+ ((double) 1 / r2) 
									+ ((double) 1 / r3));
	return parallel_resistance;
}

char perform_character_encoding (char plaintext_character, int shift_key)
{
	int encoded_character = 0;
	encoded_character = (int) plaintext_character - 'a' + 'A' - shift_key;
	return encoded_character;
}

double calculate_distance_between_2pts (double x1, double x2, double y1, double y2)
{
	double distance = 0.0;
	distance = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	return distance;
}

double calculate_general_equation (int a, double x, double y, double z)
{
	double solution = 0.0;
	solution = y / ((double) 3 / 17) - z + ( x / (a%2)) + PI;
	return solution;
}