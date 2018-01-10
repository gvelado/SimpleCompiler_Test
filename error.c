#include <stdlib.h>
#include <stdio.h>
#include "error.h"

void Error(char *error){
  printf("--> %s \n" , error);
  exit(1);
}
