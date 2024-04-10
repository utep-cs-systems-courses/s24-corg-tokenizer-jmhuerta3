#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <stdlib.h>

int main(){
  puts("Welcome to your tokenizer:)");

  fputs("Enter the phrase you want to tokenize:\n>>", stdout);
  fflush(stdout);

  char str[100];//space for my string 
  fgets(str, sizeof(str), stdin);//read input
  char **tokens = tokenize(str);
  print_tokens(tokens);

  printf("%s \n", str);

  return 0;
}
