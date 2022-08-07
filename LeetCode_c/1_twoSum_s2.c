struct HashEntry {
    int k;
    int v;
    UT_hash_handle hh;
};

struct HashEntry *hashtable;

struct HashEntry *hh_find(int k) {
    struct HashEntry *res = NULL;
    HASH_FIND_INT(hashtable, &k, res);
    return res;
}

void hh_insert(int k, int v) {
    struct HashEntry *e = (struct HashEntry*) malloc(sizeof(struct HashEntry));
    e->k = k;
    e->v = v;
    HASH_ADD_INT(hashtable, k, e);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if (NULL == nums || numsSize <= 1 || NULL == returnSize)
        return NULL;
    hashtable = NULL; // 这句代码非常重要，如果没有初始化为NULL，[3,3] 6这个测试用例会出现测试用例结果通过，但是运行时不通过的情况

    for (int i = 0; i < numsSize; ++i) {

        int tmp = target - nums[i];
        struct HashEntry *findres = hh_find(tmp);
        if (NULL != findres) {
            int *ans = (int *) calloc(2, sizeof(int));
            ans[0] = findres->v;
            ans[1] = i;
            *returnSize = 2;
            return ans;
        }
        hh_insert(nums[i], i);
    }
    
    *returnSize = 0;
    return NULL;
}