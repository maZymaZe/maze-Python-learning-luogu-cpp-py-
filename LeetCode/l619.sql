select max(num)as num 
from (
    select num from my_numbers
    group by num
    having count(*)=1) as t
;