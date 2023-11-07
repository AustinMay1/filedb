#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>

#include "common.h"
#include "file.h"
#include "parse.h"

int main(int argc, char *argv[]) {
  int c;
  char *filepath = NULL;
  bool newFile = false;
  int dbfd = -1;

  while ((c = getopt(argc, argv, "nf:")) != -1) {
    switch (c) {
    case 'n':
      newFile = true;
      break;
    case 'f':
      filepath = optarg;
      break;
    case '?':
      printf("Unknown flag: %c\n", c);
      break;
    default:
      return -1;
    }
  }

  if (filepath == NULL) {
    printf("Filepath is a required argument\n");
  }

  if (newFile) {
    dbfd = create_new_db(filepath);
    if (dbfd == STATUS_ERROR) {
      printf("Unable to create: %s\n", filepath);
      return -1;
    }
  } else {
    dbfd = open_db(filepath);
    if (dbfd == STATUS_ERROR) {
      printf("Unable to open: %s", filepath);
      return -1;
    }
  }

  return 0;
}
