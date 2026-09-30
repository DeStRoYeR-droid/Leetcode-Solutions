-- Last updated: 30/09/2026, 18:30:32
# Write your MySQL query statement below
SELECT
    query_name,
    ROUND(AVG(CAST(rating AS DECIMAL) / position), 2) AS "quality",
    ROUND(SUM(CASE WHEN rating < 3 THEn 1 ELSE 0 end) * 100 / COUNT(*), 2) AS "poor_query_percentage"
FROM
    queries
GROUP BY
    query_name;