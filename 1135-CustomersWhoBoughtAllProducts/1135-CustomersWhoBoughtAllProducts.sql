-- Last updated: 06/07/2026, 19:05:55
# Write your MySQL query statement below
SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(product_key) FROM Product);