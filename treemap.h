#ifndef TREEMAP_TREEMAP_H
#define TREEMAP_TREEMAP_H

typedef struct Node Node;
struct Node {
  char *key;
  char *value;
  Node *left;
  Node *right;
};

typedef struct TreeMap TreeMap;
struct TreeMap {
  Node *root;
};

TreeMap *newTreeMap();
void insertToTreeMap(TreeMap *treemap, const char *key, const char *value);
char *getValueFromTreeMap(const TreeMap *treemap, const char *key);
void freeTreeMap(TreeMap *treemap);
int removeFromTreeMap(TreeMap *treemap, const char *key);

#endif  // TREEMAP_TREEMAP_H
