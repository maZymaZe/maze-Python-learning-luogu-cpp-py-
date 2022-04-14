select atree.id,if(isnull(atree.p_id),'Root',
if(atree.id in(select p_id from tree),'Inner','Leaf'))type
from tree atree
order by atree.id