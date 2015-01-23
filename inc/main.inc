<?php session_start(); ob_start(); include_once('connect.inc'); include_once('dist.inc');
/*
 * main.inc
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

	if(isset($_GET['MyRegionIs'])){
		session_start();
		$_SESSION['region'] = array();
		$_SESSION['cart'] = array();
		$_SESSION['wishlist'] = array();
		switch($_GET['MyRegionIs']){
			case '>id' : $_SESSION['region'] = 1; break;
			case '>us' : $_SESSION['region'] = 2; break;
		}
		mysql_open();
		$sql = "INSERT INTO `Visitor` VALUES (NULL,".$_SESSION['region'].",'".$_SERVER['REMOTE_ADDR']."',now())";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_affected_rows() == 1){$_SESSION['id'] = mysql_insert_id();}
		mysql_close();
		header('Location: ./');
		exit();
	}
	if(!isset($_SESSION['region']) || ($_SESSION['region'] != 1 AND $_SESSION['region'] != 2)){ header('Location: ajax/region.php'); exit(); }
	if(isset($_GET['cart'])){
		switch($_GET['cart']){
			case 'plus':
			case 'add':
				$add = FALSE;
				foreach($_SESSION['cart'] as $cart){
					$i++;
					if($cart['id'] == $_GET['item']){$add = TRUE; $idx = $i; $qty = $cart['qty'];}
				}
				if($add){$_SESSION['cart'][$idx-1] = array('id'=>$_GET['item'],'qty'=>$qty+1);}
				else{$_SESSION['cart'][] = array('id'=>$_GET['item'],'qty'=>1);}
			break;
			case 'minus':
				foreach($_SESSION['cart'] as $cart){
					$i++;
					if($cart['id'] == $_GET['item']){$idx = $i; $qty = $cart['qty'];
						if($qty-1 < 1){ header('Location: ./?cart=remove&item='.$cart['id']); exit();}}
				}
				$_SESSION['cart'][$idx-1] = array('id'=>$_GET['item'],'qty'=>$qty-1);
			break;
			case 'remove':
				if(count($_SESSION['cart']) == 1){
					$_SESSION['cart'] = array();
				}else{
					foreach($_SESSION['cart'] as $cart){
						if($cart['id'] != $_GET['item']){
							$cart_['cart_'][] = array('id'=>$cart['id'],'qty'=>$cart['qty']);
						}
					}
					$_SESSION['cart'] = $cart_['cart_'];
				}
			break;
		}
		header('Location: '.$_SERVER['HTTP_REFERER']);
		exit();
	}
	if(isset($_GET['wishlist'])){
		switch($_GET['wishlist']){
			case 'plus':
			case 'add':
				$add = FALSE;
				foreach($_SESSION['wishlist'] as $cart){
					$i++;
					if($cart['id'] == $_GET['item']){$add = TRUE; $idx = $i; $qty = $cart['qty'];}
				}
				if($add){$_SESSION['wishlist'][$idx-1] = array('id'=>$_GET['item'],'qty'=>$qty+1);}
				else{$_SESSION['wishlist'][] = array('id'=>$_GET['item'],'qty'=>1);}
			break;
			case 'minus':
				foreach($_SESSION['wishlist'] as $cart){
					$i++;
					if($cart['id'] == $_GET['item']){$idx = $i; $qty = $cart['qty'];
						if($qty-1 < 1){ header('Location: ./?wishlist=remove&item='.$cart['id']); exit();}}
				}
				$_SESSION['wishlist'][$idx-1] = array('id'=>$_GET['item'],'qty'=>$qty-1);
			break;
			case 'remove':
				foreach($_SESSION['wishlist'] as $cart){
					if($cart['id'] != $_GET['item']){$cart_['cart_'][] = array('id'=>$cart['id'],'qty'=>$cart['qty']);}
				}
				$_SESSION['wishlist'] = $cart_['cart_'];
			break;
		}
		header('Location: '.$_SERVER['HTTP_REFERER']);
		exit();
	}
	function top(){
		echo '<div class="row">
						<div class="col-md-12">
							<div class="topheadrow">
								<ul class="nav nav-pills pull-left">
									<li><a id="date_time"></a></li>
								</ul>
								<ul class="nav nav-pills pull-right">
									<li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" data-hover="dropdown" href="#">'.($_SESSION['region']==1 ? 'IND' : 'ENG').'<i class="fa fa-angle-down fa-fw"></i> </a>
										<ul class="dropdown-menu" role="menu">
											<li><a href="./?MyRegionIs=>us">ENG</a></li>
											<li><a href="./?MyRegionIs=>id">IND</a></li>
										</ul>
									</li>
									<li> <a href="./?!=wishlist"> <i class="fa fa-heart fa-fw"></i> <span class="hidden-xs">'.$GLOBALS['O5'].'('.count($_SESSION['wishlist']).')</span></a> </li>
									<li> <a href="./?!=cart"> <i class="fa fa-shopping-cart fa-fw"></i> <span class="hidden-xs">'.$GLOBALS['O6'].'</span></a> </li>
								</ul>
							</div>
						</div>
					</div>';
	}
	function logo(){
		echo '<div class="col-lg-3 col-xs-12">
						<div class="logo">
							<a href="./" title="Imancha - Onine Shop">
								<div class="logoimage"><i class="fa fa-shopping-cart fa-fw"></i></div>
								<div class="logotext"><span><strong>IMANCHA</strong></span><span><sup>OS</sup></span></div>
								<span class="slogan">ONLINE SHOP</span>
							</a>
						</div>
					</div>';
	}
	function search(){
		echo '<div class="col-lg-3 col-md-4 col-sm-5 col-xs-12 pull-right">
							<div class="searchbar">
								<form action="">
									<ul class="pull-left">
										<li class="input-prepend dropdown" data-select="true"> <a class="add-on dropdown-toggle" data-hover="dropdown" data-toggle="dropdown" href=""> <span class="dropdown-display">All Categories</span> <i class="fa fa-sort fa-fw"></i> </a>
											<!-- this hidden field is used to contain the selected option from the dropdown -->
											<input class="dropdown-field" type="hidden" value="All Categories"/>
											<ul class="dropdown-menu" role="menu">';
		mysql_open();
		$sql = "SELECT * FROM `Category`";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				echo '					<li><a href="" data-value="'.$row['Name'].'">'.$row['Name'].'</a></li>';
			}
		}
		mysql_close();
		echo '						</ul>
										</li>
									</ul>
									<div class="searchbox pull-left">
										<input class="searchinput" id="search" name="q" placeholder="Search..." type="search">
										<button class="fa fa-search fa-fw" type="submit"></button>
									</div>
								</form>
							</div>
						</div>';
	}
	function mobile(){
		echo '<div class="dropdown-menu flyout-menu">
						<!-- Sub Menu -->
						<ul>
							<li><a href="./?!=about">'.$GLOBALS['O4'].'</a></li>
							<li> <a href="#"><span>'.$GLOBALS['O8'].'</span> <i class="fa fa-caret-right"></i> </a>
								<ul class="dropdown-menu sub flyout-menu">
									<li><a href="./?view=grid">'.$GLOBALS['O9'].'</a></li>
									<li><a href="./?view=list">'.$GLOBALS['O10'].'</a></li>
								</ul>
							</li>
							<li><a href="./?!=wishlist">'.$GLOBALS['O5'].'</a></li>
							<li><a href="./?!=cart">'.$GLOBALS['O6'].'</a></li>
							<li><a href="./?!=checkout">'.$GLOBALS['O7'].'</a></li>
							<li><a href="./?!=contact">'.$GLOBALS['O11'].'</a></li>
						</ul>
						<!-- end: Sub Menu -->
					</div>';
	}
	function tablet(){
		echo '<div class="dropdown-menu flyout-menu">
						<!-- Sub Menu -->
						<ul>
							<li><a href="./">'.$GLOBALS['O0'].'</a></li>
							<li><a href="./?!=about">'.$GLOBALS['O11'].'</a></li>
							<li><a href="#"><span>'.$GLOBALS['O8'].'</span></a>
								<ul class="dropdown-menu sub flyout-menu">
									<li><a href="./?view=grid">'.$GLOBALS['O9'].'</a></li>
									<li><a href="./?view=list">'.$GLOBALS['O10'].'</a></li>
								</ul>
							</li>
							<li><a href="./?!=cart">'.$GLOBALS['O6'].'</a></li>
							<li><a href="./?!=checkout">'.$GLOBALS['O7'].'</a></li>
							<li><a href="./?!=contact">'.$GLOBALS['O11'].'</a></li>
						</ul>
						<!-- end: Sub Menu -->
					</div>';
	}
	function total(){
		if(!empty($_SESSION['cart'])){
			mysql_open();
			foreach($_SESSION['cart'] as $cart){
				$sql = "SELECT `Price` FROM `Stock` WHERE `ID Book`=".$cart['id']." AND `ID Warehouse`=".$_SESSION['region']." LIMIT 1";
				$res = @mysql_query($sql) or die(mysql_error());
				if(mysql_num_rows($res) == 1){$row = mysql_fetch_assoc($res); $total += $row['Price']*$cart['qty'];}
			}
			mysql_close();
		}else{$total = 0;}
		return $total;
	}
	function item(){
		if(!empty($_SESSION['cart'])){
			mysql_open();
			foreach($_SESSION['cart'] as $cart){
				$sql = "SELECT a.`ID`,a.`Title`,a.`ISBN`,b.`Price` FROM `Book` a JOIN `Stock` b ON a.`ID`=b.`ID Book` WHERE a.`ID`=".$cart['id']." AND b.`ID Warehouse`=".$_SESSION['region']." LIMIT 1";
				$res = @mysql_query($sql) or die(mysql_error());
				if(mysql_num_rows($res) == 1){
					$row = mysql_fetch_assoc($res);
					$item .= '<div class="qc-row qc-row-item"> <span class="qc-col-qty">'.$cart['qty'].'</span> <span class="qc-col-name"><a href="./?product='.$row['ISBN'].'">'.$row['Title'].'</a></span> <span class="qc-col-price">'.symbol().$row['Price'].'</span> <span class="qc-col-remove"><button class="btn" data-toggle="tooltip" title="Remove" onclick="window.location=\'./?cart=remove&item='.$row['ID'].'\'"><i class="fa fa-times fa-fw"></i> </button>  </span> </div>';
				}
			}
			mysql_close();
		}else{$item = "";}
		return $item;
	}
	function navigation(){
		echo '<ul class="nav nav-pills nav-justified">
            <li> <a href="./"> <i class="fa fa-home fa-fw"></i> <span class="hidden-sm">'.$GLOBALS['O0'].'</span></a> </li>
            <li> <a href="./?!=about"> <i class="fa fa-info-circle fa-fw"></i> <span class="hidden-sm">'.$GLOBALS['O4'].'</span></a> </li>
            <li> <a href="./?!=contact"> <i class="fa fa-pencil-square-o fa-fw"></i> <span class="hidden-sm ">'.$GLOBALS['O11'].'</span></a> </li>
            <li class="dropdown"> <a href="./?!=cart"> <i class="fa fa-shopping-cart fa-fw"></i> <span class="hidden-sm"> '.(count($_SESSION['cart']) < 0 ? '0' : count($_SESSION['cart'])).' items | '.symbol().total().'</span></a>
              <!-- Quick Cart -->
              <div class="dropdown-menu quick-cart">
								<div class="qc-row qc-row-heading"> <span class="qc-col-qty">QTY</span> <span class="qc-col-name">'.count($_SESSION['cart']).' items in bag</span> <span class="qc-col-price">'.symbol().total().'</span> </div>
								'.item().'
                <div class="qc-row-bottom"><button class="btn qc-btn-viewcart" onclick="window.location=\'./?!=cart\'">'.$GLOBALS['O12'].'</button><button class="btn qc-btn-checkout" onclick="window.location=\'./?!=checkout\'">'.$GLOBALS['O7'].'</button></div>
              </div>
              <!-- end: Quick Cart -->
            </li>
          </ul>';
	}
	function banner(){
		echo '<div class="container">
						<div class="row">
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-4">
								<div class="rec-banner blue">
									<div class="banner"> <i class="fa fa-thumbs-up"></i>
										<h3>Guarantee</h3>
										<p>100% Money Back Guarantee*</p>
									</div>
								</div>
							</div>
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-4">
								<div class="rec-banner red">
									<div class="banner"> <i class="fa fa-tags"></i>
										<h3>Affordable</h3>
										<p>Convenient & affordable prices for you</p>
									</div>
								</div>
							</div>
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-4">
								<div class="rec-banner orange">
									<div class="banner"> <i class="fa fa-headphones"></i>
										<h3>24/7 Support</h3>
										<p>We support everything we sell</p>
									</div>
								</div>
							</div>
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-4">
								<div class="rec-banner lightblue">
									<div class="banner"> <i class="fa fa-book"></i>
										<h3>Summer Sale</h3>
										<p>Upto 50% off on all books</p>
									</div>
								</div>
							</div>
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-4">
								<div class="rec-banner darkblue">
									<div class="banner"> <i class="fa fa-gift"></i>
										<h3>Surprise Gift</h3>
										<p>Value $50 on orders over $700</p>
									</div>
								</div>
							</div>
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-4">
								<div class="rec-banner black">
									<div class="banner"> <i class="fa fa-truck"></i>
										<h3>Free Shipping</h3>
										<p>All over in world over $100</p>
									</div>
								</div>
							</div>
						</div>
					</div>
					<!-- end: Rectangle Banners -->
					<div class="row clearfix f-space30"></div>';
	}
	function footer(){
		echo '<div class="copyrights">
						<div class="container">
							<div class="row">
								<div class="col-lg-8 col-sm-6 col-xs-6"> <span class="copytxt">Designed by <a href="#">Flatro</a> and <a href="#">Imancha</a> - All rights reserved</span> </div>
								<div class="col-lg-4 col-sm-6 col-xs-6 payment-icons"> <a href="#"> <img src="images/icons/discover.png" alt="discover"> </a> <a href="#a"> <img src="images/icons/2co.png" alt="2co"> </a> <a href="#a"> <img src="images/icons/paypal.png" alt="paypal"> </a> <a href="#a"> <img src="images/icons/mastercard.png" alt="master card"> </a> <a href="#a"> <img src="images/icons/visa.png" alt="visa card"> </a> <a href="#a"> <img src="images/icons/moneybookers.png" alt="moneybookers"> </a> </div>
							</div>
						</div>
					</div>';
	}
	function error(){
		echo '<div class="container">
						<div class="errorpage">
							<div class="errortitle">
								<h4 class="animate0 fadeInUp">The page you are looking for has not been found :(</h4>
								<span class="animate1 bounceIn">4</span>
								<span class="animate2 bounceIn">0</span>
								<span class="animate3 bounceIn">4</span>
								<div class="errorbtns animate4 fadeInUp">
									<button onclick="history.back()" class="btn color3 large">Go to Previous Page</button>
								</div>
							</div>
						</div>
					</div>';
	}
	function breadcrumb(){
		if(isset($_GET['product']) AND !empty($_GET['product'])){
			mysql_open();
			$sql = "SELECT * FROM `Book` WHERE `ISBN`=".$_GET['product']." LIMIT 1";
			$res = @mysql_query($sql) or die(mysql_error());
			if(mysql_num_rows($res) == 1){
				$row = mysql_fetch_assoc($res);
				echo '<i class="fa fa-angle-right fa-fw"></i> '.$row['Title'];
			}
			mysql_close();
		}else if(isset($_GET['!'])){
			switch($_GET['!']){
				case 'about': echo '<i class="fa fa-angle-right fa-fw"></i> '.$GLOBALS['O4'].''; break;
				case 'contact': echo '<i class="fa fa-angle-right fa-fw"></i> '.$GLOBALS['O11'].''; break;
			}
		}
	}
	function categories(){
		mysql_open();
		$sql = "SELECT * FROM `Category` ORDER BY RAND() LIMIT 7";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				echo '<li><a href="#"><i class="fa fa-book"></i> <span>'.$row['Name'].'</span> <i class="fa fa-angle-right"></i> </a>';
				$sql_ = "SELECT DISTINCT(b.`Name`) FROM `Category` a JOIN `Category Detail` b ON a.`ID` = b.`ID Category` JOIN `Book Category` c ON b.`ID` = c.`ID Category Detail` JOIN `Stock` d ON c.`ID Book` = d.`ID Book` WHERE a.`ID`=".$row['ID']." AND d.`ID Warehouse`=".$_SESSION['region']." ORDER BY `Name` ASC";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) > 0){
					echo '<div class="dropdown-menu flyout-menu">
									<ul>';
					while($row_ = mysql_fetch_assoc($res_)){
						echo '	<li><a href="./?tags='.str_replace(" ","_",$row_['Name']).'">'.$row_['Name'].'</a></li>';
					}
					echo '	</ul>
								</div>';
				}
				echo '</li>';
			}
		}
		mysql_close();
	}
	function symbol(){ if($_SESSION['region'] == 1) return 'Rp '; else return '$ '; }
	function special(){
		mysql_open();
		$sql = "SELECT * FROM `Stock` WHERE `ID Warehouse` = ".$_SESSION['region']." ORDER BY RAND() LIMIT 3";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			echo '<div class="clearfix f-space30"></div>
						<div class="box-heading"><span>'.$GLOBALS['O13'].'</span></div>
						<div class="box-content">
							<div class="box-products slide carousel-fade" id="productc2">
								<ol class="carousel-indicators">
									<li class="active" data-slide-to="0" data-target="#productc2"></li>
									<li class="" data-slide-to="1" data-target="#productc2"></li>
									<li class="" data-slide-to="2" data-target="#productc2"></li>
								</ol>
								<div class="carousel-inner">';
			while($row = mysql_fetch_assoc($res)){
				$sql_ = "SELECT * FROM `Book` WHERE `ID` = ".$row['ID Book']." LIMIT 1";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) == 1){
					$row_ = mysql_fetch_assoc($res_);
					if($i == 0){ $x=' active'; }else{ $x=''; } $i++;
					echo '	<!-- item -->
									<div class="item'.$x.'">
										<div class="product-block">
											<div class="image"><a class="img" href="./?product='.$row_['ISBN'].'"><img alt="'.$row_['Title'].'" src="images/cover/'.$row_['Title'].'.png" title="'.$row_['Title'].'"></a> </div>
											<div class="product-meta">
												<div class="name"><a href="./?product='.$row_['ISBN'].'">'.$row_['Title'].'</a></div>
												<div class="big-price"> <span class="price-new"><span class="sym">'.symbol().'</span>'.$row['Price'].'</span> </div>
												<div class="big-btns"> <button class="btn btn-default btn-view pull-left" onclick="window.location=\'./?product='.$row_['ISBN'].'\'">'.$GLOBALS['O14'].'</button></button> <button class="btn btn-default btn-addtocart pull-right" onclick="window.location=\'./?cart=add&item='.$row_['ID'].'\'">'.$GLOBALS['O15'].'</button> </div>
											</div>
											<div class="meta-back"></div>
										</div>
									</div>
									<!-- end: item -->';
				}
			}
			echo '	</div>
						</div>
						<div class="carousel-controls"> <a class="carousel-control left" data-slide="prev" href="#productc2"> <i class="fa fa-angle-left fa-fw"></i> </a> <a class="carousel-control right" data-slide="next" href="#productc2"> <i class="fa fa-angle-right fa-fw"></i> </a> </div>
						<div class="nav-bg"></div>
					</div>';
		}
		mysql_close();
	}
	function bestseller(){
		mysql_open();
		$sql = "SELECT * FROM `Stock` WHERE `ID Warehouse` = ".$_SESSION['region']." ORDER BY RAND() LIMIT 3";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			echo '<div class="clearfix f-space30"></div>
						<div class="box-heading"><span>'.$GLOBALS['O16'].'</span></div>
						<div class="box-content">
							<div class="box-products slide carousel-fade" id="productc4">
								<ol class="carousel-indicators">
									<li class="active" data-slide-to="0" data-target="#productc4"></li>
									<li class="" data-slide-to="1" data-target="#productc4"></li>
									<li class="" data-slide-to="2" data-target="#productc4"></li>
								</ol>
								<div class="carousel-inner">';
			while($row = mysql_fetch_assoc($res)){
				$sql_ = "SELECT * FROM `Book` WHERE `ID` = ".$row['ID Book']." LIMIT 1";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) == 1){
					$row_ = mysql_fetch_assoc($res_);
					if($i == 0){ $x=' active'; }else{ $x=''; } $i++;
					echo '	<!-- item -->
									<div class="item'.$x.'">
										<div class="product-block">
											<div class="image"><a class="img" href="./?product='.$row_['ISBN'].'"><img alt="'.$row_['Title'].'" src="images/cover/'.$row_['Title'].'.png" title="'.$row_['Title'].'"></a> </div>
											<div class="product-meta">
												<div class="name"><a href="./?product='.$row_['ISBN'].'">'.$row_['Title'].'</a></div>
												<div class="big-price"> <span class="price-new"><span class="sym">'.symbol().'</span>'.$row['Price'].'</span> </div>
												<div class="big-btns"> <button class="btn btn-default btn-view pull-left" onclick="window.location=\'./?product='.$row_['ISBN'].'\'">'.$GLOBALS['O14'].'</button></button> <button class="btn btn-default btn-addtocart pull-right" onclick="window.location=\'./?cart=add&item='.$row_['ID'].'\'">'.$GLOBALS['O15'].'</button> </div>
											</div>
											<div class="meta-back"></div>
										</div>
									</div>
									<!-- end: item -->';
				}
			}
			echo '		</div>
							</div>
							<div class="carousel-controls"> <a class="carousel-control left" data-slide="prev" href="#productc4"> <i class="fa fa-angle-left fa-fw"></i> </a> <a class="carousel-control right" data-slide="next" href="#productc4"> <i class="fa fa-angle-right fa-fw"></i> </a> </div>
							<div class="nav-bg"></div>
						</div>';
		}
		mysql_close();
	}
	function main(){
		if(isset($_GET['product']) AND !empty($_GET['product'])){require 'product.inc';}
		else if(isset($_GET['!'])){
			if($_GET['!']=='about') require 'about.inc';
			else if($_GET['!']=='contact') require 'contact.inc';
			else if($_GET['!']=='cart') require 'cart.inc';
			else if($_GET['!']=='checkout') require 'checkout.inc';
			else if($_GET['!']=='wishlist') require 'wishlist.inc';
			else if($_GET['!']=='order') require 'order.inc';}
		else{require 'index.inc';}
	}
?>
