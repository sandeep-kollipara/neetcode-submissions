-- Write your query below
select c.customer_id, d.customer_name from
(select customer_id from 
(select a.customer_id from
(select distinct customer_id from orders where product_name = 'A') a
inner join (select distinct customer_id from orders where product_name = 'B') b
on a.customer_id = b.customer_id)
except
(select distinct customer_id from orders where product_name = 'C')) c
left join customers d on c.customer_id = d.customer_id
order by customer_name;