# Write your MySQL query statement below

# with abc as (select min(year) from sales where product_id = s.product_id group by product_id)
# select s.product_id, s.year as first_year, s.quantity, s.price from sales s inner join product p on s.product_id = p.product_id where s.year in abc

WITH abc AS(
  select s.product_id,min(s.year) as year from sales s,product p
  where s.product_id=p.product_id
  group by s.product_id
)
select s.product_id,s.year as first_year,s.quantity,s.price
from sales s,abc a
where s.product_id=a.product_id and s.year=a.year