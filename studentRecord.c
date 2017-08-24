// Student record implementation ... Assignment 1 COMP9024 17s2
#include <stdio.h>

#define LINE_LENGTH 1024

// scan input for a positive integer, returns -1 if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return -1;
   else
      return n;
}

// scan input for a positive floating point number, returns -1 if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%f", &f) != 1) || f <= 0.0 )
      return -1;
   else
      return f;
}

/*** Your code for stage 1 starts here ***/

int readValidID(void) {
    int zID;
    printf("Enter student ID: ");
    zID = readInt();
    while (zID == -1 || zID < 1000000 || zID > 9999999){
        printf("Not valid. Enter a valid value: ");
        zID = readInt();
    }

   return zID;  /* needs to be replaced */
}

int readValidCredits(void) {
    int credits;
    printf("Enter credit points: ");
    credits = readInt();
    while (credits == -1 || credits < 2 || credits > 480){
        printf("Not valid. Enter a valid value: ");
        credits = readFloat();
    }
   return credits;  /* needs to be replaced */
}

float readValidWAM(void) {
    float WAM;
    printf("Enter WAM: ");
    WAM = readFloat();
    while (WAM == -1 || WAM < 50 || WAM > 100){
        printf("Not valid. Enter a valid value: ");
        WAM = readFloat();
    }
   return WAM;  /* needs to be replaced */
}

void printStudentData(int zID, int credits, float WAM) {
    printf("------------------------\n");
    printf("Student zID: z%d\n", zID);
    printf("Credit points: %d\n", credits);
    if (WAM >= 85 && WAM <= 100){
        printf("Level of performance: HD\n");
    }else if (WAM >= 75 && WAM < 85){
        printf("Level of performance: DN\n");
    }else if (WAM >= 65 && WAM < 75){
        printf("Level of performance: CR\n");
    }else{
        printf("Level of performance: PS\n");
    }
    printf("------------------------\n");

   return;  /* needs to be replaced */
}
