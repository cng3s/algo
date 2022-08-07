/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *res = (int*)calloc(2, sizeof(int));
    if (numsSize <= 1)
        return res;

    *returnSize = 0;
    bool found = false;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                found = true;
                goto End;
            }
        }
    }
End:
    if (found)
        *returnSize = 2;
    return res;
}