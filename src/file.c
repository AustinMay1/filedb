#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "common.h"
#include "file.h"

int create_new_db(char *filename) {
  // check to make sure file doesn't already exist
  int fd = open(filename, O_RDONLY);
  if (fd != -1) {
    close(fd);
    printf("File already exists!\n");
    return STATUS_ERROR;
  }

  // create db file
  fd = open(filename, O_RDWR | O_CREAT, 0644);
  if (fd == -1) {
    perror("open");
    return STATUS_ERROR;
  }

  return fd;
}

int open_db(char *filename) {
  int fd = open(filename, O_RDWR, 0644);
  if (fd == -1) {
    perror("open");
    return STATUS_ERROR;
  }

  return fd;
}
