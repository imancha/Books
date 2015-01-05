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
							<li class="odd">
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
							<li class="right">
								<div class="userloggedinfo">
									<img src="images/photos/avatar5.png" alt="" />
									<div class="userinfo">
										<h5>Mohammad Abdul Iman Syah <small>- imancha_266@ymail.com</small></h5>
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
			case 'catalogue' : $active_2 = 'active'; $block_2 = " style='display:block;'";				
				switch($_GET['i']){
					case 'insert' : $active_2a = 'active'; break;
					case 'update' : $active_2b = 'active'; break;
					case 'view'		: $active_2c = 'active'; break;
					case 'delete'	: $active_2d = 'active'; break;
				}			
			break;
			case 'categories' : $active_3 = 'active'; $block_3 = " style='display:block;'";				
				switch($_GET['i']){
					case 'insert' : $active_3a = 'active'; break;
					case 'update' : $active_3b = 'active'; break;
					case 'view'		: $active_3c = 'active'; break;
					case 'delete'	: $active_3d = 'active'; break;
				}			
			break;
			default :
				$active_1 = 'active';
		}
		
		echo '<div class="leftmenu">        
						<ul class="nav nav-tabs nav-stacked">
							<li class="nav-header">Navigation</li>
							<li class="'.$active_1.'"><a href="./"><span class="iconfa-laptop"></span> Dashboard</a></li>						
							<li class="dropdown '.$active_2.'"><a href=""><span class="iconfa-book"></span> Book Catalogue</a>
								<ul'.$block_2.'>
									<li class="'.$active_2a.'"><a href="?!=catalogue&i=insert">Insert</a></li>
									<li class="'.$active_2b.'"><a href="?!=catalogue&i=update">Update</a></li>
									<li class="'.$active_2c.'"><a href="?!=catalogue&i=view">View</a></li>
									<li class="'.$active_2d.'"><a href="?!=catalogue&i=delete">Delete</a></li>
								</ul>
							</li>
							<li class="dropdown '.$active_3.'"><a href=""><span class="iconfa-th-list"></span> Book Categories</a>
								<ul'.$block_3.'>
									<li class="'.$active_3a.'"><a href="?!=categories&i=insert">Insert</a></li>
									<li class="'.$active_3b.'"><a href="?!=categories&i=update">Update</a></li>
									<li class="'.$active_3c.'"><a href="?!=categories&i=view">View</a></li>
									<li class="'.$active_3d.'"><a href="?!=categories&i=delete">Delete</a></li>
								</ul>
							</li>
						</ul>
					</div><!--leftmenu-->';
	}
	/*	Breadcrumb	*/
	function breadcrumb(){
		$xo = '<ul class="breadcrumbs">
						<li><a href="./"><i class="iconfa-home"></i></a> <span class="separator"></span></li>';

		switch($_GET['!']){
			case 'catalogue' : $xo .= '<li><a href="">Book Catalogue</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'view'		: $xo .= '<li>View</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
				}
			break;
			case 'categories' : $xo .= '<li><a href="">Book Categories</a> <span class="separator"></span></li>';
				switch($_GET['i']){
					case 'insert' : $xo .= '<li>Insert</li>'; break;
					case 'update' : $xo .= '<li>Update</li>'; break;
					case 'view'		: $xo .= '<li>View</li>'; break;
					case 'delete'	: $xo .= '<li>Delete</li>'; break;
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
					case 'view'		: $subtitle = 'View'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
				}
			break;
			case 'categories' : $icon = 'iconfa-th-list'; $title = 'Book Categories';
				switch($_GET['i']){
					case 'insert' : $subtitle = 'Insert'; break;
					case 'update' : $subtitle = 'Update'; break;
					case 'view'		: $subtitle = 'View'; break;
					case 'delete'	: $subtitle = 'Delete'; break;
				}
			break;
			default :
				$icon = 'iconfa-laptop'; $title = 'Dashboard'; $subtitle = 'All Features Summary';
		}

		$xo .= '<div class="pageicon"><span class="'.$icon.'"></span></div>
						<div class="pagetitle">
							<h5>'.$subtitle.'</h5>
							<h1>'.$title.'</h1>
						</div>';

		echo $xo;
	}
	/*	Footer	*/
	function footer(){
		echo '<div class="footer-left">
						<span>&copy; 2013. Shamcey Admin Template. All Rights Reserved.</span>
					</div>
					<div class="footer-right">
						<span>Designed by: <a href="http://themepixels.com/">ThemePixels</a></span>
					</div>';
	}
	/*	Main content	*/
	function main(){
		switch($_GET['!']){			
			case 'catalogue' 	: require 'catalogue.inc'; break;
			case 'categories'	: require 'categories.inc'; break;
			case 'exit' : logout(); break;
			default : require 'dashboard.inc';
		}
	}
?>
