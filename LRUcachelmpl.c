#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LRUcachelmpl.h"

/*创建一个缓存单元*/
static cacheEntryS* newCacheEntry(char key, char data){
  cacheEntryS* entry = NULL;
  if(NULL == (entry = (cacheEntryS*)malloc(sizeof(cacheEntryS)))){
    perror("malloc");
    return NULL;
  }
  memset(entry, 0x00, sizeof(cacheEntryS));
  entry->_key  =  key;
  entry->_data = data;
  return entry;
}

/*释放一个缓存单元*/
static void freeCacheEntry(cacheEntryS* entry){
  if(NULL != entry){
    free(entry);
  }
}

/*双链表的接口*/
static void removeFromList(LRUCacheS* cache, cacheEntryS* entry){
  if(cache->_lruListSize <= 0){
    return;
  } 
  if(entry == cache->_lruListHead && entry == cache->_lruListTail){
    cache->_lruListHead = cache->_lruListTail = NULL;
  }else if(entry == cache->_lruListHead){
    cache->_lruListHead = entry->_lruListNext;
    cache->_lruListHead->_lruListPre = NULL;
  }else if(entry == cache->_lruListTail){
    cache->_lruListTail = entry->_lruListPre;
    cache->_lruListTail->_lruListNext = cache->_lruListHead;
    cache->_lruListHead->_lruListPre = cache->_lruListTail;
  }else{
    entry->_lruListPre->_lruListNext = entry->_lruListNext; 
    entry->_lruListNext->_lruListPre = entry->_lruListPre;
  }
  free(entry);
  cache->_lruListSize--;
}

static cacheEntryS* insertToListHead(LRUCacheS* cache, cacheEntryS* entry){
    cacheEntryS *removedEntry = NULL;

    if (++cache->_lruListSize > cache->_cacheCapacity) {
      removedEntry = cache->_lruListTail;
      removeFromList(cache, cache->_lruListTail);   
    }

    if (cache->_lruListHead==NULL&&cache->_lruListTail==NULL) {
      cache->_lruListHead = cache->_lruListTail = entry;
    } else {
      entry->_lruListNext = cache->_lruListHead;
      entry->_lruListPre = NULL;
      cache->_lruListHead->_lruListPre = entry;
      cache->_lruListHead = entry;
    }
    return removedEntry;
}

static void freeList(LRUCacheS *cache)
{
    /*链表为空*/
    if (0 == cache->_lruListSize) return;

    cacheEntryS *entry = cache->_lruListHead;
    /*遍历删除链表上的所有节点*/
    while(entry) {
        cacheEntryS *temp = entry->_lruListNext;
        freeCacheEntry(entry);     
        entry = temp;
    }
    cache->_lruListSize = 0;
}

/*辅助性接口，用于保证最近访问的节点总是位于链表表头*/
static void updateLRUList(LRUCacheS *cache, cacheEntryS *entry) 
{
    /*将节点从链表中摘抄*/
    removeFromList(cache, entry);
    /*将节点插入链表表头*/
    insertToListHead(cache, entry);
}

/*哈希表接口*/
/*哈希函数*/
static int hashKey(LRUCacheS* cache, char key){
  return (int)key % cache->_cacheCapacity;
}

/*从哈希表获取缓存单元*/
static cacheEntryS* getValueFromHashMap(LRUCacheS* cache, char key){
  if(NULL == cache) return NULL;
  cacheEntryS* entry = cache->_hashMap[hashKey(cache, key)]; 
  while(entry){
    if(key == entry->_key)
      break;
    entry = entry->_hashListNext;
  }
  return entry;
}

/*向哈希表插入缓存单元*/
static void insertentryToHashMap(LRUCacheS* cache, cacheEntryS* entry){
  if(NULL == cache || NULL == entry) return;
  cacheEntryS* n = cache->_hashMap[hashKey(cache, entry->_key)];
  if(NULL != n){
    entry->_hashListNext = n;
    n->_hashListPre = entry;
  }
  cache->_hashMap[hashKey(cache, entry->_key)] = entry;
}

/*从哈希表删除缓存单元*/
static void removeEntryFromHashMap(LRUCacheS* cache, cacheEntryS* entry){
  if(NULL == entry || NULL == cache || NULL == cache->_hashMap) return;
  cacheEntryS* n = cache->_hashMap[hashKey(cache, entry->_key)];
  while(n){
    if(n->_key == entry->_key){
      n->_hashListPre->_hashListNext = n->_hashListNext;
    }else{
      n = n->_hashListNext;
    }
    if(n->_hashListNext){
      n->_hashListNext->_hashListPre = n->_hashListPre;
    }
    return;
  }
  n = n->_hashListNext;
}

int LRUCacheSet(void* lruCache, char key, char data){

}


