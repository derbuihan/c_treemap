#include "treemap.h"

#include <stdlib.h>
#include <string.h>

static Node *newNode(const char *key, const char *value) {
  Node *node = malloc(sizeof(Node));
  node->key = strdup(key);
  node->value = strdup(value);
  node->left = NULL;
  node->right = NULL;
  return node;
}

TreeMap *newTreeMap() {
  TreeMap *treeMap = malloc(sizeof(TreeMap));
  treeMap->root = NULL;
  return treeMap;
}

Node **findNode(Node **cur, const char *key) {
  while (*cur) {
    if (strcmp(key, (*cur)->key) > 0) {
      cur = &((*cur)->right);
    } else if (strcmp(key, (*cur)->key) < 0) {
      cur = &((*cur)->left);
    } else {
      break;
    }
  }
  return cur;
}
void insertToTreeMap(TreeMap *treemap, const char *key, const char *value) {
  Node **node = findNode(&(treemap->root), key);
  if (*node != NULL) {
    free((*node)->value);
    (*node)->value = strdup(value);
    return;
  }
  *node = newNode(key, value);
}

Node *searchNode(Node *cur, const char *key) {
  while (cur) {
    if (strcmp(key, cur->key) > 0) {
      cur = cur->right;
    } else if (strcmp(key, cur->key) < 0) {
      cur = cur->left;
    } else {
      break;
    }
  }
  return cur;
}

char *getValueFromTreeMap(const TreeMap *treemap, const char *key) {
  Node *node = searchNode(treemap->root, key);
  if (node == NULL) return NULL;
  return node->value;
}

static void freeComponents(Node *node) {
  if (node == NULL) return;
  free(node->key);
  free(node->value);
}

static void freeNodeAndComponents(Node *node) {
  if (node == NULL) return;
  freeComponents(node);
  free(node);
}

static void freeNode(Node *node) {
  if (node == NULL) return;
  freeNode(node->left);
  freeNode(node->right);
  freeNodeAndComponents(node);
}

void freeTreeMap(TreeMap *treemap) {
  freeNode(treemap->root);
  free(treemap);
}

static Node **findMinNode(Node **cur) {
  while ((*cur)->left) cur = &((*cur)->left);
  return cur;
}

int removeFromTreeMap(TreeMap *treemap, const char *key) {
  Node **node = findNode(&(treemap->root), key);
  if (*node == NULL) return -1;

  Node *tmp = *node;
  if ((*node)->left == NULL) {
    *node = (*node)->right;
    freeNodeAndComponents(tmp);
    return 0;
  }

  if ((*node)->right == NULL) {
    *node = (*node)->left;
    freeNodeAndComponents(tmp);
    return 0;
  }

  Node **min = findMinNode(&((*node)->right));
  freeComponents(*node);
  (*node)->key = strdup((*min)->key);
  (*node)->value = strdup((*min)->value);

  Node *tmp2 = *min;
  *min = (*min)->right;
  freeNodeAndComponents(tmp2);
  return 0;
}
