-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jan 06, 2015 at 04:56 AM
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
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=15 ;

--
-- Dumping data for table `Author`
--

INSERT INTO `Author` (`ID`, `Name`) VALUES
(14, ''),
(2, 'Adam Trachtenberg'),
(6, 'Andrew Stellman'),
(1, 'David Sklar'),
(7, 'Jennifer Greene'),
(5, 'Marc Rochkind'),
(4, 'Pete Goodliffe');

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
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `Book`
--

INSERT INTO `Book` (`ID`, `Title`, `SubTitle`, `Description`, `ISBN`, `Page`, `Year`, `Publisher`, `Language`) VALUES
(1, 'PHP Cookbook, 3rd Edition', 'Solutions & Examples for PHP Programmers', '<p>Want to understand a certain PHP programming technique? Or learn how to accomplish a particular task? This cookbook is the first place to look. With more than 350 code-rich recipes revised for PHP 5.4 and 5.5, this third edition provides updated solutions for generating dynamic web content everything from using basic data types to querying databases, and from calling RESTful APIs to testing and securing your site.\n\nEach recipe includes code solutions that you can freely use, along with a discussion of how and why they work. Whether you''re an experienced PHP programmer or coming to PHP from another language, this book is an ideal on-the-job resource.\n\nYou''ll find recipes to help you with:\n\n    Basic data types: strings, numbers, arrays, and dates and times\n    Program building blocks: variables, functions, classes, and objects\n    Web programming: cookies, forms, sessions, and authentication\n    Database access using PDO, SQLite, and other extensions\n    RESTful API clients and servers, including HTTP, XML, and OAuth\n    Key concepts: email, regular expressions, and graphics creation\n    Designing robust applications: security and encryption, error handling, debugging and testing, and performance tuning\n    Files, directories, and PHP''s Command Line Interface\n    Libraries and package managers such as Composer and PECL</p>', '9781449363758', 820, 2014, 'O''Reilly Media', 'English'),
(3, 'Becoming a Better Programmer', 'A Handbook for People Who Care About Code', '<p>If you&rsquo;re passionate about programming and want to get better at it, you&rsquo;ve come to the right source. Code Craft author Pete Goodliffe presents a collection of useful techniques and approaches to the art and craft of programming that will help boost your career and your well-being. Goodliffe presents sound advice that he&rsquo;s learned in 15 years of professional programming. The book&rsquo;s standalone chapters span the range of a software developer&rsquo;s life&mdash;dealing with code, learning the trade, and improving performance&mdash;with no language or industry bias. Whether you&rsquo;re a seasoned developer, a neophyte professional, or a hobbyist, you&rsquo;ll find valuable tips in five independent categories:</p>\r\n<ul>\r\n<li>Code-level techniques for crafting lines of code, testing, debugging, and coping with complexity</li>\r\n<li>Practices, approaches, and attitudes: keep it simple, collaborate well, reuse, and create malleable code</li>\r\n<li>Tactics for learning effectively, behaving ethically, finding challenges, and avoiding stagnation</li>\r\n<li>Practical ways to complete things: use the right tools, know what &ldquo;done&rdquo; looks like, and seek help from colleagues</li>\r\n<li>Habits for working well with others, and pursuing development as a social activity</li>\r\n</ul>', '9781491905531', 362, 2014, 'O''Reilly Media', 'English'),
(4, 'Programming Chrome Apps', 'Develop Cross-Platform Apps for Chrome', '<p>Put your web app design skills to work by learning how to create powerful and portable Chrome Apps. With this practical book, you&rsquo;ll learn how to build Google&rsquo;s unique apps to behave just like native apps so they can interact with hardware devices, access external files, and send notifications. Author Marc Rochkind takes you through a hands-on, objective tour of Chrome Apps, which run on any platform that supports the Chrome browser&mdash;including OS X, Windows, Linux, as well as Android and iOS. If you know how to work with HTML, CSS, JavaScript, and the DOM, you&rsquo;re ready to get started.</p>\r\n<ul>\r\n<li>Learn how to build, run, and debug Chrome Apps step-by-step</li>\r\n<li>Use Chrome Apps to access local files, sync files, and external files</li>\r\n<li>Take advantage of key-value-pair APIs, including sync storage and IndexedDB</li>\r\n<li>Use WebSockets, Google Cloud Messaging, and other networking methods</li>\r\n<li>Display graphics and images with Canvas, SVG, and the Media Galleries API</li>\r\n<li>Use alarms, context menus, location, the camera, Bluetooth, USB, and other APIs</li>\r\n<li>Publish apps to the Chrome Web Store with the Chrome Dev Editor</li>\r\n</ul>', '9781491904282', 274, 2014, 'O''Reilly Media', 'English'),
(5, 'Learning Agile', 'Understanding Scrum, XP, Lean, and Kanban', '<p>If you&rsquo;re passionate about programming and want to get better at it, you&rsquo;ve come to the right source. Code Craft author Pete Goodliffe presents a collection of useful techniques and approaches to the art and craft of programming that will help boost your career and your well-being. Goodliffe presents sound advice that he&rsquo;s learned...</p>', '9781449331924', 420, 2014, 'O''Reilly Media', 'English');

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

--
-- Dumping data for table `Book Author`
--

INSERT INTO `Book Author` (`ID Book`, `ID Author`) VALUES
(1, 1),
(1, 2),
(3, 4),
(3, 14),
(4, 5),
(4, 14),
(5, 1),
(5, 14),
(5, 14);

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

--
-- Dumping data for table `Book Category`
--

INSERT INTO `Book Category` (`ID Book`, `ID Category Detail`) VALUES
(1, 15),
(3, 3),
(3, 15),
(4, 12),
(4, 23),
(5, 2),
(5, 23);

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
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `Category`
--

INSERT INTO `Category` (`ID`, `Name`) VALUES
(1, 'Programming');

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
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=24 ;

--
-- Dumping data for table `Category Detail`
--

INSERT INTO `Category Detail` (`ID`, `ID Category`, `Name`) VALUES
(1, 1, '.NET & Windows Programming'),
(2, 1, 'Agile'),
(3, 1, 'Android Programming'),
(4, 1, 'Apple Programming'),
(5, 1, 'C/C++'),
(6, 1, 'C#'),
(7, 1, 'Design Patterns'),
(8, 1, 'Game Design & Development'),
(9, 1, 'Graphics & Multimedia Programming'),
(10, 1, 'iOS Programming'),
(11, 1, 'Java'),
(12, 1, 'JavaScript'),
(13, 1, 'Mobile Design & Development'),
(14, 1, 'Perl'),
(15, 1, 'PHP'),
(16, 1, 'Python'),
(17, 1, 'R'),
(18, 1, 'Ruby & Rails'),
(19, 1, 'Secure Programming'),
(20, 1, 'Software Engineering'),
(21, 1, 'Testing'),
(22, 1, 'Windows Phone Programming'),
(23, 1, 'Other Programming Languages');

-- --------------------------------------------------------

--
-- Table structure for table `Customer`
--

CREATE TABLE IF NOT EXISTS `Customer` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the customer',
  `Name` varchar(255) NOT NULL COMMENT 'The name of the customer',
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
  `ID Order` int(11) NOT NULL COMMENT 'The ID of the order',
  `ID Warehouse` int(11) NOT NULL COMMENT 'The ID of the warehouse',
  `ID Shipping Method` int(11) NOT NULL COMMENT 'The ID of the shipping method',
  `ID Payment Method` int(11) NOT NULL COMMENT 'The ID of the payment method',
  `Date` datetime NOT NULL COMMENT 'The date of the dispatch',
  KEY `ID Order` (`ID Order`,`ID Shipping Method`,`ID Payment Method`),
  KEY `ID Shipping` (`ID Shipping Method`),
  KEY `ID Payment` (`ID Payment Method`),
  KEY `ID Shipping Method` (`ID Shipping Method`),
  KEY `ID Payment Method` (`ID Payment Method`),
  KEY `ID Warehouse` (`ID Warehouse`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `Order`
--

CREATE TABLE IF NOT EXISTS `Order` (
  `ID Order` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the order',
  `ID Customer` int(11) NOT NULL COMMENT 'The ID of the customer',
  `Date` datetime NOT NULL COMMENT 'The date of the order',
  `ID Cart` int(11) NOT NULL COMMENT 'The ID of the cart',
  PRIMARY KEY (`ID Order`),
  KEY `ID Customer` (`ID Customer`),
  KEY `ID Cart` (`ID Cart`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Payment`
--

CREATE TABLE IF NOT EXISTS `Payment` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the payment',
  `Name` varchar(255) NOT NULL COMMENT 'The name of the payment',
  `Account` varchar(255) NOT NULL COMMENT 'The account of the payment',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Payment Method`
--

CREATE TABLE IF NOT EXISTS `Payment Method` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the payment method',
  `ID Warehouse` int(11) NOT NULL COMMENT 'The ID of the warehouse',
  `ID Payment` int(11) NOT NULL COMMENT 'The ID of the payment',
  PRIMARY KEY (`ID`),
  KEY `ID Warehouse` (`ID Warehouse`),
  KEY `ID Payment` (`ID Payment`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Shipping`
--

CREATE TABLE IF NOT EXISTS `Shipping` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the shipping',
  `Name` int(255) NOT NULL COMMENT 'The name of the shipping',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Shipping Method`
--

CREATE TABLE IF NOT EXISTS `Shipping Method` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The ID of the shipping method',
  `ID Warehouse` int(11) NOT NULL COMMENT 'The ID of the warehouse',
  `ID Shipping` int(11) NOT NULL COMMENT 'The ID of the shipping',
  PRIMARY KEY (`ID`),
  KEY `ID Warehouse` (`ID Warehouse`),
  KEY `ID Shipping` (`ID Shipping`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

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

--
-- Dumping data for table `Stock`
--

INSERT INTO `Stock` (`ID Warehouse`, `ID Book`, `Stock`, `Price`) VALUES
(2, 1, 10, 59.99),
(2, 3, 1, 49.99),
(1, 4, 3, 498000),
(2, 4, 8, 39.99),
(1, 5, 5, 539800),
(2, 5, 13, 44.99);

-- --------------------------------------------------------

--
-- Table structure for table `Visitor`
--

CREATE TABLE IF NOT EXISTS `Visitor` (
  `ID` int(11) NOT NULL AUTO_INCREMENT COMMENT 'The id of the visitor',
  `Name` varchar(255) NOT NULL COMMENT 'The name of the visitor',
  `Datetime` datetime NOT NULL,
  PRIMARY KEY (`ID`)
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
  ADD CONSTRAINT `Payment Method_ibfk_1` FOREIGN KEY (`ID Warehouse`) REFERENCES `Warehouse` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Payment Method_ibfk_2` FOREIGN KEY (`ID Payment`) REFERENCES `Payment` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Shipping Method`
--
ALTER TABLE `Shipping Method`
  ADD CONSTRAINT `Shipping Method_ibfk_1` FOREIGN KEY (`ID Warehouse`) REFERENCES `Warehouse` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Shipping Method_ibfk_2` FOREIGN KEY (`ID Shipping`) REFERENCES `Shipping` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Stock`
--
ALTER TABLE `Stock`
  ADD CONSTRAINT `Stock_ibfk_1` FOREIGN KEY (`ID Warehouse`) REFERENCES `Warehouse` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Stock_ibfk_2` FOREIGN KEY (`ID Book`) REFERENCES `Book` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
