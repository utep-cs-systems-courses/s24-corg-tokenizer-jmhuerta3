#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <stdlib.h>

int main(){
  puts("Welcome to your tokenizer:)");
  bool still =true;
  
  while(still){
    puts("What do you want to do?");
    puts("1. Tokenize!");
    puts("2. See history");
    puts("3. Exit program");

    fputs("Please enter one of the options (1-3): >>" stdout);
    fflush(stdout);

    char opt[3];//space for my option string
    fgets(opt, sizeof(opt), stdin);//read input and store in the right variable

    switch(opt){
    case "1":
      fputs("Enter the phrase you want to tokenize:\n>>", stdout);
      fflush(stdout);

      char str[100];//space for my string
      fgets(str, sizeof(str), stdin);//read input

      char **tokens =tokenize(str);
      puts("These is your tokenized phrase: ");
      print_tokens(tokens);
      break;

    case "2":
      puts("1. Full history");
      puts("2. 
    }

    
  }
  puts("What do you want to do?");
  puts("1. Tokenize!");
  puts("2. See history");
  puts("3. Exit program");

  fputs("Please enter one of the options (1-3): >>" stdout);
  fflush(stdout);
  fputs("Enter the phrase you want to tokenize:\n>>", stdout);
  fflush(stdout);

  char str[100];//space for my string 
  fgets(str, sizeof(str), stdin);//read input
  printf("%s \n", str);
  char **tokens = tokenize(str);
  print_tokens(tokens);
  List* history = init_history();
  add_history(history, str);
  char *get0 = get_history(history, 0);
  printf("%s \n", get0);
  print_history(history);
  
  return 0;
}
