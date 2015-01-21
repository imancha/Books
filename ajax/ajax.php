<?php session_start(); include_once('../inc/connect.inc');
/*
 * ajax.php
 *
 * Copyright 2015 Imancha <imancha_266@ymail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

	if(isset($_GET['order'])){
		mysql_open();
		mysql_query("START TRANSACTION");
		$sql = "INSERT INTO `Cart` VALUES (NULL,".$_SESSION['id'].")";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_affected_rows() == 1){
			$id = mysql_insert_id();
			foreach($_SESSION['cart'] as $cart){
				$sql = "INSERT INTO `Cart Item` VALUES (".$id.",".$cart['id'].",".$cart['qty'].")";
				$res = @mysql_query($sql) or die(mysql_error());
				if(mysql_affected_rows() != 1){$error=TRUE;}
			}
		}else{$error=TRUE;}
		$sql = "INSERT INTO `Customer` VALUES (NULL,'".mysql_real_escape_string(trim($_GET['a']))."','".mysql_real_escape_string(trim($_GET['b']))."','".mysql_real_escape_string(trim($_GET['c']))."','".mysql_real_escape_string(trim($_GET['d']))."','".mysql_real_escape_string(trim($_GET['e']))."','".mysql_real_escape_string(trim($_GET['f']))."','".mysql_real_escape_string(trim($_GET['g']))."','".mysql_real_escape_string(trim($_GET['h']))."','".mysql_real_escape_string(trim($_GET['i']))."','".mysql_real_escape_string(trim($_GET['j']))."')";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_affected_rows() == 1){$id_=mysql_insert_id();}else{$error=TRUE;}
		foreach($_SESSION['cart'] as $cart){
			$sql = "SELECT `Price` FROM `Stock` WHERE `ID Book`=".$cart['id']." AND `ID Warehouse`=".$_SESSION['region']." LIMIT 1";
			$res = @mysql_query($sql) or die(mysql_error());
			if(mysql_num_rows($res) == 1){
				$row = mysql_fetch_assoc($res);
				$total += $row['Price']*$cart['qty'];
			}else{$error=TRUE;}
		}
		$sql = "INSERT INTO `Order` VALUES (NULL,".$id_.",NOW(),'".mysql_real_escape_string(trim($_GET['s']))."',".$id.",".$total.")";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_affected_rows() == 1){$id__=mysql_insert_id();}else{$error=TRUE;}
		$sql = "INSERT INTO `Dispatch` VALUES (NULL,".$id__.",".$_SESSION['region'].",".$_GET['q'].",".$_GET['r'].",'Delivered')";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_affected_rows() != 1){$error=TRUE;}
		if($error){
			mysql_query("ROLLBACK");
			echo "Oops, Change a few things up and try submitting again.";
		}else{
			mysql_query("COMMIT");
			$_SESSION['cart'] = array();
			echo "OK";
		}
		mysql_close();
	}
?>
