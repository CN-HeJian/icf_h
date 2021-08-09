##### 1、makefile的规则

需要注意的是commad如果不与target以及prerequisites在一行，需要以[Tab键]开头，如果和prerequisites在一行，可以用分号作为分隔

```
//以tab键为换行符号
target://目标文件：exe file、obj file、label
prerequisites://生成target所需要的文件
	command://shell命令
//以;为分隔
prerequisites;command
```

##### 2、简化makefile文件的编写

- 使用变量

```
edit : main.o kbd.o command.o display.o \
                  insert.o search.o files.o utils.o
            cc -o edit main.o kbd.o command.o display.o \
                       insert.o search.o files.o utils.o
变为：
object = main.o kbd.o command.o display.o insert.o search.o file.o utils.o
edit: $(object) cc -o edit $(object)//使用$(object)的方式来使用这个变量
```

- 自动推导

  make命令看到一个.o文件，他会自动将对应的c文件加载到依赖关系中，例子：make找到一个whatever.o文件，那么whatever.c就会是whatever.o的依赖文件，并且cc -c whatever.c也会推导出来

```
search.o : search.c defs.h buffer.h
            cc -c search.c
变为
search.o : defs.h buffer.h
```

- `.PHONY`的加入

  PHONY显示的指明clean表示一个伪目标文件

  rm前面的-表示某些文件出现了问题忽略，继续执行后面的事

  clearn规则不要放在文件的开头，不然就会变成make的默认目标

```
.PHONY : clean
clean :
	-rm edit $(object)
```

##### 3、makefile里面有什么

makefile里面包含五个东西，分别为显示规则、隐晦规则、变量定义、文件指示、注释

- 显示规则：显示规则说明如何生成一个或者多个目标文件
- 隐晦规则：make所支持的自动推导功能
- 变量定义：当amkefile执行时，变量都会扩展到相应的引用位置
- 文件指示：包括两个部分，一种是引用另外一个makefile文件，另一种是只需要当前makefile中的一部分，例如c语言#if
- 注释：使用#进行注释，在maikefile中如果需要使用#，使用反斜杠进行转义

##### 4、引用其他的makefile

```
//有这么几个makefile：a.mk b.mk c.mk 还有一个文件叫做foo.make 以及一个变量 $(bar),其中包含了e.mk和f.mk
include foo.make *.mk $(bar)
等价于
include foo,make a.mk b.mk c.mk e.mk f.mk
```

##### 5、书写规则

```
foo.o foo.c defs.h
	  cc -c -g foo.c
//foo.o表示我们的目标，foo.c和defs.h表示所依赖的源文件，`cc -c -g foo.c`表示命令
```

##### 6、在规则中使用通配符

make支持三种通配符："*"，"?","[...]"

```
clean 
	rm -f *.o//“*.c”表示后缀为c的文件
```

通配符在变量中并不会展开

```
object = *.o
objeccts := $(wildcard *.o) //想要通配符在变量中展开，需要使用关键字"wildcard"
```

##### 7、文件搜寻

- 特殊变量VPATH

Makefile问价中的特殊变量VPATH就是完成这个功能的，如果没有指明这个变量，make只会在当前的目录中去寻找依赖文件和目标文件，如果定义了这个变量，make就会在当前目录找不到的情况下，到指定的目录中寻找文件

```
VPATH = src:../headers
```

- 关键字vpath

```
1、vpath <pattern>;<directories>;//为符合模式<pattern>;的文件指定搜索目录<directories>
	eg:vpath %.h ../hraders
2、vpath <pattern>;//清除符合模式<pattern>;的文件的搜索目录
3、vapth//清楚已经设置好了的文件搜索目录
```

- 连续使用vpath语句

```
vpath %.c foo
vpath % blish
vpath %.c bar
```

##### 8、伪目标

伪目标一般没有依赖的文件。但是，我们也可以为伪目标指定所依赖的文件。伪目标同样可以作为“默认目标”，只要将其放在第一个。一个示例就是，如果你的Makefile需要一口气生成若干个可执行文件，但你只想简单地敲一个make完事，并且，所有的目标文件都写在一个Makefile中，那么你可以使用“伪目标”这个特性：

```
all :prog1 prog2 prog3
.PHONY:all
prog1 : prog1.o utils.o
	cc -o prog1 prog1.o utils.o
prog2 : prog2.o
	cc -o prog2 prog2.o
prog3 : prog3.o sort.o utils.o
	cc -o prog3 prog3.o sort.o utils.o
```

Makefile中的第一个目标会被作为其默认目标。我们声明了一个“all”的伪目标，其依赖于其它三个目标。由于伪目标的特性是，总是被执行的，所以其依赖的那三个目标就总是不如“all”这个目标新。所以，其它三个目标的规则总是会被决议。也就达到了我们一口气生成多个目标的目的。“.PHONY : all”声明了“all”这个目标为“伪目标”。上面表示目标也可以成为依赖

```
.PHONY: cleanall cleanobj cleandiff

cleanall : cleanobj cleandiff
		rm program

cleanobj :
		rm *.o

cleandiff :
		rm *.diff
```

前面讲述到目标可以作为依赖，而这个例子表示伪目标同样也可成为依赖,我们可以输入“make cleanall”和“make cleanobj”和“make cleandiff”命令来达到清除不同种类文件的目的。

##### 9、多目标

