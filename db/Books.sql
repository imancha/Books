-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jan 21, 2015 at 10:27 AM
-- Server version: 5.5.40-0ubuntu0.14.04.1
-- PHP Version: 5.5.9-1ubuntu4.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `Books`
--

-- --------------------------------------------------------

--
-- Table structure for table `Author`
--

CREATE TABLE IF NOT EXISTS `Author` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the author',
  `Name` varchar(255) NOT NULL COMMENT 'The name of the author',
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Name` (`Name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Book`
--

CREATE TABLE IF NOT EXISTS `Book` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the book',
  `Title` varchar(255) NOT NULL COMMENT 'The title of the book',
  `SubTitle` varchar(255) NOT NULL COMMENT 'The subtitle of the book',
  `Description` text NOT NULL COMMENT 'The description of the book',
  `ISBN` varchar(255) NOT NULL COMMENT 'The International Standard Book Number (ISBN) of the book',
  `Page` int(11) NOT NULL COMMENT 'The number of pages of the book',
  `Year` year(4) NOT NULL COMMENT 'The publication date (year) of the book',
  `Publisher` varchar(255) NOT NULL COMMENT 'The publisher of the book',
  `Language` varchar(255) NOT NULL COMMENT 'The language of the book',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Book Author`
--

CREATE TABLE IF NOT EXISTS `Book Author` (
  `ID Book` int(11) NOT NULL COMMENT 'The ID of the book',
  `ID Author` int(11) NOT NULL COMMENT 'The ID of the author',
  KEY `ID Book` (`ID Book`,`ID Author`),
  KEY `ID Author` (`ID Author`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Book Category`
--

CREATE TABLE IF NOT EXISTS `Book Category` (
  `ID Book` int(11) NOT NULL COMMENT 'The ID of the book',
  `ID Category Detail` int(11) NOT NULL COMMENT 'The id category detail of the book',
  KEY `ID Book` (`ID Book`),
  KEY `ID Category` (`ID Category Detail`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Book Review`
--

CREATE TABLE IF NOT EXISTS `Book Review` (
  `ID Book` int(11) NOT NULL COMMENT 'The ID of the book',
  `Reviewer` varchar(255) NOT NULL COMMENT 'The reviewer of the book',
  `Email` varchar(255) NOT NULL COMMENT 'The email of the reviewer',
  `Review` text NOT NULL COMMENT 'The review of the book',
  `Rate` int(11) NOT NULL COMMENT 'The rate of the review',
  `Date` datetime NOT NULL COMMENT 'The date of the review',
  KEY `ID Book` (`ID Book`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Cart`
--

CREATE TABLE IF NOT EXISTS `Cart` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the shopping cart',
  `ID Visitor` int(11) NOT NULL COMMENT 'The id visitor of the cart',
  PRIMARY KEY (`ID`),
  KEY `ID Book` (`ID Visitor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Cart Item`
--

CREATE TABLE IF NOT EXISTS `Cart Item` (
  `ID Cart` int(11) NOT NULL COMMENT 'The ID of the cart',
  `ID Book` int(11) NOT NULL COMMENT 'The ID of the book',
  `Quantity` int(11) NOT NULL,
  KEY `ID Cart` (`ID Cart`,`ID Book`),
  KEY `ID Book` (`ID Book`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Category`
--

CREATE TABLE IF NOT EXISTS `Category` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the category',
  `Name` varchar(255) NOT NULL COMMENT 'The name of the category',
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Name` (`Name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Category Detail`
--

CREATE TABLE IF NOT EXISTS `Category Detail` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The id of the subject of the category',
  `ID Category` int(11) NOT NULL COMMENT 'The ID of the category',
  `Name` varchar(255) NOT NULL COMMENT 'The name of the subject of the category',
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Name` (`Name`),
  KEY `ID Category` (`ID Category`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Customer`
--

CREATE TABLE IF NOT EXISTS `Customer` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the customer',
  `First Name` varchar(255) NOT NULL COMMENT 'The name of the customer',
  `Last Name` varchar(255) NOT NULL COMMENT 'The last name of the customer',
  `Email` varchar(255) NOT NULL COMMENT 'The email of the customer',
  `Phone` varchar(255) NOT NULL COMMENT 'The phone number of the customer',
  `Company` varchar(255) NOT NULL COMMENT 'The company name of the customer',
  `Address` varchar(255) NOT NULL COMMENT 'The address of the customer',
  `City` varchar(255) NOT NULL COMMENT 'The city of the customer',
  `Post Code` varchar(255) NOT NULL COMMENT 'The post code of the customer',
  `State` varchar(255) NOT NULL COMMENT 'The state of the customer',
  `Country` varchar(255) NOT NULL COMMENT 'The country of the customer',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Dispatch`
--

CREATE TABLE IF NOT EXISTS `Dispatch` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `ID Order` int(11) NOT NULL COMMENT 'The ID of the order',
  `ID Warehouse` int(11) NOT NULL COMMENT 'The ID of the warehouse',
  `ID Shipping Method` int(11) NOT NULL COMMENT 'The ID of the shipping method',
  `ID Payment Method` int(11) NOT NULL COMMENT 'The ID of the payment method',
  `Status` enum('Packing','Shipping','Delivered') NOT NULL DEFAULT 'Packing' COMMENT 'The satus of the dispatch',
  PRIMARY KEY (`ID`),
  KEY `ID Order` (`ID Order`,`ID Shipping Method`,`ID Payment Method`),
  KEY `ID Shipping` (`ID Shipping Method`),
  KEY `ID Payment` (`ID Payment Method`),
  KEY `ID Shipping Method` (`ID Shipping Method`),
  KEY `ID Payment Method` (`ID Payment Method`),
  KEY `ID Warehouse` (`ID Warehouse`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Order`
--

CREATE TABLE IF NOT EXISTS `Order` (
  `ID Order` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the order',
  `ID Customer` int(11) NOT NULL COMMENT 'The ID of the customer',
  `Date` datetime NOT NULL COMMENT 'The date of the order',
  `Message` text NOT NULL COMMENT 'The message of the order',
  `ID Cart` int(11) NOT NULL COMMENT 'The ID of the cart',
  `Total` double NOT NULL,
  PRIMARY KEY (`ID Order`),
  KEY `ID Customer` (`ID Customer`),
  KEY `ID Cart` (`ID Cart`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Payment Method`
--

CREATE TABLE IF NOT EXISTS `Payment Method` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the payment method',
  `ID Warehouse` int(11) NOT NULL,
  `Name` varchar(255) NOT NULL,
  `Description` varchar(255) NOT NULL COMMENT 'The description of the payment method',
  `Account` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `ID Warehouse` (`ID Warehouse`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=7 ;

--
-- Dumping data for table `Payment Method`
--

INSERT INTO `Payment Method` (`ID`, `ID Warehouse`, `Name`, `Description`, `Account`) VALUES
(1, 2, 'Direct Bank Transfer', 'Make your payment directly into our bank account. Please use your Order ID as the payment reference. Your order wont be shipped until the funds have cleared in our account.', '0203278738'),
(2, 2, 'Monybookers', 'Moneybookers(Skrill) makes it easy for developers to accept credit cards on the web.', 'imancha_266@ymail.com'),
(3, 2, 'Paypal', 'Appropriately seize value-added quality vectors via fully researched process improvements. ', 'imancha_266@ymail.com'),
(4, 1, 'BNI', 'Transfer melalui Bank BNI', '0203278738'),
(5, 1, 'BRI', 'Transfer melalui Bank BRI', '085224057100'),
(6, 1, 'BCA', 'Transfer melalui Bank BCA', '085795525434');

-- --------------------------------------------------------

--
-- Table structure for table `Shipping Method`
--

CREATE TABLE IF NOT EXISTS `Shipping Method` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the shipping method',
  `ID Warehouse` int(11) NOT NULL COMMENT 'The id warehouse of the shipping method',
  `Name` varchar(255) NOT NULL COMMENT 'The name of the shipping method',
  `Description` varchar(255) NOT NULL COMMENT 'The description of the shipping method',
  `Cost` double NOT NULL COMMENT 'The cost of the shipping method',
  `Estimate` varchar(255) NOT NULL COMMENT 'The estimate day of the shipping method',
  PRIMARY KEY (`ID`),
  KEY `ID Warehouse` (`ID Warehouse`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=7 ;

--
-- Dumping data for table `Shipping Method`
--

INSERT INTO `Shipping Method` (`ID`, `ID Warehouse`, `Name`, `Description`, `Cost`, `Estimate`) VALUES
(1, 2, 'Standard International Postage', 'Delivered to your letterbox within', 0, '7-14 working days'),
(2, 2, 'DHL Standard Postage', 'Delivered to your letterbox within', 2.99, '2-5 working days'),
(3, 2, 'Fedex Quick Delivery', 'Delivered to your letterbox within', 6.4, '1-3 working days'),
(4, 1, 'Kantor Pos', '', 10000, '7-14 hari kerja'),
(5, 1, 'TIKI', '', 20000, '2-5 hari kerja'),
(6, 1, 'JNE', '', 40000, '1-3 hari kerja');

-- --------------------------------------------------------

--
-- Table structure for table `Stock`
--

CREATE TABLE IF NOT EXISTS `Stock` (
  `ID Warehouse` int(11) NOT NULL COMMENT 'The ID of the warehouse',
  `ID Book` int(11) NOT NULL COMMENT 'The ID of the book',
  `Stock` int(11) NOT NULL DEFAULT '0' COMMENT 'The stock of the book at the warehouse',
  `Price` double NOT NULL DEFAULT '0' COMMENT 'The price of the book',
  KEY `ID Warehouse` (`ID Warehouse`,`ID Book`),
  KEY `ID Book` (`ID Book`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Visitor`
--

CREATE TABLE IF NOT EXISTS `Visitor` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The id of the visitor',
  `ID Warehouse` int(11) NOT NULL,
  `Name` varchar(255) NOT NULL COMMENT 'The name of the visitor',
  `Datetime` datetime NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `ID Warehouse` (`ID Warehouse`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Warehouse`
--

CREATE TABLE IF NOT EXISTS `Warehouse` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the warehouse',
  `Name` varchar(255) NOT NULL COMMENT 'The name of the warehouse',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `Warehouse`
--

INSERT INTO `Warehouse` (`ID`, `Name`) VALUES
(1, 'Indonesia'),
(2, 'United States');

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Book Author`
--
ALTER TABLE `Book Author`
  ADD CONSTRAINT `Book Author_ibfk_1` FOREIGN KEY (`ID Book`) REFERENCES `Book` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Book Author_ibfk_2` FOREIGN KEY (`ID Author`) REFERENCES `Author` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Book Category`
--
ALTER TABLE `Book Category`
  ADD CONSTRAINT `Book Category_ibfk_1` FOREIGN KEY (`ID Book`) REFERENCES `Book` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Book Category_ibfk_2` FOREIGN KEY (`ID Category Detail`) REFERENCES `Category Detail` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Book Review`
--
ALTER TABLE `Book Review`
  ADD CONSTRAINT `Book Review_ibfk_1` FOREIGN KEY (`ID Book`) REFERENCES `Book` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Cart`
--
ALTER TABLE `Cart`
  ADD CONSTRAINT `Cart_ibfk_1` FOREIGN KEY (`ID Visitor`) REFERENCES `Visitor` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Cart Item`
--
ALTER TABLE `Cart Item`
  ADD CONSTRAINT `Cart Item_ibfk_1` FOREIGN KEY (`ID Cart`) REFERENCES `Cart` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Cart Item_ibfk_2` FOREIGN KEY (`ID Book`) REFERENCES `Stock` (`ID Book`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Category Detail`
--
ALTER TABLE `Category Detail`
  ADD CONSTRAINT `Category Detail_ibfk_1` FOREIGN KEY (`ID Category`) REFERENCES `Category` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Dispatch`
--
ALTER TABLE `Dispatch`
  ADD CONSTRAINT `Dispatch_ibfk_1` FOREIGN KEY (`ID Order`) REFERENCES `Order` (`ID Order`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Dispatch_ibfk_2` FOREIGN KEY (`ID Warehouse`) REFERENCES `Warehouse` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Dispatch_ibfk_3` FOREIGN KEY (`ID Shipping Method`) REFERENCES `Shipping Method` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Dispatch_ibfk_4` FOREIGN KEY (`ID Payment Method`) REFERENCES `Payment Method` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Order`
--
ALTER TABLE `Order`
  ADD CONSTRAINT `Order_ibfk_1` FOREIGN KEY (`ID Customer`) REFERENCES `Customer` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Order_ibfk_2` FOREIGN KEY (`ID Cart`) REFERENCES `Cart` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Payment Method`
--
ALTER TABLE `Payment Method`
  ADD CONSTRAINT `Payment Method_ibfk_1` FOREIGN KEY (`ID Warehouse`) REFERENCES `Warehouse` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Shipping Method`
--
ALTER TABLE `Shipping Method`
  ADD CONSTRAINT `Shipping Method_ibfk_1` FOREIGN KEY (`ID Warehouse`) REFERENCES `Warehouse` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Stock`
--
ALTER TABLE `Stock`
  ADD CONSTRAINT `Stock_ibfk_1` FOREIGN KEY (`ID Warehouse`) REFERENCES `Warehouse` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Stock_ibfk_2` FOREIGN KEY (`ID Book`) REFERENCES `Book` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Visitor`
--
ALTER TABLE `Visitor`
  ADD CONSTRAINT `Visitor_ibfk_1` FOREIGN KEY (`ID Warehouse`) REFERENCES `Warehouse` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
