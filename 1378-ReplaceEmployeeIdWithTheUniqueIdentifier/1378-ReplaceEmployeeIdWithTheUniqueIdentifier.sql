-- Last updated: 30/09/2026, 18:29:03
# Write your MySQL query statement below
SELECT
    eu.unique_id AS "unique_id",
    e.name AS "name"
FROM 
    Employees e LEFT JOIN EmployeeUNI eu
ON
    e.id = eu.id;