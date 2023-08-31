CREATE SCHEMA `ag_clients_base` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin;
CREATE TABLE `ag_clients_base`.`clients_table` (
  `clients_id` INT(11) NOT NULL AUTO_INCREMENT,
  `clients_name` NVARCHAR(50) NOT NULL DEFAULT '<Ф. И. О.>',
  `clients_tel` NVARCHAR(12) NOT NULL DEFAULT '+7',
  `clients_email` NVARCHAR(50) NULL DEFAULT NULL,
  `clients_city` NVARCHAR(50) NULL DEFAULT NULL,
  `clients_date` DATE NULL DEFAULT NULL,
  `clients_tour` NVARCHAR(150) NULL DEFAULT NULL,
  PRIMARY KEY (`clients_id`),
  UNIQUE INDEX `clients_name_UNIQUE` (`clients_name` ASC),
  UNIQUE INDEX `clients_tel_UNIQUE` (`clients_tel` ASC),
  UNIQUE INDEX `clients_email_UNIQUE` (`clients_email` ASC))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8
COLLATE = utf8_bin;