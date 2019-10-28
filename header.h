//int main();
struct node * create_list();
void print_list(struct node *current);
struct node * insert_front(struct node *list, int x);
struct node * free_list(struct node *list);
struct node * remove_node(struct node *front, int data);
