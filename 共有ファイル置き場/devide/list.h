struct node{
    char name[20];
    struct node *next;
};
typedef struct node NODE;

NODE *add(char *,NODE *);
void print(NODE *);
void insert(int,char *,NODE **);
void free_list(NODE **);
void delete(int,NODE **); 
void delete_name(char *,NODE **);
void count_node(NODE *);
void replace(char *,char *,NODE *);