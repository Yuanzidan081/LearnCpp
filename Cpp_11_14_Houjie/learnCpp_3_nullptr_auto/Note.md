+ nullptr和std::nullptr_t：

```cpp
// \include\stddef.h
#if defined(__cplusplus) && __cplusplus >= 201103L
#ifndef _GXX_NULLPTR_T
#define _GXX_NULLPTR_T
  typedef decltype(nullptr) nullptr_t;
#endif
#endif /* C++11.  */
```

+ auto测试：

![](image/resultAuto.png)