-- Last updated: 13/07/2026, 22:18:15
# Write your MySQL query statement below
SELECT 
    name
FROM
    Customer
WHERE
    referee_id IS NULL OR
    referee_id != 2;