select
    sell_date,
    count(distinct product) num_sold,
    GROUP_CONCAT(distinct product) products
from
    activities
group by sell_date
order by sell_date;
