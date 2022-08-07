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