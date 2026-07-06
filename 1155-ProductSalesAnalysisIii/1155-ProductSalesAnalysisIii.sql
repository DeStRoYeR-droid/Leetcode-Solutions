-- Last updated: 06/07/2026, 19:05:51
# Write your MySQL query statement below
SELECT 
    product_id, year as first_year, quantity, price 
FROM sales
WHERE (product_id, year) IN 
(select distinct product_id, min(year) from sales group by product_id)