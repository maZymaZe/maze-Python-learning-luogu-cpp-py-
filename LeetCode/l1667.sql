select user_id, concat(upper(left(name,1)), lower(right(name,length(name)-1))) as name 
from Users
order by user_id