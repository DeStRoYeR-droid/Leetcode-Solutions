-- Last updated: 30/09/2026, 18:26:37
# Write your MySQL query statement below
SELECT 
    user_id,
    CONCAT(UPPER(LEFT(name, 1)), LOWER(SUBSTRING(name, 2))) AS "name"
FROM
    Users
ORDER BY
    user_id;