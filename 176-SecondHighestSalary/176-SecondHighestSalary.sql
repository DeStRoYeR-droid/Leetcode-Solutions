-- Last updated: 13/07/2026, 22:24:56
# Write your MySQL query statement below
SELECT
    (
        SELECT 
            DISTINCT Salary 
        FROM 
            EMPLOYEE
        ORDER BY
            SALARY DESC
        LIMIT 1 OFFSET 1
    )
    as SecondHighestSalary;