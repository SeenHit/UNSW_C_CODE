#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "studentLL.h"
#include "studentRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    studentRecordT data;
    struct node    *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;
   int length;
   int credits_sum;
   float wam_sum;
   float weighted_wam;

/* Add more fields if you wish */
} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity:
// Explanation:
List newLL() {
  List list = malloc(sizeof(ListRep)); // create a pointer for list
  list -> head = NULL;
  list -> length = 0;
  list -> credits_sum = 0;
  list -> wam_sum = 0;
  list -> weighted_wam = 0;

   return list;  /* needs to be replaced */
}

// Time complexity:
// Explanation:
void dropLL(List listp) {
  NodeT *current_position = listp -> head;
  while (current_position != NULL){
    NodeT *temp = current_position -> next;
    free(current_position);
    current_position = temp;
  }
   free(listp);  /* needs to be replaced */
}

// Time complexity:
// Explanation:
void inLL(List listp, int zid) {
  NodeT *current_position = listp -> head;
  int i;
  for (i = 0; i < listp -> length; i++){
    if (current_position -> data.zID == zid){
      printStudentData(current_position -> data.zID, current_position -> data.credits, current_position -> data.WAM);
      return;
    }
    NodeT *temp = current_position -> next;
    current_position = temp; //can i combine these two into one?
  }
  printf("No record found.\n");
   return;  /* needs to be replaced */
}

// Time complexity:
// Explanation:
void insertLL(List listp, int zid, int cr, float wam) {
  NodeT *new = malloc(sizeof(NodeT)); //create a pointer for node
  assert(new != NULL);
  NodeT *current_position = listp -> head;
  int i;
  new -> data.zID = zid;
  new -> data.credits = cr;
  new -> data.WAM = wam;


  if (listp -> head == NULL){
    new -> next = listp -> head;
    listp -> head = new;
    listp -> length++;
    listp -> credits_sum += cr;
    listp -> wam_sum += wam;
    printf("Student record added.\n");
    return;  /* needs to be replaced */
  } else if (zid < listp -> head -> data.zID){
    new -> next = listp -> head;
    listp -> head = new;
    listp -> length++;
    listp -> credits_sum += cr;
    listp -> wam_sum += wam;
    printf("Student record added.\n");
    return;
  } else if (listp -> head -> data.zID == zid){
    new -> next = listp -> head -> next;
    listp -> wam_sum = wam + listp -> wam_sum - listp -> head -> data.WAM;
    listp -> credits_sum = cr + listp -> credits_sum - listp -> head -> data.credits;
    free(listp -> head);
    listp -> head = new;
    printf("Student record updated.\n");
    return;
   }
   for (i = 0; i < listp -> length; i++){
     if(current_position->next==NULL){
         new->next = NULL;
         current_position->next = new;
	 listp -> wam_sum += wam;
       listp -> credits_sum += cr;
       listp -> length++;
	 printf("Student record added.xixixixixi\n");
         return ;
     }
     if (current_position -> next -> data.zID > zid){
       new -> next = current_position -> next;
       current_position -> next = new;
       listp -> wam_sum += wam;
       listp -> credits_sum += cr;
       listp -> length++;
       printf("Student record added.\n");
       return;
     }else if (current_position -> next -> data.zID == zid){
       new -> next = current_position -> next -> next;
       listp -> wam_sum = wam + listp -> wam_sum - current_position -> next -> data.WAM;
       listp -> credits_sum = cr + listp -> credits_sum - current_position -> next -> data.credits;
       free(current_position -> next);
       current_position -> next = new;
       printf("Student record updated.\n");
       return;
     }
      else {
       NodeT *temp = current_position -> next ->next;
       current_position = temp;
     }
   }
   new -> next = NULL;
   current_position -> next = new;
   listp -> wam_sum += wam;
   listp -> credits_sum += cr;
   listp -> length++;
   printf("Student record added.\n");
   return;
}


// Time complexity:
// Explanation:
void getStatLL(List listp, int *n, float *wam, float *w_wam) {
  float Sum_credits_wam = 0;
  int i;
  NodeT *current_position = listp -> head;
  for (i = 0; i < listp -> length; i++){
    Sum_credits_wam += current_position -> data.WAM * current_position -> data.credits;
    NodeT *temp = current_position -> next;
    current_position = temp;
  }
  listp -> weighted_wam = Sum_credits_wam / listp -> credits_sum;
  *n = listp -> length;
  *wam = listp -> wam_sum / listp -> length;
  *w_wam = listp -> weighted_wam;
   return;  /* needs to be replaced */
}

// Time complexity:
// Explanation:
void showLL(List listp) {
  NodeT *current_position = listp -> head;
  int i;
  for (i = 0; i < listp -> length; i++){
    printf("------------------------\n");
    printf("Student zID: z%d\n", current_position -> data.zID);
    printf("Credits: %d\n", current_position -> data.credits);
    if (current_position -> data.WAM >= 85 && current_position -> data.WAM <= 100){
      printf("Level of performance: HD\n");
    }else if (current_position -> data.WAM >= 75 && current_position -> data.WAM < 85){
      printf("Level of performance: DN\n");
    }else if (current_position -> data.WAM >= 65 && current_position -> data.WAM < 75){
      printf("Level of performance: CR\n");
    }else{
      printf("Level of performance: PS\n");
    }
    printf("------------------------\n");
    NodeT *temp = current_position -> next;
    current_position = temp;
  }

   return;  /* needs to be replaced */
}
