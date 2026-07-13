-- Last updated: 13/07/2026, 22:18:02
# Write your MySQL query statement below
SELECT 
    name, population, area
FROM 
    World
WHERE
    area >= 3000000 OR population >= 25000000;