#include <stdio.h>
#include <stdlib.h>
#include "zmalloc.h"


typedef struct dictEntry {
    void *key;
    union {
        void *val;
        int64_t i64;
    } v;
    struct dictEntry *next;
} dictEntry;


typedef struct dictht {
    dictEntry **table;
} dictht;

typedef struct dictType {
    uint64_t (*hashFunction)(const void *key);
    void *(*keyDup)(void *privdata, const void *key);
    void *(*valDup)(void *privdata, const void *obj);
    int (*keyCompare)(void *privdata, const void *key1, const void *key2);
    void (*keyDestructor)(void *privdata, void *key);
    void (*valDestructor)(void *privdata, void *obj);
} dictType;

typedef struct dict {
    dictType *type;
    void *privdata;
    dictht ht[2];
} dict;

// 创建
dict *createDict(dictType *dt, void *privDataPtr) {
    dict *dc = zmalloc(sizeof(*dc));
    
    dc->type = dt;
    dc->privdata = privDataPtr;

    return dc;
}

// 添加
int dictAdd(dict *dc, const void *key, const void *val) {
    return 0;
}

// 查找
dictEntry *dictFind(dict *dc, const void *key) {
    dictEntry *entry;

    return entry;
}

// 删除
int dictDelete(dict *dc, const void *key) {
    return 0;
}

// 释放
void dictRelease(dict *dc) {

    return;
}

int main() {
    dict *dc = createDict(NULL, NULL);

    int k = 1;
    int v = 2;

    dictAdd(dc, &k, &v);

    dictEntry *entry = dictFind(dc, &k);

    printf("%ld", (entry->v).i64);

    dictRelease(dc);

    return EXIT_SUCCESS;
}