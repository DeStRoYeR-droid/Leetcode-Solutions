-- Last updated: 13/07/2026, 22:24:46
# Write your MySQL query statement below
SELECT 
    e2.name AS Employee
FROM 
    Employee e1
INNER JOIN
    Employee e2 ON e1.ID = e2.managerID
WHERE e1.salary < e2.salary;
