-- phpMyAdmin SQL Dump
-- version 4.5.4.1deb2ubuntu2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Feb 09, 2017 at 07:36 AM
-- Server version: 5.7.17-0ubuntu0.16.04.1
-- PHP Version: 7.0.13-0ubuntu0.16.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `taxowl`
--
CREATE DATABASE IF NOT EXISTS `taxowl` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin;
USE `taxowl`;

-- --------------------------------------------------------

--
-- Table structure for table `APPLICATIONS`
--

DROP TABLE IF EXISTS `APPLICATIONS`;
CREATE TABLE IF NOT EXISTS `APPLICATIONS` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `VERSION` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `ATTRIBUTE`
--

DROP TABLE IF EXISTS `ATTRIBUTE`;
CREATE TABLE IF NOT EXISTS `ATTRIBUTE` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `ATTRIBUTEINSTANCE`
--

DROP TABLE IF EXISTS `ATTRIBUTEINSTANCE`;
CREATE TABLE IF NOT EXISTS `ATTRIBUTEINSTANCE` (
  `ID` varchar(255) NOT NULL,
  `ATTRIBUTESETINSTANCE_ID` varchar(255) NOT NULL,
  `ATTRIBUTE_ID` varchar(255) NOT NULL,
  `VALUE` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `ATTINST_SET` (`ATTRIBUTESETINSTANCE_ID`),
  KEY `ATTINST_ATT` (`ATTRIBUTE_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `ATTRIBUTESET`
--

DROP TABLE IF EXISTS `ATTRIBUTESET`;
CREATE TABLE IF NOT EXISTS `ATTRIBUTESET` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `ATTRIBUTESETINSTANCE`
--

DROP TABLE IF EXISTS `ATTRIBUTESETINSTANCE`;
CREATE TABLE IF NOT EXISTS `ATTRIBUTESETINSTANCE` (
  `ID` varchar(255) NOT NULL,
  `ATTRIBUTESET_ID` varchar(255) NOT NULL,
  `DESCRIPTION` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `ATTSETINST_SET` (`ATTRIBUTESET_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `ATTRIBUTEUSE`
--

DROP TABLE IF EXISTS `ATTRIBUTEUSE`;
CREATE TABLE IF NOT EXISTS `ATTRIBUTEUSE` (
  `ID` varchar(255) NOT NULL,
  `ATTRIBUTESET_ID` varchar(255) NOT NULL,
  `ATTRIBUTE_ID` varchar(255) NOT NULL,
  `LINENO` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `ATTUSE_LINE` (`ATTRIBUTESET_ID`,`LINENO`),
  KEY `ATTUSE_ATT` (`ATTRIBUTE_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `ATTRIBUTEVALUE`
--

DROP TABLE IF EXISTS `ATTRIBUTEVALUE`;
CREATE TABLE IF NOT EXISTS `ATTRIBUTEVALUE` (
  `ID` varchar(255) NOT NULL,
  `ATTRIBUTE_ID` varchar(255) NOT NULL,
  `VALUE` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `ATTVAL_ATT` (`ATTRIBUTE_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `BREAKS`
--

DROP TABLE IF EXISTS `BREAKS`;
CREATE TABLE IF NOT EXISTS `BREAKS` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `VISIBLE` tinyint(1) NOT NULL DEFAULT '1',
  `NOTES` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `CATEGORIES`
--

DROP TABLE IF EXISTS `CATEGORIES`;
CREATE TABLE IF NOT EXISTS `CATEGORIES` (
  `ID` varchar(255) CHARACTER SET utf8 NOT NULL,
  `NAME` varchar(255) CHARACTER SET utf8 NOT NULL,
  `PARENTID` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `IMAGE` mediumblob,
  `TEXTTIP` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `CATSHOWNAME` smallint(6) NOT NULL DEFAULT '1',
  PRIMARY KEY (`ID`),
  UNIQUE KEY `CATEGORIES_NAME_INX` (`NAME`),
  KEY `CATEGORIES_FK_1` (`PARENTID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- --------------------------------------------------------

--
-- Table structure for table `CLOSEDCASH`
--

DROP TABLE IF EXISTS `CLOSEDCASH`;
CREATE TABLE IF NOT EXISTS `CLOSEDCASH` (
  `MONEY` varchar(255) NOT NULL,
  `HOST` varchar(255) NOT NULL,
  `HOSTSEQUENCE` int(11) NOT NULL,
  `DATESTART` datetime NOT NULL,
  `DATEEND` datetime DEFAULT NULL,
  `NOSALES` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`MONEY`),
  UNIQUE KEY `CLOSEDCASH_INX_SEQ` (`HOST`,`HOSTSEQUENCE`),
  KEY `CLOSEDCASH_INX_1` (`DATESTART`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `CSVIMPORT`
--

DROP TABLE IF EXISTS `CSVIMPORT`;
CREATE TABLE IF NOT EXISTS `CSVIMPORT` (
  `ID` varchar(255) NOT NULL,
  `ROWNUMBER` varchar(255) DEFAULT NULL,
  `CSVERROR` varchar(255) DEFAULT NULL,
  `REFERENCE` varchar(1024) DEFAULT NULL,
  `CODE` varchar(1024) DEFAULT NULL,
  `NAME` varchar(1024) DEFAULT NULL,
  `PRICEBUY` double DEFAULT NULL,
  `PRICESELL` double DEFAULT NULL,
  `PREVIOUSBUY` double DEFAULT NULL,
  `PREVIOUSSELL` double DEFAULT NULL,
  `CATEGORY` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `CUSTOMERS`
--

DROP TABLE IF EXISTS `CUSTOMERS`;
CREATE TABLE IF NOT EXISTS `CUSTOMERS` (
  `ID` varchar(255) NOT NULL,
  `SEARCHKEY` varchar(255) NOT NULL,
  `TAXID` varchar(255) DEFAULT NULL,
  `NAME` varchar(255) NOT NULL,
  `TAXCATEGORY` varchar(255) DEFAULT NULL,
  `CARD` varchar(255) DEFAULT NULL,
  `MAXDEBT` double NOT NULL DEFAULT '0',
  `ADDRESS` varchar(255) DEFAULT NULL,
  `ADDRESS2` varchar(255) DEFAULT NULL,
  `POSTAL` varchar(255) DEFAULT NULL,
  `CITY` varchar(255) DEFAULT NULL,
  `REGION` varchar(255) DEFAULT NULL,
  `COUNTRY` varchar(255) DEFAULT NULL,
  `FIRSTNAME` varchar(255) DEFAULT NULL,
  `LASTNAME` varchar(255) DEFAULT NULL,
  `EMAIL` varchar(255) DEFAULT NULL,
  `PHONE` varchar(255) DEFAULT NULL,
  `PHONE2` varchar(255) DEFAULT NULL,
  `FAX` varchar(255) DEFAULT NULL,
  `NOTES` varchar(255) DEFAULT NULL,
  `VISIBLE` bit(1) NOT NULL DEFAULT b'1',
  `CURDATE` datetime DEFAULT NULL,
  `CURDEBT` double DEFAULT '0',
  `IMAGE` mediumblob,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `CUSTOMERS_SKEY_INX` (`SEARCHKEY`),
  KEY `CUSTOMERS_TAXCAT` (`TAXCATEGORY`),
  KEY `CUSTOMERS_TAXID_INX` (`TAXID`),
  KEY `CUSTOMERS_NAME_INX` (`NAME`),
  KEY `CUSTOMERS_CARD_INX` (`CARD`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `DRAWEROPENED`
--

DROP TABLE IF EXISTS `DRAWEROPENED`;
CREATE TABLE IF NOT EXISTS `DRAWEROPENED` (
  `OPENDATE` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `NAME` varchar(255) DEFAULT NULL,
  `TICKETID` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `FLOORS`
--

DROP TABLE IF EXISTS `FLOORS`;
CREATE TABLE IF NOT EXISTS `FLOORS` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `IMAGE` mediumblob,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `FLOORS_NAME_INX` (`NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `LEAVES`
--

DROP TABLE IF EXISTS `LEAVES`;
CREATE TABLE IF NOT EXISTS `LEAVES` (
  `ID` varchar(255) NOT NULL,
  `PPLID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `STARTDATE` datetime NOT NULL,
  `ENDDATE` datetime NOT NULL,
  `NOTES` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `lEAVES_PPLID` (`PPLID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `LINEREMOVED`
--

DROP TABLE IF EXISTS `LINEREMOVED`;
CREATE TABLE IF NOT EXISTS `LINEREMOVED` (
  `REMOVEDDATE` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `NAME` varchar(255) DEFAULT NULL,
  `TICKETID` varchar(255) DEFAULT NULL,
  `PRODUCTID` varchar(255) DEFAULT NULL,
  `PRODUCTNAME` varchar(255) DEFAULT NULL,
  `UNITS` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `LOCATIONS`
--

DROP TABLE IF EXISTS `LOCATIONS`;
CREATE TABLE IF NOT EXISTS `LOCATIONS` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `ADDRESS` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `LOCATIONS_NAME_INX` (`NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `MOORERS`
--

DROP TABLE IF EXISTS `MOORERS`;
CREATE TABLE IF NOT EXISTS `MOORERS` (
  `VESSELNAME` varchar(255) DEFAULT NULL,
  `SIZE` int(11) DEFAULT NULL,
  `DAYS` int(11) DEFAULT NULL,
  `POWER` bit(1) NOT NULL DEFAULT b'0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `ORDERS`
--

DROP TABLE IF EXISTS `ORDERS`;
CREATE TABLE IF NOT EXISTS `ORDERS` (
  `USER_ID` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `PLACE_ID` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `PRODUCT_ID` varchar(255) COLLATE utf8_bin NOT NULL DEFAULT '',
  `CUSTOMER_ID` varchar(255) COLLATE utf8_bin NOT NULL,
  `PRODUCT_QUANTITY` bigint(3) UNSIGNED ZEROFILL DEFAULT NULL,
  `CONFIRMED` tinyint(1) NOT NULL,
  PRIMARY KEY (`USER_ID`,`PLACE_ID`,`PRODUCT_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- --------------------------------------------------------

--
-- Table structure for table `PAYMENTS`
--

DROP TABLE IF EXISTS `PAYMENTS`;
CREATE TABLE IF NOT EXISTS `PAYMENTS` (
  `ID` varchar(255) NOT NULL,
  `RECEIPT` varchar(255) NOT NULL,
  `PAYMENT` varchar(255) NOT NULL,
  `TOTAL` double NOT NULL DEFAULT '0',
  `TRANSID` varchar(255) DEFAULT NULL,
  `RETURNMSG` mediumblob,
  `NOTES` varchar(255) DEFAULT NULL,
  `TENDERED` double DEFAULT NULL,
  `CARDNAME` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `PAYMENTS_FK_RECEIPT` (`RECEIPT`),
  KEY `PAYMENTS_INX_1` (`PAYMENT`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `PEOPLE`
--

DROP TABLE IF EXISTS `PEOPLE`;
CREATE TABLE IF NOT EXISTS `PEOPLE` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `APPPASSWORD` varchar(255) DEFAULT NULL,
  `CARD` varchar(255) DEFAULT NULL,
  `ROLE` varchar(255) NOT NULL,
  `VISIBLE` bit(1) NOT NULL,
  `IMAGE` mediumblob,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `PEOPLE_NAME_INX` (`NAME`),
  KEY `PEOPLE_FK_1` (`ROLE`),
  KEY `PEOPLE_CARD_INX` (`CARD`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `PICKUP_NUMBER`
--

DROP TABLE IF EXISTS `PICKUP_NUMBER`;
CREATE TABLE IF NOT EXISTS `PICKUP_NUMBER` (
  `ID` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `PLACES`
--

DROP TABLE IF EXISTS `PLACES`;
CREATE TABLE IF NOT EXISTS `PLACES` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `X` int(11) NOT NULL,
  `Y` int(11) NOT NULL,
  `FLOOR` varchar(255) NOT NULL,
  `CUSTOMER` varchar(255) DEFAULT NULL,
  `WAITER` varchar(255) DEFAULT NULL,
  `TICKETID` varchar(255) DEFAULT NULL,
  `TABLEMOVED` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  UNIQUE KEY `PLACES_NAME_INX` (`NAME`),
  KEY `PLACES_FK_1` (`FLOOR`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `PRODUCTS`
--

DROP TABLE IF EXISTS `PRODUCTS`;
CREATE TABLE IF NOT EXISTS `PRODUCTS` (
  `ID` varchar(255) NOT NULL,
  `REFERENCE` varchar(255) NOT NULL,
  `CODE` varchar(255) NOT NULL,
  `CODETYPE` varchar(255) DEFAULT NULL,
  `NAME` varchar(255) NOT NULL,
  `PRICEBUY` double NOT NULL DEFAULT '0',
  `PRICESELL` double NOT NULL DEFAULT '0',
  `CATEGORY` varchar(255) NOT NULL,
  `TAXCAT` varchar(255) NOT NULL,
  `ATTRIBUTESET_ID` varchar(255) DEFAULT NULL,
  `STOCKCOST` double DEFAULT NULL,
  `STOCKVOLUME` double DEFAULT NULL,
  `IMAGE` mediumblob,
  `ISCOM` bit(1) NOT NULL DEFAULT b'0',
  `ISSCALE` bit(1) NOT NULL DEFAULT b'0',
  `ISKITCHEN` bit(1) NOT NULL DEFAULT b'0',
  `PRINTKB` bit(1) NOT NULL DEFAULT b'0',
  `SENDSTATUS` bit(1) NOT NULL DEFAULT b'0',
  `ISSERVICE` bit(1) NOT NULL DEFAULT b'0',
  `ATTRIBUTES` mediumblob,
  `DISPLAY` varchar(255) DEFAULT NULL,
  `ISVPRICE` smallint(6) NOT NULL DEFAULT '0',
  `ISVERPATRIB` smallint(6) NOT NULL DEFAULT '0',
  `TEXTTIP` varchar(255) DEFAULT '',
  `WARRANTY` smallint(6) NOT NULL DEFAULT '0',
  `STOCKUNITS` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  UNIQUE KEY `PRODUCTS_INX_0` (`REFERENCE`),
  UNIQUE KEY `PRODUCTS_INX_1` (`CODE`),
  UNIQUE KEY `PRODUCTS_NAME_INX` (`NAME`),
  KEY `PRODUCTS_FK_1` (`CATEGORY`),
  KEY `PRODUCTS_TAXCAT_FK` (`TAXCAT`),
  KEY `PRODUCTS_ATTRSET_FK` (`ATTRIBUTESET_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `PRODUCTS_CAT`
--

DROP TABLE IF EXISTS `PRODUCTS_CAT`;
CREATE TABLE IF NOT EXISTS `PRODUCTS_CAT` (
  `PRODUCT` varchar(255) NOT NULL,
  `CATORDER` int(11) DEFAULT NULL,
  PRIMARY KEY (`PRODUCT`),
  KEY `PRODUCTS_CAT_INX_1` (`CATORDER`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `PRODUCTS_COM`
--

DROP TABLE IF EXISTS `PRODUCTS_COM`;
CREATE TABLE IF NOT EXISTS `PRODUCTS_COM` (
  `ID` varchar(255) NOT NULL,
  `PRODUCT` varchar(255) NOT NULL,
  `PRODUCT2` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `PCOM_INX_PROD` (`PRODUCT`,`PRODUCT2`),
  KEY `PRODUCTS_COM_FK_2` (`PRODUCT2`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `RECEIPTS`
--

DROP TABLE IF EXISTS `RECEIPTS`;
CREATE TABLE IF NOT EXISTS `RECEIPTS` (
  `ID` varchar(255) NOT NULL,
  `MONEY` varchar(255) NOT NULL,
  `DATENEW` datetime NOT NULL,
  `ATTRIBUTES` mediumblob,
  `PERSON` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `RECEIPTS_FK_MONEY` (`MONEY`),
  KEY `RECEIPTS_INX_1` (`DATENEW`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `RESERVATIONS`
--

DROP TABLE IF EXISTS `RESERVATIONS`;
CREATE TABLE IF NOT EXISTS `RESERVATIONS` (
  `ID` varchar(255) NOT NULL,
  `CREATED` datetime NOT NULL,
  `DATENEW` datetime NOT NULL DEFAULT '2015-01-01 00:00:00',
  `TITLE` varchar(255) NOT NULL,
  `CHAIRS` int(11) NOT NULL,
  `ISDONE` bit(1) NOT NULL,
  `DESCRIPTION` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `RESERVATIONS_INX_1` (`DATENEW`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `RESERVATION_CUSTOMERS`
--

DROP TABLE IF EXISTS `RESERVATION_CUSTOMERS`;
CREATE TABLE IF NOT EXISTS `RESERVATION_CUSTOMERS` (
  `ID` varchar(255) NOT NULL,
  `CUSTOMER` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `RES_CUST_FK_2` (`CUSTOMER`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `RESOURCES`
--

DROP TABLE IF EXISTS `RESOURCES`;
CREATE TABLE IF NOT EXISTS `RESOURCES` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `RESTYPE` int(11) NOT NULL,
  `CONTENT` mediumblob,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `RESOURCES_NAME_INX` (`NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `ROLES`
--

DROP TABLE IF EXISTS `ROLES`;
CREATE TABLE IF NOT EXISTS `ROLES` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `PERMISSIONS` mediumblob,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `ROLES_NAME_INX` (`NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `SHAREDTICKETS`
--

DROP TABLE IF EXISTS `SHAREDTICKETS`;
CREATE TABLE IF NOT EXISTS `SHAREDTICKETS` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `CONTENT` mediumblob,
  `APPUSER` varchar(255) DEFAULT NULL,
  `PICKUPID` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `SHIFTS`
--

DROP TABLE IF EXISTS `SHIFTS`;
CREATE TABLE IF NOT EXISTS `SHIFTS` (
  `ID` varchar(255) NOT NULL,
  `STARTSHIFT` datetime NOT NULL,
  `ENDSHIFT` datetime DEFAULT NULL,
  `PPLID` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `SHIFT_BREAKS`
--

DROP TABLE IF EXISTS `SHIFT_BREAKS`;
CREATE TABLE IF NOT EXISTS `SHIFT_BREAKS` (
  `ID` varchar(255) NOT NULL,
  `SHIFTID` varchar(255) NOT NULL,
  `BREAKID` varchar(255) NOT NULL,
  `STARTTIME` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `ENDTIME` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`ID`),
  KEY `SHIFT_BREAKS_BREAKID` (`BREAKID`),
  KEY `SHIFT_BREAKS_SHIFTID` (`SHIFTID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `STOCKCURRENT`
--

DROP TABLE IF EXISTS `STOCKCURRENT`;
CREATE TABLE IF NOT EXISTS `STOCKCURRENT` (
  `LOCATION` varchar(255) NOT NULL,
  `PRODUCT` varchar(255) NOT NULL,
  `ATTRIBUTESETINSTANCE_ID` varchar(255) DEFAULT NULL,
  `UNITS` double NOT NULL,
  UNIQUE KEY `STOCKCURRENT_INX` (`LOCATION`,`PRODUCT`,`ATTRIBUTESETINSTANCE_ID`),
  KEY `STOCKCURRENT_FK_1` (`PRODUCT`),
  KEY `STOCKCURRENT_ATTSETINST` (`ATTRIBUTESETINSTANCE_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `STOCKDIARY`
--

DROP TABLE IF EXISTS `STOCKDIARY`;
CREATE TABLE IF NOT EXISTS `STOCKDIARY` (
  `ID` varchar(255) NOT NULL,
  `DATENEW` datetime NOT NULL,
  `REASON` int(11) NOT NULL,
  `LOCATION` varchar(255) NOT NULL,
  `PRODUCT` varchar(255) NOT NULL,
  `ATTRIBUTESETINSTANCE_ID` varchar(255) DEFAULT NULL,
  `UNITS` double NOT NULL,
  `PRICE` double NOT NULL,
  `APPUSER` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `STOCKDIARY_FK_1` (`PRODUCT`),
  KEY `STOCKDIARY_ATTSETINST` (`ATTRIBUTESETINSTANCE_ID`),
  KEY `STOCKDIARY_FK_2` (`LOCATION`),
  KEY `STOCKDIARY_INX_1` (`DATENEW`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `STOCKLEVEL`
--

DROP TABLE IF EXISTS `STOCKLEVEL`;
CREATE TABLE IF NOT EXISTS `STOCKLEVEL` (
  `ID` varchar(255) NOT NULL,
  `LOCATION` varchar(255) NOT NULL,
  `PRODUCT` varchar(255) NOT NULL,
  `STOCKSECURITY` double DEFAULT NULL,
  `STOCKMAXIMUM` double DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `STOCKLEVEL_PRODUCT` (`PRODUCT`),
  KEY `STOCKLEVEL_LOCATION` (`LOCATION`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `TAXCATEGORIES`
--

DROP TABLE IF EXISTS `TAXCATEGORIES`;
CREATE TABLE IF NOT EXISTS `TAXCATEGORIES` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `TAXCAT_NAME_INX` (`NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `TAXCUSTCATEGORIES`
--

DROP TABLE IF EXISTS `TAXCUSTCATEGORIES`;
CREATE TABLE IF NOT EXISTS `TAXCUSTCATEGORIES` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `TAXCUSTCAT_NAME_INX` (`NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `TAXES`
--

DROP TABLE IF EXISTS `TAXES`;
CREATE TABLE IF NOT EXISTS `TAXES` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `CATEGORY` varchar(255) NOT NULL,
  `CUSTCATEGORY` varchar(255) DEFAULT NULL,
  `PARENTID` varchar(255) DEFAULT NULL,
  `RATE` double NOT NULL DEFAULT '0',
  `RATECASCADE` bit(1) NOT NULL DEFAULT b'0',
  `RATEORDER` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `TAXES_NAME_INX` (`NAME`),
  KEY `TAXES_CAT_FK` (`CATEGORY`),
  KEY `TAXES_CUSTCAT_FK` (`CUSTCATEGORY`),
  KEY `TAXES_TAXES_FK` (`PARENTID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `TAXLINES`
--

DROP TABLE IF EXISTS `TAXLINES`;
CREATE TABLE IF NOT EXISTS `TAXLINES` (
  `ID` varchar(255) NOT NULL,
  `RECEIPT` varchar(255) NOT NULL,
  `TAXID` varchar(255) NOT NULL,
  `BASE` double NOT NULL DEFAULT '0',
  `AMOUNT` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  KEY `TAXLINES_TAX` (`TAXID`),
  KEY `TAXLINES_RECEIPT` (`RECEIPT`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `THIRDPARTIES`
--

DROP TABLE IF EXISTS `THIRDPARTIES`;
CREATE TABLE IF NOT EXISTS `THIRDPARTIES` (
  `ID` varchar(255) NOT NULL,
  `CIF` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `ADDRESS` varchar(255) DEFAULT NULL,
  `CONTACTCOMM` varchar(255) DEFAULT NULL,
  `CONTACTFACT` varchar(255) DEFAULT NULL,
  `PAYRULE` varchar(255) DEFAULT NULL,
  `FAXNUMBER` varchar(255) DEFAULT NULL,
  `PHONENUMBER` varchar(255) DEFAULT NULL,
  `MOBILENUMBER` varchar(255) DEFAULT NULL,
  `EMAIL` varchar(255) DEFAULT NULL,
  `WEBPAGE` varchar(255) DEFAULT NULL,
  `NOTES` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `THIRDPARTIES_CIF_INX` (`CIF`),
  UNIQUE KEY `THIRDPARTIES_NAME_INX` (`NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `TICKETLINES`
--

DROP TABLE IF EXISTS `TICKETLINES`;
CREATE TABLE IF NOT EXISTS `TICKETLINES` (
  `TICKET` varchar(255) NOT NULL,
  `LINE` int(11) NOT NULL,
  `PRODUCT` varchar(255) DEFAULT NULL,
  `ATTRIBUTESETINSTANCE_ID` varchar(255) DEFAULT NULL,
  `UNITS` double NOT NULL,
  `PRICE` double NOT NULL,
  `TAXID` varchar(255) NOT NULL,
  `ATTRIBUTES` mediumblob,
  PRIMARY KEY (`TICKET`,`LINE`),
  KEY `TICKETLINES_FK_2` (`PRODUCT`),
  KEY `TICKETLINES_ATTSETINST` (`ATTRIBUTESETINSTANCE_ID`),
  KEY `TICKETLINES_FK_3` (`TAXID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `TICKETS`
--

DROP TABLE IF EXISTS `TICKETS`;
CREATE TABLE IF NOT EXISTS `TICKETS` (
  `ID` varchar(255) NOT NULL,
  `TICKETTYPE` int(11) NOT NULL DEFAULT '0',
  `TICKETID` int(11) NOT NULL,
  `PERSON` varchar(255) NOT NULL,
  `CUSTOMER` varchar(255) DEFAULT NULL,
  `STATUS` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  KEY `TICKETS_FK_2` (`PERSON`),
  KEY `TICKETS_CUSTOMERS_FK` (`CUSTOMER`),
  KEY `TICKETS_TICKETID` (`TICKETTYPE`,`TICKETID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `TICKETSNUM`
--

DROP TABLE IF EXISTS `TICKETSNUM`;
CREATE TABLE IF NOT EXISTS `TICKETSNUM` (
  `ID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `TICKETSNUM_PAYMENT`
--

DROP TABLE IF EXISTS `TICKETSNUM_PAYMENT`;
CREATE TABLE IF NOT EXISTS `TICKETSNUM_PAYMENT` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `TICKETSNUM_REFUND`
--

DROP TABLE IF EXISTS `TICKETSNUM_REFUND`;
CREATE TABLE IF NOT EXISTS `TICKETSNUM_REFUND` (
  `ID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `ATTRIBUTEINSTANCE`
--
ALTER TABLE `ATTRIBUTEINSTANCE`
  ADD CONSTRAINT `ATTINST_ATT` FOREIGN KEY (`ATTRIBUTE_ID`) REFERENCES `ATTRIBUTE` (`ID`),
  ADD CONSTRAINT `ATTINST_SET` FOREIGN KEY (`ATTRIBUTESETINSTANCE_ID`) REFERENCES `ATTRIBUTESETINSTANCE` (`ID`) ON DELETE CASCADE;

--
-- Constraints for table `ATTRIBUTESETINSTANCE`
--
ALTER TABLE `ATTRIBUTESETINSTANCE`
  ADD CONSTRAINT `ATTSETINST_SET` FOREIGN KEY (`ATTRIBUTESET_ID`) REFERENCES `ATTRIBUTESET` (`ID`) ON DELETE CASCADE;

--
-- Constraints for table `ATTRIBUTEUSE`
--
ALTER TABLE `ATTRIBUTEUSE`
  ADD CONSTRAINT `ATTUSE_ATT` FOREIGN KEY (`ATTRIBUTE_ID`) REFERENCES `ATTRIBUTE` (`ID`),
  ADD CONSTRAINT `ATTUSE_SET` FOREIGN KEY (`ATTRIBUTESET_ID`) REFERENCES `ATTRIBUTESET` (`ID`) ON DELETE CASCADE;

--
-- Constraints for table `ATTRIBUTEVALUE`
--
ALTER TABLE `ATTRIBUTEVALUE`
  ADD CONSTRAINT `ATTVAL_ATT` FOREIGN KEY (`ATTRIBUTE_ID`) REFERENCES `ATTRIBUTE` (`ID`) ON DELETE CASCADE;

--
-- Constraints for table `CATEGORIES`
--
ALTER TABLE `CATEGORIES`
  ADD CONSTRAINT `CATEGORIES_FK_1` FOREIGN KEY (`PARENTID`) REFERENCES `CATEGORIES` (`ID`);

--
-- Constraints for table `CUSTOMERS`
--
ALTER TABLE `CUSTOMERS`
  ADD CONSTRAINT `CUSTOMERS_TAXCAT` FOREIGN KEY (`TAXCATEGORY`) REFERENCES `TAXCUSTCATEGORIES` (`ID`);

--
-- Constraints for table `LEAVES`
--
ALTER TABLE `LEAVES`
  ADD CONSTRAINT `lEAVES_PPLID` FOREIGN KEY (`PPLID`) REFERENCES `PEOPLE` (`ID`);

--
-- Constraints for table `PAYMENTS`
--
ALTER TABLE `PAYMENTS`
  ADD CONSTRAINT `PAYMENTS_FK_RECEIPT` FOREIGN KEY (`RECEIPT`) REFERENCES `RECEIPTS` (`ID`);

--
-- Constraints for table `PEOPLE`
--
ALTER TABLE `PEOPLE`
  ADD CONSTRAINT `PEOPLE_FK_1` FOREIGN KEY (`ROLE`) REFERENCES `ROLES` (`ID`);

--
-- Constraints for table `PLACES`
--
ALTER TABLE `PLACES`
  ADD CONSTRAINT `PLACES_FK_1` FOREIGN KEY (`FLOOR`) REFERENCES `FLOORS` (`ID`);

--
-- Constraints for table `PRODUCTS`
--
ALTER TABLE `PRODUCTS`
  ADD CONSTRAINT `PRODUCTS_ATTRSET_FK` FOREIGN KEY (`ATTRIBUTESET_ID`) REFERENCES `ATTRIBUTESET` (`ID`),
  ADD CONSTRAINT `PRODUCTS_FK_1` FOREIGN KEY (`CATEGORY`) REFERENCES `CATEGORIES` (`ID`),
  ADD CONSTRAINT `PRODUCTS_TAXCAT_FK` FOREIGN KEY (`TAXCAT`) REFERENCES `TAXCATEGORIES` (`ID`);

--
-- Constraints for table `PRODUCTS_CAT`
--
ALTER TABLE `PRODUCTS_CAT`
  ADD CONSTRAINT `PRODUCTS_CAT_FK_1` FOREIGN KEY (`PRODUCT`) REFERENCES `PRODUCTS` (`ID`);

--
-- Constraints for table `PRODUCTS_COM`
--
ALTER TABLE `PRODUCTS_COM`
  ADD CONSTRAINT `PRODUCTS_COM_FK_1` FOREIGN KEY (`PRODUCT`) REFERENCES `PRODUCTS` (`ID`),
  ADD CONSTRAINT `PRODUCTS_COM_FK_2` FOREIGN KEY (`PRODUCT2`) REFERENCES `PRODUCTS` (`ID`);

--
-- Constraints for table `RECEIPTS`
--
ALTER TABLE `RECEIPTS`
  ADD CONSTRAINT `RECEIPTS_FK_MONEY` FOREIGN KEY (`MONEY`) REFERENCES `CLOSEDCASH` (`MONEY`);

--
-- Constraints for table `RESERVATION_CUSTOMERS`
--
ALTER TABLE `RESERVATION_CUSTOMERS`
  ADD CONSTRAINT `RES_CUST_FK_1` FOREIGN KEY (`ID`) REFERENCES `RESERVATIONS` (`ID`),
  ADD CONSTRAINT `RES_CUST_FK_2` FOREIGN KEY (`CUSTOMER`) REFERENCES `CUSTOMERS` (`ID`);

--
-- Constraints for table `SHIFT_BREAKS`
--
ALTER TABLE `SHIFT_BREAKS`
  ADD CONSTRAINT `SHIFT_BREAKS_BREAKID` FOREIGN KEY (`BREAKID`) REFERENCES `BREAKS` (`ID`),
  ADD CONSTRAINT `SHIFT_BREAKS_SHIFTID` FOREIGN KEY (`SHIFTID`) REFERENCES `SHIFTS` (`ID`);

--
-- Constraints for table `STOCKCURRENT`
--
ALTER TABLE `STOCKCURRENT`
  ADD CONSTRAINT `STOCKCURRENT_ATTSETINST` FOREIGN KEY (`ATTRIBUTESETINSTANCE_ID`) REFERENCES `ATTRIBUTESETINSTANCE` (`ID`),
  ADD CONSTRAINT `STOCKCURRENT_FK_1` FOREIGN KEY (`PRODUCT`) REFERENCES `PRODUCTS` (`ID`),
  ADD CONSTRAINT `STOCKCURRENT_FK_2` FOREIGN KEY (`LOCATION`) REFERENCES `LOCATIONS` (`ID`);

--
-- Constraints for table `STOCKDIARY`
--
ALTER TABLE `STOCKDIARY`
  ADD CONSTRAINT `STOCKDIARY_ATTSETINST` FOREIGN KEY (`ATTRIBUTESETINSTANCE_ID`) REFERENCES `ATTRIBUTESETINSTANCE` (`ID`),
  ADD CONSTRAINT `STOCKDIARY_FK_1` FOREIGN KEY (`PRODUCT`) REFERENCES `PRODUCTS` (`ID`),
  ADD CONSTRAINT `STOCKDIARY_FK_2` FOREIGN KEY (`LOCATION`) REFERENCES `LOCATIONS` (`ID`);

--
-- Constraints for table `STOCKLEVEL`
--
ALTER TABLE `STOCKLEVEL`
  ADD CONSTRAINT `STOCKLEVEL_LOCATION` FOREIGN KEY (`LOCATION`) REFERENCES `LOCATIONS` (`ID`),
  ADD CONSTRAINT `STOCKLEVEL_PRODUCT` FOREIGN KEY (`PRODUCT`) REFERENCES `PRODUCTS` (`ID`);

--
-- Constraints for table `TAXES`
--
ALTER TABLE `TAXES`
  ADD CONSTRAINT `TAXES_CAT_FK` FOREIGN KEY (`CATEGORY`) REFERENCES `TAXCATEGORIES` (`ID`),
  ADD CONSTRAINT `TAXES_CUSTCAT_FK` FOREIGN KEY (`CUSTCATEGORY`) REFERENCES `TAXCUSTCATEGORIES` (`ID`),
  ADD CONSTRAINT `TAXES_TAXES_FK` FOREIGN KEY (`PARENTID`) REFERENCES `TAXES` (`ID`);

--
-- Constraints for table `TAXLINES`
--
ALTER TABLE `TAXLINES`
  ADD CONSTRAINT `TAXLINES_RECEIPT` FOREIGN KEY (`RECEIPT`) REFERENCES `RECEIPTS` (`ID`),
  ADD CONSTRAINT `TAXLINES_TAX` FOREIGN KEY (`TAXID`) REFERENCES `TAXES` (`ID`);

--
-- Constraints for table `TICKETLINES`
--
ALTER TABLE `TICKETLINES`
  ADD CONSTRAINT `TICKETLINES_ATTSETINST` FOREIGN KEY (`ATTRIBUTESETINSTANCE_ID`) REFERENCES `ATTRIBUTESETINSTANCE` (`ID`),
  ADD CONSTRAINT `TICKETLINES_FK_2` FOREIGN KEY (`PRODUCT`) REFERENCES `PRODUCTS` (`ID`),
  ADD CONSTRAINT `TICKETLINES_FK_3` FOREIGN KEY (`TAXID`) REFERENCES `TAXES` (`ID`),
  ADD CONSTRAINT `TICKETLINES_FK_TICKET` FOREIGN KEY (`TICKET`) REFERENCES `TICKETS` (`ID`);

--
-- Constraints for table `TICKETS`
--
ALTER TABLE `TICKETS`
  ADD CONSTRAINT `TICKETS_CUSTOMERS_FK` FOREIGN KEY (`CUSTOMER`) REFERENCES `CUSTOMERS` (`ID`),
  ADD CONSTRAINT `TICKETS_FK_2` FOREIGN KEY (`PERSON`) REFERENCES `PEOPLE` (`ID`),
  ADD CONSTRAINT `TICKETS_FK_ID` FOREIGN KEY (`ID`) REFERENCES `RECEIPTS` (`ID`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;