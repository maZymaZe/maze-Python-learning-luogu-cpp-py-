# Write your MySQL query statement below
SELECT name,
    SUM(t1.amount) AS balance
FROM Transactions AS t1
    INNER JOIN Users AS u1
    ON t1.account = u1.account
GROUP BY u1.account
HAVING SUM(t1.amount) > 10000;

