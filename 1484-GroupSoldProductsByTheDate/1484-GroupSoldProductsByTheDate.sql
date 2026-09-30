-- Last updated: 30/09/2026, 18:28:05
# Write your MySQL query statement below
SELECT
    sell_date,
    COUNT(DISTINCT product) AS "num_sold",
    GROUP_CONCAT(DISTINCT product ORDER BY product) AS "products"
FROM 
    Activities
GROUP BY
    sell_date
ORDER BY
    sell_date;