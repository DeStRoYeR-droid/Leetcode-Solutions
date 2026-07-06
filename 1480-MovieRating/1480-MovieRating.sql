-- Last updated: 06/07/2026, 19:03:41
# Write your MySQL query statement below
(SELECT u.name AS results
FROM MovieRating m
JOIN Users u ON m.user_id = u.user_id
GROUP BY m.user_id, u.name
ORDER BY count(*) desc, u.name
LIMIT 1)

UNION ALL

(SELECT mo.title AS results
FROM MovieRating m
JOIN Movies mo ON m.movie_id = mo.movie_id
WHERE created_at LIKE '2020-02%'
GROUP BY mo.movie_id, mo.title
ORDER BY AVG(rating) desc, mo.title
LIMIT 1)