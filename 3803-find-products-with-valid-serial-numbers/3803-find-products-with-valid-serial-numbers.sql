# Write your MySQL query statement below
select product_id,product_name,description 
from products 
where regexp_like(description,"\\bSN[0-9]{4}-[0-9]{4}\\b",'c')
order by 1