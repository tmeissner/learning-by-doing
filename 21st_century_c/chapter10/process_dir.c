#define _GNU_SOURCE
#include <stdio.h>

#include <dirent.h>
#include <stdlib.h>

#include "process_dir.h"


int process_dir_r(filestruct level) {
  if (!level.fullname) {
    if (level.name) {
      level.fullname = level.name;
    } else {
      level.fullname = ".";
    }
  }
  int errct = 0;

  DIR *current = opendir(level.fullname);
  if (!current) {
    return 1;
  }

  struct dirent *entry;
  while ((entry = readdir(current))) {

    if (entry->d_name[0] == '.') {
      continue;
    }

    filestruct next_level = level;
    next_level.name = entry->d_name;
    if ((asprintf(&next_level.fullname, "%s/%s", level.fullname, entry->d_name) == -1) ||
        (next_level.fullname == NULL)) {
      return 1;
    }

    if (entry->d_type == DT_DIR) {
      next_level.depth++;
      if (level.directory_action) {
        level.directory_action(next_level);
      }
      errct += process_dir_r(next_level);
    } else if (entry->d_type == DT_REG && level.file_action) {
      level.file_action(next_level);
      errct += next_level.error;
    }

    if (next_level.fullname) {
      free(next_level.fullname);
    }
  }
  (void) closedir(current);
  return errct;
}
