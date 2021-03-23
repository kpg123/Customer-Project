#include "customer.h"
//got Binary search from online source :
//https://www.tutorialspoint.com/binary-search-a-string-in-cplusplus
int binarySearchString(std::vector<customer*> arr, std::string x, int n) {
   int lower = 0;
   int upper = n - 1;
   while (lower <= upper) {
      int mid = lower + (upper - lower) / 2;
      int res = 1; 
      if (x == (arr[mid]->getID()))
         res = 0;
      if (res == 0)
         return mid;
      if (x > (arr[mid]->getID()))
         lower = mid + 1;
      else
         upper = mid - 1;
   }
   return -1;
}
