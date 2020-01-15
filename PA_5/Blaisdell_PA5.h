#ifndef BLAISDELL_PA5_H
#define BLAISDELL_PA5_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void print_normal (char normal_top[], char normal_bottom[], int size, int *pass);
void print_sample (char sample_top[], char sample_bottom[], int size, int *pass);
void read_file_normal (char normal_top[], char normal_bottom[], char sample_top[], char sample_bottom[],
					char *flag, int *size, int *pass);
void read_file_sample (char normal_top[], char normal_bottom[], char sample_top[], char sample_bottom[],
					char *flag, int *size_s, int *pass);
void compare_sample (char normal_top[], char normal_bottom[], char sample_top[], char sample_bottom[],
					char *flag, int *size, int *size_s, int *pass, int missing[]);
void loop_counter (int *loop_count);
void insert_random (char random_top_pair[], char random_bottom_pair[]);
void make_temp (void);
void populate_random(char random_top_pair[], char random_bottom_pair[]);
void tweak_random(char random_top_pair[], char random_bottom_pair[]);

#endif