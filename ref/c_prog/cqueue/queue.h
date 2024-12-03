#ifndef _QUEUE_H_
#define _QUEUE_H_

#define WORDLENGTH 32

struct QNode;

typedef struct {
  struct QNode *head;
  struct QNode **tail;
} Queue;

void initQueue(Queue *queue);

void offer(Queue *queue, char *word);

char *poll(Queue *queue);

void clearQueue(Queue *queue);

#endif
