<!--
 Copyright 2021 icf
 
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

# basic api
- malloc
- free
- calloc
- realloc
- sbrk

## 分配器满足的要求
- 处理任意请求序列
- 立即响应请求
- 只会使用堆
- 对齐块
- 不修改已分配块

## 优化目标
- 最大化吞吐率
  1）分配请求的最坏运行时间与空闲块成线性关系
  2）释放内存为常数时间
- 最大化内存利用率
  1)内存并非无限大..

## 碎片
- 内部碎片
  1）定量
  2）有效的payload/已经分配的内存
- 外部碎片
  1）需要新分配的请求，难以装下新的请求

## 实现一个内存分配器


