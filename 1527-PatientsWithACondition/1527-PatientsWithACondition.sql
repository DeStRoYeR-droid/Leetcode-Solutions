-- Last updated: 30/09/2026, 18:27:43
# Write your MySQL query statement below
SELECT
    *
FROM 
    Patients
WHERE
    conditions LIKE "DIAB1%" OR conditions LIKE "% DIAB1%";