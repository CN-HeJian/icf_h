## 1、Version Control System(git)

##### 1、退回某次提交

```shell
git log
git revert xxxxx//xx表示信息码
```

##### 2、新建分支，并切换到之前的分支

```shell
git branch FixBug
git checkout FixBug
```

##### 3、合并分支，将两个分支的内容进行合并，主动合并

```shell
git branch FixBug
git checkout FixBug
git commit -m "Create start doc"
git checkout main
git commit -m "Update git doc"
git merge FixBug#将另一个分支合并到当前分支
```

##### 4、另一种合并分支，被动合并

```shell
#将当前所在的分支移植到merge后的分支
git branch bugFix
git checkout bugFix
git commit -m "Turn to bugFix"
git checkout main
git commit -m "Turn to main"
git checkout fixBug
git rebase main #在bugFix分支上，将此分支移动到main分支
git checkout main#切换到main分支
git rebase fixBug#main分支移动到fixBug位置处
```

##### 5、git分支

```shell
git checkout hash[i] #切换到hash值对应的分支
git checkout C3
git checkout HEAD^ #相对引用
git checkout HEAD^
git checkout HEAD^
git checkout HEAD~4 #相对引用高手
git branch -f main C4#强制将main放在C4
```

##### 6、示例

```shell
#切换到一个分支的一个引用
git checkout C4
#------------------------------------------------------------
#在这个分支上做一些修改
git add -u
git commit -m "Add file.txt"
git push#会失败
#------------------------------------------------------------
git branch temp#新建一个临时分支
git branch#当前有哪些分支
git checkout main#切换到主分支
git merge temp#合并临时分支到main分支
git reset --merge#如果合并出现了问题，则撤销上次的合并
```

## 2、windows terminal

##### 1、创建新文件

```
echo >cpu.h //相当于linux中的touch
```

##### 2、给文件改名字

```
mv cpu.h ass.h
```

## 3、shell

##### 1、定义变量

```shell
>>foo=bar
>>echo $foo
bar
>>foo = bar
bash:command not found:foo
>>echo "hello"
hello
>>echo 'World'
World
>>echo "Value is $foo"
value is bar
>>echo 'Value is $foo'
value is $foo
>>echo "we are in $(pwd)"
we are in /home/icf/Desktop/test
```

##### 2、$_

```
$_ //表示上一次命令输入的参数
mkdir hj
cd $_  
cd hj
//进入hj目录下，上面这两条命令都能达到相同的目的
```

##### 3、！！

```shell
!!记录上一次使用的命令
>>mkdir /mnt/new
permision denied
>>sudo !!
sudo mkdir /mnt/new
//上面两条指令是等价的
```

##### 4、￥？

```shell
>>sudo mkdir /mnt/king
>>cd /mnt
>>rm -rf king
permission denied
>>echo $?  //返回上一条消息的是否出错，也即是上一条命令的返回值
1
>>sudo rm -rf king
>>echo $?
0
```

##### 5、||

```shell
//作为条件判断
>>false || echo "0ops fail"
0ops fail
>>true || echo "Will be not be printed" //运算规则是一样的
>>true || echo "Op2"
Op2
```

##### 6、重定向

```shell
>>cat <(ls -l)
total 4
-rwxrwxrwx 1 icf icf 33 Aug 12 09:48 mcd.sh
>>cat <(ls -l ..)
total 8
drwxr-xr-x 4 icf icf 4096 Aug 11 11:25 second
drwxr-xr-x 4 icf icf 4096 Aug 11 11:25 test
>>cat <(ls -l) <(ls -l ..)//需要注意空格
total 4
-rwxrwxrwx 1 icf icf 33 Aug 12 09:48 mcd.sh
total 8
drwxr-xr-x 4 icf icf 4096 Aug 11 11:25 second
drwxr-xr-x 4 icf icf 4096 Aug 11 11:25 test
```

##### 7、特殊含义

```shell
$$ //shell本身的pid
$?//上一条指令的返回值
$0//shell本身的文件名
$#//添加到shell的参数个数
$*//所有的参数列表
$@//和$*类似
```

##### 8、综合示例

```shell
------------------example.sh----------------------
#! /bin/bash
echo "Staring program at $(date)"
echo "Running program $0 with $# argument with pid $$"

for file in "$@"; do
	grep foobar "$file" > /dev/null 2> /dev/null
	if [[ "$?" -ne 0 ]]; then
	  echo "File $file" does not have any foobar,adding one
	  echo "# foobar" >> "$file"
	fi
done
--------------------cmd----------------------------
>> source example.sh  mcd.sh example.sh 
Staring program at Thu 12 Aug 2021 04:21:02 PM CST
Running program bash with 2 argument with pid 1280
File mcd.sh does not have any foobar,adding one

```

##### 9、ls

```
>>touch a.sh a1.sh//匹配后缀
>>ls *sh
a.sh a1.sh
>>ls a*//匹配前缀
a.sh a1.sh
```

##### 10、Tools

```
shellcheck
tree
nnn
tldr 
sudo apt-get install tldr/nnn/tree
```

##### 11、find

```shell
#在当前目录下查找所有名称为src的文件夹
find . -name src -type d
#查找前一天内容被修改的所有文件
find . -mtime -1
#查找所有文件在500k至10M的tar.gz文件
find . -size +500k -size -10M -name '*.tar.gz'
#删除全部扩展名为.tmp的文件,{}两边需要加空格
find . -name '*.tmp' -exec rm {} \;
#查找全部的PNG文件并转换为JPG
find . -name '*.png' - exec convert {} {}.jpg \;
```

##### 12、execise

```shell
ls -a -h -t --color=auto
#-a输出所有文件，包括隐藏文件
#-h以人类可以理解的格式输出
#-t文件以最近访问顺序排序
#--color==auto以彩色文本形式输出
```

```shell
--------------------------------------------marco.sh------------------
#!/bin/bash
 marco(){
     echo "$(pwd)" > $HOME/marco_history.log
     echo "save pwd $(pwd)"
 }
 polo(){
     cd "$(cat "$HOME/marco_history.log")"
 }
 -----------------cmd-----------------
>>source marco.sh
>>marco
 /home/icf/Desktop/test
>>cd
>>polo
```

- 终端中连续按两次tab，可以显示匹配到前缀的命令
- 只能在同一个窗口执行
- $HOME,注意要大写且不用加括号

```shell
#---------buggy
#!/usr/bin/env bash
n=$(( RANDOM % 100 ))
if [[ n -eq 42 ]]; then
	echo "Something went wrong"
	>&2 echo "The error was using magic numbers"
	exit 1
fi
echo "Everything went according to plan"
#---------debug
"#!/usr/bin"
while true
do
	./buggy.sh 2> l.log
	if [[ $? -ne 0 ]]; then
		echo "failed after $count time"
		cat l.log
		break;
	fi
	((count++))	
done
```

- 可以使用shellcheck来查错
- if前面需要加上空格
- **>&2** 也就是把结果输出到和标准错误一样；之前如果有定义标准错误重定向到某file文件，那么标准输出也重定向到这个file文件。
        其中&的意思，可以看成是“The same as”、“与...一样”的意思

```shell
mkdir html_root
cd html_root
touch {1..10}.html
mkdir yyds
cd yyds
touch xx.html  i .html
find . -type f -name "*.html" | xargs -d '\n' tar -cvzf html.zip #表示当前目录以及子目录 -d '\n'将参数的分隔符设置为'\n'而不是默认的space
```

```
find . -type f -print0 | xargs -0 ls -lt | head -1 # 找到最近修改的文件
```

- xargs识别字符段的标识是空格或者换行符，所以如果一个文件名里有空格或者换行符，xargs就会把它识别成两个字符串
- find -print0表示在find的每一个结果之后加一个NULL字符，而不是默认加一个换行符。find的默认在每一个结果后加一个'\n'，所以输出结果是一行一行的。
- xargs -0表示xargs用NULL来作为分隔符。这样前后搭配就不会出现空格和换行符的错误了。选择NULL做分隔符，是因为一般编程语言把NULL作为字符串结束的标志，所以文件名不可能以NULL结尾，这样确保万无一失

### 4、vim

```shell
>>vim mcd.sh
//i表示插入
	mcd(){
		mkdir -p "$1"
		cd ”$1“
	}
//退出先按ese
	//[:q!]退出且不保存
	//[:wq]保存并退出
//加载文件到source
	source mcd.sh//1
	. mcd.sh//2
//执行定义的函数
	mcd yyds
//-----------------------------------------命令行中的输入-----------------------------
vim mcd.sh
...编辑函数
...mcd(){
...    mkdir -p "$1"
...    cd "$1"
...}
source mcd.sh
mcd test
```

- 删除全部的文件

  ```shell
  :0,$d 
  ```

  