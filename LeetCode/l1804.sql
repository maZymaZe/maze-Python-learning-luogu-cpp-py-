# Write your MySQL query statement below
SELECT 
    s.product_id, p.product_name
FROM 
    sales s
LEFT JOIN 
    product p 
ON 
    s.product_id = p.product_id
GROUP BY 
    s.product_id
HAVING MIN(sale_date) >= '2019-01-01' 
AND MAX(sale_date) <= '2019-03-31';
