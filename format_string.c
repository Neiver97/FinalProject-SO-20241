#include <stdio.h>
#include <string.h>

void vuln(char *string){
  printf(string);
}
  
int main(int argc, char **argv){
  vuln(argv[1]);
}
