#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

struct node{
  int i;
  struct node *next;
};


void print_list(struct node *current){
  printf("[");
  if (current == NULL){
    printf(" ]\n");
    return;
  }
  while (current->next != NULL){
    printf("%d%s",current->i,",");
      current = current->next;
  }
  printf("%d%s",current->i,"]\n");
}

struct node * create_list(){
  srand(time(NULL));
  
  struct node *randomList = (struct node*)malloc(sizeof(struct node));
  struct node *first = (struct node*)malloc(sizeof(struct node));
  randomList = NULL;
  printf("Printing empty list:\n");
  print_list(randomList);
  
  int len = 5 + rand() % 10;
  int x;

  first->i = rand() % 10;
  randomList = first;
  for (x = 1; x < len; x++){
    randomList->i = rand() % 10;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    randomList->next = newNode;
    randomList = randomList->next;				 
  }
  randomList->next = NULL;
  return first;
}

struct node * insert_front(struct node *list, int x){
  struct node *front = (struct node*)malloc(sizeof(struct node));
  front->i = x;
  front->next = list;
  return front;
}

struct node * free_list(struct node *list){
  while (list != NULL){
    struct node *current = list->next;
    printf("freeing node: %d\n", list->i);
    free(malloc(sizeof(list)));
    list = list->next;
  }
  printf("list freed\n");
  return NULL;
}

struct node * remove_node(struct node *front, int data){
  struct node *first = (struct node*)malloc(sizeof(struct node));
  while (front->i == data)
    front = front->next;
  first = front;
  
  while (front->next != NULL){
    if (front->next->i == data){
      struct node *toBeRemoved = (struct node*)malloc(sizeof(struct node));
      toBeRemoved = front->next;
      struct node *after = (struct node*)malloc(sizeof(struct node));
      after = toBeRemoved->next;
      front->next = after;
      toBeRemoved->next = NULL;
      front = front->next;
    }
    else front = front->next;
  }
  return first;
}


int main(){
  printf("Printing random list:\n");
  struct node *list = create_list();
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
