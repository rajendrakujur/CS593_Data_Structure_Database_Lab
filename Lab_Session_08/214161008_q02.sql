-- Second part
create view dept_summary(D, C, total_s, average_s)
as select dept_no, count(*), sum(salary), avg(salary)
from employee
group by dept_no;

-- 
select * from dept_summary;

-- 
select D, C
from dept_summary
where total_s > 100000

-- 
select D, average_s
from dept_summary
where C > (
    select C
    from dept_summary
    where D = 4
);

-- 
update dept_summary 
set D = 3 
where D = 4;

-- 
delete from dept_summary
where C > 4;
