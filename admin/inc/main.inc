<?php session_start(); ob_start();
/*
 * main.inc
 *
 * Copyright 2014 Imancha <imancha_266@ymail.com>
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

	if(isset($_POST['login'])){
		if($_POST['username'] == "imancha" AND $_POST['password'] == "imancha"){
			session_start();
			$_SESSION['name'] = "Imancha";
			header('Location: ./');
			exit();
		}
	}
	/*	Login	*/
	if(!isset($_SESSION['name'])){
		header('Location: inc/login.inc');
		exit();
	}
	/*	Logout	*/
	function logout(){
		session_start();
		session_destroy();
		header("Location: ./");
		exit();
	}
	/*	Header	*/
	function top(){
		echo '<div class="logo">
						<a href="./"><img src="images/logo.png" alt="" /></a>
					</div>
					<div class="headerinner">
						<ul class="headmenu">
<!--					<li class="odd">
								<a class="dropdown-toggle" data-toggle="dropdown" href="#">
									<span class="count"></span>
									<span class="head-icon head-message"></span>
									<span class="headmenu-label">Messages</span>
								</a>
								<ul class="dropdown-menu">
									<li class="nav-header">Messages</li>
								</ul>
							</li>
							<li>
								<a class="dropdown-toggle" data-toggle="dropdown" data-target="#">
									<span class="count"></span>
									<span class="head-icon head-users"></span>
									<span class="headmenu-label">New Users</span>
								</a>
								<ul class="dropdown-menu newusers">
									<li class="nav-header">New Users</li>
								</ul>
							</li>
							<li class="odd">
								<a class="dropdown-toggle" data-toggle="dropdown" data-target="#">
									<span class="count"></span>
									<span class="head-icon head-bar"></span>
									<span class="headmenu-label">Statistics</span>
								</a>
								<ul class="dropdown-menu">
									<li class="nav-header">Statistics</li>
								</ul>
							</li>
-->						<li class="right">
								<div class="userloggedinfo">
									<img src="images/photos/avatar5.png" alt="" />
									<div class="userinfo">
										<h5>Mohammad Abdul Iman Syah</h5>
										<ul>
											<li><a href="">Edit Profile</a></li>
											<li><a href="">Account Settings</a></li>
											<li><a href="?!=exit">Sign Out</a></li>
										</ul>
									</div>
								</div>
							</li>
						</ul><!--headmenu-->
					</div>';
	}
	/*	Left panel navigation	*/
	function navigation(){
		switch($_GET['!']){
			case 'catalogue' : $active_2 = 'active'; break;
			case 'categories' : $active_3 = 'active'; break;
			case 'customer' : $active_4 = 'active'; break;
			case 'dispatch' : $active_5 = 'active'; break;
			case 'review'		: $active_6 = 'active'; break;
			case 'shipping'	: $active_7 = 'active'; break;
			case 'payment'	: $active_8 = 'active'; break;
			case 'visitor'	: $active_9 = 'active'; break;
			case 'order'		: $active_10 = 'active'; break;
			default : $active_1 = 'active';
		}
		echo '<div class="leftmenu">
						<ul class="nav nav-tabs nav-stacked">
							<li class="nav-header">Navigation</li>
							<li class="'.$active_1.'"><a href="./"><span class="iconfa-laptop"></span> Dashboard</a></li>
							<li class="'.$active_2.'"><a href="./?!=catalogue"><span class="iconfa-book"></span> Book Catalogue</a></li>
							<li class="'.$active_3.'"><a href="./?!=categories"><span class="iconfa-th-list"></span> Book Categories</a></li>
							<li class="'.$active_4.'"><a href="./?!=customer"><span class="iconfa-group"></span> Book Customer</a></li>
							<li class="'.$active_5.'"><a href="./?!=dispatch"><span class="iconfa-road"></span> Book Dispatch</a></li>
							<li class="'.$active_10.'"><a href="./?!=order"><span class="iconfa-shopping-cart"></span> Book Order</a></li>
							<li class="'.$active_6.'"><a href="./?!=review"><span class="iconfa-star"></span> Book Review</a></li>
							<li class="'.$active_7.'"><a href="./?!=shipping"><span class="iconfa-truck"></span> Shipping Method</a></li>
							<li class="'.$active_8.'"><a href="./?!=payment"><span class="iconfa-money"></span> Payment Method</a></li>
							<li class="'.$active_9.'"><a href="./?!=visitor"><span class="iconfa-globe"></span> Visitor</a></li>
						</ul>
					</div><!--leftmenu-->';
	}
	/*	Breadcrumb	*/
	function breadcrumb(){
		$xo = '<ul class="breadcrumbs">
						<li><a href="./"><i class="iconfa-home"></i></a> <span class="separator"></span></li>';
		switch($_GET['!']){
			case 'catalogue' : $xo .= '<li><a href="./?!=catalogue">Book Catalogue</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
					default : $xo .= '<li>View</li>';
				}
			break;
			case 'categories' : $xo .= '<li><a href="./?!=categories">Book Categories</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
					default: $xo .= '<li>View</li>';
				}
			break;			
			case 'customer' : $xo .= '<li><a href="./?!=customer">Book Customer</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
					default: $xo .= '<li>View</li>';
				}
			break;
			case 'dispatch' : $xo .= '<li><a href="./?!=dispatch">Book Dispatch</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
					default: $xo .= '<li>View</li>';
				}
			break;
			case 'review' : $xo .= '<li><a href="./?!=review">Book Review</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
					default: $xo .= '<li>View</li>';
				}
			break;
			case 'shipping' : $xo .= '<li><a href="./?!=shipping">Shipping Method</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
					default: $xo .= '<li>View</li>';
				}
			break;
			case 'payment' : $xo .= '<li><a href="./?!=payment">Payment Method</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
					default: $xo .= '<li>View</li>';
				}
			break;
			case 'visitor' : $xo .= '<li><a href="./?!=visitor">Visitor</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
					default: $xo .= '<li>View</li>';
				}
			break;
			case 'order' : $xo .= '<li><a href="./?!=order">Book Order</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
					default: $xo .= '<li>View</li>';
				}
			break;
			default :
				$xo .= '<li>Dashboard</li>';
		}

		$xo .= '<li class="right">
							<a href="" data-toggle="dropdown" class="dropdown-toggle"><i class="icon-tint"></i> Color Skins</a>
							<ul class="dropdown-menu pull-right skin-color">
								<li><a href="default">Default</a></li>
								<li><a href="navyblue">Navy Blue</a></li>
								<li><a href="palegreen">Pale Green</a></li>
								<li><a href="red">Red</a></li>
								<li><a href="green">Green</a></li>
								<li><a href="brown">Brown</a></li>
							</ul>
						</li>
					</ul>';

		echo $xo;
	}
	/*	Page header	*/
	function pageheader(){
		$xo = '<form action="" method="post" class="searchbar">
						<input type="text" name="keyword" placeholder="To search type and hit enter..." />
					 </form>';

		switch($_GET['!']){
			case 'catalogue' : $icon = 'iconfa-book'; $title = 'Book Catalogue';
				switch($_GET['i']){
					case 'insert' : $subtitle = 'Insert'; break;
					case 'update' : $subtitle = 'Update'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
					default		: $subtitle = 'View'; break;
				}
			break;
			case 'categories' : $icon = 'iconfa-th-list'; $title = 'Book Categories';
				switch($_GET['i']){
					case 'insert' : $subtitle = 'Insert'; break;
					case 'update' : $subtitle = 'Update'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
					default		: $subtitle = 'View'; break;
				}
			break;			
			case 'customer' : $icon = 'iconfa-group'; $title = 'Book Customer';
				switch($_GET['i']){
					case 'insert' : $subtitle = 'Insert'; break;
					case 'update' : $subtitle = 'Update'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
					default		: $subtitle = 'View'; break;
				}
			break;
			case 'dispatch' : $icon = 'iconfa-road'; $title = 'Book Dispatch';
				switch($_GET['i']){
					case 'insert' : $subtitle = 'Insert'; break;
					case 'update' : $subtitle = 'Update'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
					default		: $subtitle = 'View'; break;
				}
			break;
			case 'review' : $icon = 'iconfa-star'; $title = 'Book Review';
				switch($_GET['i']){
					case 'insert' : $subtitle = 'Insert'; break;
					case 'update' : $subtitle = 'Update'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
					default		: $subtitle = 'View'; break;
				}
			break;
			case 'shipping' : $icon = 'iconfa-truck'; $title = 'Shipping Method';
				switch($_GET['i']){
					case 'insert' : $subtitle = 'Insert'; break;
					case 'update' : $subtitle = 'Update'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
					default		: $subtitle = 'View'; break;
				}
			break;
			case 'payment' : $icon = 'iconfa-money'; $title = 'Payment Method';
				switch($_GET['i']){
					case 'insert' : $subtitle = 'Insert'; break;
					case 'update' : $subtitle = 'Update'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
					default		: $subtitle = 'View'; break;
				}
			break;
			case 'visitor' : $icon = 'iconfa-globe'; $title = 'Visitor';
				switch($_GET['i']){
					case 'insert' : $subtitle = 'Insert'; break;
					case 'update' : $subtitle = 'Update'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
					default		: $subtitle = 'View'; break;
				}
			break;
			case 'order' : $icon = 'iconfa-shopping-cart'; $title = 'Book Order';
				switch($_GET['i']){
					case 'insert' : $subtitle = 'Insert'; break;
					case 'update' : $subtitle = 'Update'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
					default		: $subtitle = 'View'; break;
				}
			break;
			default :
				$icon = 'iconfa-laptop'; $title = 'Dashboard'; $subtitle = 'All Features Summary';
		}

		$xo .= '<div class="pageicon"><span class="'.$icon.'"></span></div>
						<div class="pagetitle"><h5>'.$subtitle.'</h5><h1>'.$title.'</h1></div>';

		echo $xo;
	}
	/*	Footer	*/
	function footer(){
		echo '<div class="footer-right">
						<span>Designed by: <a href="#">ThemePixels</a> and <a href="#">Imancha</a>. All Rights Reserved.</span>
					</div>';
	}
	function please($action, $string) {
    $output = false;
    $encrypt_method = "AES-256-CBC";
    $secret_key = 'Imancha';
    $secret_iv = 'Mohammad Abdul Iman Syah';
    $key = hash('sha256', $secret_key);
    $iv = substr(hash('sha256', $secret_iv), 0, 16);
    if($action == 'encrypt'){
			$output = openssl_encrypt($string, $encrypt_method, $key, 0, $iv);
			$output = base64_encode($output);
    }else if($action == 'decrypt'){$output = openssl_decrypt(base64_decode($string), $encrypt_method, $key, 0, $iv);}
    return $output;
	}
	/*	Main content	*/
	function main(){
		switch($_GET['!']){
			case 'catalogue' 	: require 'catalogue.inc'; break;
			case 'categories'	: require 'categories.inc'; break;
			case 'customer' 	: require 'customer.inc'; break;
			case 'dispatch' 	: require 'dispatch.inc'; break;
			case 'review'			: require 'review.inc'; break;
			case 'shipping'		: require 'shipping.inc'; break;
			case 'payment'		: require 'payment.inc'; break;
			case 'visitor'		: require 'visitor.inc'; break;
			case 'order'		: require 'order.inc'; break;
			case 'exit' : logout(); break;
			default : require 'dashboard.inc';
		}
	}
?>
