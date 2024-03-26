#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
  int *size;
} List;

/* Initialize the linked list to keep the history. */
List* init_history(){
  
  List* history = (List*)malloc(sizeof(List));

  history->root=NULL;
  history->size=0;
  return history;
} ;

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  s_Item*  new_Item = malloc(sizeof(s_Item));
  
  new_Item->str = str;
  new_Item->next=NULL;

  s_Item* curr = malloc(sizeof(s_Item));
  curr = *list->root;
  
  
  if (list->root=NULL){
    new_Item->id=0;
    list->root = new_Item;
    list->size =1;
  }
  else{
    for (i=0;i<list->size;i++){
      if(list->id
    }
  }
};

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id);

/*Print the entire contents of the list. */
void print_history(List *list);

/*Free the history list and the strings it references. */
void free_history(List *list);

#endif
