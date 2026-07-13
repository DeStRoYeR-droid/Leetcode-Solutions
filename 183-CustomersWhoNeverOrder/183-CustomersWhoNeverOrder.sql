-- Last updated: 13/07/2026, 22:24:32
# Write your MySQL query statement below
SELECT
    name AS "Customers"
FROM 
    Customers
WHERE
    id NOT IN (
        SELECT 
            DISTINCT(customerId)
        FROM Orders
    )