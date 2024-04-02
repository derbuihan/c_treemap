#include <stdio.h>

#include "treemap.h"

int main() {
  struct TreeMap *treeMap = newTreeMap();

  insertToTreeMap(treeMap, "key14", "value14");
  insertToTreeMap(treeMap, "key12", "value12");
  insertToTreeMap(treeMap, "key16", "value16");
  insertToTreeMap(treeMap, "key11", "value11");
  insertToTreeMap(treeMap, "key13", "value13");
  insertToTreeMap(treeMap, "key15", "value15");
  insertToTreeMap(treeMap, "key17", "value17");

  removeFromTreeMap(treeMap, "key14");
  char *value = getValueFromTreeMap(treeMap, "key15");
  printf("Value of key15: %s\n", value);

  freeTreeMap(treeMap);

  return 0;
}
