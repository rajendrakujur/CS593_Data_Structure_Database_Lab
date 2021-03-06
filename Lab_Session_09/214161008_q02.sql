
-- CREATE TABLE FACULTY
CREATE TABLE  FACULTY
(
    FACULTY_ID INTEGER NOT NULL,
    FACULTY_NAME VARCHAR(30) NOT NULL,
    DEPARTMENT_ID INTEGER NOT NULL,
    PRIMARY KEY (FACULTY_ID)
);

-- CREATE TABLE STUDENT
CREATE TABLE STUDENT
(
    STUDENT_ID INTEGER NOT NULL,
    STUDENT_NAME VARCHAR(30) NOT NULL,
    MAJOR VARCHAR(20) NOT NULL,
    STUDENT_LEVEL VARCHAR(30) NOT NULL,
    AGE INTEGER NOT NULL,
    FACULTY_ID INTEGER,
    PRIMARY KEY (STUDENT_ID),
    CHECK ( AGE>14 and  AGE<28),
    FOREIGN KEY (FACULTY_ID) REFERENCES FACULTY(FACULTY_ID)
);

-- CREATE TABLE CLASS
CREATE TABLE CLASS
(
    CLASS_NAME VARCHAR(30) NOT NULL,
    MEETS_AT time NOT NULL,
    ROOM VARCHAR(5) NOT NULL,
    FACULTY_ID INTEGER ,
    PRIMARY KEY (CLASS_NAME),
    FOREIGN KEY (FACULTY_ID) REFERENCES FACULTY(FACULTY_ID)
);

-- CREATE TABLE ENROLLED
CREATE TABLE ENROLLED
(
    STUDENT_ID INTEGER NOT NULL,
    CLASS_NAME VARCHAR(30) NOT NULL,
    PRIMARY KEY (STUDENT_ID,CLASS_NAME),
    FOREIGN KEY (STUDENT_ID) REFERENCES STUDENT(STUDENT_ID),
    FOREIGN KEY (CLASS_NAME) REFERENCES CLASS(CLASS_NAME)
);

-- INSERT INTO FACULTY

INSERT INTO FACULTY(FACULTY_ID, FACULTY_NAME, DEPARTMENT_ID) values (1,'Piyush Rai',231);
INSERT INTO FACULTY(FACULTY_ID, FACULTY_NAME, DEPARTMENT_ID) values (3,'Manik Chakraborthy',56);
INSERT INTO FACULTY(FACULTY_ID, FACULTY_NAME, DEPARTMENT_ID) values (2,'PV Subba Reddy',142);
INSERT INTO FACULTY(FACULTY_ID, FACULTY_NAME, DEPARTMENT_ID) values (5,'Subramanyam',472);
INSERT INTO FACULTY(FACULTY_ID, FACULTY_NAME, DEPARTMENT_ID) values (4,'Big Sur',214);
INSERT INTO FACULTY(FACULTY_ID, FACULTY_NAME, DEPARTMENT_ID) values (6,'Amey Karkare',112);
INSERT INTO FACULTY(FACULTY_ID, FACULTY_NAME, DEPARTMENT_ID) values (7,'Ramakrishnudu',321);
INSERT INTO FACULTY(FACULTY_ID, FACULTY_NAME, DEPARTMENT_ID) values (8,'Rama Rao',123);
INSERT INTO FACULTY(FACULTY_ID, FACULTY_NAME, DEPARTMENT_ID) values (9,'Palash Gosh',86);
INSERT INTO FACULTY(FACULTY_ID, FACULTY_NAME, DEPARTMENT_ID) values (10,'Andrew NG',694);

-- INSERT INTO STUDENT

INSERT INTO STUDENT (STUDENT_ID, STUDENT_NAME, MAJOR, STUDENT_LEVEL, AGE, FACULTY_ID) values (1,'Avinash','Mechanical','JR',17,4);
INSERT INTO STUDENT (STUDENT_ID, STUDENT_NAME, MAJOR, STUDENT_LEVEL, AGE, FACULTY_ID) values (2,'Nemendra','Computer Science','SOPH',18,null);
INSERT INTO STUDENT (STUDENT_ID, STUDENT_NAME, MAJOR, STUDENT_LEVEL, AGE, FACULTY_ID) values (3,'Ankur','Electronics','JR',18,5);
INSERT INTO STUDENT (STUDENT_ID, STUDENT_NAME, MAJOR, STUDENT_LEVEL, AGE, FACULTY_ID) values (4,'Mayank','History','SOPH',20,1);
INSERT INTO STUDENT (STUDENT_ID, STUDENT_NAME, MAJOR, STUDENT_LEVEL, AGE, FACULTY_ID) values (5,'NEERAJ','Accounting','SR',21,4);
INSERT INTO STUDENT (STUDENT_ID, STUDENT_NAME, MAJOR, STUDENT_LEVEL, AGE, FACULTY_ID) values (6,'Shubham','Zoology','SOPH',19,3);
INSERT INTO STUDENT (STUDENT_ID, STUDENT_NAME, MAJOR, STUDENT_LEVEL, AGE, FACULTY_ID) values (7,'Sukhdev','Biotechnology','JR',17,1);
INSERT INTO STUDENT (STUDENT_ID, STUDENT_NAME, MAJOR, STUDENT_LEVEL, AGE, FACULTY_ID) values (8,'Kamal','Mathematics','JR',16,2);
INSERT INTO STUDENT (STUDENT_ID, STUDENT_NAME, MAJOR, STUDENT_LEVEL, AGE, FACULTY_ID) values (9,'Ashutosh','Astronomy','SR',22,null);

-- INSERT INTO CLASS 

INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Thermodynamics','08:00:00','R128',1);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Database','10:00:00','F220',5);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Algorithms','08:00:00','C102',7);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Mathematics','09:00:00','I028',8);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Operating System','08:00:00','C102',3);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Social Popular Movements','08:30:00','I028',8);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Deep Learning','09:30:00','I028',9);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Statistics','11:30:00','R128',5);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Automata Theory','09:00:00','C102',1);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Fluid Mechanics','10:00:00','I028',5);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Economic History','09:30:00','C102',3);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Power Electronics','09:00:00','R128',2);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('State and Power','10:00:00','F220',1);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Compiler Design','10:00:00','F220',8);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Data Structures','11:00:00','C102',7);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Physics','08:00:00','F220',7);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Communications','12:00:00','I028',4);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Biomolecules','10:00:00','C102',1);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Biochemistry','08:00:00','R128',6);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Ecology','09:30:00','F220',7);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Psychology','11:00:00','C102',5);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Programming','01:00:00','R128',3);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Integrated Circuits','10:30:00','F220',4);
INSERT INTO CLASS (CLASS_NAME, MEETS_AT, ROOM, FACULTY_ID) values ('Business Management','01:00:00','I028',7);

-- INSERT INTO ENROLLED TABLE

INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (1,'Thermodynamics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (2,'Automata Theory');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (1,'Fluid Mechanics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (2,'Database');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (2,'Algorithms');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (3,'Statistics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (4,'Social Popular Movements');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (1,'Mathematics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (2,'Mathematics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (2,'Operating System');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (4,'Economic History');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (2,'Deep Learning');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (3,'Power Electronics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (4,'State and Power');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (1,'Deep Learning');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (2,'Compiler Design');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (3,'Data Structures');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (3,'Integrated Circuits');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (2,'Data Structures');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (4,'Physics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (6,'Biomolecules');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (7,'Deep Learning');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (6,'Biochemistry');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (5,'Communications');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (5,'Business Management');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (6,'Mathematics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (8,'Deep Learning');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (7,'Mathematics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (6,'Ecology');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (4,'Deep Learning');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (1,'Programming');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (5,'Statistics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (8,'Physics');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (3,'Programming');
INSERT INTO ENROLLED (STUDENT_ID,CLASS_NAME) values (5,'Mathematics');

SELECT * FROM FACULTY;
SELECT * FROM STUDENT;
SELECT * FROM CLASS;
SELECT * FROM ENROLLED;

-- (I) Write a stored procedure which takes student_level as input and return the average age of
-- the students of the particular level.
-- Done

DELIMITER //
CREATE PROCEDURE AVG_AGE(IN LEVEL VARCHAR(5), OUT AVERAGE_AGE FLOAT)
BEGIN
    SELECT AVG(AGE) INTO AVERAGE_AGE
    FROM STUDENT
    WHERE STUDENT_LEVEL = LEVEL;

    SELECT AVERAGE_AGE;
END;
//
DELIMITER ;

CALL AVG_AGE('JR', @AVERAGE_AGE);
CALL AVG_AGE('SOPH', @AVERAGE_AGE);
CALL AVG_AGE('SR', @AVERAGE_AGE);

-- (II) Write a stored procedure which takes faculty_id as input and return the list of all the
-- students those are taught by faculty faculty_id.
-- Done

DELIMITER //
CREATE PROCEDURE STUDENTS_OF_FACULTY(IN FID INTEGER, OUT STUDENTS_NAME VARCHAR(30))
BEGIN
    SELECT DISTINCT STUDENT_NAME
    FROM STUDENT S, ENROLLED E, CLASS C
    WHERE S.STUDENT_ID = E.STUDENT_ID AND E.CLASS_NAME = C.CLASS_NAME AND C.FACULTY_ID = FID;
END;
//
DELIMITER ;

CALL STUDENTS_OF_FACULTY(4, @STUDENTS_NAME);
-- (III) Write a stored procedure which return all the class having keyword ???ics??? in its name and
-- those either meet in room R128 or having 3 or more students enrolled.
-- Done

DELIMITER //
CREATE PROCEDURE SUBJECTS_WITH_GIVEN_RESTRICTION()
BEGIN 
    SELECT CLASS_NAME
    FROM CLASS 
    WHERE CLASS_NAME LIKE '%ics%' AND 
    (
        ROOM = 'R128' OR 
        CLASS_NAME IN 
        (
            SELECT CLASS_NAME
            FROM ENROLLED E
            GROUP BY CLASS_NAME
            HAVING COUNT(STUDENT_ID) >= 3
        )
    );
END;
//
DELIMITER ;

CALL SUBJECTS_WITH_GIVEN_RESTRICTION;

-- (IV) Write a stored procedure which return the reduced age of oldest student by 20% who is
-- either a mathematics major or enrolled in a course taught by Teacher id 1.
-- Done

DELIMITER //
CREATE PROCEDURE MANIPULATED_AGE()
BEGIN
    DECLARE REDUCED_AGE FLOAT DEFAULT 0.0;
    DECLARE ORIGINAL_AGE FLOAT DEFAULT 0.0;
    SELECT DISTINCT MAX(S.AGE) INTO ORIGINAL_AGE
    FROM STUDENT S, ENROLLED E, CLASS C
    WHERE MAJOR = 'Mathematics' OR 
    (
        S.STUDENT_ID = E.STUDENT_ID 
        AND 
        E.CLASS_NAME = C.CLASS_NAME
        AND 
        C.FACULTY_ID = 1
    );
    SET REDUCED_AGE = (1-0.2)*ORIGINAL_AGE;
    SELECT REDUCED_AGE;
END;
//
DELIMITER ;

CALL MANIPULATED_AGE;

-- (V) Write a stored procedure having IN and OUT parameter which take the room number as
-- an IN parameter and write the count of all the classed held in a particular room into the OUT
-- parameter.
-- Done

DELIMITER //
CREATE PROCEDURE NUMBER_OF_CLASSES(IN INPUT_ROOM VARCHAR(5), OUT CLASS_COUNT INTEGER)
BEGIN
    SELECT COUNT(*) INTO CLASS_COUNT
    FROM CLASS
    WHERE ROOM = INPUT_ROOM
    GROUP BY ROOM;

    SELECT CLASS_COUNT;
END;
//
DELIMITER ;

CALL NUMBER_OF_CLASSES('C102', @CLASS_COUNT);
CALL NUMBER_OF_CLASSES('R128', @CLASS_COUNT);
CALL NUMBER_OF_CLASSES('I028', @CLASS_COUNT);
