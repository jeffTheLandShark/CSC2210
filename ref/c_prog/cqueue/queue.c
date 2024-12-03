/*
 *
 *
 */

#include "queue.h"

#include <stdlib.h>
#include <string.h>

typedef struct QNode {
  char *word;
  struct QNode *next;
} QNode;

static QNode *makeQNode(char *word) {
  QNode *node = (QNode *) malloc(sizeof(QNode));
  node->next = NULL;
  node->word = (char *) malloc(sizeof(char) * strlen(word) + 1);
  strcpy(node->word, word);
  return node;
}

void initQueue(Queue *queue) {
  queue->head = NULL;
  queue->tail = &(queue->head);
}

void offer(Queue *queue, char *word) {
  *queue->tail = makeQNode(word);
  queue->tail = &((*queue->tail)->next);
}

char *poll(Queue *queue) {
  // POLL LOGIC HERE (WAS NOT LISTENING)
}

void clearQueue(Queue *queue) {
  while (queue->head != NULL) {
    poll(queue);
  }
}