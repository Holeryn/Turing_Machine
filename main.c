#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "PROGRAM.h"
#include "tape.h"

/* .    . */
/* |\   |\ */
/* _..;|;__;|; */
/* ,'   ';` \';`-. */
/* 7;-..     :   ) */
/* .--._)|   `;==,|,==' */
/*  `\`@; \_ `<`G," G). */
/*    `\/-;,(  )  .>. ) */
/*        < ,-;'-.__.;' */
/*         `\_ `-,__,' */
/*            `-..,;,> */
/*               `;;;; */
/*                `  ` */

/*  (\-"````"-/) */
/*  //^\    /^\\ */
/*  ;/ ~_\  /_~ \; */
/*  |  / \\// \  | */
/*  (, \0/  \0/  ,) */
/*  |   /    \   | */
/*  | (_\.__./_) | */
/*  \  \v-..-v/ / */
/*   \ `====' / */
/*    `\\\///' */
/*     '\\//' */
/*       \/ */


// HOW To write a PROPER TM CODE FOR THIS INTERPRETER
// - NO SPACE AT THE BEGINNING OF THE CODE (SEE read_next_word in tm.c)
// - JUST ONE SPACE TO SEPARATE WORD (SEE read_next_word in tm.c)
// - The maximum size of the words MUST be WORD_SIZE (see tm.h)

//#################################################
//# THIS IS AN ACCADEMIC EXERCISE I WILL NOT CARE #
//# OF A LOT OF GOOD CODING PRACTISE TO MINIZE MY #
//# TIME DOING THINKS I DON'T REALLY CARE.        #
//#################################################

int main(int argc, char **argv){
  int fd1,fd2;
  char *PROGRAM;
  char *TAPE;

  TM ISTRUCTIONS[MAX_NUMBER_OF_ISTRUCTION];

  int T_size = 0, P_size = 0; // Tipe and program length

  PROGRAM = calloc(PROGRAM_SIZE,sizeof(char));
  TAPE = calloc(TAPE_SIZE,sizeof(char));

  fd1 = open(argv[1], O_RDONLY);
  fd2 = open(argv[2], O_RDONLY);

  if(fd1 == -1){
    FATAL_ERROR("open() argv[0] failed");
  }

  if(fd2 == -1){
    FATAL_ERROR("open() argv[1] failed");
  }

  if(read(fd1,PROGRAM,PROGRAM_SIZE) == -1){
    FATAL_ERROR("read() PROGRAM failed");
  }

  if(read(fd2,TAPE,TAPE_SIZE) == -1){
    FATAL_ERROR("read() TAPE failed");
  }

  for(int i = 0; TAPE[i] != '\0'; i++){
    T_size++;
  }

  for(int i = 0; PROGRAM[i] != '\0';i++){
    P_size++;
  }

  // T_size = TAPE SIZE + 1('\0')
  // P_SIZE = PROGRAM SIZE + 1('\0')

  #if DEBUG
  printf("%d %d\n",P_size,T_size);
  #endif

  BuildProgram(PROGRAM,P_size,ISTRUCTIONS);

  #if DEBUG
  for(int i = 0; i <= ISTRUCTIONS[0].NUMBER_OF_ISTRUCTION; i++){
    printf("\n%d %c %d %c %c\n",
           ISTRUCTIONS[i].STATE1,
           ISTRUCTIONS[i].R,
           ISTRUCTIONS[i].STATE2,
           ISTRUCTIONS[i].W,
           ISTRUCTIONS[i].ACTION);
  }
  #endif

  EXECUTE(ISTRUCTIONS,TAPE);

  for(int i = 0; i <= TAPE_SIZE; i++){
    printf("%c",TAPE[i]);
  }

  printf("\n");

  return 0;
}
