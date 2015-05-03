struct filestruct;
typedef void (*level_fn)(struct filestruct path);


typedef struct filestruct
{
  char *name, *fullname;
  level_fn directory_action, file_action;
  int depth, error;
  void *data;
} filestruct;



#define process_dir(...) process_dir_r((filestruct){__VA_ARGS__})

int process_dir_r(filestruct level);
