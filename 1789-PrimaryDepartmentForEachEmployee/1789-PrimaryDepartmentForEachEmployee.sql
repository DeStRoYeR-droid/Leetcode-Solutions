-- Last updated: 30/09/2026, 18:25:33
# Write your MySQL query statement below
SELECT 
    employee_id,
    department_id
FROM 
    Employee
WHERE
    primary_flag = 'Y'
UNION
SELECT 
    employee_id, department_id
FROM 
    Employee
GROUP BY 
    employee_id
HAVING 
    COUNT(*)=1;