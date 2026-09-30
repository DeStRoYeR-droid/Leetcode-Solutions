-- Last updated: 30/09/2026, 18:35:49
# Write your MySQL query statement below
SELECT
    x,
    y,
    z,
    IF (x + y + z - GREATEST(x, y, z) > GREATEST(x, y, z), "Yes", "No") AS "triangle"
FROM
    Triangle;