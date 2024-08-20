/*create hash map*/
/*populate hash map*/
/*iterate through hash map and find target - element (compliment)*/
/*if element is in the hash table lookup and return it along with the element*/
#include <stdbool.h>
#include <strings.h>
#include <time.h>

typedef struct {
  int index;
  int nums;
} result;

result *hashTable[10];

void hashInit(int numsSize) {
  for (int i = 0; i < numsSize; i++) {
    hashTable[i] = NULL;
  }
}

unsigned int hash(int key, int numsSize) { return key % numsSize; }

bool hashInsert(result *number, int numsSize) {
  if (number == NULL)
    return false;
  int index = hash(number->nums, numsSize);
  if (hashTable[index] != NULL) {
    return false;
  }
  hashTable[index] = number;
  return true;
}
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  hashInit(numsSize);

  /* populate hash table*/
  /* iterat through hash table*/
  /* return num if compliment is in the table*/
}
