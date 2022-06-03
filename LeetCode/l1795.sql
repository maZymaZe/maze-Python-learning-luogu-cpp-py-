select product_id,store,price from(
    select product_id,store1 as price,'store1' as store
    from Products
    union all
    select product_id,store2 as price,'store2' as store
    from Products
    union all
    select product_id,store3 as price,'store3' as store
    from Products
)as t
where price is not null