# Write your MySQL query statement below
select T.request_at as `Day`,
    round(sum(if(T.Status='completed',0,1))/count(T.Status),2)
as `Cancellation Rate`
from trips as T 
where T.Client_id not in
(
    select users_id from users where banned='Yes'
)and T.Driver_id not in
(
    select users_id from users where banned='Yes'
)
and T.request_at between '2013-10-01' and '2013-10-03'
group by T.request_at;