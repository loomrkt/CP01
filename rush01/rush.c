// creation d'un matrice
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int **ft_create_matrice(int row, int col)
{
	int i;
	int **matrice;


	matrice = (int **) malloc(sizeof(int *) * row);
	if (matrice == NULL)
	{
		printf("Échec de l'allocation\n");
		exit(0);
	}
	i = 0;
	while (i < col)
	{
		matrice[i] = malloc(sizeof(int) * col);
		i++;
	}
	return (matrice);
}

void    ft_init_tab(int **c, int row, int col)
{
	int i;
	int j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			c[i][j] = 0;
			j++;
		}
		i++;
	}
}

void    ft_print_tab(int **c, int row, int col)
{
	int i;
	int j;


	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf("%d",c[i][j]);
			j++;
		}
		printf("\n");
		i++;   
	}
}


void    ft_free_tab(int **c, int row)
{
	int i;


	i = 0;
	while (i < row)
	{
		free(c[i]);
		i++;   
	}
	free(c);
}


int ft_strlen(char *str)
{
	int i;


	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}


int ft_check_row_col(char input[])
{
	int i;


	i = 4;
	while (i <= 9)
	{
		if(ft_strlen(input) == (4 * i))
		{
			return (i);
		}
		i++;
	}
	return (0);
}


char    *ft_format_input(char *input)
{
	int i;


	i = 0;
	while (input[i] != '\0')
	{
		if(i == ((ft_strlen(input) / 2) + 1))
		{
			break;
		}
		input[i] = input[i*2];
		i++;
	}

	input[i] = '\0';
	return (input);
}


int ft_check_input(char input[])
{
	int i;


	i = 0;
	while (input[i] != '\0')
	{
		if((input[i] < '0') || (input[i] > '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}


int ft_char_To_int(char c)
{
	int n;


	n = c - '0';
	return(n);
}


int ft_check_input_value(char input[], int row)
{
	int i;


	i = 0;
	while (i < row)
	{
		if(((ft_char_To_int(input[((row*2) + i)])
			+ ft_char_To_int(input[((row*3) + i)]))
			> (row + 1)))
			return (0);
		i++;
	}
	i = 0;
	while (i < row)
	{
		if(((ft_char_To_int(input[((row*0) + i)])
			+ ft_char_To_int(input[((row*1) + i)]))
			> (row + 1)))
			return (0);
		i++;
	}
	return (1);
}


void    ft_possible_value_left(int **c, int row, int col, char input[])
{
	int i;
	int j;


	i = 0;
	while (i < row)
	{
		if (input[((row*2) + i)] == '1')
		{
			c[i][0] = row;
		}
		if (input[((row*2) + i)] == (row + 48))
			j = 0;
			while ( j < col)
			{
				c[i][j] = row - ((row - j) - 1);
				j++;
			}
		i++;   
	}
}


void    ft_possible_value_right(int **c, int row, int col, char input[])
{
	int i;
	int j;


	i = 0;
	while (i < row)
	{
		if (input[((row*3) + i)] == '1')
		{
			c[i][row - 1] = row;
		}
		if (input[((row*3) + i)] == (row + 48))
			j = 0;
			while ( j < col)
			{
				c[i][j] = row - j;
				j++;
			}
		i++;   
	}
}

void    ft_possible_value_top(int **c, int row, int col, char input[])
{
	int i;
	int j;

	i = 0;
	while (i < row)
	{
		if (input[((row*0) + i)] == '1')
		{
			c[0][i] = row;
		}
		if (input[((row*0) + i)] == (row + 48))
			j = 0;
			while ( j < col)
			{
				c[j][i] = row - ((row - j) - 1);
				j++;
			}
		i++;   
	}
}

void    ft_possible_value_bottom(int **c, int row, int col, char input[])
{
	int i;
	int j;

	i = 0;
	while (i < row)
	{
		if (input[((row*1) + i)] == '1')
		{
			c[row - 1][i] = row;
		}
		if (input[((row*1) + i)] == (row + 48))
			j = 0;
			while ( j < col)
			{
				c[j][i] = row - j;
				j++;
			}
		i++;   
	}
}

int    is_valid(int **c, int row, int col, int nbr)
{
	int i;

	i = 0;
	while (i < row)
	{
		if (c[i][nbr] == 0)
		{
			return (0);
		}
		i++;   
	}
	i = 0;
	while (i < col)
	{
		if (c[nbr][i] == 0)
		{
			return (0);
		}
		i++;   
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int row;
	int col;
	int **c;
	int	i;


	if (argc == 2)
	{
		ft_format_input(argv[1]);
		printf("apres formattage : %s \n",argv[1]);
		printf("ckeck : %d \n",ft_check_input(argv[1]));
		if(ft_check_input(argv[1]))
		{
			if (ft_check_row_col(argv[1]) != 0)
			{
				row = ft_check_row_col(argv[1]);
				col = row;
				printf("row : %d \n",row);
				printf("col : %d \n",col);
				if(ft_check_input_value(argv[1], row))
				{
					printf("check value : %d\n",ft_check_input_value(argv[1], row));
					c = ft_create_matrice(row, col);
					ft_init_tab(c, row, col);
					ft_print_tab(c, row, col);
					printf("\n");
					ft_possible_value_left(c, row, col, argv[1]);
					ft_print_tab(c, row, col);
					printf("\n");
					ft_possible_value_right(c, row, col, argv[1]);
					ft_print_tab(c, row, col);
					printf("\n");
					ft_possible_value_top(c, row, col, argv[1]);
					ft_print_tab(c, row, col);
					printf("\n");
					ft_possible_value_bottom(c, row, col, argv[1]);
					ft_print_tab(c, row, col);
					printf("\n");
					ft_free_tab(c, row);
				}
				else
				{
					printf("value d'entree incorrecte\n");
				}
			}
			else
			{
				printf("La taille de l'input n'est pas exacte");
			}
		}
		else
		{
			printf("L'input contient d'autre caractere a part les numeriques\n");
		}
	}
	else
	{
		printf("erreur d'argument\n");
	}

	return (0);
}
