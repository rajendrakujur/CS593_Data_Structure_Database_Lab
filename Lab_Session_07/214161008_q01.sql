-- Create Database
create database 214161008_02;

-- Use the database
use 214161008_02;

-- Create employee table
create table employee
(
    employee_id integer not null,
    employee_name varchar(30),
    salary_in_USD float,
    primary key (employee_id),
    check (salary_in_USD >=500)
);

-- Create Aircraft Table
create table aircraft
(
    aircraft_id integer not null,
    aircraft_name varchar(30),
    cruising integer,
    primary key (aircraft_id)
);

-- Create Certified Table
create table certified
(
    aircraft_id integer,
    employee_id integer,
    primary key(aircraft_id,employee_id),
    foreign key (aircraft_id) references aircraft(aircraft_id),
    foreign key (employee_id) references employee(employee_id)
);

-- Create Flight Table 
create table flight
(
    flight_number integer not null,
    flight_from varchar(30),
    flight_to varchar(30),
    distance float,
    departs time,
    arrives time,
    price_in_USD float,
    aircraft_id integer not null,
    primary key (flight_number),
    foreign key (aircraft_id) references aircraft(aircraft_id)
);

-- Insertion into Employee table
insert into employee (employee_id, employee_name, salary_in_USD) values (1, 'Adam', 35000);
insert into employee (employee_id, employee_name, salary_in_USD) values (2, 'David', 90000);
insert into employee (employee_id, employee_name, salary_in_USD) values (3, 'Wilson', 48000);
insert into employee (employee_id, employee_name, salary_in_USD) values (4, 'Jonathan', 120000);
insert into employee (employee_id, employee_name, salary_in_USD) values (5, 'George', 110000);
insert into employee (employee_id, employee_name, salary_in_USD) values (6, 'Mathhew', 100000);
insert into employee (employee_id, employee_name, salary_in_USD) values (7, 'Kane', 75000);
insert into employee (employee_id, employee_name, salary_in_USD) values (8, 'Kevin', 80000);
insert into employee (employee_id, employee_name, salary_in_USD) values (9, 'Donald', 46500);
insert into employee (employee_id, employee_name, salary_in_USD) values (10, 'Mitchel', 52000);
insert into employee (employee_id, employee_name, salary_in_USD) values (11, 'Potter', 90000);
insert into employee (employee_id, employee_name, salary_in_USD) values (12, 'Andrew', 87000);
insert into employee (employee_id, employee_name, salary_in_USD) values (13, 'Elon', 105000);


-- Insertion into Aircraft table
insert into aircraft (aircraft_id, aircraft_name, cruising) values (1, 'Emirates', 3000);
insert into aircraft (aircraft_id, aircraft_name, cruising) values (2, 'Boeing', 3350);
insert into aircraft (aircraft_id, aircraft_name, cruising) values (3, 'Vistara', 800);
insert into aircraft (aircraft_id, aircraft_name, cruising) values (4, 'LATAM', 1000);
insert into aircraft (aircraft_id, aircraft_name, cruising) values (5, 'British Airways', 2800);
insert into aircraft (aircraft_id, aircraft_name, cruising) values (6, 'Air France', 3100);
insert into aircraft (aircraft_id, aircraft_name, cruising) values (7, 'Flynas', 3200);

-- Insertion into certified table
insert into certified (aircraft_id, employee_id) values (1, 2);
insert into certified (aircraft_id, employee_id) values (1, 1);
insert into certified (aircraft_id, employee_id) values (2, 4);
insert into certified (aircraft_id, employee_id) values (2, 3);
insert into certified (aircraft_id, employee_id) values (4, 4);
insert into certified (aircraft_id, employee_id) values (6, 2);
insert into certified (aircraft_id, employee_id) values (3, 2);
insert into certified (aircraft_id, employee_id) values (7, 4);
insert into certified (aircraft_id, employee_id) values (3, 6);
insert into certified (aircraft_id, employee_id) values (5, 5);
insert into certified (aircraft_id, employee_id) values (4, 2);
insert into certified (aircraft_id, employee_id) values (4, 5);
insert into certified (aircraft_id, employee_id) values (5, 6);
insert into certified (aircraft_id, employee_id) values (6, 5);
insert into certified (aircraft_id, employee_id) values (3, 1);
insert into certified (aircraft_id, employee_id) values (2, 2);
insert into certified (aircraft_id, employee_id) values (1, 8);
insert into certified (aircraft_id, employee_id) values (5, 3);
insert into certified (aircraft_id, employee_id) values (2, 9);
insert into certified (aircraft_id, employee_id) values (6, 8);
insert into certified (aircraft_id, employee_id) values (7, 8);

-- Insertion into Flight table
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (24, 'Los Angeles', 'Honolulu', 1500, '08:00:00', '12:00:00', 40000, 7);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (37, 'Madison', 'New York', 2200, '14:35:00', '17:00:00', 40000, 4);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (10, 'Honolulu', 'New York', 2450, '15:00:00', '17:40:00', 45000, 2);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (02, 'Los Angeles', 'Honolulu', 1850, '11:00:00', '13:00:00', 60000, 5);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (33, 'Madison', 'Los Angeles', 3100, '08:10:00', '10:00:00', 40200, 1);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (91, 'Los Angeles', 'Chicago', 905, '06:05:00', '07:10:00', 4800, 2);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (31, 'Madison', 'New York', 3100, '07:00:00', '15:15:00', 34000, 6);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (28, 'Los Angeles', 'Honolulu', 5000, '08:40:00', '13:20:00', 55000, 3);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (47, 'Madison', 'Dubai', 4820, '06:25:00', '12:15:00', 48000, 6);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (87, 'Los Angeles', 'Chicago', 4201, '10:00:00', '12:55:00', 2450, 5);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (50, 'Dubai', 'Chicago', 5400, '13:05:00', '15:20:00', 68000, 4);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (83, 'Chicago', 'New York', 2040, '16:00:00', '18:10:00', 15000, 1);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (4854, 'Madison', 'New York', 5485, '16:00:00', '18:10:00', 15000, 1);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (470, 'Dubai', 'New York', 6905, '13:20:00', '16:10:00', 24000, 3);
insert into flight (flight_number, flight_from, flight_to, distance, departs, arrives, price_in_USD, aircraft_id) values (85, 'Chicago', 'Los Angeles', 1205, '15:25:00', '21:15:00', 22580, 4);

-- Data in Employee Table 
select * from employee;

-- Data in Certified Table
select * from certified;

-- Data in Aircraft Table
select * from aircraft;

-- Data in Flight Table
select * from flight;

-- Schema Description of Employee Table 
describe employee;

-- Schema Description of Certified Table
describe certified;

-- Schema Description of Aircraft Table
describe aircraft;

-- Schema Description of Flight Table
describe flight;

-- (I) Find the names of aircraft such that all pilots certified to operate them have salaries more than $80,000.
-- Done

select aircraft_name 
from aircraft A
where not exists
(
    select *
    from certified C
    where C.aircraft_id = A.aircraft_id and 
    not exists
    (
        select *
        from employee E
        where E.salary_in_USD > 80000 and E.employee_id = C.employee_id
    )
);

-- (II) For each pilot who is certified for more than three aircraft, find the eid and the maximum cruising range of the aircraft for which she or he is certified.
-- Done

select certified.employee_id, max(aircraft.cruising)
from certified , aircraft
where certified.aircraft_id = aircraft.aircraft_id and certified.employee_id in 
(
    select employee_id
    from certified
    group by (employee_id)
    having count(aircraft_id) > 3
)
group by certified.employee_id;


-- (III) Find the names of pilots whose salary is less than the price of the cheapest route from Los Angeles to Honolulu.
-- Done

select employee_name
from employee
where employee_id in 
(
    select distinct employee_id
    from certified 
)
and salary_in_USD <
(   
    select min(price_in_USD)
    from flight
    where flight_from = 'Los Angeles' and flight_to = 'Honolulu'
);

-- (IV) For all aircraft with cruising range over 1000 miles, find the name of the aircraft and the average salary of all pilots certified for this aircraft.
-- Done

select A.aircraft_name, avg(E.salary_in_USD)
from aircraft A, certified Cer, employee E
where A.aircraft_id = Cer.aircraft_id and Cer.employee_id = E.employee_id and A.cruising > 1000
group by A.aircraft_id;


-- (V) Find the names of pilots certified for some Boeing aircraft.
-- Done

select employee_name
from employee
where employee_id in 
(
    select employee_id
    from certified
    where aircraft_id in 
    (
        select aircraft_id
        from aircraft
        where aircraft_name = 'Boeing'
    )
);

-- (VI) Find the aids of all aircraft that can be used on routes from Los Angeles to Chicago.
-- Done

select aircraft_id
from aircraft
where aircraft_id in 
(
    select aircraft_id
    from flight
    where flight_from = 'Los Angeles' and flight_to = 'Chicago'
);


-- (VII) Identify the routes that can be piloted by every pilot who makes more than $100,000.
-- Done

select distinct flight_from, flight_to
from flight
where aircraft_id in 
(
    select aircraft_id
    from certified
    where employee_id in 
    (
        select employee_id
        from employee
        where salary_in_USD > 100000
    )
);

-- (VIII) Print the enames of pilots who can operate planes with cruising range greater than 3000 miles but are not certified on any Boeing aircraft.
-- Done

select distinct employee_name
from employee
where employee_id in 
(
    select employee_id 
    from certified
    where aircraft_id in 
    (
        select aircraft_id
        from aircraft
        where cruising > 3000
    ) and 
    employee_id not in 
    (
        select employee_id 
        from certified
        where aircraft_id in
        (
            select aircraft_id
            from aircraft
            where aircraft_name = 'Boeing'
        )
    )
)

-- (IX) A customer wants to travel from Madison to New York with no more than two changes of flight. List the choice of departure times from Madison if the customer
-- wants to arrive in New York by 6 p.m.
-- Done

select departs as departure_time
from flight F
where (F.flight_from = 'Madison') and 
(
    (
        F.flight_to = 'New York' and F.arrives <= '18:00:00'
    ) 
    or 
    exists
    (
        select *
        from flight G
        where G.flight_from = F.flight_to and G.flight_to = 'New York' and F.arrives < G.departs and G.arrives <= '18:00:00'
    )
    or
    exists
    (
        select *
        from flight H
        where H.flight_from = F.flight_to and F.arrives < H.departs and H.arrives <= '18:00:00' and 
        exists
        (
            select *
            from flight I
            where I.flight_from = H.flight_to and I.flight_to = 'New York' and H.arrives < I.departs and I.arrives <= '18:00:00'
        )
    )
);


-- (X) Compute the difference between the average salary of a pilot and the average salary of all employees (including pilots).
-- Done

select all_employee.avg_of_all - pilots_only.avg_of_pilots as difference
from 
(
    select avg(salary_in_USD) as avg_of_all
    from employee
) all_employee,
(
    select avg(salary_in_USD) as avg_of_pilots
    from employee E
    where exists
    (
        select *
        from certified C
        where C.employee_id = E.employee_id
    )
) pilots_only;

-- (XI) Print the name and salary of every nonpilot whose salary is more than the average salary for pilots.
-- Done

select employee_name, salary_in_USD
from employee
where employee_id not in 
(
    select distinct E.employee_id
    from employee E, certified C
    where E.employee_id = C.employee_id
)
and salary_in_USD > 
(
    select avg(salary_in_USD)
    from employee M, certified R
    where M.employee_id = R.employee_id
);

-- (XII) Print the names of employees who are certified only on aircrafts with cruising range longer than 1000 miles.
-- Done

select employee_name
from employee E
where not exists
(
    select *
    from certified C
    where C.employee_id = E.employee_id and
    not exists
    (
        select aircraft_id
        from aircraft A
        where cruising > 1000 and C.aircraft_id = A.aircraft_id 
    )
) and exists
(
    select employee_id 
    from certified 
    where E.employee_id = certified.employee_id
);

-- (XIII) Print the names of employees who are certified only on aircrafts with cruising range longer than 1000 miles, but on at least two such aircrafts.
-- Done

select employee_name
from employee E
where not exists
(
    select *
    from certified C
    where C.employee_id = E.employee_id and
    not exists
    (
        select aircraft_id
        from aircraft A
        where cruising > 1000 and C.aircraft_id = A.aircraft_id 
    )
) and exists
(
    select employee_id, count(aircraft_id) 
    from certified 
    where E.employee_id = certified.employee_id
    group by employee_id
    having count(certified.aircraft_id) >= 2
);

-- (XIV) Print the names of employees who are certified only on aircrafts with cruising range longer than 1000 miles and who are certified on some Boeing aircraft.
-- Done

select employee_name
from employee E
where not exists
(
    select *
    from certified C
    where C.employee_id = E.employee_id and
    not exists
    (
        select aircraft_id
        from aircraft A
        where cruising > 1000 and C.aircraft_id = A.aircraft_id 
    )
) and 
exists
(
    select *
    from certified R
    where E.employee_id = R.employee_id and E.employee_id in 
    (
        select employee_id
        from aircraft A
        where  A.aircraft_id = R.aircraft_id and A.aircraft_name = 'Boeing'
    )
);

-- Testing Phase

select distinct K.sid
from supplier K
where not exists
(
    select *
    from parts P
    where not exists
    (
        select pid 
        from supplier S
        where S.sid = K.sid and P.pid = S.pid
    )
);
