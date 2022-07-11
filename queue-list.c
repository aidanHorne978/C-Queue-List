#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct q_item *q_item;

struct q_item {
    double item;
    q_item next;
};

struct queue {
    q_item first;
    q_item last;
    int length;
};

queue queue_new() {
    queue q = malloc(sizeof *q);
    q->first = q->last = NULL;
    q->length =0;
    return q;
}

/** dont need to remember this one*/

void enqueue(queue q, double item) {
    q_item i = malloc(sizeof *i);
    i->item = item;
    i->next = NULL;
    if (q->length == 0) {
        q->first = i;
    } else {
        q->last->next = i;
    }
    q->last = i;
    q->length++;
}

double dequeue(queue q) {
    q_item temp = q->first;
    double d = temp ->item;
    q->first = temp -> next;
    free(temp);
    q->length--;
    return d;
}

void queue_print(queue q) {
    /* print queue contents one per line to 2 decimal places */
    int i;
    q_item qi = q->first;
    for(i=0; i<q->length; i++){
        printf("%.2f\n", qi -> item);
          qi = qi->next;
    }
  
}

/** or this one*/

void queue_print_info(queue q) {
    if (q->length == 0) {
        printf("The queue is empty\n");
    } else {
        printf("first %.2f, last %.2f, length %d\n", q->first->item,
               q->last->item, q->length);
    }
}

 int queue_size(queue q) {
     return q->length;
}

void queue_free_aux (q_item i)
{
    if (i == NULL)
    {
        return;
    }
    queue_free_aux(i -> next);
    free(i);
}

 queue queue_free(queue q) {
     queue_free_aux (q -> first);
     free(q);
     return q;
}
