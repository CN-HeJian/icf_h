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

### 汇总数据

- ```sql
    SELECT AVG(product) AS avg_price FROM sele;
    SELECT COUNT(*) AS num_cust FROM sele;
    SELECT MAX(product) AS max_price FROM sele;
    SELECT MIN(product) AS min_price FROM sele;
    SELECT SUM(product) AS items_ordered FROM sele;
    SELECT COUNT(*) AS num_items,MIN(product) AS price_min,MAX(product) AS price_max,AVG(product) AS price_avg FROM sele;
    ```

### 分组数据

- ```sql
    //数据分组
    SELECT COUNT(*) AS num_prods FROM sele WHERE product = 'DLL01';
    //创建分组
    SELECT product, COUNT(product) AS num_prods FROM sele GROUP BY product;
    //过滤分组,WHERE过滤行、HAVING 过滤分组
    SELECT cust_id,COUNT(*) AS orders FROM Orders GROUP BY cust_id HAVING COUNT(*)>=2;
    //列出具有两个以上产品且其价格大于等于4的供应商
    SELECT vend_id,COUNT(*) AS num_prods FROM Products WHERE prod_price>=4 GROUP BY vend_id HAVING COUNT(*)>=2
    //分组与排序,默认排序方法为升序排序
    SELECT order_num,COUNT(*) AS items FROM OrderItems GROUP BY order_num HAVING COUNT(*)>=3 ORDER BY items ,order_num
    //语句执行顺序
    SELECT -> FROM -> WHERE -> GROUP BY -> HAVING -> ORDER BY
    ```