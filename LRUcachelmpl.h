#pragma once

typedef struct cacheEntryS{
  char _key; /*数据的key*/
  char _data; /*数据的data*/

  /*缓存哈希表指针，分别指向哈希桶的前一个节点和后一个节点*/
  struct cacheEntryS* hashListPre;
  struct cacheEntryS* hashListNext;

  /*缓存双向链表指针，分别指向链表的前一个节点和后一个节点*/
  struct cacheEntryS* lruListPre;
  struct cacheEntryS* lruListNext;
}cacheEntryS;

typedef struct LRUCacheS{
  int _cacheCapacity; /*缓存容量*/
  cacheEntryS** _hashMap; /*缓存的哈希表*/

  cacheEntryS* _lruListHead; /*缓存双向链表表头*/
  cacheEntryS* _lruListTail; /*缓存双向链表表尾*/
  int _lruListSize; /*缓存双向链表节点个数*/
}LRUCacheS;

