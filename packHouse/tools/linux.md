1、Linux下默认的文件描述符为1024、通过下面的命令查看：

```
ulimit -n
```

2、修改文件描述符号

```
1）vim /etc/security/limits.conf
2）在文件最后一行添加 * - nofile 4096
```

```
#*               soft    core            0
#root            hard    core            100000
#*               hard    rss             10000
#@student        hard    nproc           20
#@faculty        soft    nproc           20
#@faculty        hard    nproc           50
#ftp             hard    nproc           0
#ftp             -       chroot          /ftp
#@student        -       maxlogins       4

* -nofile 4096

# End of file
```

3、修改后不能保存

```
强制退出，启用sudo
:q！
sudo vim **
```

