#include "../include/include.h"
#include <string.h>

void	set_keyboard_color(t_key *keyboard, char letter, char *color)
{
	for (int i = 0; i < 26; i++)
	{
		if (keyboard[i].letter == letter)
		{
			if (!strcmp(keyboard[i].color, RED))
				;
			else if (!strcmp(keyboard[i].color, BLACK))
				;
			else if (!strcmp(keyboard[i].color, YELLOW) && strcmp(color, RED))
				;
			else
				keyboard[i].color = color;
		}
	}
}

void	print_grid(t_data *data)
{
	// Print the top border
	printf("%s", TOP_LEFT);
	for (int j = 0; j < data->word.nb_letter; j++)
	{
		printf("%s%s%s", HORIZONTAL, HORIZONTAL, HORIZONTAL);
		if (j < data->word.nb_letter - 1)
			printf("%s", T_TOP);
	}
	printf("%s\n", TOP_RIGHT);

	// Print the Wordle grid
	for (int i = 0; i < ATTEMPT; i++)
	{
		printf("%s", VERTICAL);
		int k = 0;

		// Print the row with guesses
		if (!data->win && i == data->attempts)
		{	
			printf(" %s%c%s ", WHITE, data->word.first_letter, RESET);
			printf("%s", VERTICAL);
			k = 1;
		}
		for (int j = k; j < data->word.nb_letter; j++)
		{
			if (data->guesses[i] && data->guesses[i][j])
			{
				if (data->guesses[i][j] == data->word.word[j])
				{
					printf(" %s%c%s ", RED, data->guesses[i][j], RESET);
					set_keyboard_color(data->keyboard, data->guesses[i][j], RED); 
					data->word.alpha[data->guesses[i][j] - 65]--;
				}
				else if (data->word.alpha[data->guesses[i][j] - 65] > 0)
				{
					//strchr(data->guesses[i] + j, data->guesses[i][j]);
					printf(" %s%c%s ", YELLOW, data->guesses[i][j], RESET);
					set_keyboard_color(data->keyboard, data->guesses[i][j], YELLOW); 
					data->word.alpha[data->guesses[i][j] - 65]--;
				}
				else
				{
					printf(" %s%c%s ", WHITE, data->guesses[i][j], RESET);
					set_keyboard_color(data->keyboard, data->guesses[i][j], BLACK); 
				}
			}
			else
				printf("%s _ %s", BLACK_ON_WHITE, RESET); // Empty box for no guess
			printf("%s", VERTICAL);
		}
		printf("\n");

		// Print the border between rows
		if (i < ATTEMPT - 1)
		{
			printf("%s", T_LEFT);
			for (int j = 0; j < data->word.nb_letter; j++)
			{
				printf("%s%s%s", HORIZONTAL, HORIZONTAL, HORIZONTAL);
				if (j < data->word.nb_letter - 1)
					printf("%s", CROSS);
			}
			printf("%s\n", T_RIGHT);
		}
		refill_alpha(data);
	}

	// Print the bottom border
	printf("%s", BOTTOM_LEFT);
	for (int j = 0; j < data->word.nb_letter; j++)
	{
		printf("%s%s%s", HORIZONTAL, HORIZONTAL, HORIZONTAL);
		if (j < data->word.nb_letter - 1)
			printf("%s", T_BOTTOM);
	}
	printf("%s\n", BOTTOM_RIGHT);
}

void	print_keyboard(t_data *data, t_key *keyboard)
{
	int numRows = 3;
	int numCols[] = {10, 10, 6}; // Nombre de colonnes pour chaque rangée

	int index = 0;

	printf("\n");
	for (int i = 0; i < numRows; i++)
	{
		int padding = (2 * data->word.nb_letter - numCols[i]) / 2; // Calcul du padding pour centrer la ligne
		for (int p = 0; p < padding; p++)
			printf("  "); // Espace pour le padding
		for (int j = 0; j < numCols[i]; j++)
		{
			printf("%s%c%s ", keyboard[index].color, keyboard[index].letter, RESET);
			index++;
		}
		printf("\n");
	}
	printf("\n");
}

void	print_rules(void)
{
	printf("\e[H\e[2J\e[3J");
    // Print the rules
	printf("Bienvenue dans Sutom !\n");
	printf("Règles du jeu :\n");
	printf("1. Vous avez 6 tentatives pour deviner un mot de 6 à 9 lettres.\n");
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
