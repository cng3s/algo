char* compressString(char* S){
    int len = strlen(S);
    if (len == 0 || len == 1)
        return S;

    char c = S[0];
    int cnt = 1;
    char *ans = (char*) calloc(100000, sizeof(char));
    char *p = ans;

    for (int i = 1; i < len; ++i) {
        if (S[i] == c) {
            ++cnt;
        } else {
            snprintf(p, 100000, "%c%d", c, cnt);
            cnt = 1;
            c = S[i];
            while (*p != 0) 
                ++p;
        }
    }

    snprintf(p, 100000, "%c%d", c, cnt);

    int ans_len = strlen(ans);
    if (ans_len >= len)
        return S;

    return ans;
}
