<?php session_start(); ob_start(); include_once('connect.inc');
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
		session_destroy();
		session_start();
		switch($_GET['MyRegionIs']){
			case '>id' : $_SESSION['region'] = 1; break;
			case '>us' : $_SESSION['region'] = 2; break;
		}
		header('Location: ./');
		exit();
	}
	if(!isset($_SESSION['region']) || ($_SESSION['region'] != 1 AND $_SESSION['region'] != 2)){ header('Location: inc/region.inc'); exit(); }
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
				foreach($_SESSION['cart'] as $cart){
					if($cart['id'] != $_GET['item']){$cart_['cart_'][] = array('id'=>$cart['id'],'qty'=>$cart['qty']);}
				}
				$_SESSION['cart'] = $cart_['cart_'];
			break;
		}
		header('Location: '.$_SERVER['HTTP_REFERER']);
		exit();
	}
	function top(){
		echo '<div class="row">
						<div class="col-md-12">
							<div class="topheadrow">
								<ul class="nav nav-pills pull-right">
									<li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" data-hover="dropdown" href="#a">ENG <i class="fa fa-angle-down fa-fw"></i> </a>
										<ul class="dropdown-menu" role="menu">
											<li><a href="#a">ENG</a></li>
											<li><a href="#a">IND</a></li>
										</ul>
									</li>
									<li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" data-hover="dropdown" href="#a">USD <i class="fa fa-angle-down fa-fw"></i> </a>
										<ul class="dropdown-menu" role="menu">
											<li><a href="#a">USD</a></li>
											<li><a href="#a">RP</a></li>
										</ul>
									</li>
									<li> <a href="#a"> <i class="fa fa-heart fa-fw"></i> <span class="hidden-xs">Wishlist(0)</span></a> </li>
									<li> <a href="./?!=cart"> <i class="fa fa-shopping-cart fa-fw"></i> <span class="hidden-xs">My Cart</span></a> </li>
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
								<form action="#">
									<ul class="pull-left">
										<li class="input-prepend dropdown" data-select="true"> <a class="add-on dropdown-toggle" data-hover="dropdown" data-toggle="dropdown" href=""> <span class="dropdown-display">All Categories</span> <i class="fa fa-sort fa-fw"></i> </a>
											<!-- this hidden field is used to contain the selected option from the dropdown -->
											<input class="dropdown-field" type="hidden" value="All Categories"/>
											<ul class="dropdown-menu" role="menu">';
		mysql_open();
		$sql = "SELECT * FROM `Category` WHERE `Name` IN (".implode(', ',setcategories()).")";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				echo '					<li><a href="" data-value="'.$row['Name'].'">'.$row['Name'].'</a></li>';
			}
		}
		mysql_close();
		echo '						<li><a href="" data-value="All Categories">All Categories</a></li>
											</ul>
										</li>
									</ul>
									<div class="searchbox pull-left">
										<input class="searchinput" id="search" placeholder="Search..." type="search">
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
							<li><a href="./?!=about">About us</a></li>
							<li> <a href=""><span>Account</span> <i class="fa fa-caret-right"></i> </a>
								<ul class="dropdown-menu sub flyout-menu">
									<li><a href="./?!=login">Login/Register</a></li>
									<li><a href="./?!=order">My Orders</a></li>
									<li><a href="./?!=wish">Wish list</a></li>
									<li><a href="./?!=cart">Shopping Cart</a></li>
									<li><a href="./?!=checkout">Checkout</a></li>
								</ul>
							</li>
							<li> <a href=""><span>Product</span> <i class="fa fa-caret-right"></i> </a>
								<ul class="dropdown-menu sub flyout-menu">
									<li><a href="./?view=grid">Category Grid</a></li>
									<li><a href="./?view=list">Category List</a></li>
								</ul>
							</li>
							<li><a href="./?!=cart">Shoping Cart</a></li>
							<li><a href="./?!=checkout">Checkout</a></li>
							<li><a href="./?!=contact">Contact us</a></li>
						</ul>
						<!-- end: Sub Menu -->
					</div>';
	}
	function tablet(){
		echo '<div class="dropdown-menu flyout-menu">
						<!-- Sub Menu -->
						<ul>
							<li><a href="./">Home</a></li>
							<li><a href="./?!=about">About us</a></li>
							<li><a href=""><span>Product</span></a>
								<ul class="dropdown-menu sub flyout-menu">
									<li><a href="./?view=grid">Category Grid</a></li>
									<li><a href="./?view=list">Category List</a></li>
								</ul>
							</li>
							<li><a href="./?!=cart">Shoping Cart</a></li>
							<li><a href="./?!=checkout">Checkout</a></li>
							<li><a href="./?!=contact">Contact us</a></li>
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
		}
		return $item;
	}
	function navigation(){
		echo '<ul class="nav nav-pills nav-justified">
            <li> <a href="./"> <i class="fa fa-home fa-fw"></i> <span class="hidden-sm">Home</span></a> </li>
            <li> <a href="./?!=about"> <i class="fa fa-info-circle fa-fw"></i> <span class="hidden-sm">About</span></a> </li>
            <li> <a href="./?!=contact"> <i class="fa fa-pencil-square-o fa-fw"></i> <span class="hidden-sm ">Contact</span></a> </li>
            <li class="dropdown"> <a href="./?!=cart"> <i class="fa fa-shopping-cart fa-fw"></i> <span class="hidden-sm"> '.count($_SESSION['cart']).' items | '.symbol().total().'</span></a>
              <!-- Quick Cart -->
              <div class="dropdown-menu quick-cart">
								<div class="qc-row qc-row-heading"> <span class="qc-col-qty">QTY</span> <span class="qc-col-name">'.count($_SESSION['cart']).' items in bag</span> <span class="qc-col-price">'.symbol().total().'</span> </div>
								'.item().'
                <div class="qc-row-bottom"><button class="btn qc-btn-viewcart" onclick="window.location=\'./?!=cart\'">view cart</button><button class="btn qc-btn-checkout" onclick="window.location=\'./?!=checkout\'">checkout</button></div>
              </div>
              <!-- end: Quick Cart -->
            </li>
          </ul>';
	}
	function banner(){
		echo '<div class="container">
						<div class="row">
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-6">
								<div class="rec-banner blue">
									<div class="banner"> <i class="fa fa-thumbs-up"></i>
										<h3>Guarantee</h3>
										<p>100% Money Back Guarantee*</p>
									</div>
								</div>
							</div>
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-6">
								<div class="rec-banner red">
									<div class="banner"> <i class="fa fa-tags"></i>
										<h3>Affordable</h3>
										<p>Convenient & affordable prices for you</p>
									</div>
								</div>
							</div>
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-6">
								<div class="rec-banner orange">
									<div class="banner"> <i class="fa fa-headphones"></i>
										<h3>24/7 Support</h3>
										<p>We support everything we sell</p>
									</div>
								</div>
							</div>
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-6">
								<div class="rec-banner lightblue">
									<div class="banner"> <i class="fa fa-book"></i>
										<h3>Summer Sale</h3>
										<p>Upto 50% off on all books</p>
									</div>
								</div>
							</div>
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-6">
								<div class="rec-banner darkblue">
									<div class="banner"> <i class="fa fa-gift"></i>
										<h3>Surprise Gift</h3>
										<p>Value $50 on orders over $700</p>
									</div>
								</div>
							</div>
							<div class="col-lg-2 col-md-2 col-sm-4 col-xs-6">
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
								<div class="col-lg-8 col-sm-8 col-xs-12"> <span class="copytxt">Designed by <a href="#a">Flatro</a> -  All rights reserved</span> <span class="btmlinks"><a href="#a">Return Policy</a> | <a href="#a">Privacy Policy</a> | <a href="#a">Terms of Use</a></span> </div>
								<div class="col-lg-4 col-sm-4 col-xs-12 payment-icons"> <a href="#a"> <img src="images/icons/discover.png" alt="discover"> </a> <a href="#a"> <img src="images/icons/2co.png" alt="2co"> </a> <a href="#a"> <img src="images/icons/paypal.png" alt="paypal"> </a> <a href="#a"> <img src="images/icons/mastercard.png" alt="master card"> </a> <a href="#a"> <img src="images/icons/visa.png" alt="visa card"> </a> <a href="#a"> <img src="images/icons/moneybookers.png" alt="moneybookers"> </a> </div>
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
				case 'about': echo '<i class="fa fa-angle-right fa-fw"></i> About'; break;
				case 'contact': echo '<i class="fa fa-angle-right fa-fw"></i> Contact'; break;
			}
		}
	}
	function setcategories(){
		if($_SESSION['region'] == 1){ $category = array("'A'","'B'","'C'","'D'","'E'","'F'"); }
		else{ $category = array("'Programming'","'B'","'C'","'D'","'E'","'F'"); }
		return $category;
	}
	function categories(){
		mysql_open();
		$sql = "SELECT * FROM `Category` WHERE `Name` IN (".implode(', ',setcategories()).")";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				echo '<li><a href="#"><i class="fa fa-book"></i> <span>'.$row['Name'].'</span> <i class="fa fa-angle-right"></i> </a>';
				$sql_ = "SELECT * FROM `Category Detail` WHERE `ID Category` = '".$row['ID']."' ORDER BY `Name` ASC";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) > 0){
					echo '<div class="dropdown-menu flyout-menu">
									<ul>';
					while($row_ = mysql_fetch_assoc($res_)){
						echo '	<li><a href="#">'.$row_['Name'].'</a></li>';
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
	function setfeatured(){
		if($_SESSION['region'] == 1){ $featured = array(1,2,3,4,5,6,7,8,9); }
		else{ $featured = array(1,2,3,4,5,6,7,8,9); }
		return $featured;
	}
	function setspecial(){
		if($_SESSION['region'] == 1){ $special = array(1,2,3); }
		else{ $special = array(1,3,4); }
		return $special;
	}
	function setbestseller(){
		if($_SESSION['region'] == 1){ $bestseller = array(1,2,3); }
		else{ $bestseller = array(1,3,4); }
		return $bestseller;
	}
	function featured(){
		echo '<div class="box-products slide" id="productc1">
          <div class="carousel-controls"> <a class="carousel-control left" data-slide="prev" href="#productc1"> <i class="fa fa-angle-left fa-fw"></i> </a> <a class="carousel-control right" data-slide="next" href="#productc1"> <i class="fa fa-angle-right fa-fw"></i> </a> </div>
						<div class="carousel-inner">
							<!-- Items Row -->
							<div class="item active">
								<div class="row box-product">';
		mysql_open();
		$sql = "SELECT * FROM `Stock` WHERE `ID Warehouse` = ".$_SESSION['region']." AND `ID Book` IN (".implode(', ',setfeatured()).") ORDER BY `ID Book` ASC";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				$sql_ = "SELECT * FROM `Book` WHERE `ID` = ".$row['ID Book']." LIMIT 1";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) == 1){
					$row_ = mysql_fetch_assoc($res_);
					echo '		<!-- Product -->
										<div class="col-lg-4 col-md-4 col-sm-4 col-xs-12">
											<div class="product-block">
												<div class="image"><a class="img" href="./?product='.$row_['ISBN'].'"><img alt="'.$row_['Title'].'" src="images/cover/'.$row_['Title'].'.png" title="'.$row_['Title'].'"></a> </div>
												<div class="product-meta">
													<div class="name"><a href=./?product="'.$row_['ISBN'].'">'.$row_['Title'].'</a></div>
													<div class="big-price"> <span class="price-new"><span class="sym">'.symbol().'</span>'.$row['Price'].'</span> </div>
													<div class="big-btns"> <a class="btn btn-default btn-view pull-left" href="./?product='.$row_['ISBN'].'">View</a> <a class="btn btn-default btn-addtocart pull-right" href="#">Add to Cart</a> </div>
													<div class="small-price"> <span class="price-new"><span class="sym">'.symbol().'</span>'.$row['Price'].'</span> </div>
													<div class="rating"> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star-half-o"></i> <i class="fa fa-star-o"></i> </div>
													<div class="small-btns">
														<button class="btn btn-default btn-compare pull-left" data-toggle="tooltip" title="Add to Compare"> <i class="fa fa-retweet fa-fw"></i> </button>
														<button class="btn btn-default btn-wishlist pull-left" data-toggle="tooltip" title="Add to Wishlist"> <i class="fa fa-heart fa-fw"></i> </button>
														<button class="btn btn-default btn-addtocart pull-left" data-toggle="tooltip" title="Add to Cart"> <i class="fa fa-shopping-cart fa-fw"></i> </button>
													</div>
												</div>
												<div class="meta-back"></div>
											</div>
										</div>
										<!-- end: Product -->';
				}
				++$i;
				if($i%3 == 0 AND $i != mysql_num_rows($res)){
					echo '</div>
							</div>
							<!-- end: Items Row -->
							<!-- Items Row -->
							<div class="item">
								<div class="row box-product">';
				}
				if($i == mysql_num_rows($res)){ echo '</div></div><!-- end: Items Row -->'; }
			}
		}
		mysql_close();
		echo '	</div>
					</div>';
	}
	function special(){
		mysql_open();
		$sql = "SELECT * FROM `Stock` WHERE `ID Warehouse` = ".$_SESSION['region']." AND `ID Book` IN (".implode(', ',setspecial()).") ORDER BY `ID Book` ASC";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			echo '<div class="clearfix f-space30"></div>
						<div class="box-heading"><span>Specials</span></div>
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
												<div class="big-btns"> <a class="btn btn-default btn-view pull-left" href="./?product='.$row_['ISBN'].'">View</a> <a class="btn btn-default btn-addtocart pull-right" href="#">Add to Cart</a> </div>
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
	function recent(){
		echo '<div class="box-products slide" id="productc3">
          <div class="carousel-controls"> <a class="carousel-control left" data-slide="prev" href="#productc3"> <i class="fa fa-angle-left fa-fw"></i> </a> <a class="carousel-control right" data-slide="next" href="#productc3"> <i class="fa fa-angle-right fa-fw"></i> </a> </div>
						<div class="carousel-inner">
							<!-- Items Row -->
							<div class="item active">
								<div class="row box-product">';
		mysql_open();
		$sql = "SELECT * FROM `Stock` WHERE `ID Warehouse` = ".$_SESSION['region']." ORDER BY `ID Book` DESC LIMIT 9";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				$sql_ = "SELECT * FROM `Book` WHERE `ID` = ".$row['ID Book']." LIMIT 1";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) == 1){
					$row_ = mysql_fetch_assoc($res_);
					echo '		<!-- Product -->
										<div class="col-lg-4 col-md-4 col-sm-4 col-xs-12">
											<div class="product-block">
												<div class="image"><a class="img" href="#"><img alt="'.$row_['Title'].'" src="images/cover/'.$row_['Title'].'.png" title="'.$row_['Title'].'"></a> </div>
												<div class="product-meta">
													<div class="name"><a href="./?product='.$row_['ISBN'].'">'.$row_['Title'].'</a></div>
													<div class="big-price"> <span class="price-new"><span class="sym">'.symbol().'</span>'.$row['Price'].'</span> </div>
													<div class="big-btns"> <a class="btn btn-default btn-view pull-left" href="./?product='.$row_['ISBN'].'">View</a> <a class="btn btn-default btn-addtocart pull-right" href="#">Add to Cart</a> </div>
													<div class="small-price"> <span class="price-new"><span class="sym">'.symbol().'</span>'.$row['Price'].'</span> </div>
													<div class="rating"> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star-half-o"></i> <i class="fa fa-star-o"></i> </div>
													<div class="small-btns">
														<button class="btn btn-default btn-compare pull-left" data-toggle="tooltip" title="Add to Compare"> <i class="fa fa-retweet fa-fw"></i> </button>
														<button class="btn btn-default btn-wishlist pull-left" data-toggle="tooltip" title="Add to Wishlist"> <i class="fa fa-heart fa-fw"></i> </button>
														<button class="btn btn-default btn-addtocart pull-left" data-toggle="tooltip" title="Add to Cart"> <i class="fa fa-shopping-cart fa-fw"></i> </button>
													</div>
												</div>
												<div class="meta-back"></div>
											</div>
										</div>
										<!-- end: Product -->';
				}
				++$i;
				if($i%3 == 0 AND $i != mysql_num_rows($res)){
					echo '</div>
							</div>
							<!-- end: Items Row -->
							<!-- Items Row -->
							<div class="item">
								<div class="row box-product">';
				}
				if($i == mysql_num_rows($res)){ echo '</div></div><!-- end: Items Row -->'; }
			}
		}
		mysql_close();
		echo '	</div>
					</div>';
	}
	function bestseller(){
		mysql_open();
		$sql = "SELECT * FROM `Stock` WHERE `ID Warehouse` = ".$_SESSION['region']." AND `ID Book` IN (".implode(', ',setbestseller()).") ORDER BY `ID Book` ASC";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			echo '<div class="clearfix f-space30"></div>
						<div class="box-heading"><span>Best Seller</span></div>
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
												<div class="big-btns"> <a class="btn btn-default btn-view pull-left" href="./?product='.$row_['ISBN'].'">View</a> <a class="btn btn-default btn-addtocart pull-right" href="#">Add to Cart</a> </div>
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
			else if($_GET['!']=='checkout') require 'checkout.inc';}
		else{require 'index.inc';}
	}
?>
