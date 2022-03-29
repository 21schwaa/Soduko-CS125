#include <stdio.h>
#include <stdlib.h>

int main() {
  int validScore;
  int score=0;
  int round=0;
  FILE *f;
  f=fopen("scoreSheet.txt", "w");
  if (validScore) {
    score=score+1;
    fprintf(f, "Game %d score: %d", round, score);
    fclose(f);
  }
  
  return 0;
}
