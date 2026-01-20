-------------Database creation-------------

create database ResearchPapers
Go

use ResearchPapers

------------Table Creation-----------------
create table Author
(
AID int,
AName varchar(50),
Primary key (AID),
)
create table Journal
(
JID int,
JTitle varchar(50),
Primary key (JID),
)
create table Paper
(
PID int,
ATitle varchar(50),
JournalID int,
Primary key (PID),
foreign key (JournalID) references Journal
)
create table Write
(
AuthorID int,
PaperID  int,
Primary key (AuthorID, PaperID )
)
