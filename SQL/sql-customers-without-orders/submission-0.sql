-- Write your query below
select name from
(select a.id, a.name, b.id as order_id from customers a 
left join orders b 
on a.id = b.customer_id)
where order_id is null;