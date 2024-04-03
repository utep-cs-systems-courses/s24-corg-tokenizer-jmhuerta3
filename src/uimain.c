#include <stdio.h>
#include "tokenizer.h"

int main(){
  puts("Welcome to your tokenizer:)");

  fputs("Enter the phrase you want to tokenize:\n>>", stdout);
  fflush(stdout);

  char str[100];//space for my string 
  fgets(str, sizeof(str), stdin);//read input 

  printf("%s \n", str);

  return 0;
}
