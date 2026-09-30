-- Last updated: 30/09/2026, 18:30:38
# Write your MySQL query statement below
SELECT 
    person_name
FROM
    (
        SELECT *, SUM(weight) OVER(ORDER BY turn) as total_weight FROM queue
    ) q
WHERE total_weight <= 1000
ORDER BY total_weight DESC
LIMIT 1;