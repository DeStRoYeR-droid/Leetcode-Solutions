-- Last updated: 13/07/2026, 22:17:59
# Write your MySQL query statement below
SELECT 
    class
FROM
    Courses
GROUP BY class
HAVING COUNT(*) >= 5;