#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	check_place(int row, int column, int *board, int log)
{
	int	i = 0;

	if (log)
		printf("check_place update for row: %i, col: %i\n", row, column);
	while (i < row)
	{
		if (board[i] == column)
		{
			if (log)
			{
				printf("+ conflict detected at:\n");
				printf("curr(%i, %i) | board(%i, %i)\n\n", row, column, i, board[i]);			
			}
			return (0);
		}
		if (abs(i - row) == abs(board[i] - column))
		{
			if (log)
			{
				printf("X conflict detected at:\n");
				printf("curr(%i, %i) | board(%i, %i)\n\n", row, column, i, board[i]);			
			}
			return (0);
		}
		i++;
	}
	// printf("found a placeable spot.\n");
	return (1);
}

void	print_board(int *board, int total)
{
	int i;

	i = 0;
	while (i < total)
	{
		printf("%i ", board[i]);
		i++;
	}
	printf("\n");
}

void	backtrack_queens(int row, int total, int *board, int log)
{
	int column = 0;
	while (column < total)
	{
		if (check_place(row, column, board, log))
		{
			board[row] = column;
			if (log)
				printf("column: %i\n", column);
			if (row == total - 1)
			{
				if (log)
					printf("found one.\n");
				print_board(board, total);
				return ;
			}
			if (log)
			{
				printf("----------------------------------\n");
				printf("going to row %i\n", row+1);
			}
			backtrack_queens(row + 1, total, board, log);
			if (log)
			{
				printf("----------------------------------\n");
				printf("going back to row %i.\n", row);
			}
		}
		column++;
	}
}

void	n_queens(int n)
{
	int	row = 0;
	int	board[128];
	backtrack_queens(row, n, board, 0);
}


int main(void)
{
	int n;
	printf("N Queens: ");
	scanf("%d", &n);
	printf("\n");
	n_queens(n);
}