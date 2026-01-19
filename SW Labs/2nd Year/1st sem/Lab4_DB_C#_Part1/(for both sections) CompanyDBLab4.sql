-------------Database creation-------------
Create database CompanyDBLab4
GO
use CompanyDBLab4

------------Table Creation-----------------
create table Employee
(
Fname varchar(50) not null,
Lname varchar(50) not null,
SSN int,
primary key (SSN),
Address varchar(50),
Dno int,
)

create table Department
(
Dname varchar(50),
Dnumber int Identity(1,1),
primary key (Dnumber),
)


create table Project
(
Pname varchar(50),
Pnumber int,
primary key(Pnumber),
Dnum int,
foreign key (Dnum) references Department
)

create table Works_On
(
Essn int,
Pno int,
primary key (Essn,Pno),
Hours float,
foreign key (Essn) references Employee,
foreign key (Pno) references Project
)
-----------inserting Employee Foreign key--------------
alter table Employee add foreign key (DNO) references Department

-- Insert 5 different departments
INSERT INTO Department (Dname) VALUES
('IT'),
('Management'),
('Headquarters'),
('Administration'),
('Research');

-- Insert 10 different students
INSERT INTO Employee (Fname, Lname, SSN, Address, Dno) VALUES
('John', 'Doe', 12345, '731 Fondren, Houston, TX', 1),
('Jane', 'Smith', 23456, '638 Voss, Houston, TX', 2),
('Mike', 'Johnson', 34567, '5631 Rice, Houston, T', 3),
('Sarah', 'Williams', 45678, '975 Fire Oak, Humble, TX', 4),
('David', 'Brown', 56789, '450 Stone, Houston, TX', 5),
('Emily', 'Davis', 67890, '980 Dallas, Houston, TX', 1),
('Daniel', 'Lee', 78901, '3321 Castle, Spring, TX', 2),
('Olivia', 'Martin', 89012, '291 Berry, Bellaire, TX', 3),
('Michael', 'Anderson', 90123, '222 Lasfegas, Houston, TX', 4),
('Sophia', 'Taylor', 01234, '555 los angelos,Spring , TX', 5);

-- Insert 5 assignments
INSERT INTO Project(Pnumber,Pname, Dnum) VALUES
(1,'Project#1', 1),
(2,'Project#2', 2),
(3,'Project#3', 3),
(4,'Project#4', 4),
(5,'Projectt#5', 5);

-- Insert 20 solves
INSERT INTO Works_On(Essn, Pno, Hours) VALUES
(12345, 1, 60),
(23456, 2, 90),
(34567, 3, 75),
(45678, 4, 120),
(56789, 5, 45),
(67890, 1, 70),
(78901, 2, 80),
(90123, 3, 100),
(01234, 4, 55),
(12345, 5, 85),
(23456, 1, 95),
(34567, 2, 110),
(45678, 3, 40),
(56789, 4, 50),
(67890, 5, 65),
(78901, 1, 125),
(90123, 2, 70),
(01234, 3, 80),
(12345, 4, 105),
(23456, 5, 60);
