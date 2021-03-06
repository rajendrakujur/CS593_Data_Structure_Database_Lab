
-- Create Table Faculty
create table  faculty
(
    faculty_id integer not null,
    faculty_name varchar(30) not null,
    department_id integer not null,
    primary key (  faculty_id)
);

create table student
(
    student_id integer not null,
    student_name varchar(30) not null,
    major varchar(20) not null,
    student_level varchar(30) not null,
    age integer not null,
    faculty_id integer,
    primary key (student_id),
    check ( age>14 and  age<28),
    foreign key (  faculty_id) references  faculty(  faculty_id)
);

create table class
(
    class_name varchar(30) not null,
    meets_at time not null,
    room varchar(5) not null,
    faculty_id integer ,
    primary key (class_name),
    foreign key (faculty_id) references faculty(faculty_id)
);

create table enrolled
(
    student_id integer not null,
    class_name varchar(30) not null,
    primary key (student_id,class_name),
    foreign key (student_id) references student(student_id),
    foreign key (class_name) references class(class_name)
);

-- alter table employee
-- add constraint employee_chk_2 check
-- (
--     (
--         select count(*)
--         from enrolled E
--         group by E.student_id
--         having count(*) > 5
--     ) = 0
-- );

-- Schema of Faculty Table 
describe faculty;

-- Schema of Student Table
describe student;

-- Schema of Class Table
describe class;

-- Schema of Enrolled Table
describe enrolled;

--  faculty

insert into faculty(faculty_id, faculty_name, department_id) values (1,'Piyush Rai',231);
insert into faculty(faculty_id, faculty_name, department_id) values (3,'Manik Chakraborthy',56);
insert into faculty(faculty_id, faculty_name, department_id) values (2,'PV Subba Reddy',142);
insert into faculty(faculty_id, faculty_name, department_id) values (5,'Subramanyam',472);
insert into faculty(faculty_id, faculty_name, department_id) values (4,'Big Sur',214);
insert into faculty(faculty_id, faculty_name, department_id) values (6,'Amey Karkare',112);
insert into faculty(faculty_id, faculty_name, department_id) values (7,'Ramakrishnudu',321);
insert into faculty(faculty_id, faculty_name, department_id) values (8,'Rama Rao',123);
insert into faculty(faculty_id, faculty_name, department_id) values (9,'Palash Gosh',86);
insert into faculty(faculty_id, faculty_name, department_id) values (10,'Andrew NG',694);

-- student

insert into student (student_id, student_name, major, student_level, age, faculty_id) values (1,'Avinash','Mechanical','JR',17,4);
insert into student (student_id, student_name, major, student_level, age, faculty_id) values (2,'Nemendra','Computer Science','SOPH',18,null);
insert into student (student_id, student_name, major, student_level, age, faculty_id) values (3,'Ankur','Electronics','JR',18,5);
insert into student (student_id, student_name, major, student_level, age, faculty_id) values (4,'Mayank','History','SOPH',20,1);
insert into student (student_id, student_name, major, student_level, age, faculty_id) values (5,'NEERAJ','Accounting','SR',21,4);
insert into student (student_id, student_name, major, student_level, age, faculty_id) values (6,'Shubham','Zoology','SOPH',19,3);
insert into student (student_id, student_name, major, student_level, age, faculty_id) values (7,'Sukhdev','Biotechnology','JR',17,1);
insert into student (student_id, student_name, major, student_level, age, faculty_id) values (8,'Kamal','Data Science','JR',16,2);
insert into student (student_id, student_name, major, student_level, age, faculty_id) values (9,'Ashutosh','Astronomy','SR',22,null);

-- class table

insert into class (class_name, meets_at, room, faculty_id) values ('Thermodynamics','08:00:00','R128',1);
insert into class (class_name, meets_at, room, faculty_id) values ('Database','10:00:00','F220',5);
insert into class (class_name, meets_at, room, faculty_id) values ('Algorithms','08:00:00','C102',7);
insert into class (class_name, meets_at, room, faculty_id) values ('Mathematics','09:00:00','I028',1);
insert into class (class_name, meets_at, room, faculty_id) values ('Operating System','08:00:00','C302',3);
insert into class (class_name, meets_at, room, faculty_id) values ('Social Popular Movements','08:30:00','I028',8);
insert into class (class_name, meets_at, room, faculty_id) values ('Deep Learning','09:30:00','IO28',9);
insert into class (class_name, meets_at, room, faculty_id) values ('Computer Networks','11:30:00','R128',6);
insert into class (class_name, meets_at, room, faculty_id) values ('Automata Theory','09:00:00','C302',1);
insert into class (class_name, meets_at, room, faculty_id) values ('Fluid Mechanics','10:00:00','I028',5);
insert into class (class_name, meets_at, room, faculty_id) values ('Economic History','09:30:00','C102',3);
insert into class (class_name, meets_at, room, faculty_id) values ('Power Electronics','09:00:00','R128',2);
insert into class (class_name, meets_at, room, faculty_id) values ('State and Power','10:00:00','F220',1);
insert into class (class_name, meets_at, room, faculty_id) values ('Compiler Design','10:00:00','F220',8);
insert into class (class_name, meets_at, room, faculty_id) values ('Data Structures','11:00:00','C302',7);
insert into class (class_name, meets_at, room, faculty_id) values ('Ideology, Culture and Society','08:00:00','F220',7);
insert into class (class_name, meets_at, room, faculty_id) values ('Communications','12:00:00','I028',4);
insert into class (class_name, meets_at, room, faculty_id) values ('Biomolecules','10:00:00','C102',1);
insert into class (class_name, meets_at, room, faculty_id) values ('Biochemistry','08:00:00','R128',6);
insert into class (class_name, meets_at, room, faculty_id) values ('Ecology','09:30:00','F220',7);
insert into class (class_name, meets_at, room, faculty_id) values ('Psychology','11:00:00','C302',5);
insert into class (class_name, meets_at, room, faculty_id) values ('Programming','01:00:00','R128',3);
insert into class (class_name, meets_at, room, faculty_id) values ('Integrated Circuits','10:30:00','F220',4);
insert into class (class_name, meets_at, room, faculty_id) values ('Business Management','01:00:00','I028',7);

-- enrolled table

insert into enrolled (student_id,class_name) values (1,'Thermodynamics');
insert into enrolled (student_id,class_name) values (2,'Automata Theory');
insert into enrolled (student_id,class_name) values (1,'Fluid Mechanics');
insert into enrolled (student_id,class_name) values (2,'Database');
insert into enrolled (student_id,class_name) values (2,'Algorithms');
insert into enrolled (student_id,class_name) values (3,'Computer Networks');
insert into enrolled (student_id,class_name) values (4,'Social Popular Movements');
insert into enrolled (student_id,class_name) values (1,'Mathematics');
insert into enrolled (student_id,class_name) values (2,'Mathematics');
insert into enrolled (student_id,class_name) values (2,'Operating System');
insert into enrolled (student_id,class_name) values (4,'Economic History');
insert into enrolled (student_id,class_name) values (2,'Deep Learning');
insert into enrolled (student_id,class_name) values (3,'Power Electronics');
insert into enrolled (student_id,class_name) values (4,'State and Power');
insert into enrolled (student_id,class_name) values (1,'Deep Learning');
insert into enrolled (student_id,class_name) values (2,'Compiler Design');
insert into enrolled (student_id,class_name) values (3,'Data Structures');
insert into enrolled (student_id,class_name) values (3,'Integrated Circuits');
insert into enrolled (student_id,class_name) values (2,'Data Structures');
insert into enrolled (student_id,class_name) values (4,'Ideology, Culture and Society');
insert into enrolled (student_id,class_name) values (6,'biomolecules');
insert into enrolled (student_id,class_name) values (7,'Deep Learning');
insert into enrolled (student_id,class_name) values (6,'Biochemistry');
insert into enrolled (student_id,class_name) values (5,'Communications');
insert into enrolled (student_id,class_name) values (5,'Business Management');
insert into enrolled (student_id,class_name) values (6,'Mathematics');
insert into enrolled (student_id,class_name) values (8,'Deep Learning');
insert into enrolled (student_id,class_name) values (7,'Mathematics');
insert into enrolled (student_id,class_name) values (6,'Ecology');
insert into enrolled (student_id,class_name) values (4,'Deep Learning');
insert into enrolled (student_id,class_name) values (1,'Programming');
insert into enrolled (student_id,class_name) values (5,'Programming');
insert into enrolled (student_id,class_name) values (8,'Programming');
insert into enrolled (student_id,class_name) values (3,'Programming');
insert into enrolled (student_id,class_name) values (5,'Mathematics');

-- (I) Find the names of all Juniors (level = JR) who are enrolled in a class taught by 1 Teach.
-- Done

select student_name
from student
where student_level = 'JR' and student_id in 
(
    select distinct student_id
    from enrolled
    where class_name in
    (
        select class_name
        from class
        where faculty_id is not null
    )
);


-- (II) Find the age of the oldest student who is either a history major or enrolled in a course taught by 1 Teach.
-- Done

select max(age)
from
(
    (
        select age 
        from student
        where major = 'History'
    )
    union 
    (
        select age
        from student
        where student_id in 
        (
            select distinct student_id
            from enrolled
            where class_name in
            (
                select class_name
                from class
                where faculty_id is not null
            )
        )
    )
) as ages;

-- (III) Find the names of all classes that either meet in room R128 or have five or more students enrolled.
-- Done

(
    select class_name 
    from class
    where room = 'R128'
)
union 
(
    select class_name
    from class
    where class_name in 
    (
        select class_name 
        from enrolled 
        group by class_name
        having count(student_id) >= 5
    )
);


-- (IV) Find the names of all students who are enrolled in two classes that meet at the same time.
-- Done

select student_name
from student S
where exists
(
    select meets_at
    from class C, enrolled E
    where E.student_id = S.student_id and C.class_name = E.class_name
    group by meets_at
    having count(C.class_name) = 2
);

-- select student.student_id, student.student_name, class.class_name, class.meets_at
-- from student, enrolled, class
-- where student.student_id = enrolled.student_id and enrolled.class_name = class.class_name
-- order by student_id, meets_at


-- (V) Find the names of faculty members who teach in every room in which some class is taught.
-- Done

select faculty_name
from faculty F
where not exists
(
    select distinct room
    from class C
    where not exists
    (
        select *
        from class D
        where F.faculty_id = D.faculty_id and C.room = D.room
    )
);

-- (VI) Find the names of faculty members for whom the combined enrolment of the courses that they teach is less than five.
-- Not Done

select faculty_name
from faculty F
where exists
(
    select C.faculty_id
    from class C
    where C.faculty_id = F.faculty_id
    and exists 
    (
        (select faculty_id, count(student_id) as class_strength
        from enrolled E
        where E.class_name = C.class_name) particular_class
    ) 
    group by C.faculty_id
    having sum(particular_class.class_strength) < 5
)

group by faculty
having sum(particular_class.class_strength) < 5;

-- (VII) For each level, print the level and the average age of students for that level.
-- Done

select student_level, avg(age)
from student
group by student_level;


-- (VIII) For all levels except JR, print the level and the average  age of students for that level.
-- Done

select  student_level, avg(age)
from student
group by  student_level
having  student_level != 'JR';

-- (IX) For each faculty member that has taught classes only in room R128, print the faculty member???s name and the total number of classes she or he has taught.
-- Done

select faculty_name, count(class_name)
from faculty F, class G
where F.faculty_id = G.faculty_id and not exists
(
    select room
    from class C
    where C.faculty_id = F.faculty_id
    and not exists
    (
        select room
        from class D
        where room = 'R128' and C.room = D.room
    )
)
and exists
(
    select *
    from class E
    where E.faculty_id = F.faculty_id
)
group by F.faculty_id;

-- (X) Find the names of students enrolled in the maximum number of classes.
-- Done

select student_name
from student
where student_id in 
(
    select student_id
    from enrolled 
    group by student_id
    having count(class_name) = 
    (
        select count(student_id)
        from enrolled
        group by student_id
        order by count(student_id) desc
        limit 1
    )
);

-- (XI) Find the names of students not enrolled in any class.
-- Done

select student_name
from student
where student_id not in 
(
    select student_id 
    from enrolled 
    group by student_id
);
