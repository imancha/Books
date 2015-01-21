<?php include_once('../inc/connect.inc');
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

	function address(){
		echo 'address';
	}
	function delete(){
		mysql_open();
		mysql_query("START TRANSACTION");
		$sql = "DELETE FROM `Category Detail` WHERE `ID`=".$_GET[')']."";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_affected_rows() == 1){
			mysql_query("COMMIT");
			echo '<div class="alert alert-success">
							<button class="close" type="button" data-dismiss="alert">x</button>
							<strong>Success! </strong>
							Deleted from Categories.
						</div>';
		}else{
			mysql_query("ROLLBACK");
			echo '<div class="alert alert-error">
							<button class="close" type="button" data-dismiss="alert">x</button>
							<strong>Failed! </strong>
							Deleted from Categories.
						</div>';
		}
		mysql_close();
	}
	function updateC(){
		mysql_open();
		mysql_query("START TRANSACTION");
		$sql = "UPDATE `Category` SET `Name`=".$_GET['*']." WHERE `ID`=".$_GET[')']." LIMIT 1";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_affected_rows() == 1){mysql_query("COMMIT"); echo 'OK';}
		else{mysql_query("ROLLBACK");}
		mysql_close();
	}
	
	switch($_GET['!']){
		case 'address' : address(); break;
		case 'categories' : updateC(); break;
	}
?>
