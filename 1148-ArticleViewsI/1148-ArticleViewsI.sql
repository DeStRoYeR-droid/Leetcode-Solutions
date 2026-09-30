-- Last updated: 30/09/2026, 18:31:12
# Write your MySQL query statement below
SELECT
    DISTINCT author_id AS "id"
FROM
    Views
WHERE
    viewer_id = author_id
ORDER BY
    author_id;