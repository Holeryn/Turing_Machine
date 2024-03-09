#include "PROGRAM.h"

#include <string.h>

// global program counter
// (see comments in main.c)
int pc = 0;

static char *read_next_word(char PROGRAM[PROGRAM_SIZE]){
  char *word;
  word = malloc(sizeof(char));

  int i;
  for(i = 0;PROGRAM[pc] != ' ' && PROGRAM[pc] != '\0' && PROGRAM[pc] != '\n'; i++){
    word[i] = PROGRAM[pc];
    realloc(word,sizeof(char)*(i + 2));
    pc++;
  }

  realloc(word,sizeof(char)*(i + 3));
  word[i + 1] = '\0';

  // jump blank space
  pc++;

  return word;
}

void BuildProgram(char PROGRAM[PROGRAM_SIZE], int P_size, TM ISTRUCTIONS[]){
  char *word;
  int op = 1; // operation counter
  word = malloc(sizeof(char)*WORD_SIZE);

  int I = 0; // Iterator in ISTRUCTIONS


  while(pc <= P_size){
    word = read_next_word(PROGRAM);

    // Eaxh operation is divided in 5 words
    // SX A SY B L/R
    switch(op){
    case 1: // State1
 {
   	  char state1[WORD_SIZE-1];
      int S1; // State 1 converted
      int i;

      for(i = 1; word[i] != '\0'; i++){
       state1[i-1] = word[i];
      }

      state1[i-1] = '\0';
      S1 = atoi(state1);

      ISTRUCTIONS[I].STATE1 = S1;

      op = 2;
      break;
 }
    case 2: // Readed value on head
 {
      char R;
      R = word[0];

      ISTRUCTIONS[I].R = R;
      op = 3;
      break;
 }
    case 3: // Transition state
{
	  char state2[WORD_SIZE-1];
  	  int S2; // State 1 converted
  	  int i;

      if(word[0] == 'H'){
        ISTRUCTIONS[I].STATE2 = 0; // H = 0
      }else{

      	for(i = 1; word[i] != '\0'; i++){
	      state2[i-1] = word[i];
      	}

        state2[i-1] = '\0';

        S2 = atoi(state2);

        ISTRUCTIONS[I].STATE2 = S2;
      }

      op = 4;
      break;
}
    case 4: // Value to write
{
      char W;
      W = word[0];

      ISTRUCTIONS[I].W = W;

      op = 5;
      break;
 }
    case 5: // action, L->0 left R->1 Right 0 halt
 {
      char A;
      A = word[0];

      ISTRUCTIONS[I].ACTION = A;

      op = 1;
      I++;
      break;
 }
    }

    # if DEBUG
    printf("%s",word);
    #endif
  }

  ISTRUCTIONS[0].NUMBER_OF_ISTRUCTION = I - 1;
}
