#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LRUcachelmpl.h"
#include "LRUcache.h"

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

/*创建LRU cache*/
int LRUCacheCreate(int capacity, void** lru_cache){
  
}

/*销毁LRU cache*/
int LRUCacheDestroy(void* lru_cache){
}

/*将数据放入LRU缓存中*/
int LRUCacheSet(void* lru_cache, char key, char date){
}

/*从缓存中获取数据*/
char LRUCacheGet(void* lru_cache, char key){
}

/*打印缓存中的数据，按访问时间从新到旧的顺序输出*/
void LRUCachePrint(void* lru_cache){
}
