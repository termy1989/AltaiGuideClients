CREATE SCHEMA `ag_rental_base` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin ;


CREATE SCHEMA `ag_clients_base` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin ;
CREATE TABLE `ag_clients_base`.`clients_table` (
  `clients_name` NVARCHAR(50) NOT NULL DEFAULT '<Ф. И. О.>',
  `clients_tel` NVARCHAR(12) NOT NULL DEFAULT '+7',
  `clients_email` NVARCHAR(50) NULL DEFAULT NULL,
  `clients_city` NVARCHAR(50) NULL DEFAULT NULL,
  `clients_date` NVARCHAR(150) NULL DEFAULT NULL,
  `clients_tour` NVARCHAR(150) NULL DEFAULT NULL,
  PRIMARY KEY (`name`),
  UNIQUE INDEX `name_UNIQUE` (`name` ASC),
  UNIQUE INDEX `phone_UNIQUE` (`phone` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_bin;


    QString str = "INSERT INTO `" + db_name + "`.`" + db_table + "` (clients_name, clients_tel, "
                                       "clients_email, clients_city, "
                                       "clients_date, clients_tour) "
                                       "VALUES ('<Имя>', '+7', '<Email>', "
                                       "'<Город>', NULL, '<Пусто>');";



CREATE TABLE `ag_rental_base`.`groups_table` (
  `name` NVARCHAR(75) NOT NULL,
  PRIMARY KEY (`name`),
  UNIQUE INDEX `name_UNIQUE` (`name` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_bin;

CREATE TABLE `ag_rental_base`.`products_table` (
  `group_name` NVARCHAR(75) NOT NULL,
  `name` NVARCHAR(100) NOT NULL DEFAULT '<Наименование>',
  `count` INT(5) UNSIGNED NOT NULL DEFAULT '1',
  `price3` DOUBLE UNSIGNED NOT NULL DEFAULT '100',
  `price` DOUBLE UNSIGNED NOT NULL DEFAULT '100',
  CONSTRAINT `products_groups_fk`
  FOREIGN KEY (`group_name`) REFERENCES `ag_rental_base`.`groups_table` (`name`) ON DELETE RESTRICT ON UPDATE CASCADE,
  PRIMARY KEY (`name`),
  UNIQUE INDEX `name_UNIQUE` (`name` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_bin;

CREATE TABLE `ag_rental_base`.`orders_table` (
  `id_order` INT(11) NOT NULL AUTO_INCREMENT,
  `product_name` NVARCHAR(100) NOT NULL,
  `count` INT(5) NOT NULL DEFAULT '0',
  `customer_name` NVARCHAR(50) NOT NULL,
  `startDate` DATE NOT NULL,
  `endDate` DATE NOT NULL,
  CONSTRAINT `orders_products_fk`
  FOREIGN KEY (`product_name`) REFERENCES `ag_rental_base`.`products_table` (`name`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `orders_customers_fk`
  FOREIGN KEY (`customer_name`) REFERENCES `ag_rental_base`.`customers_table` (`name`) ON DELETE RESTRICT ON UPDATE CASCADE,
  PRIMARY KEY (`id_order`),
  UNIQUE INDEX `id_order_UNIQUE` (`id_order` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_bin;

INSERT INTO `ag_rental_base`.`groups_table` (`name`) VALUES ('- ВСЕ ТОВАРЫ -');
INSERT INTO `ag_rental_base`.`groups_table` (`name`) VALUES ('не указана');
INSERT INTO `ag_rental_base`.`customers_table` (name, phone) VALUES ('- ВСЕ КЛИЕНТЫ -', 'null');