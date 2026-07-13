-- Last updated: 13/07/2026, 22:24:09
# Write your MySQL query statement below
DELETE FROM 
    Person
WHERE 
    id NOT IN (
    SELECT id
    FROM (
        SELECT min(id) AS id
        FROM Person
        GROUP BY email
    ) TEMP
);