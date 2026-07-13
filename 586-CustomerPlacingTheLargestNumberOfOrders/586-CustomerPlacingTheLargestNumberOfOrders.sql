-- Last updated: 13/07/2026, 22:18:07
# Write your MySQL query statement below
SELECT
    customer_number
FROM 
    Orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;