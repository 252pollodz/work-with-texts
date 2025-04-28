#include <stdio.h>
#include <stdlib.h>
FILE *fptr;
int main() {
//   fptr = fopen("test.txt","a");
//    if (!fptr)exit(1);
//
//    fprintf(fptr,"testowy napis nr dodany na koncu\n");
//    fclose(fptr);
    fptr = fopen("test.txt","r");
    if (!fptr)exit(1);
    char str;
    fseek (fptr, -1, SEEK_END);

    for (int i = 50; i>0; i--) {
      str = fgetc(fptr);
      fseek (fptr, -2, SEEK_CUR);
      printf("%c", str);
    }
    printf("\n");
    fclose(fptr);

    return 0;
}