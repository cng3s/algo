struct HashEntry {
    int k;
    char v;
    UT_hash_handle hh;
};

struct HashEntry *hashtable;

struct HashEntry *ht_find(int k) {
    if (NULL == hashtable)
        return NULL;
    struct HashEntry *res = NULL;
    HASH_FIND_INT(hashtable, &k, res);
    return res;
}

void ht_insert(int k, char v) {
    struct HashEntry *e = (struct HashEntry *) calloc(1, sizeof(struct HashEntry));
    e->k = k;
    e->v = v;
    HASH_ADD_INT(hashtable, k, e);
}

void ht_erase(struct HashEntry *e) {
    if (!e)
        return;
    HASH_DEL(hashtable, e);
    free(e);
}

int lengthOfLongestSubstring(char * s){
    if (!s)
        return 0;
    
    int slen = strlen(s), ans = 0, r = -1;
    hashtable = NULL;

    for (int i = 0; i < slen; ++i) {

        if (i > 0) {
            struct HashEntry *findres = ht_find(s[i-1]);
            ht_erase(findres);
        }

        while (r+1 < slen) {
            struct HashEntry *findres = ht_find(s[r+1]);
            if (findres) 
                break;
            ht_insert(s[r+1], s[r+1]);
            ++r;
        }

        ans = (ans < r-i+1 ? r-i+1 : ans);
    }

    return ans;
}