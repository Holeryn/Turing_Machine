#include "tape.h"

static int GetIndex(TM INSTRUCTIONS[],int state,char r){
  for(int i = 0; i <= INSTRUCTIONS[0].NUMBER_OF_ISTRUCTION; i++){
    if(INSTRUCTIONS[i].STATE1 == state && INSTRUCTIONS[i].R == r) return i;
  }

  return -1;
}

void EXECUTE(TM INSTRUCTIONS[],char input[]){
  int state = 1; // We begin from state S1
  int I;
  int i = 0;

  do{
    I = GetIndex(INSTRUCTIONS, state,input[i]);

    #if DEBUG
    printf("%d %c\n",I,input[i]);
    #endif

    if(I == -1){
      FATAL_ERROR("NOT VALID TAPE FOR GIVEN PROGRAM");
    }

    if(INSTRUCTIONS[I].STATE2 == 0)
      break;

    state = INSTRUCTIONS[I].STATE2;
    input[i] = INSTRUCTIONS[I].W;
    switch(INSTRUCTIONS[I].ACTION){
    case 'L': i--; break;
    case 'R': i++;break;
    }

  }while(INSTRUCTIONS[I].STATE2 != 0);

}
