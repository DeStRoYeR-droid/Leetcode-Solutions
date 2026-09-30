-- Last updated: 30/09/2026, 18:27:24
SELECT 
    v.customer_id, 
    COUNT(v.visit_id) AS count_no_trans 
FROM 
    Visits v LEFT JOIN Transactions t 
ON 
    v.visit_id = t.visit_id  
WHERE 
    t.amount IS NULL 
GROUP BY 
    v.customer_id; 