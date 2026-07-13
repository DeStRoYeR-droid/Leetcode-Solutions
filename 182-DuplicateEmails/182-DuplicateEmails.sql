-- Last updated: 13/07/2026, 22:24:44
# Write your MySQL query statement below
SELECT email FROM Person GROUP BY email HAVING COUNT(*) > 1;