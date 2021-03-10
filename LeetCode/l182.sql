# Write your MySQL query statement below
select distinct X.Email
from Person as X,Person as Y
where X.Email = Y.Email and X.Id != Y.Id;