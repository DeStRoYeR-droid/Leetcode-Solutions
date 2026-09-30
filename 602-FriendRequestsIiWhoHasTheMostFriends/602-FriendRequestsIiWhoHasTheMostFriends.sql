-- Last updated: 30/09/2026, 18:35:54
# Write your MySQL query statement below
WITH BASE AS (
    SELECT requester_id id FROM RequestAccepted UNION ALL
    SELECT accepter_id id FROM RequestAccepted
)

SELECT id, COUNT(*) as "num" FROM BASE GROUP BY 1 ORDER BY 2 DESC LIMIT 1;