#include "Blaisdell_PA5.h"

/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Function: print_normal
* Description: This function performs the following:
* prints the normal sample information to a file
* Precondition: Arrays, normal_top and normal_bottom must be populated
*				array size must be defined
* Postcondition: Normal sample data is written to the output file
*/
void print_normal (char normal_top[], char normal_bottom[], int size, int *pass)
{
	FILE *outfile = NULL;
	int count = 0;

	outfile = fopen ("mutations.txt", "a");

	fprintf (outfile, "\n		Normal sample %d:\n", *pass);
	for (count = 0; count < size; count++)
	{
		fprintf (outfile, "%c", normal_top[count]);
	}
	fprintf (outfile, "\n");
	count = 0;
	for (count = 0; count < size; count++)
	{
		fprintf (outfile, "%c", normal_bottom[count]);
	}
	fprintf (outfile, "\n");

	fclose (outfile);
}

/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Function: print_sample
* Description: This function performs the following:
* prints the sample data to a file
* Precondition: Arrays, sample_top and sample_bottom must be populated
*				array size must be defined
* Postcondition: Sample data is written to the output file
*/
void print_sample (char sample_top[], char sample_bottom[], int size, int *pass)
{
	FILE *outfile = NULL;
	int count = 0;

	outfile = fopen ("mutations.txt", "a");

	fprintf (outfile, "\n		Sample data %d:\n", *pass);

	for (count = 0; count < size; count++)
	{
		fprintf (outfile, "%c", sample_top[count]);
	}
	fprintf (outfile, "\n");
	count = 0;
	for (count = 0; count < size; count++)
	{
		fprintf (outfile, "%c", sample_bottom[count]);
	}
	fprintf (outfile, "\n");

	fclose (outfile);
}

/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Function: read_file_normal 
* Description: This function performs the following:
* Reads the Normal Sample data into the Normal Arrays
* if there is more than one sample defined after the "N" flag denoting Normal,
* it will read each sample successively and retain only the most recently read
* information as determined by a "pass" count variable that is defined in main
* Precondition: The Sequences.txt file must be populated. The data must be 
*				arranged so that all normal samples appear after a single
*				'N' flag denoting "normal".
*				The pass variable must be defined.
* Postcondition: The normal_top and normal_bottom arrays will be populated with
*				each respective row of the data from the file
*/
void read_file_normal (char normal_top[], char normal_bottom[], char sample_top[], char sample_bottom[],
					char *flag, int *size, int *pass)
{
	FILE *infile = NULL;
	char base = '\0', eatspace = '\0';
	int index = 0, cycle_count = 0, clear = 0;

	infile = fopen ("Sequences.txt", "r");
	
	
	if (*flag == '\0')
	{
		do
		{
		fscanf(infile, "%c", &base);
		if (base == 'N')
		{
			*flag = base;
			fscanf (infile, "%c", &eatspace);
			for (cycle_count = 0; cycle_count < *pass; cycle_count++)
			{ // cycle count for loop, begin
				for (clear = 0; clear < 15; clear++)
			{ // begin clear arrays
				normal_top[clear] = '\0';
				normal_bottom[clear] = '\0';
			} // end clear arrays
			do
			{
				fscanf (infile, "%c", &base);
				if (base != '\n')
				{
				normal_top[index] = base;
				index++;
				}
			} while (base != '\n');
			index = 0;
			do
			{
				fscanf (infile, "%c", &base);
				if (base != '\n')
				{
				normal_bottom[index] = base;
				index++;
				}
			} while (base != '\n');
			*size = index;
			index = 0;
			fscanf (infile, "%c", &eatspace);
			} // end for loop
		}
		} while (!feof (infile));
	} // end if	
	fclose (infile);
}

/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Function: read_file_sample
* Description: This function performs the following:
* Reads the Sample data into the Sample Arrays
* if there is more than one sample defined after the "S" flag denoting Sample,
* it will read each sample successively and retain only the most recently read
* information as determined by a "pass" count variable that is defined in main
* Precondition: The Sequences.txt file must be populated. The data must be 
*				arranged so that all sample data appears after a single
*				'S' flag denoting "sample".
*				The pass variable must be defined.
* Postcondition: The sample_top and sample_bottom arrays will be populated with
*				each respective row of the data from the file
*/
void read_file_sample (char normal_top[], char normal_bottom[], char sample_top[], char sample_bottom[],
						char *flag, int *size_s, int *pass)
	{
		FILE *infile = NULL;
		char base = '\0', eatspace = '\0';
		int index = 0, cycle_count = 0, clear = 0;

		infile = fopen ("Sequences.txt", "r");

		if (*flag == 'N')
		{
			do
			{
			fscanf(infile, "%c", &base);		
			if (base == 'S')
			{
				*flag = base;
				fscanf (infile, "%c", &eatspace);
				for (cycle_count = 0; cycle_count < *pass; cycle_count++)
				{ // cycle count for loop, begin
				for (clear = 0; clear < 15; clear++)
				{ // begin clear arrays
					sample_top[clear] = '\0';
					sample_bottom[clear] = '\0';
				} // end clear arrays
				do
				{
					fscanf (infile, "%c", &base);
					if (base != '\n')
					{
					sample_top[index] = base;
					index++;
					}
				} while (base != '\n');
				index = 0;
				do
				{
					fscanf (infile, "%c", &base);
					if (base != '\n')
					{
					sample_bottom[index] = base;
					index++;
					}
				
				} while (base != '\n');
				*size_s = index;
				index = 0;
				fscanf (infile, "%c", &eatspace);
				} // end for loop
			}
			} while (!feof (infile));
		}
		fclose (infile);
	}

/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Function compare_sample
* Description: This function performs the following:
* Compares the Normal data to the Sample data and notes any discrepancies.
* Precondition: Normal arrays and Sample arrays must be populated.
*				Array size must be set.
* Postcondition: The discrepancies in the data samples will be printed to an output file
*/
void compare_sample (char normal_top[], char normal_bottom[], char sample_top[], char sample_bottom[],
					char *flag, int *size, int *size_s, int *pass, int missing[])
{
	FILE *outfile = NULL;
	int index = 0, mutation_flag = 0, normal_index = 0, sample_index = 0, missing_index = 0, 
		count = 0;

	outfile = fopen ("mutations.txt", "a");

	index = 0;

	if (*size_s < * size)
	{ // check missing
	while (normal_index < *size)
	{
		if ((sample_top[sample_index]) == (normal_top[normal_index]) && 
			(sample_bottom[sample_index]) == (normal_bottom[normal_index]))
		{
			sample_index++;
			normal_index++;
		} // end if statement
		else
		{
			missing[missing_index] = normal_index;
			normal_index++;
		} // end else
		missing_index++;
	} // end check missing while loop
	normal_index = 0;
	sample_index = 0;

	// print missing results to file
	fprintf (outfile, "		Missing Sequences detected in sequence %d:\n", *pass);
	for (count = 0; count < *size; count++)
	{
		if (missing[count] !=0)
		{
		fprintf (outfile, "Missing Sequence: %d\n", missing[count] + 1);
		}
	} // end printing for loop
	fprintf (outfile, "\n");
	} // end if (only look for missing if the sample array is shorter than the normal array
	else
	{

	// if no missing sequences, compare all sequences

	for (index = 0; index < *size; index++)
	{
	if ((normal_top[index] == sample_bottom[index]) && (normal_bottom[index] == sample_top[index]))
	{
		// if a mutation has been detected, only print that notice once by setting a flag
		// that if set prevents the message from being displayed again
		if (mutation_flag == 0)
		{
		fprintf (outfile, "\n		Mutation detected in sequence %d!\n", *pass);
		mutation_flag = 1;
		} // end mutation_flag check
		fprintf (outfile, "Swapped, position %d: ", index+1);
		fprintf (outfile, "Normal = %c / %c; Sample = %c / %c\n", normal_top[index], normal_bottom[index], 
			sample_top[index], sample_bottom[index]);
	}
	else if (normal_top[index] != sample_top[index])
	{
		if (mutation_flag == 0)
		{
		fprintf (outfile, "\n		Mutation detected in sequence %d!\n", *pass);
		mutation_flag = 1;
		} // end mutation_flag check
		fprintf (outfile, "Abnormality in Top, Position %d: ", index+1);
		fprintf (outfile, "Normal = %c, Sample = %c\n", normal_top[index], sample_top[index]);
	}
	else if (normal_bottom[index] != sample_bottom[index])
	{
		if (mutation_flag == 0)
		{
		fprintf (outfile, "\n		Mutation detected in sequence %d!\n", *pass);
		mutation_flag = 1;
		} // end mutation_flag check
		fprintf (outfile, "Abnormality in Bottom, Position %d: ", index+1);
		fprintf (outfile, "Normal = %c, Sample = %c\n", normal_bottom[index], sample_bottom[index]);
	}
	}
	} // end else missing
	fclose (outfile);
}

/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Function loop_counter
* Description: This function performs the following:
* Count the number of lines between 'N' and 'S'. Used to determine how many times to loop 
* the read and compare functions to get all of the data in the file and terminate when there 
* are no more samples to evaluate
* Precondition: Sequences.txt must exist and have data following an 'N' flag followed by
*				an 'S' flag.
* Postcondition: A count of the number of lines between 'N' and 'S' is stored in a variable
*					"loop_count" for use elsewhere.
*/
void loop_counter (int *loop_count)
{
	FILE *infile = NULL;
	char count_var = '\0';

	infile = fopen ("Sequences.txt", "r");
	
	while (count_var != 'S')
	{
		fscanf (infile, "%c", &count_var);
		if (count_var == '\n')
		{
			(*loop_count)++;
		} // end if \n
	} // end while loop

	fclose (infile);
}

/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Function insert_random
* Description: This function performs the following:
* insert random sequences into Sequences.txt
* Precondition: Sequences.txt must exist, generate_random must have been called to populate
* the random sequence
* Postcondition: Previously random generated sequences are inserted into Sequences.txt
*/
void insert_random (char random_top_pair[], char random_bottom_pair[])
{
	FILE *infile = NULL, *outfile = NULL;
	char transfer = '/0', transfer2 = '/0', transfer3 = '/0';
	int index = 0;

	infile = fopen ("Temp.txt", "r");
	outfile = fopen ("Sequences.txt", "w");

	// copy the contents of Sequences.txt to Temp.txt

	while (transfer != 'S')
	{
		fscanf (infile, "%c", &transfer);
		if (transfer != 'S')
		{
		fprintf (outfile, "%c", transfer);
		}
	} // end read until S loop
	
	// insert the previously generated random sequence into the Normal section
	for (index = 0; index < 15; index++)
	{
		fprintf(outfile, "%c", random_top_pair[index]);
	} // end print random characters (top)
	index = 0;
	fprintf(outfile, "\n");

	for (index = 0; index < 15; index++)
	{
		fprintf(outfile, "%c", random_bottom_pair[index]);
	} // end print random characters (top)
	index = 0;
	fprintf(outfile, "\n");

	// finish reading Temp.txt and put the rest of the contents in Sequences.txt
	fprintf (outfile, "\nS");
	
	while (!feof (infile))
	{
		fscanf (infile, "%c", &transfer);
		// only print one blank line, if a blank line has already been printed, do not print another
		if ((transfer3 == '\n') && (transfer2 == '\n') && (transfer == '\n'))
		{
		}
		else
		{
			fprintf (outfile, "%c", transfer);
		}
		transfer3 = transfer2;
		transfer2 = transfer;
	} // end read until !feof loop

	// tweak the random data
	tweak_random (random_top_pair, random_bottom_pair);

	// insert the tweaked random data at the end of the sample data
	for (index = 0; index < 15; index++)
	{
		fprintf(outfile, "%c", random_top_pair[index]);
	} // end print random characters (top)
	index = 0;
	fprintf(outfile, "\n");

	for (index = 0; index < 15; index++)
	{
		fprintf(outfile, "%c", random_bottom_pair[index]);
	} // end print random characters (top)
	index = 0;
	fprintf(outfile, "\n");

	fclose (infile);
	fclose (outfile);
} // end insert random

/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Function make_temp
* Description: This function performs the following:
* Copies the contents of Sequences.txt into a temp file that will be used to put new data
* in to Sequences.txt
* Precondition: Sequences.txt must exist
* Postcondition: All information in Sequences.txt will be duplicated into Temp.txt
*/
void make_temp (void)
{
	FILE *infile = NULL, *outfile = NULL;
	char character = '\0', character2 = '\0', character3 = '\0';

	infile = fopen ("Sequences.txt", "r");
	outfile = fopen ("Temp.txt", "w");

	while (!feof (infile))
	{
		fscanf (infile, "%c", &character);
		// only print 1 blank line, if a blank line has already been printed, don't print another
		if ((character3 == '\n') && (character2 == '\n') && (character == '\n'))
		{
		}
		else
		{
			fprintf (outfile, "%c", character);
		}
		character3 = character2;
		character2 = character;
	}

	fclose (infile);
	fclose (outfile);
}

/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Function populate_random
* Description: This function performs the following:
* Generates a random gene sequence by generating a random number between 0 and 3
* and translates that into letters A, T, C or G and then combines them with an 
* appropriate matching letter, i.e. T for A, C for G, etc.
* Precondition: random_top_pair and random_bottom_pair must exist
* Postcondition: Two arrays, random_top_pair and random_bottom_pair will contain
* valid-esque human genome information
*/
void populate_random(char random_top_pair[], char random_bottom_pair[])
{
	int random_num = 0, loop_count = 0;
	char random_char = '\0';

	srand ((unsigned int) time(NULL));
	
	for (loop_count = 0; loop_count < 15; loop_count++)
	{
	random_num = rand() % 4;
	switch (random_num)
	{
	case 0:
		random_char = 'A';
		break;
	case 1:
		random_char = 'T';
		break;
	case 2:
		random_char = 'C';
		break;
	case 3:
		random_char = 'G';
		break;
	default:
		printf ("you should not be seeing this\n");
	} // end Switch statement
	random_top_pair[loop_count] = random_char;
	if (random_char == 'A')
	{
		random_bottom_pair[loop_count] = 'T';
	} // end populate bottom pair if 'A'
	if (random_char == 'T')
	{
		random_bottom_pair[loop_count] = 'A';
	} // end populate bottom pair if 'T'
	if (random_char == 'C')
	{
		random_bottom_pair[loop_count] = 'G';
	} // end populate bottom pair if 'C'
	if (random_char == 'G')
	{
		random_bottom_pair[loop_count] = 'C';
	} // end populate bottom pair if 'G'
	} // end for loop
} // end function

/*
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 5
* Date: October 22, 2014
* Function tweak_random
* Description: This function performs the following:
* Modifies the previously generated random sequence in a random manner.
* A random number between 0 and 14 is generated to decide how many top pairs to alter
* A second random number is created for each number of top pairs to alter and changes 
* the array at that index to a random letter from the choices of A, T, C, G
* Precondition: random_top_pair and random_bottom_pair must exist and have been populated
* Postcondition: The two arrays, random_top_pair and random_bottom_pair will be 
* modified in a random fashion
*/
void tweak_random(char random_top_pair[], char random_bottom_pair[])
{
	char random_char = '\0';
	int how_many = 0, index = 0, which_one = 0, random_num = 0;

	srand ((unsigned int) time(NULL));
	how_many = rand() % 15;

	for (index = 0; index < how_many; index++)
	{
	random_num = rand() % 4;
	switch (random_num)
	{
	case 0:
		random_char = 'A';
		break;
	case 1:
		random_char = 'T';
		break;
	case 2:
		random_char = 'C';
		break;
	case 3:
		random_char = 'G';
		break;
	default:
		printf ("you should not be seeing this\n");
	} // end Switch statement
		which_one = rand() % 15;
		random_top_pair[which_one] = random_char;
	} // end modify for loop (top)
	index = 0;

	for (index = 0; index < how_many; index++)
	{
	random_num = rand() % 4;
	switch (random_num)
	{
	case 0:
		random_char = 'A';
		break;
	case 1:
		random_char = 'T';
		break;
	case 2:
		random_char = 'C';
		break;
	case 3:
		random_char = 'G';
		break;
	default:
		printf ("you should not be seeing this\n");
	} // end Switch statement
		which_one = rand() % 15;
		random_bottom_pair[which_one] = random_char;
	} // end modify for loop (bottom)
}