select player_id,MIN(event_date) AS first_login
from Activity
group by player_id;