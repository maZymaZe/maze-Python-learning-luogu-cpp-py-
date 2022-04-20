select distinct viewer_id as id
from views
where viewer_id=author_id
order by id