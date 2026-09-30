-- Last updated: 30/09/2026, 18:31:55
# Write your MySQL query statement below
SELECT
    p.product_name,
    s.year, 
    s.price
FROM 
    Sales s JOIN Product p 
ON
    s.product_id = p.product_id;