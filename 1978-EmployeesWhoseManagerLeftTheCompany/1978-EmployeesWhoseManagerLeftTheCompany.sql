-- Last updated: 07/09/2026, 22:52:33
# Write your MySQL query statement below
SELECT
    employee_id
FROM
    Employees
WHERE
    salary < 30000 AND
    manager_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY employee_id;