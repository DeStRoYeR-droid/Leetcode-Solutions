-- Last updated: 06/07/2026, 18:59:29
# Write your MySQL query statement below
SELECT
    employee_id
FROM
    Employees
WHERE
    salary < 30000 AND
    manager_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY employee_id;