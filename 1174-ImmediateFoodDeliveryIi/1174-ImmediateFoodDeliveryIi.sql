-- Last updated: 30/09/2026, 18:31:00
# Write your MySQL query statement below
SELECT
    ROUND(100 * SUM(IF(d.order_date = d.customer_pref_delivery_date, 1, 0)) / COUNT(DISTINCT d.customer_id), 2) AS "immediate_percentage"   
FROM
    Delivery d
WHERE
    (d.customer_id, d.order_date) IN (SELECT customer_id, MIN(order_date) FROM Delivery GROUP BY customer_id);