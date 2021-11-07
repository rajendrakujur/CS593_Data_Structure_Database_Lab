create database 214161008_03;

use 214161008_03;

-- employee Table Creation
create table employee
(
    first_name varchar(30) not null,
    middle_name varchar(30),
    last_name varchar(30),
    ssn integer,
    birth_date date,
    address varchar(30),
    sex char(1),
    salary integer,
    super_ssn integer,
    dept_no integer,
    primary key (ssn),
    check (sex in ('M' ,'F'))
);

-- department Table Creation
create table department
(
    dept_name varchar(30),
    dept_no integer,
    mgr_ssn integer,
    mgr_start_date date,
    primary key (dept_no),
    foreign key (mgr_ssn) references employee(ssn)
);

alter table employee
add foreign key (dept_no) references department(dept_no);
    
alter table employee
add foreign key (super_ssn) references employee(ssn);

-- Dept. Locations Table Creation
create table department_location
(
    dept_no integer,
    location varchar(30),
    primary key (dept_no, location),
    foreign key (dept_no) references department(dept_no)
);

-- project Table Creation
create table project
(
    project_name varchar(30),
    project_no integer,
    project_location varchar(30),
    dept_no integer,
    primary key (project_no),
    foreign key (dept_no) references department(dept_no)
);

-- works_on Table Creation
create table works_on
(
    employee_ssn integer,
    project_no integer,
    hours float,
    primary key (employee_ssn, project_no)
);

-- dependent Table Creation
create table dependent
(
    employee_ssn integer,
    dependent_name varchar(30),
    sex char(1),
    birth_date date,
    relationship varchar(10),
    primary key (employee_ssn),
    check (relationship='Spouse' or relationship='Child' or relationship = 'Parent'),
    foreign key (employee_ssn) references employee(ssn)
);

-- Insert into employee
insert into employee (first_name, middle_name, last_name, ssn, birth_date, address, sex, salary, super_ssn, dept_no) values ('John', 'B', 'Smith', 123456789, '1965-01-09', '731 Fondren, Houston, TX', 'M', 6500, 999887777,5);
insert into employee (first_name, middle_name, last_name, ssn, birth_date, address, sex, salary, super_ssn, dept_no) values ('Franklin', 'T', 'Wong', 333445555,  '1955-12-08', '638 Voss, Hoston, TX', 'M', 8000, 987654321, 5);
insert into employee (first_name, middle_name, last_name, ssn, birth_date, address, sex, salary, super_ssn, dept_no) values ('Alicia', 'J', 'Zelaya', 999887777, '1968-07-19', '3321 Castle, Spring, TX', 'F', 7200, 888665555, 4);
insert into employee (first_name, middle_name, last_name, ssn, birth_date, address, sex, salary, super_ssn, dept_no) values ('Jennifer', 'S', 'Wellas', 987654321, '1941-06-20', '291 Berry, Bellaire, TX', 'F', 6780, 987987987, 4);
insert into employee (first_name, middle_name, last_name, ssn, birth_date, address, sex, salary, super_ssn, dept_no) values ('Ramesh', 'K', 'Narayan', 666884444, '1962-09-15', '975 Fire Oak, Humble, TX', 'M', 5700, 123456789, 5);
insert into employee (first_name, middle_name, last_name, ssn, birth_date, address, sex, salary, super_ssn, dept_no) values ('Joyce', 'A', 'English', 453453453, '1972-07-31', '5631 Rice, Houston, TX', 'M', 8600, 666884444, 5);
insert into employee (first_name, middle_name, last_name, ssn, birth_date, address, sex, salary, super_ssn, dept_no) values ('Ahmad', 'V', 'Jabbar', 987987987, '1969-03-29', '980 Dallas, Hoston, TX', 'M', 6950, 453453453, 4);
insert into employee (first_name, middle_name, last_name, ssn, birth_date, address, sex, salary, super_ssn, dept_no) values ('James', 'E', 'Borg', 888665555, '1937-11-10', '450 Stone, Houston, TX', 'M', 7800, 987654321, 1);

select * from employee;

-- Insert into department
insert into department(dept_name, dept_no, mgr_ssn, mgr_start_date) values ('Research', 5, 333445555, '1980-02-15');
insert into department(dept_name, dept_no, mgr_ssn, mgr_start_date) values ('Administration', 4, 987654321, '1982-05-30');
insert into department(dept_name, dept_no, mgr_ssn, mgr_start_date) values ('Headquarters', 1, 888665555, '1984-11-01');
insert into department(dept_name, dept_no, mgr_ssn, mgr_start_date) values ('Headquarters', 3, 123456789, '1987-12-23');
insert into department(dept_name, dept_no, mgr_ssn, mgr_start_date) values ('Headquarters', 2, 453453453, '1991-06-19');

select * from department;

-- Insert into department Locations
insert into department_location(dept_no, location) values (1, 'Houston');
insert into department_location(dept_no, location) values (4, 'Stanford');
insert into department_location(dept_no, location) values (5, 'Bellaire');
insert into department_location(dept_no, location) values (2, 'Sugarland');
insert into department_location(dept_no, location) values (3, 'Priceton');

select * from department_location;

-- Insert into works_on
insert into works_on(employee_ssn, project_no, hours) values (123456789, 1, 32.5);
insert into works_on(employee_ssn, project_no, hours) values (123456789, 2, 7.5);
insert into works_on(employee_ssn, project_no, hours) values (666884444, 3, 40.0);
insert into works_on(employee_ssn, project_no, hours) values (453453453, 1, 20.0);
insert into works_on(employee_ssn, project_no, hours) values (453453453, 2, 20.0);
insert into works_on(employee_ssn, project_no, hours) values (333445555, 2, 10.0);
insert into works_on(employee_ssn, project_no, hours) values (333445555, 3, 10.0);
insert into works_on(employee_ssn, project_no, hours) values (333445555, 10, 10.0);
insert into works_on(employee_ssn, project_no, hours) values (333445555, 20, 10.0);
insert into works_on(employee_ssn, project_no, hours) values (999887777, 30, 30.0);
insert into works_on(employee_ssn, project_no, hours) values (999887777, 10, 10.0);
insert into works_on(employee_ssn, project_no, hours) values (987987987, 10, 35.0);
insert into works_on(employee_ssn, project_no, hours) values (987987987, 30, 5.0);
insert into works_on(employee_ssn, project_no, hours) values (987654321, 30, 20.0);
insert into works_on(employee_ssn, project_no, hours) values (987654321, 20, 15.0);
insert into works_on(employee_ssn, project_no, hours) values (888665555, 20, 10.5);

select * from works_on;

-- Insert into project
insert into project(project_name, project_no, project_location, dept_no) values ('ProductX', 1, 'Bellaire', 5);
insert into project(project_name, project_no, project_location, dept_no) values ('ProductY', 2, 'Sugarland', 5);
insert into project(project_name, project_no, project_location, dept_no) values ('ProductZ', 3, 'Houston', 5);
insert into project(project_name, project_no, project_location, dept_no) values ('Computerization', 10, 'Stafford', 4);
insert into project(project_name, project_no, project_location, dept_no) values ('Reorganization', 20, 'Hoston', 1);
insert into project(project_name, project_no, project_location, dept_no) values ('Newbenifits', 30, 'Stafford', 4);

select * from project;

-- Insert into dependent
insert into dependent(employee_ssn, dependent_name, sex, birth_date, relationship) values (666884444, 'Andrew', 'M', '1994-12-27', 'Child');
insert into dependent(employee_ssn, dependent_name, sex, birth_date, relationship) values (999887777, 'Ellie', 'F', '1922-04-15', 'Parent');
insert into dependent(employee_ssn, dependent_name, sex, birth_date, relationship) values (123456789, 'Perry', 'F', '1965-02-10', 'Spouse');
insert into dependent(employee_ssn, dependent_name, sex, birth_date, relationship) values (453453453, 'Gillespe', 'M', '1974-07-30', 'Parent');
insert into dependent(employee_ssn, dependent_name, sex, birth_date, relationship) values (987987987, 'Rashid', 'M', '1994-11-07', 'Child');
insert into dependent(employee_ssn, dependent_name, sex, birth_date, relationship) values (888665555, 'Kane', 'M', '1992-08-08', 'Child');
insert into dependent(employee_ssn, dependent_name, sex, birth_date, relationship) values (333445555, 'Adam', 'M', '1975-05-20', 'Spouse');
insert into dependent(employee_ssn, dependent_name, sex, birth_date, relationship) values (987654321, 'Wilson', 'M', '1987-07-15', 'Spouse');

select * from dependent;

-- Create a view that has the department name, manager name, and manager salary for every department
create view department_details(dept_name, employeeFName, employeeMidName, employeeLName, employeeSalary) 
as 
    select D.dept_name, E.last_name, E.middle_name, E.first_name, E.salary
    from department D, employee E
    where D.mgr_ssn = E.ssn;

select * from department_details;

-- Create a view that has the employee Name, Supervisor name and employee salary for each employee who works in the "Research" department.
create view employee_details(employeeFName, employeeMidName, employeeLName, SupervisorFName, SupervisorMidName, SupervisorLName, employeeSalary) 
as 
    select employee.first_name as employeeFName, employee.middle_name as employeeMidept_name,
    employee.last_name as employeelast_name , Supervisor.first_name as SupervisorFName, 
    Supervisor.middle_name as SupervisorMidept_name, Supervisor.last_name as Supervisorlast_name,
    employee.salary as employee_salary
    from employee, employee Supervisor
    where employee.dept_no = 
    (
        select dept_no 
        from department
        where dept_name = 'Research'
    )
    and employee.super_ssn = Supervisor.ssn;

select * from employee_details;

-- A view that has the project name, controlling department name, Number of employees, and total hours worked per week on the project, for each project.
create view project_details(project, department, number_of_employees, hours_per_week) 
as 
    select P.project_name as project, D.dept_name, count(W.project_no) as number_of_employees, sum(W.hours) as hours_per_week
    from project P, department D, works_on W
    where P.dept_no = D.dept_no and P.project_no = W.project_no
    group by (P.project_no);

select * from project_details;

-- A view that has the project name, controlling department name, number of employees, and total hours worked per week on the project for each
-- project with more than one employee working on it.

create view project_with_more_than_one_employee(project, department, number_of_employees, hours_per_week) 
as
    select P.project_name as project, D.dept_name, count(W.project_no) as number_of_employees, sum(W.hours) as hours_per_week
    from project P, department D, works_on W
    where P.dept_no = D.dept_no and P.project_no = W.project_no
    group by (P.project_no)
    having count(W.project_no) > 1;

select * from project_with_more_than_one_employee;
