#ifndef BLAISDELL_PA4_H
#define BLAISDELL_PA4_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main_menu (void);
int display_rules (void);
double bank (double balance);
double play_craps (double balance, double initial_balance, int number_of_rolls);
double get_wager_amount (double wager);
char check_wager_amount (double wager, double balance);
int roll_die ();
char evaluate_roll (int point, int dice_sum);
double you_win (double wager, double balance);
double you_lose (double wager, double balance);
void chatter_messages (int number_rolls, char evaluation,
					   double initial_bank_balance,
					   double current_bank_balance,
					   int dice_sum, int point);

#endif
