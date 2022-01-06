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

### 使用子查询
- ```sql
    //利用子查询进行过滤
    SELECT order_num FROM OrderItems WHERE prod_id = 'RGAN01';  //找到订单编号
    SELECT cust_id FROM Orders WHERE order_num IN (2007,2008);  //找到顾客id
    SELECT cust_name, cust_contact FROM Customers WHERE cust_id IN ('10000004','10000005') //找到顾客具体信息
    //将前两句嵌套
    SELECT cust_id FROM Orders WHERE order_num IN (SELECT order_num FROM OrderItems WHERE prod_id = 'RGAN01');
    //三句嵌套
    SELECT cust_name,cust_contact FROM Customers WHERE cust_id IN(
        SELECT cust_id FROM Orders WHERE order_num IN (
            SELECT order_num FROM OrderItems HWERE prod_id = 'RGAN01'
        )
    );
    //以下为SQLILE语句
    SELECT date,OPT2PeakToPack from MACH08 WHERE OPT2PeakToPack == 3 AND date IN (select date from MACH08 ORDER BY DESC LIMIT 500);
    //作为计算字段使用子查询
    SELECT COUNT(*) AS orders FROM Orders WHERE cust_id = '10000001';
    SELECT cust_name,cust_state,(SELECT COUNT(*) FROM Orders WHERE Orders.cust_id = Customers.cust_id) AS orders FROM Customers ORDER BY cust_name;

    ```

### 联结表
- ```sql
    //关系表：商品名和供应商信息成两个表，供应商表中的供应商ID为主键，产品表中只存储与供应商表的供应商ID，对数据做一部分限制，只允许存在供货商表中的供应商产品存入产品表
    SELECT vend_name,prod_name,prod_price FROM Vendors,Products WHERE Vendors.vend_id = Products.vend_id;
    //在联结两个表时，实际要做的是将第一个表中的每一行与第二个表中的每一行配对,WHERE语句作为过滤条件，只包含那些匹配给定条件(这里是联结条件)的行，没有WHERE筛选的话就是笛卡尔积
    SELECT vend_name,prod_name,prod_price FROM Vendors,Products
    //内联结
    SELECT vend_name,prod_anme,prod_price FROM Vendors INNER JOIN Products ON Vendors.vend_id = Products.vend_id;
    //联结多个表
    SELECT Prod_name,vend_name,prod_price,quantity FROM OrderItems,Products,Vendors WHERE Products.vend_id = Vendors.vend_id AND OrderItems.PROD_ID = Products.prod_id AND order_num = 2007;
    //使用联结表替换子查询
    SELECT cust_name,cust_contact FROM Customers WHERE cust_id IN (
        SELECT cust_id FROM Orders WHERE order_num IN(
            SELECT order_num FROM OrderItems WHERE prod_id = 'RGAN01'
        )
    );
    SELECT cust_name,cust_contact FROM Customers,Orders,OrderItems WHERE Customers.cust_id = Orders.cust_id AND OrderItems.order_num = Orders.order_num AND prod_id = 'RGAN01'
    ```

### 创建高级联结
- ```sql 
    SELECT PTRIM(vend_name)+'('+RTRIM(vend_country)+')' AS vend_title FROM Vendors ORDER BY vend_name;
    SELECT cust_name,cust_contact FROM Customers AS C,Orders AS O,orderItems AS OI WHERE C.cust_id = O.cust_id AND OI.order_num = O.order_num AND prod_id = 'RGAN01';
    ```
