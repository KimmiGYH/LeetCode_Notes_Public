# 检查运行时间

```cpp
time_t startTime = clock();
time_t endTime = clock();

cout << "time : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
```
