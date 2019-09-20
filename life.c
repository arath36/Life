#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clears the buffer, passes in the parameter by address

// extra functions I added
int numberOfNeighbors (char *grid[], int row, int col, int numRows, int numCols);
void clearBuffer(char *bufferArr, int size);

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {
    FILE *fptr;


    fptr = fopen(fname, "r");


    

    // grid is an array pointers to character arrays.

    if (fptr == NULL) {
        printf("NO File");
        exit(-42);
    } else {
        int rowCount = 0;
        int colCount = 0;
        char buf[BUFSIZ];

        clearBuffer(buf, BUFSIZ);



        while (fgets(buf, sizeof(buf), fptr)) {
            int length = strlen(buf) + 1;
            //printf("%d", length);
            char *newlineptr = (char *) malloc(length);
            colCount = length;
            newlineptr = strcpy(newlineptr, buf);
           // printf("%s", newlineptr);
            grid[rowCount] = newlineptr;
            rowCount++;
            clearBuffer(buf, BUFSIZ);

        }
          *numRows = rowCount;
          *numCols = colCount;
            
        }
        fclose(fptr);
        int returnCheck = numberOfNeighbors(grid,5,11,7,14);


    




        
    }

void showWorld(char *grid[], int numRows, int numCols) {
    for (int i = 0; i<numRows; i++) {
        char* rowPtr = grid[i];
        for (int j = 0; j < numCols; j++) {
            //printf("%c", *(rowPtr + j));
            if (*(rowPtr + j) == '0') {
                printf(".");
            }

            if (*(rowPtr + j) == '1') {
                printf("*");
            }


        }
        printf("\n");

    }
    printf("\n\n");

}


void iterateGeneration(char *grid[], int numRows, int numCols) {
    char gridCopy[numRows][numCols];

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            gridCopy[i][j] = grid[i][j];
        }
    }

     for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            char currentValue = grid[i][j];
            int neighbors = numberOfNeighbors(grid, i, j, numRows, numCols);
            if (currentValue == '0') {
                if (neighbors == 3) {
                    gridCopy[i][j] = '1';
                }
            } else {
                if (neighbors <= 1) {
                    gridCopy[i][j] = '0';
                } else if (neighbors >= 4) {
                    gridCopy[i][j] = '0';
                }
            }
        }
    }


    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            grid[i][j] = gridCopy[i][j];
        }
    }


}




// extra functions


// returns the number of Neighbors from the grid
int numberOfNeighbors (char *grid[], int row, int col, int numRows, int numCols) {
    int totalNeighbors = 0;
    for (int i = -1; i <= 1 ; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                // do nothing since its that specific character
            } else {
               int neighborRow = row + i;
               int neighborCol = col + j;
               if (neighborRow >= 0 && neighborRow < numRows && neighborCol >= 0 && neighborCol < numCols) {
                   // checks to see if the identified rows are valid i.e will not go through if neighbor row = -1 
                    char neighbor = grid[neighborRow][neighborCol];
               
                    if (neighbor == '1') {
                        totalNeighbors++;
                    }
               }

               
               
            }
        }
    }



    return totalNeighbors;
}

void clearBuffer(char *bufferArr, int size) {
    for (int i = 0; i < size; i++) {
        *(bufferArr+i) = 0;
    }
}





