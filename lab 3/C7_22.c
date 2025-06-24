#include <stdio.h>

void main() {
    int numRows, binomial = 1;
    int row, col, spaces;

    printf("Enter the number of rows: ");
    scanf("%d", &numRows);

    for(row = 0; row < numRows; row++)
    {
        // Print leading spaces
        for(spaces = 1; spaces <= numRows - row; spaces++)
        {
            printf("  ");
        }

        for(col = 0; col <= row; col++)
        {
            // Calculate binomial coefficient
            if (col == 0 || row == 0)
                binomial = 1;
            else
                binomial = binomial * (row - col + 1) / col;

            printf("%4d", binomial);
        }
        printf("\n");
    }

}
