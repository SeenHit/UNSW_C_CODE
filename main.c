/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Student record manager

     COMP9024 17s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "studentRecord.h"
#include "studentLL.h"

void printHelp();
void StudentLinkedListProcessing();

int main(int argc, char *argv[]) {
   if (argc == 2) {
     int m, n = atoi(argv[1]), CREDITS = 0;
     float WAM = 0, Sum_credits_wam = 0;
     studentRecordT *dynamic_array = malloc(n * sizeof(studentRecordT));
     for (m = 0; m < n; m++){
       dynamic_array[m].zID = readValidID();
       dynamic_array[m].credits = readValidCredits();
       CREDITS += dynamic_array[m].credits;
       dynamic_array[m].WAM = readValidWAM();
       WAM += dynamic_array[m].WAM;
       Sum_credits_wam += dynamic_array[m].credits * dynamic_array[m].WAM; //weighted average wam
     }
     for (m = 0; m < n; m++){
       printStudentData(dynamic_array[m].zID, dynamic_array[m].credits, dynamic_array[m].WAM);
     }
     printf("Average WAM: %.3f\n", WAM / n);
     printf("Weighted average WAM: %.3f\n", Sum_credits_wam / CREDITS);
      /*** Insert your code for stage 1 here ***/

   } else {
      StudentLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void StudentLinkedListProcessing() {
   int op, ch;
   int zID, credits, length;
   float WAM, Average_weighted_wam;

   List list = newLL();   // create a new linked list

   while (1) {
      printf("Enter command (a,f,g,p,q, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':

         zID = readValidID();
         credits = readValidCredits();
         WAM = readValidWAM();
         insertLL(list, zID, credits, WAM);
            /*** Insert your code for adding a student record ***/

	    break;

         case 'f':
         case 'F':
         zID = readValidID();
         inLL(list, zID);
            /*** Insert your code for finding a student record ***/

	    break;

         case 'g':
         case 'G':
         getStatLL(list, &length, &WAM, &Average_weighted_wam);
         printf("Number of records: %d\n", length);
         printf("Average WAM: %.3f\n", WAM);
         printf("Average weighted WAM: %.3f\n", Average_weighted_wam);
            /*** Insert your code for getting statistical information ***/

	    break;

         case 'h':
         case 'H':
            printHelp();
	    break;

         case 'p':
         case 'P':
         showLL(list);
            /*** Insert your code for printing all student records ***/

	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" A - Add student record\n" );
   printf(" F - Find student record\n" );
   printf(" G - Get statistics\n" );
   printf(" H - Help\n");
   printf(" P - Print all records\n" );
   printf(" Q - Quit\n");
   printf("\n");
}
