#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  
  List* history = (List*)malloc(sizeof(List));

  history->root=NULL;
  history->size=0;
  return history;
} 

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  //allocate space for the new item
  Item *new_Item =(Item*) malloc(sizeof(Item));
  //new_Item->str = str;
  new_Item->next=NULL;

  Item *curr =list->root;
  
  if (curr==NULL){
    new_Item->id=0;
    list->root = new_Item;
    list->size +1;
  }
  else{
    while(curr->next != NULL){
      curr=curr->next;
    }
    curr->next=new_Item;
    list->size+1;
    new_Item->id=curr ->id+1;    
  }
  
  //now we have to allocate space for the new node
  //so we have to get its length
  int str_length=0;
  
  while(*str != '\0'){
    str_length++;
    //make the pointer move to the next character
    str++;
  }

  //reset the str pointer
  str -=length;

  new_Item->str=str;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *curr=list->root;

  if(curr==NULL){
    return "You have no history stored";
  }

  while(curr != NULL){
    if(curr->id==id){
      return curr->str;
    }
    curr=curr->next;
  }
  return "Something went wrong";
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item *curr = list->root;

  if(cur==NULL){
    printf("You have no history to be printed\n");
    break;
  }

  printf("This is your history so far:\n");
  while(curr != NULL){
    printf("%s\n", curr->str);
    curr= curr->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *curr = list->root;

  while(list->root != NULL){
    list->root = list->root->next;
    free(curr->str);
    free(curr);
    curr = list->root;
  }
  free(list);
}

#endif
