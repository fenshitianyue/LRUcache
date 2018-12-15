#include <stdio.h>
#include <stdlib.h>
#include "LRUcache.h"

/*错误处理宏*/
#define HANDLE_ERROR(msg) do { fprintf(strerr, "%s file.", msg); exit(-1);}while(0)

/*封装缓存数据处理接口*/
#define LRUCACHE_PUTDATA(cache, data) \
  do {\
    if(0 != LRUCacheSet(cache, data, data)) \
      fprintf(stderr, "put (%c %c) to cache fail.\n", data, data); \
    else \
      fprintf(stdout, "put (%c %c) to cache successful.\n", data, data); \
  }while(0)

#define LRUCACHE_GETDATA(cache, key) \
  do {\
    char data = LRUCacheGet(cache, key); \
    if('\0' == data) \
      fprintf(stderr, "get data (key:%c) from cache fail.\n", key); \
    else if(key == data) \
      fprintf(stdout, "get (%c %c) from cache\n", key, data) \
  }while(0)

/*测试用例*/
void test_case_1(){

}

void test_case_2(){

}

void test_case_3(){

}

int main() {
  test_case_1(); 
  test_case_2(); 
  test_case_3(); 
  return 0;
}
