create table contact
(
    address varchar(20) not null,
    phone_number integer not null,
    primary key (address)
);

create table musician
(
    SSN integer not null,
    musician_name varchar(20) not null,
    address varchar(20) not null,
    primary key (SSN),
    foreign key (address) references contact(address)
);

create table instrument
(
    instrument_name varchar(20) not null,
    SSN integer not null,
    musical_key varchar(20) not null,
    primary key (instrument_name, SSN),
    foreign key (SSN) references musician(SSN)
);

create table album
(
    album_id integer not null,
    title varchar(50) not null,
    copyright_date date not null,
    format varchar(2) not null,
    SSN integer not null,
    primary key (album_id),
    foreign key (SSN) references musician(SSN)
);

create table song
(
    title varchar(20) not null,
    SSN integer not null,
    author varchar(20) not null,
    album_id integer not null,
    primary key (title, SSN),
    foreign key (SSN) references musician(SSN),
    foreign key (album_id) references album(album_id)
);


insert into contact(address, phone_number) values ('West Bengal',123456789);
insert into contact(address, phone_number) values ('Mumbai',987654321);
insert into contact(address, phone_number) values ('Hyderabad',456789123);
insert into contact(address, phone_number) values ('Chennai',159478632);
insert into contact(address, phone_number) values ('Kanpur',658974213);
insert into contact(address, phone_number) values ('Jaipur',325698741);

insert into musician(SSN, musician_name,address) values (1,'Arijit Singh','West Bengal');
insert into musician(SSN, musician_name,address) values (2,'Kumar Sanu','Chennai');
insert into musician(SSN, musician_name,address) values (3,'Neha Kakkar','Mumbai');
insert into musician(SSN, musician_name,address) values (4,'Atif Aslam','West Bengal');
insert into musician(SSN, musician_name,address) values (5,'Salman Khan','Jaipur');
insert into musician(SSN, musician_name,address) values (6,'K.K.','Kanpur');
insert into musician(SSN, musician_name,address) values (7,'Akriti Kakar','Hyderabad');
insert into musician(SSN, musician_name,address) values (8,'Alka Ajith','Kanpur');

insert into instrument(instrument_name, SSN,musical_key) values ('Cornet',1,'C');
insert into instrument(instrument_name, SSN,musical_key) values ('Trombone',1,'B-flat');
insert into instrument(instrument_name, SSN,musical_key) values ('Guitar',2,'E-flat');
insert into instrument(instrument_name, SSN,musical_key) values ('Xylophone',2,'E-flat');
insert into instrument(instrument_name, SSN,musical_key) values ('Organ pipes',3,'C');
insert into instrument(instrument_name, SSN,musical_key) values ('Galtons Whistle',4,'C');
insert into instrument(instrument_name, SSN,musical_key) values ('Cornet',5,'C');
insert into instrument(instrument_name, SSN,musical_key) values ('Trombone',6,'B-flat');
insert into instrument(instrument_name, SSN,musical_key) values ('Cornet',7,'C,');
insert into instrument(instrument_name, SSN,musical_key) values ('Trombone',8,'B-flat');

insert into album(album_id, title,copyright_date, format, SSN) values (1,'Udaan',DATE('2012-12-17'),'CD',5);
insert into album(album_id, title,copyright_date, format, SSN) values (2,'Guzaarish',DATE('2011-10-17'),'MC',4);
insert into album(album_id, title,copyright_date, format, SSN) values (3,'Delhi Belly',DATE('2015-08-05'),'MC',7);
insert into album(album_id, title,copyright_date, format, SSN) values (4,'Rockstar',DATE('2017-12-10'),'CD',3);


insert into song(title,SSN,author, album_id) values ('Aaj Se Ter',1,'Anand Bakshi',1);
insert into song(title,SSN,author, album_id) values ('Tere Mere',1,'Hasrat Jaipuri',1);
insert into song(title,SSN,author, album_id) values ('Enna Sona',2,'Kedar Sharma',2);
insert into song(title,SSN,author, album_id) values ('Humsafar',4,'Kaifi Azmi',4);
insert into song(title,SSN,author, album_id) values ('Nazm Nazm',5,'Indivar',3);
insert into song(title,SSN,author, album_id) values ('Aaj Din Chadheya',2,'Majrooh Sultanpuri',4);


-- a. For each of the musician, find their mobile number and address.
-- Done

select musician.musician_name, contact.address, contact.phone_number
from musician, contact
where musician.address = contact.address;

-- b. Find the details of musicians who don’t share same address.
-- Done

select musician.SSN, musician.musician_name, musician.address, contact.phone_number
from musician , contact
where musician.address = contact.address and
musician.address in (select address from musician group by address having count(address)=1);

-- c. Find musicians who plays exactly 2 instruments and have performed
-- in more than 1 songs.
-- Done not able to submit :/

select *
from musician 
where SSN in
(select musician.SSN
from musician, instrument
where musician.SSN = instrument.SSN
group by instrument.SSN
having count(instrument.instrument_name)=2) and 
SSN in (select SSN from song group by SSN having count(SSN)>1); 


-- d. For each of the musician, find the number of instruments each
-- musician is playing.
-- Done

select musician.musician_name, count(instrument.instrument_name)
from musician, instrument
where musician.SSN = instrument.SSN
group by instrument.SSN;

-- e. For each of the musician who plays more than 2 instrument, find the
-- number of albums they are producing.
-- Done not able to submit :/

select musician.SSN, musician.musician_name, count(album_id)
from musician, album
where musician.SSN = album.SSN and musician.SSN in (select SSN from instrument group by SSN having count(instrument_name)>1)
group by album.album_id;