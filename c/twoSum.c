/*create hash map*/
/*populate hash map*/
/*iterate through hash map and find target - element (compliment)*/
/*if element is in the hash table lookup and return it along with the element*/
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

typedef struct {
  int index;
  int num;
} result;

result *hashTable[10];

void hashInit() {
  for (int i = 0; i < 10; i++) {
    hashTable[i] = NULL;
  }
}

unsigned int hash(int key, int numsSize) { return key % numsSize; }

bool hashInsert(int number, int numsSize, int realIndex) {
  int index = hash(number, numsSize);

  while (hashTable[index] != NULL) {
    if (hashTable[index]->num == number) {
      return false;
    }
    index = (index + 1) % numsSize;
  }

  result *newRes = (result *)malloc(sizeof(result));
  newRes->num = number;
  newRes->index = realIndex;
  hashTable[index] = newRes;
  return true;
}

result *hashLookup(int number, int numsSize) {
  unsigned int index = hash(number, numsSize);
  while (hashTable[index] != NULL) {
    if (hashTable[index]->num == number)
      return hashTable[index];
    index = (index + 1) % numsSize;
  }
  return NULL;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  hashInit();
  for (int i = 0; i < numsSize; i++) {
    hashInsert(nums[i], numsSize, i);
  }
  for (int i = 0; i < numsSize; i++) {
    int comp = target - nums[i];
    result *searchComp = hashLookup(comp, numsSize);
    if (searchComp != NULL) {
      result *searchNum = hashLookup(nums[i], numsSize);
      int *answer = (int *)malloc(2 * sizeof(int));
      answer[0] = searchComp->index;
      answer[1] = searchNum->index;
      *returnSize = 2;
      return answer;
    }
  }
  *returnSize = 0;
  return NULL;
  /* populate hash table*/
  /* iterat through hash table*/
  /* return num if compliment is in the table*/
}
