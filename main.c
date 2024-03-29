#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"
#include "functions.c"

int main(){
  printf("Printing random list:\n");
  struct node *list = (struct node*)malloc(sizeof(struct node));
  list = create_list();
  print_list(list);
  printf("Inserting 5 in front:\n");
  list = insert_front(list, 5);
  print_list(list);
  printf("Removing 3:\n");
  list = remove_node(list, 3);
  print_list(list);
  printf("Removing 4:\n");
  list = remove_node(list, 4);
  print_list(list);
  printf("Removing 7:\n");
  list = remove_node(list, 7);
  print_list(list);
  printf("Freeing list.\n");
  list = free_list(list);
  printf("Printing freed list:\n");
  print_list(list);
}
