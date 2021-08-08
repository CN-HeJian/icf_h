1、生成汇编文件

```
g++ -S main.cpp
g++ -S A.cpp
g++ -S B.cpp
```

2、生成可重定向目标文件

```
g++ -Og -c main.cpp//-Og表示编译优化等级
g++ -c A.cpp
g++ -c B.cpp
```

3、生成完全链接的可执行目标文件

```
g++ -o prog main.o A.o B.o
```

4、反汇编O文件

```
objdump -d main.o
```



