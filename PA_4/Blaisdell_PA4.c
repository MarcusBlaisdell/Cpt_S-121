#include "Blaisdell_PA4.h"

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 4
* Date: October 8, 2014
* Description: This function performs the following:
* Displays the main menu of the game
* Preconditions: main must exist, called from main
* Postconditions: calls the next function based on user input
*/
void main_menu (void)
{
	int main_option = 0, initial_balance_flag = 0, number_of_rolls = 0;
	double balance = 0.0, initial_balance = 0.0;

	do
	{
	system ("cls"); // clear the screen
	printf ("Balance = %.2lf\n", balance);
	printf ("Welcome to the game of Craps\n\n");
	printf ("Choose an option from the menu below:\n\n");
	printf ("1) Explain the rules\n");
	printf ("2) Bank (Convert your money to/from casino chips\n");
	printf ("3) Play Craps\n");
	printf ("4) Exit the game\n\n");
	scanf ("%d", &main_option);
	printf ("main_option = %d\n", main_option); // for testing, delete before submitting

	switch (main_option)
	{
	case 1:
		display_rules ();
		break;
	case 2:
		balance = bank (balance);
		if (initial_balance_flag == 0)
		{
			initial_balance = balance;
			initial_balance_flag = 1;
		}
		break;
	case 3:
		balance = play_craps (balance, initial_balance, number_of_rolls);
		break;
	case 4:
		break;
	default:
		printf ("Invalid Entry\n");
	}
	} while (main_option != 4);
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 4
* Date: October 8, 2014
* Description: This function performs the following:
* Displays the rules of the game
* Preconditions: user selected from main_menu, called from function main_menu
* Postconditions: returns to the function that called it, no return values
*/
int display_rules (void)
{
	int finished = 0;

	system ("cls");
	printf ("Rules:\n");
	printf ("Main Menu\n");
	printf ("Option 1 brings you here, to the rules page.\n");
	printf ("Option 2 lets you add or remove money from your account.\n");
	printf ("If you were in a real casino, this would be the equivalent of\n");
	printf ("converting your cash to chips.\n");
	printf ("In this menu, option 1 allows you to add money.\n");
	printf ("Option 2 allows you to remove money.\n");
	printf ("In the main menu, option 3 starts the game.\n");
	printf ("You will be prompted to place a wager.\n");
	printf ("You must enter a value greater than 0 to play.\n");
	printf ("You cannot bet more than what is in your bank balance.\n");
	printf ("Once your wager is placed, the computer will automatically\n");
	printf ("roll the dice for you.\n");
	printf ("If, on the first roll, the sum of the two dice is 2, 3, or 12,\n");
	printf ("you will lose the roll.\n");
	printf ("The casino keeps the amount you have wagered.\n");
	printf ("If on your first roll, the sum of the two dice is a 7 or 11,\n");
	printf ("you win. Your wager is returned to you and the house pays you\n");
	printf ("the amount of your wager.\n");
	printf ("If on your first roll, the sum of your dice is 4, 5, 6, 8, 9 or 10,\n");
	printf ("this becomes your 'point'.\n");
	printf ("The goal at this time is to roll that same total before rolling\n");
	printf ("a 7. If you roll a 7 before you match the point, you lose.\n");
	printf ("If you do roll the point again without rolling a 7, you will win.\n");
	printf ("\n");
	printf ("It's pretty simple but the best way to learn is to play.\n");
	printf ("Press 1 to return to the main menu\n");
	scanf ("%d", &finished);

	return finished;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 4
* Date: October 8, 2014
* Description: This function performs the following:
* Adjusts the players bank balance
* Preconditions: user selected from main_menu, called from function main_menu
*				if a bank balance already exists, it is passed in from the 
*				previous function.
*				can be called from main_menu and from play_game
* Postconditions: returns the new bank balance
*/
double bank (double balance)
{
	int choice = 0;
	double adjust = 0.0;

	printf ("Choose an option from the menu:\n");
	printf ("1) Purchase more casino chips\n");
	printf ("2) Cash out chips\n");
	printf ("?");
	scanf (" %d", &choice);
	
	switch (choice)
	{
	case 1:
		printf ("Enter a quantity to add to your balance\n?");
		scanf ("%lf", &adjust);
		balance = balance + adjust;
		break;
	case 2:
		printf ("Enter a quantity to subtract from your balance\n?");
		scanf ("%lf", &adjust);
		if (adjust <= balance)
		{
		balance = balance - adjust;
		}
		else
		{
			printf ("I am sorry, you do not have that much money in your account\n");
		}
		break;
	default:
		printf ("Invalid entry\n");
	}

	printf ("Balance = %lf\n", balance);
	return balance;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 4
* Date: October 8, 2014
* Description: This function performs the following:
* Plays the game
* Preconditions: called from main_menu
* Postconditions: returns the new bank balance
*/
double play_craps (double balance, double initial_balance, int number_of_rolls)
{
	int choice = 0, die1 = 0, die2 = 0, point = 0, dice_sum = 0;
	double wager = 0.0;
	char evaluation = '\0', status = '\0';

	system ("cls");

	if (balance == 0.0)
	{
		printf ("You must have money to play this game.\n");
		printf ("Please go to the bank and add money to your account\n");
		printf ("Press 1 to continue\n");
		scanf ("%d", &choice);
	}
	else
	{
		wager = get_wager_amount (balance);

	balance = balance - wager;

	do
	{
	system ("cls");
	printf ("Initial balance = %.2lf\n", initial_balance);
	printf ("The player has $%.2lf in their hands\n\n", balance);
	printf ("		The wager on the table is: $%.2lf\n", wager);
	if (point == 0)
	{
		printf ("There is no point to make, player wants a 7 or an 11\n");
	}
	if (point != 0)
	{
		printf ("The point is %d, the player wants another %d\n", point, point);
		printf ("The player does not want a 7.\n");
	}
	srand ((unsigned int) time(NULL)); // seed the random number generator with the time
	die1 = roll_die ();
	die2 = roll_die ();
	dice_sum = die1 + die2;
	number_of_rolls ++;

	printf ("Roll Result: \n");
	printf ("%d : %d\n", die1, die2); // display the value of each die
	printf ("\n%d!\n", dice_sum); // display the sum of the dice
	printf ("\nPlayer rolled a = %d\n", dice_sum); // exclaim, casino style, the sum

	// evaluate the roll
	evaluation = evaluate_roll (point, dice_sum);

	if (evaluation == 'W')
	{
		balance = you_win (wager, balance);
		point = 0;
		chatter_messages (number_of_rolls, evaluation, initial_balance, 
			balance, dice_sum, point);
		wager = 0.0;
	}

	if (evaluation == 'w')
	{
		chatter_messages (number_of_rolls, evaluation, initial_balance, 
			balance, dice_sum, point);
		balance = you_win (wager, balance);
		point = 0;
		wager = 0.0;
	}

	if (evaluation == 'L')
	{
		you_lose (wager, balance);
		point = 0;
		chatter_messages (number_of_rolls, evaluation, initial_balance, 
			balance, dice_sum, point);
		wager = 0.0;
	}

	if (evaluation == 'l')
	{
		you_lose (wager, balance);
		point = 0;
		chatter_messages (number_of_rolls, evaluation, initial_balance, 
			balance, dice_sum, point);
		wager = 0.0;
	}

	if (evaluation == 's')
	{
		point = dice_sum;
		chatter_messages (number_of_rolls, evaluation, initial_balance, 
			balance, dice_sum, point);
	}

	if (evaluation == 'p')
	{
		chatter_messages (number_of_rolls, evaluation, initial_balance, 
			balance, dice_sum, point);
	}

	printf ("Player has $%.2lf in their hands\n", balance);
	printf ("The wager on the table is $%.2lf\n", wager);

	printf ("Press 1 to continue\n?");
	scanf ("%d", &choice);
	} while ((choice == 1) && (evaluation != 'w') && (evaluation != 'l'));
	}
	return balance;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 4
* Date: October 8, 2014
* Description: This function performs the following:
* Prompts the user to enter a wager amount and returns that value
* Preconditions: balance must be greater than 0
* Postconditions: returns the value of the wager
*/
double get_wager_amount (double balance)
{
	char status = '\0';
	double wager = 0.0;
	do
	{
		printf ("Player has $%.2lf to play\n", balance);
		printf ("Place a bet\n?");
		scanf ("%lf", &wager);
		if (wager == 0.0)
		{
			printf ("You must enter a wager if you wish to play\n");
		}
		else
		{
		status = check_wager_amount (wager, balance);
		if (status == 'v')
		{
			printf ("\nPlayer has bet %lf\n", wager);
		}
		else
		{
			wager = 0.0;
			printf ("I am sorry, you do not have enough money to cover that bet\n");
			printf ("Please choose another wager that is less than or equal to $%.2lf\n", 
			balance);
		}
		}
	} while (wager == 0.0);

	return wager;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 4
* Date: October 8, 2014
* Description: This function performs the following:
* Evaluates the wager, determines if there is enough money in the balance
* to cover the wager, if yes, adjusts balance, if no, displays a message 
* and returns to the place wager option
* Preconditions: balance must exist, wager must exist
* Postconditions: returns the adjusted bank balance if the wager is valid
* returns the existing bank balance if the wager is invalid and returns to 
* the place a wager option
*/
char check_wager_amount (double wager, double balance)
{
	char status = '\0';

	if (wager <= balance)
	{
		status = 'v';
	}
	else
	{
		status = 'i';
	}

	return status;
}

int roll_die ()
{
	int die = 0;

	// srand ((unsigned int) time(NULL));
	die = (rand () % 6) + 1;

	return die;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 4
* Date: October 8, 2014
* Description: This function performs the following:
* Evaluates the dice roll
* if the point is 0 and the dice_sum = 7 or 11, return a 'w' for win
* if the point is 0 and the dice_sum = 2, 3, or 12, return a 'l' for lose
* if the point is not zero and the dice_sum != point, return a 'p' for play on
* if the point is not zero and the dice_sum = point, return a 'w' for win
* if the point is not zero and the dice_sum = 7, return a 'l' for lose
* if the point is 0 and the dice_sum = 4, 5, 6, 8, 9, 10, or 11,
* return 's' for set point (since all other conditions should be evaluated by the 
* previous conditions, this is set as else rather than a lengthy evaluation)
* Preconditions: point value must exist, dice_sum must exist
* Postconditions: returns a win, lose or play on indicator
*/
char evaluate_roll (int point, int dice_sum)
{
	if ((point == 0) && ((dice_sum == 7) || (dice_sum == 11)))
	{
		return 'W';
	}
	if ((point == 0) && ((dice_sum == 2) || (dice_sum == 3) || (dice_sum == 12)))
	{
		return 'L';
	}
	if ((point != 0) && (dice_sum == 7))
	{
		return 'l';
	}
	if ((point != 0) && (dice_sum != point))
	{
		return 'p';
	}
	if ((point != 0) && (dice_sum == point))
	{
		return 'w';
	}
	else
	{
		return 's';
	}
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 4
* Date: October 8, 2014
* Description: This function performs the following:
* adjusts the balance by adding the wager amount
* Preconditions: balance and wager must exist
* Postconditions: returns the new balance
*/
double you_win (double wager, double balance)
{
	printf ("You have won $%.2lf!\n", wager);
	balance = balance + wager + wager;
	printf ("You now have $%.2lf\n",balance);

	return balance;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 4
* Date: October 8, 2014
* Description: This function performs the following:
* prints a message to the screen
* Preconditions: evaluate_roll returns a 'l'
* Postconditions: none
*/
double you_lose (double wager, double balance)
{
	printf ("you lose $%.2lf\n", wager);
	printf ("you still have $%.2lf\n",balance);

	return balance;
}

/*
* Programmer: Marcus Blaisdell
* Class: CptS 121, Fall 2014; Lab Section 9
* Programming Assignment: Programming Assignment 4
* Date: October 8, 2014
* Description: This function performs the following:
* prints a message to the screen appropriate to the current game condition
* Preconditions: number of rolls must exist, win, loss or point must be set,
* beginning bank balance must be set, current balance must be known
* Postconditions: none
*/
void chatter_messages (int number_rolls, char evaluation, 
					   double initial_bank_balance, double balance, 
					   int dice_sum, int point)
{
	if (evaluation == 'W')
	{
		printf ("Winner!\n\n");
		printf ("Fresh roll, no point, player rolled a %d, Winner!\n",dice_sum);
	}

	if (evaluation == 'w')
	{
		printf ("Winner!\n\n");
		printf ("			Player made point!\n");
		printf ("%d came up before you could roll a 7!\n", dice_sum);
	}

	if (evaluation == 'L')
	{
		printf ("Craps!\n\n");
		printf ("Fresh roll, no point, player rolled a %d, sorry, you lose this one\n", 
			dice_sum);
	}

	if (evaluation == 'l')
	{
		printf ("Craps! %d!\n\n", dice_sum);
		printf ("Player rolled a %d before they made their point.\n", 
			dice_sum);
		printf ("Sorry my friend, you lose this round.\n");
		if (balance > 0.0)
		{
			printf ("You still have $%.2lf, you're still in the game\n", balance);
		}
	}

	if (evaluation == 's')
	{
		printf ("		The point is %d, the player wants another %d\n", point, point);
	}

	if (evaluation == 'p')
	{
		printf ("\nPlay on\n");
	}

}