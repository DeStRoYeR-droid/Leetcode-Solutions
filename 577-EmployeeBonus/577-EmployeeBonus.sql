-- Last updated: 30/09/2026, 18:36:11
SELECT 
    e.name AS "name",
    b.bonus AS "bonus"
FROM
    Employee e LEFT JOIN Bonus b ON e.empId = b.empId
WHERE
    b.bonus < 1000 OR b.bonus IS NULL;