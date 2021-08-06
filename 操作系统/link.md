1、生成汇编文件

```
g++ -S main.cpp
g++ -S A.cpp
g++ -S B.cpp
```

2、生成可重定向目标文件

```
g++ -c main.s
g++ -c A.s
g++ -c B.s
```

3、生成完全链接的可执行目标文件

```
g++ -o prog main.o A.o B.o
```



