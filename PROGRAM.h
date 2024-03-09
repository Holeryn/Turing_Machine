#ifndef PROGRAM_M
#define PROGRAM_M

#include <stdio.h>
#include <stdlib.h>

#define FATAL_ERROR(m) perror(m); \
  exit(-1);
#define TAPE_SIZE 4096
#define PROGRAM_SIZE 4096
#define WORD_SIZE 5
#define MAX_NUMBER_OF_ISTRUCTION 4096

// 0 if is not in debugging
// 1 if is in debugging
#define DEBUG 0

struct TM_t {
  int STATE1; // SXXX = XXX state of the head
  char R; 		  // Readed value on the head
  int STATE2; // Transition state
  char W;		  // Value to write
  char ACTION;	  // 0 left 1 right
  int NUMBER_OF_ISTRUCTION;
};
typedef struct TM_t TM;

void BuildProgram(char PROGRAM[PROGRAM_SIZE], int P_size,TM ISTRUCTIONS[]);

#endif
