#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LRUcache.h"


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
