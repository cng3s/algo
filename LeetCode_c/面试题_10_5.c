int findString(char** words, int wordsSize, char* s){
    int ans = 0;
    for (int i = 0; i < wordsSize; ++i) {
        if (strcmp(words[i], s) == 0)
            return i;
    }
    return -1;
}
