-- Last updated: 30/09/2026, 18:29:35
# Write your MySQL query statement below
SELECT
    DISTINCT visited_on,
    SUM(AMOUNT) OVER w AS "amount",
    ROUND((SUM(AMOUNT) OVER w)/7, 2) AS "average_amount"
FROM
    Customer
    WINDOW w AS (
        ORDER BY visited_on
        RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW
    )
    LIMIT 6, 999