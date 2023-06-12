# Write your MySQL query statement below
# with cnt as ()
select customer_id from customer group by customer_id having count(distinct(product_key)) in (select count(product_key) from product);