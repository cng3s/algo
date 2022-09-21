/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int getRgbyIx(char c)
{
    if (c == 'R') 
        return 0;
    else if (c == 'G')
        return 1;
    else if (c == 'B')
        return 2;
    else if (c == 'Y')
        return 3;
    else
        assert(0);
}

int* masterMind(char* solution, char* guess, int* returnSize){
    int *ans = (int*)calloc(2, sizeof(int));
    *returnSize = 2;
    int rgby[4] = {0};

    for (int i = 0; i < 4; ++i) {
        if (solution[i] != guess[i]) {
            ++ rgby[getRgbyIx(solution[i])];
        } else {
            ++ ans[0];
            guess[i] = '*'; // test case: "BGBG" "RGBR"
        } 
    }

    for (int i = 0; i < 4; ++i) {
        if (guess[i] == '*')
            continue;
        int *p = &rgby[getRgbyIx(guess[i])];
        if (*p > 0) {
            --(*p);
            ++ ans[1];
        }
    }

    return ans;
}
