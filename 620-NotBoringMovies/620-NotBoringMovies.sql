-- Last updated: 13/07/2026, 22:17:49
# Write your MySQL query statement below
SELECT 
    *
FROM 
    Cinema
WHERE
    id % 2 != 0 AND
    description != 'boring'
ORDER BY rating DESC;