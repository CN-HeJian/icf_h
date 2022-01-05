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

- ```sql
   SELECT AVG(product) AS avg_price FROM sele;
    SELECT COUNT(*) AS num_cust FROM sele;
    SELECT MAX(product) AS max_price FROM sele;
    SELECT MIN(product) AS min_price FROM sele;
    SELECT SUM(product) AS items_ordered FROM sele;
    SELECT COUNT(*) AS num_items,MIN(product) AS price_min,MAX(product) AS price_max,AVG(product) AS price_avg FROM sele;
  ```