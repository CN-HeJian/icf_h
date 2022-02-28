<!--
 Copyright 2022 icf
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
     http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
-->

tcp/udp
---tcp是可靠的、面向字节流的传输层协议，而udp协议是不可靠的、面向数据包的协议
---tcp实现可靠传输协议需要三次握手，和四次挥手、以及传输过程中的流量控制、拥塞控制、超时重传、校验和等机制实现
---三次握手过程
---四次挥手过程
---Tcp头部的实现




map/unordered_map


c++特性
继承/多态/封装

进程间通信!!!
管道/消息队列/共享内存/信号量/信号/socket套接字

反转链表!!!

冒泡排序!!!

快速排序!!!

归并排序！！！

介绍项目



自我介绍

面试官，您好，我是贺鉴，现在华中科技大学材料学院研二在读，本科也是毕业于华中科技大学材料学院。
我最早与编程接触是大一学习了C++，后来在大三的时候参加了全国大学生机器人大赛，因为做机器人控制相关的经历，让我对编程很感兴趣。
在研究生阶段做了一个企业合作的项目，在项目中学习了新的知识，进一步加深了对计算机基础知识的理解。
为了进一步提升自己，我期望能够找到一份C++开发的暑期实习，让自己在编程的路上走得更远。





项目相关的问题

c++多态
lru

页面置换算法（最近）

(FIFO)先进先出
LRU (淘汰最长时间未访问的页面)
LFU（淘汰最近使用频率最少的）

select epoll poll
静态链接、动态链接

设计模式
单例模式！！！
观察者模式
工厂模式

学过什么课程、怎么学习

深入理解计算机系统，操作系统导论
计算机网络自定向下
linux高性能服务器编程
平时会做做题
在项目中学习



空间配置器（X）



五层模型以及每一层对应的协议

accept bind listen recv send
//将文件描述符和对应的ip、port做绑定
bind(int sockfd,const struct sockaddr,socklen_t addrlen);

//主动连接的套接字变成被连接的套接字，使进程变成一个服务器进程，半连接队列的长度
listen(int sockfd，int backlog)

//write成功返回，将buf中的数据被复制到了kernel中的Tcp发送缓冲区
//write发生阻塞？当kernel中该socket的发送缓冲区已经满时，对于每个socket，都拥有自己的send_buffer和receive_buff，一般来说，由于接收端进程从socket读数据的速度更跟不上发送段进程向socket写数据的速度,最终导致发送端调用阻塞
//https://www.cnblogs.com/wuchanming/p/3783650.html
ssize_t write(int fd,const void* buf,size_t count)
blocking中的write只有在缓冲区放下真个buffer时才返回
nonblock write则是返回能够放下的字节数

read()
read总是在接收缓冲区有数据时立即返回，而不是等到给定的read buffer填满时才返回
只有当receive buffer为空时，blocking 模式才会等待，nonblock模式会返回-1


accept()

//对于客户端的connect函数，该函数的功能是客户端主动连接服务器，建立连接是通过三次握手
而这个连接是通过内核完成的
connect()


数据包的传递流程
应用层、传输层、网络层、链路层、物理层

最满意的项目!!
看什么书籍

社会实践队伍：
主要是调研渝新欧国际铁路的崛起，这条线路是从重庆开往欧洲，连接了亚欧大陆。
渝新欧国际铁路在重庆市的领导下已经全线开通，但还处于发展阶段，仍然有需要亟待解决的问题，我们对调研出来的问题提出了自己的理解和建议。
最大的感想就是伟大的事业并不是一簇即成的，而是在实现过程中不断迭代出来的。


1）宣传力度比较小，周围的居民对物流站的工作不太了解，也不了解一带一路的建设
2）由于渝新欧铁路取得了成功，内陆各个城市争夺中欧铁路起点，恶行竞争，造成资源浪费
3）回程货源不足，大部分都是出口，而回城运载率较低

