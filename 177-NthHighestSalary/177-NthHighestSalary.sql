-- Last updated: 13/07/2026, 22:24:52
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N - 1;
RETURN (
        SELECT
            DISTINCT(salary)
        FROM
            Employee
        ORDER BY
            Salary DESC
        LIMIT 1 OFFSET N
);
END