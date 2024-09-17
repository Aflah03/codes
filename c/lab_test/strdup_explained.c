#include <stdio.h>
#include <string.h>
int main() {
  char original[] = "HELLO, WORLD";
  char *duplicate = strdup(original);//dynamic memory allocation
  if (duplicate == NULL) {

    printf("memory allocation failed");
    return 1;
  }

  printf("the original is : %s\n",original);
  printf("Duplicate is : %s",duplicate);
}
