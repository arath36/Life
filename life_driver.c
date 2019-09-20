//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312


/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Austin Rath, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Austin Rath
 * email address: arath36@gmail.com
 * UTEID: ar63736
 * Section 5 digit ID: 16020
 *
 */

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "life.h"


int main(int argc, char *argv[]) {

   //edit these two lines and use the command line arguments

   char *fName = (char*) malloc(strlen(argv[1]) + 1);
   strcpy(fName, argv[1]);
   const int numGenerations  = atoi(argv[2]); //set to a smaller number for debugging

   const int MAX_ROWS = 80; //we want the world to fit on one screen

   //array of strings that will hold the grid
   char *world[MAX_ROWS];
   int numRows;
   int numCols;

   populateWorld(fName, world, &numRows, &numCols);

   showWorld(world, numRows, numCols);

   for (int iteration = 0; iteration < numGenerations; iteration++) {

     // code to clear screen goes here
     system("clear");

     iterateGeneration(world, numRows, numCols);

     showWorld(world, numRows, numCols);
  }

  free(fName);
  for (int i = 0; i < numRows; i++) {
    free(world[i]);
  }

  return 0;
}



