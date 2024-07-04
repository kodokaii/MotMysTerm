#include "../include/include.h"
/*
// Function to print the Wordle interface
void print_interface(char guesses[][5], char results[][5], int wordLength)
{

	// Print the top border
	printf("%s", TOP_LEFT);
	for (int j = 0; j < wordLength; j++)
	{
		printf("%s%s%s", HORIZONTAL, HORIZONTAL, HORIZONTAL);
		if (j < wordLength - 1)
			printf("%s", T_TOP);
	}
	printf("%s\n", TOP_RIGHT);

	// Print the Wordle grid
	for (int i = 0; i < ATTEMPT; i++)
	{
		// Print the row with guesses
		printf("%s", VERTICAL);
		for (int j = 0; j < wordLength; j++)
		{
			char result = results[i][j];
			char guess = guesses[i][j];

			if (result == 'G')
				printf(" %s%c%s ", RED, guess, RESET);  // Red for correct position
			else if (result == 'Y')
				printf(" %s%c%s ", YELLOW, guess, RESET); // Yellow for correct letter but wrong position
			else
			{
				if (guess == ' ')
					printf("%s _ %s", BLACK_ON_WHITE, RESET); // Empty box for no guess
				else
					printf(" %s%c%s ", WHITE, guess, RESET); // White for incorrect letter
			}
			printf("%s", VERTICAL);
		}
		printf("\n");

		// Print the border between rows
		if (i < ATTEMPT - 1)
		{
			printf("%s", T_LEFT);
			for (int j = 0; j < wordLength; j++)
			{
				printf("%s%s%s", HORIZONTAL, HORIZONTAL, HORIZONTAL);
				if (j < wordLength - 1)
					printf("%s", CROSS);
			}
			printf("%s\n", T_RIGHT);
		}
	}

	// Print the bottom border
	printf("%s", BOTTOM_LEFT);
	for (int j = 0; j < wordLength; j++)
	{
		printf("%s%s%s", HORIZONTAL, HORIZONTAL, HORIZONTAL);
		if (j < wordLength - 1)
			printf("%s", T_BOTTOM);
	}
	printf("%s\n", BOTTOM_RIGHT);
}*/

void	display_keyboard(t_key keyboard[], int numRows, int numCols[])
{
	int index = 0;

	for (int i = 0; i < numRows; i++) {
		int padding = (13 - numCols[i]) / 2; // Calcul du padding pour centrer la ligne
		for (int p = 0; p < padding; p++) {
			printf("  "); // Espace pour le padding
		}

		for (int j = 0; j < numCols[i]; j++) {
			printf("%s%c\033[0m ", keyboard[index].color, keyboard[index].letter);
			index++;
		}
		printf("\n");
	}
}

void	print_rules(void)
{
	printf("\033[2J\033[H");
    // Print the rules
	printf("Bienvenue à Sutom !\n");
	printf("Règles du jeu :\n");
	printf("1. Vous avez 6 tentatives pour deviner un mot de 5 à 7 lettres.\n");
	printf("2. Chaque mot doit être un mot valide.\n");
	printf("3. Après chaque tentative, la couleur des cases changera pour montrer à quel point votre tentative était proche du mot.\n");
	printf("   - %sRouge%s : La lettre est dans le mot et à la bonne place.\n", RED, RESET);
	printf("   - %sJaune%s : La lettre est dans le mot mais à la mauvaise place.\n", YELLOW, RESET);
	printf("   - %sBlanc%s : La lettre n'est pas dans le mot.\n\n", WHITE, RESET);
	printf("Exemple :\n");
	printf("Deviner : ");
	printf("%s S %s %s U %s %s T %s %s O %s %s M %s\n", RED, RESET, YELLOW, RESET, WHITE, RESET, WHITE, RESET, YELLOW, RESET);
	printf("Explication : S est correct et à la bonne place (Rouge). U est correct mais à la mauvaise place (Jaune).\n");
	printf("T n'est pas dans le mot (Blanc). O n'est pas dans le mot (Blanc). M est correct mais à la mauvaise place (Jaune).\n");
	printf("Bonne chance et amusez-vous bien !\n\n");
}
