#include <stdio.h>

struct node {
	int war;
	struct node *next;
};

void drukuj(struct node *p) {
	while (NULL != p) {
		printf("%d\n", p->war);
		p = p->next;
  	}
}

int main() {
	struct node *head;
  	struct node *a;
  	struct node *b;
  	struct node *c;
	struct node *d;

  	a = malloc(sizeof(struct node));
 	b = malloc(sizeof(struct node));
  	c = malloc(sizeof(struct node));
	d = malloc(sizeof(struct node));

  	a->war = 1;
  	b->war = 3;
  	c->war = 5;
	d->war = 7;

  	a->next = b;
  	b->next = c;
  	c->next = d;
	d->next = NULL;

  
  	head = a;
  	drukuj(head);
}
