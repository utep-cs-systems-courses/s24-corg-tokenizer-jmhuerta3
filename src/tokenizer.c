#define _TOKENIZER_
#include <stdlib.h>
#include <stdio.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c==' '||c=='\t'){
    return 1;
  }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if(!space_char(c) && c!='\0'){
    return 1;
  }
  return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  while(space_char(*str) && *str != '\0'){
    str++;
  }
  if (*str == '\0'){
    return NULL;
  }
  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int count =0;

  //token pointer to point at the first token
  char *token = token_start(str);
  
  while(token != NULL){
    counter +=1;

    //goes to the end token and then points at the next token
    token = token_terminator(token);
    token = token_start(token);
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  //allocating space for the new string that will be
  //+1 the lenght of teh original str
  char *newStr = (char *)malloc((len+1)*sizeof(char *));
  int i=0;

  //return if the str is NULL
  if(newStr ==NULL){return newStr;}
  
  while(non_space(*inStr)){
    newStr[i]=inStr[i];
    i++;
  }

  //setting the end of our string to the zero termination/null
  newStr[i]='\0';

  return newStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  //see how many tokens we need to store
  int count = count_tokens(str);

  //allocate space for the resulting array
  char **tokens = (char **)malloc((count+1)*sizeof(char *));

  if(tokens==NULL){ return NULL;}
  
  //pointers for the start and end of the tokens
  char* start = token_start(str);
  char *end;
  
  for(int i =0;i<counter;i++){
    //check if the token is NULL and break out of the for loop
    if(start == NULL){ break;}

    //point to the end of the token
    end = token_terminator(start);

    tokens[i]= copy_str(start,(end-start));

    //restart the start pointer to look at the next token
    start = token_start(end);
    
  }
  tokens[i] = 0;
  return tokens;
  
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  //check if we have any tokens
  if (tokens == NULL){
    printf("We have no tokens\n");
    return;
  }
  int i =0;
  
  while(tokens[i] != NULL){
    printf("%s \n", tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens){
  if(tokens == NULL){
    return;}

  int i	=0;

  while(tokens[i] != NULL){
    //free each token
    free(tokens[i]);
    i++;
  }

  //free the array
  free(tokens);
}

