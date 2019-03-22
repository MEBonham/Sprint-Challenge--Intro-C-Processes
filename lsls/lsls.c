#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path = ".";
  if (argc > 1)
  {
    path = argv[1];
  }
  

  // Open directory
  DIR *dir_ptr = opendir(path);

  // Repeatly read and print entries
  struct dirent *file_info;
  char *file_name;
  struct stat size_buf;
  while ((file_info = readdir(dir_ptr)) != NULL)
  {
    file_name = file_info->d_name;
    stat(file_name, &size_buf);
    printf("%10lld  %s\n", (long long int) size_buf.st_size, file_name);
    // printf("%s\n", file_name);
  }

  // Close directory
  closedir(dir_ptr);

  return 0;
}