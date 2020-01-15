#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <stdio.h>
#include <math.h>

#define PI 3.14159

// Required Function Prototypes

int calculate_series_resistance (int r1, int r2, int r3);
double calculate_total_sales_tax (double sales_tax_rate, double item_cost);
double calculate_volume_pyramid (double l, double w, double h);
double calculate_parallel_resistance (int r1, int r2, int r3);
char perform_character_encoding (char plaintext_character, int shift_key);
double calculate_distance_between_2pts (double x1, double x2, double y1, double y2);
double calculate_general_equation (int a, double x, double y, double z);

#endif