

#ifndef hook_h
#define hook_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

bool nemgvn(bool enable, void *targets[], void *replacements[], int count);

#ifdef __cplusplus
}
#endif

#endif /* hook_h */