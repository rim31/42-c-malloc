
// #include  "malloc.h"
#include <stdlib.h>


int main()
{
  malloc(1024);
  malloc(1024 * 32);
  malloc(1024 * 1024);
  malloc(1024 * 1024 * 16);
  malloc(1024 * 1024 * 128);
  show_alloc_mem();
return (0);
}


// #include <stdlib.h>
//
// int main()
// {
//    malloc(1024);
//    malloc(1024 * 32);
//    malloc(1024 * 1024);
//    malloc(1024 * 1024 * 16);
//    malloc(1024 * 1024 * 128);
//    show_alloc_mem();
//    return (0);
// }
// // gcc -o test5 test5.c -L. -lft_malloc
// //./test5
//
// L'affichage correspond au sujet et à la répartition TINY/SMALL/LARGE du projet ?
