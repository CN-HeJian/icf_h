// Copyright 2021 icf
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <boost/type_index.hpp>

using namespace std;
using boost::typeindex::type_id_with_cvr;  

template<typename T>
void PrintType(T&& param)
{
    // 利用Boost库打印模板推导出来的 T 类型
	cout << "T type：" << type_id_with_cvr<T>().pretty_name() << endl; 
    
    // 利用Boost库打印形参的类型
	cout << "param type:" << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}

int main(int argc, char *argv[])
{
	int a = 0;                              // 左值
	PrintType(a);                           // 传入左值

	int &lvalue_refence_a = a;              // 左值引用
	PrintType(lvalue_refence_a);            // 传入左值引用

	PrintType(int(2));                      // 传入右值
}
