#include<stdio.h>

int a[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int count = 0;

int is_available(int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		if (column == a[i]) return 0;
		if (a[i] - column == i - row) return 0;
		if (column - a[i] == i - row) return 0;
	}
	return 1;
}

void find_place(int queen_number)
{
	if (queen_number == 8)
	{
		for (int i = 0; i < 8; i++)
			printf("%d ", a[i]);
		putchar('\n');
		count++;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (is_available(queen_number, i))
			{
				a[queen_number] = i;
				find_place(queen_number + 1);
			}
		}
	}
}

int main() {
	find_place(0);
	printf("%d ", count);
	return 0;
}