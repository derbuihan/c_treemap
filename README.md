# C TreeMap Implementation

This is an implementation of a basic TreeMap data structure written in C. TreeMaps in C are a way of storing data in
key-value pairs and provide efficient insertion, deletion and retrieval operations.

## Features

- This TreeMap implementation uses the simple binary search tree data structure.
- Basic operations such as insertion (`insertToTreeMap`), deletion (`removeFromTreeMap`), and
  retrieval (`getValueFromTreeMap`), and freeing the memory (`freeTreeMap`).
- A function to create a new TreeMap (`newTreeMap`).

## Functions

- `TreeMap *newTreeMap();`
- `void insertToTreeMap(TreeMap *treemap, const char *key, const char *value);`
- `char *getValueFromTreeMap(const TreeMap *treemap, const char *key);`
- `void freeTreeMap(TreeMap *treemap);`
- `int removeFromTreeMap(TreeMap *treemap, const char *key);`

## Example Use

```C
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
```

## How to Build

The TreeMap implementation is contained in a single C source file. There are no external dependencies. Compile using
your favorite C compiler.

## License

[MIT](https://choosealicense.com/licenses/mit/)