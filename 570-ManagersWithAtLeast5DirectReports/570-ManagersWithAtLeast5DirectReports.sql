-- Last updated: 13/07/2026, 22:18:20
# Write your MySQL query statement below
SELECT
    name
FROM
    Employee
WHERE 
    id IN (
        SELECT 
            managerId 
        FROM 
            Employee 
        GROUP BY managerId
        HAVING COUNT(managerId) >= 5
);