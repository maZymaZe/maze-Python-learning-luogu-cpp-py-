select customer_number
from orders
group by customer_number order by count(*)DESC limit 1;