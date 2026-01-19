create database Store
Go

use Store

create table Users
(
id int,
first_name varchar(50) NOT NULL,
last_name varchar(50) NULL,
email varchar(50) NOT NULL,
address varchar(50) NOT NULL,

Primary key (id)
)
create table Products
(
id int,
name varchar(50) NOT NULL,
price float NOT NULL,
description varchar(50) NULL,

Primary key (id)
)
create table Orders
(
id int,
user_id int NOT NULL,
product_id int NOT NULL,
quantity int NOT NULL,
total_price float NOT NULL,

Primary key (id),

CONSTRAINT fk_orders_users
foreign key (user_id) references Users(id)
ON DELETE CASCADE
ON UPDATE CASCADE,

CONSTRAINT fk_orders_products
foreign key (product_id) references Products(id)
ON DELETE CASCADE
ON UPDATE CASCADE
)

