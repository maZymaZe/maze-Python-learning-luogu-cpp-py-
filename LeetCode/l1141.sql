select activity_date AS day,count(DISTINCT user_id) AS active_users
from Activity
where datediff('2019-07-27',activity_date)<30
Group by activity_date