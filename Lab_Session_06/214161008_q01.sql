-- table creation according to the given problem statement
create table product
(
    product_id integer not null,
    product_name varchar(30) not null,
    price_in_USD float not null,
    category varchar(30) not null,
    manufacturer varchar(30) not null,
    primary key (product_id)
);

create table purchase
(
    product_id integer not null,
    buyer_name varchar(30) not null,
    purchase_date date not null,
    price_in_USD float not null,
    primary key (product_id,buyer_name),
    foreign key (product_id) references product(product_id)
);

-- product table

insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (12,'Laptop',500,'Electronics','Dell');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (24,'Laptop',480,'Electronics','HP');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (42,'Laptop',900,'Electronics','Apple');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (65,'Laptop',460,'Electronics','Lenovo');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (47,'Laptop',450,'Electronics','Acer');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (23,'Laptop',540,'Electronics','Asus');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (27,'Laptop',550,'Electronics','Samsung');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (279,'Laptop',650,'Electronics','Huawei');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (7,'Mouse',40,'Electronics','Dell');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (69,'Mouse',35,'Electronics','Logitech');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (352,'Mouse',30,'Electronics','HP');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (689,'Solid State Drive',120,'Electronics','Kingston');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (64,'Solid State Drive',115,'Electronics','Corsair');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (353,'Solid State Drive',130,'Electronics','Samsung');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (68,'Keyboard',12,'Electronics','Dell');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (657,'Keyboard',20,'Electronics','Logitech');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (35,'Keyboard',34,'Electronics','HP');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (63,'Air Conditioner',309,'Appliances','Hitachi');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (41,'Air Conditioner',270,'Appliances','Blue Star');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (14,'Air Conditioner',320,'Appliances','Croma');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (36,'Air Conditioner',200,'Appliances','Samsung');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (336,'Air Conditioner',210,'Appliances','Huawei');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (345,'Shirts',65,'Clothing','Arrow');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (78,'Shirts',40,'Clothing','John Players');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (125,'Shirts',41,'Clothing','Peter England');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (462,'Shirts',50,'Clothing','Louis Phillipe');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (201,'Shirts',35,'Clothing','Zodiac');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (128,'Smartphone',650,'Electronics','Apple');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (124,'Smartphone',480,'Electronics','Motorola');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (162,'Smartphone',380,'Electronics','Lenovo');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (102,'Smartphone',550,'Electronics','Samsung');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (2,'Smartphone',600,'Electronics','Huawei');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (256,'shoe',54,'Sports','Reebok');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (20,'shoe',45,'Sports','Skechers');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (242,'shoe',60,'Sports','Nike');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (33,'shoe',75,'Sports','Adidas');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (421,'shoe',44.30,'Sports','Xtep');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (26,'badminton',54,'Sports','Yonex');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (230,'badminton',45,'Sports','Wilson');
insert into product(product_id, product_name,price_in_USD,category,manufacturer) values (22,'badminton',60.20,'Sports','Li-ning');


-- Purchase table

insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (65,'Kamal',DATE('2012-12-17'),460);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (22,'Avinash',DATE('2014-10-18'),120.4);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (7,'Gaurav',DATE('2012-12-11'),24);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (78,'Qamar',DATE('2012-08-01'),160);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (256,'Pawan',DATE('2018-12-27'),54);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (201,'Alam',DATE('2012-04-05'),70);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (345,'Niranjan',DATE('2012-02-28'),130);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (65,'Neeraj',DATE('2018-12-27'),460);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (14,'Manish',DATE('2019-01-02'),320);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (242,'Pushkar',DATE('2012-12-17'),240);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (7,'Abhinav',DATE('2014-10-18'),12);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (78,'Gaurang',DATE('2019-01-02'),80);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (345,'Muneer',DATE('2015-10-17'),65);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (256,'Pratyush',DATE('2014-10-18'),108);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (27,'Kamlesh',DATE('2011-08-22'),550);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (14,'Yogendra',DATE('2012-12-17'),640);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (125,'Apoorv',DATE('2018-12-27'),42);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (42,'Budhar',DATE('2015-10-17'),900);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (23,'Rajeshwar',DATE('2019-01-02'),540);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (345,'Ankit',DATE('2012-12-17'),130);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (65,'Mann',DATE('2013-04-19'),460);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (162,'Virendra',DATE('2018-12-27'),380);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (63,'Udghosh',DATE('2012-04-05'),309);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (345,'Abhas',DATE('2015-10-17'),65);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (256,'Bodhisatva',DATE('2012-12-17'),54);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (22,'Rajesh',DATE('2014-10-18'),60.2);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (42,'Vinay',DATE('2013-04-19'),900);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (65,'Rakesh',DATE('2014-10-18'),460);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (162,'Ajit',DATE('2018-12-27'),380);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (256,'Kamal',DATE('2011-08-22'),54);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (230,'Ankur',DATE('2014-10-18'),90);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (27,'Niranjan',DATE('2014-10-18'),550);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (65,'Kuldeep',DATE('2012-04-05'),460);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (125,'Rajeev',DATE('2019-01-02'),82);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (41,'Atmanand',DATE('2013-04-19'),270);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (128,'Jothiprakash',DATE('2011-08-22'),650);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (65,'Shubham',DATE('2013-04-19'),460);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (23,'Rishabh',DATE('2012-12-17'),540);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (242,'Rohan',DATE('2019-01-027'),60);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (65,'Akash',DATE('2018-12-27'),460);
insert into purchase(product_id, buyer_name,purchase_date,price_in_USD) values (22,'Amit',DATE('2013-04-19'),120.4);

-- a.Find the date for which maximum number of product was purchased.
-- Done

select purchasing_date.purchase_date
from 
(select purchase_date
from purchase
group by purchase_date
order by count(purchase_date) desc) as purchasing_date
limit 1;

-- b.Find the manufacturer name and products which manufactures more than 2 product.
-- Done

select product.manufacturer, product.product_name
from product
where manufacturer in (
select manufacturer
from product
group by manufacturer
having count(product_id) > 2);

-- c.Find the manufacturer name and products which manufactures more than 1 product and which has been purchased by at least 1 customer.
-- Done

select product.manufacturer, product.product_name
from 
(select manufacturer from product group by manufacturer having count(product_id) > 1) as manufactures_more_than_one, product
where product.manufacturer = manufactures_more_than_one.manufacturer 
and product.product_id in (select product_id from purchase);

-- d.Find product details sort by purchase date from latest to oldest.
-- Done

select product.product_id, product.product_name, product.price_in_USD, product.category, product.manufacturer, purchase.purchase_date
from product, purchase
where product.product_id = purchase.product_id
order by purchase.purchase_date desc;

-- e.Find product details which has been bought by more than 2 customers.
-- Done

select product.product_id, product.product_name, product.price_in_USD, product.category, product.manufacturer, count(product.product_id) as bought_by
from product, purchase
where product.product_id = purchase.product_id
group by purchase.product_id
having count(purchase.product_id) > 2;

-- f.Find all the product whose price > avg price of the product.
-- Done

select *
from product
where product.price_in_USD > (select avg(price_in_USD) from product);

-- g.Find product details which has not been purchased by customers yet.
-- Done

select *
from product
where product_id not in (select product_id from purchase group by product_id);


-- h.Find product details whose name starts with letter a or ends with e.
-- Done

select *
from product
where product_name like 'a%' or product_name like '%e';


-- i.Find all companies that make some products withprice < 100
-- Done

select distinct manufacturer
from product
where price_in_USD < 100;

-- j.Find all companies s.t. all of their products have price < 100
-- Done 

select manufacturer
from 
(select manufacturer, max(price_in_USD) as Max_price
from product
group by manufacturer) as product_with_max_price
where product_with_max_price.Max_price < 100;
