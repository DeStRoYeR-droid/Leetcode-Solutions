-- Last updated: 30/09/2026, 18:25:47
# Write your MySQL query statement below
SELECT
    product_id
FROM 
    Products
WHERE
    low_fats = 'Y' AND recyclable = 'Y';