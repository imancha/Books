<?php include_once('connect.inc');
/*
 * tag.inc
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

	mysql_open();	
	$sql = "SELECT * FROM `Book Category` WHERE `ID Category Detail`=(SELECT `ID` FROM `Category Detail` WHERE LOWER(`Name`) LIKE LOWER('".$_GET['tag']."'))";
	$res = @mysql_query($sql) or die(mysql_error($_SERVER['HTTP_REFERER']));
	$max = mysql_num_rows($res);
	if(isset($_GET['max'])){
		session_start();
		switch($_GET['max']){
			case 12 : $_SESSION['max'] = 12; break;
			case 24 : $_SESSION['max'] = 24; break;
			case 48 : $_SESSION['max'] = 48; break;
			case 96 : $_SESSION['max'] = 96; break;
			case 'all' : $_SESSION['max'] = $max; break;
			default : $_SESSION['max'] = 9;
		}
		header('Location: '.$_SERVER['HTTP_REFERER']);
		exit();
	}
	switch($_SESSION['max']){
		case 12 : $a0 = ' class="active"'; break;
		case 24 : $a1 = ' class="active"'; break;
		case 48 : $a2 = ' class="active"'; break;
		case 96 : $a3 = ' class="active"'; break;
		case $max : $a6 = ' class="active"'; break;
		default : $_SESSION['max'] = 9;
	}
	if(isset($_GET['sort'])){
		session_start();
		switch($_GET['sort']){
			case 'name': $_SESSION['sort'] = $_GET['to']=='asc' ? 'a.`Title` ASC' : 'a.`Title` DESC'; break;
			case 'price': $_SESSION['sort'] = $_GET['to']=='asc' ? 'b.`Price` ASC' : 'b.`Price` DESC'; break;
			case 'publisher': $_SESSION['sort'] = $_GET['to']=='asc' ? 'a.`Publisher` ASC' : 'a.`Publisher` DESC'; break;
			default: $_SESSION['sort'] = 'a.`ID` DESC';
		}
		header('Location: '.$_SERVER['HTTP_REFERER']);
		exit();
	}
	switch($_SESSION['sort']){
		case 'a.`Title` ASC': $b0 = ' class="active"'; break;
		case 'a.`Title` DESC': $b1 = ' class="active"'; break;
		case 'b.`Price` ASC': $b2 = ' class="active"'; break;
		case 'b.`Price` DESC': $b3 = ' class="active"'; break;
		case 'a.`Publisher` ASC': $b4 = ' class="active"'; break;
		case 'a.`Publisher` DESC': $b5 = ' class="active"'; break;
		default: $_SESSION['sort'] = 'a.`ID` DESC'; $b6 = ' class="active"';
	}
	if(isset($_GET['view'])){
		session_start();
		$_GET['view'] == 'list' ? $_SESSION['view'] = 'list' : $_SESSION['view'] = 'grid';
		header('Location: '.$_SERVER['HTTP_REFERER']);
		exit();
	}
	if(!isset($_GET['pages'])){
		$start = 1;
		$end = 9;
		$_GET['pages'] = 1;
	}
	$_SESSION['view'] == 'list' ? $c1 = ' active' : $c2 = ' active';
	$start = ($_SESSION['max']*$_GET['pages']-$_SESSION['max'])+1;
	$end = $start+$_SESSION['max']-1;
	$end = $max < $end ? $max : $end;

	echo '<div class="container">
				<!-- row -->
				<div class="row">
					<div class="col-md-9 col-sm-12 col-xs-12 box-block">
						<div class="box-heading category-heading"><span>Showing '.$start.'-'.$end.' of '.$max.' products</span>
								<ul class="nav nav-pills pull-right">
									<li class="dropdown"> <a class="dropdown-toggle" data-toggle="dropdown" data-hover="dropdown" href=""> '.$_SESSION['max'].' per page <i class="fa fa-sort fa-fw"></i> </a>
										<ul class="dropdown-menu" role="menu">
											<li'.$a0.'><a href="./?max=12">12 per page</a></li>
											<li'.$a1.'><a href="./?max=24">24 per page</a></li>
											<li'.$a2.'><a href="./?max=48">48 per page</a></li>
											<li'.$a3.'><a href="./?max=96">96 per page</a></li>
											<li'.$a6.'><a href="./?max=all">Show all</a></li>
										</ul>
									</li>
									<li class="dropdown"> <a class="dropdown-toggle" data-toggle="dropdown" data-hover="dropdown" href=""> Sort by <i class="fa fa-sort fa-fw"></i> </a>
										<ul class="dropdown-menu" role="menu">
											<li'.$b0.'><a href="./?sort=name&to=asc">Name (A-Z)</a></li>
											<li'.$b1.'><a href="./?sort=name&to=desc">Name (Z-A)</a></li>
											<li'.$b2.'><a href="./?sort=price&to=asc">Price (Low-High)</a></li>
											<li'.$b3.'><a href="./?sort=price&to=desc">Price (High-Low)</a></li>
											<li'.$b4.'><a href="./?sort=publisher&to=asc">Publisher (A-Z)</a></li>
											<li'.$b5.'><a href="./?sort=publisher&to=desc">Publisher (Z-A)</a></li>
											<li'.$b6.'><a href="./?sort=recent">Recent</a></li>
										</ul>
									</li>
									<li class="view-list'.$c1.'"> <a href="./?view=list"> <i class="fa fa-list-ul fa-fw"></i></a> </li>
									<li class="view-grid'.$c2.'"> <a href="./?view=grid"> <i class="fa fa-th-large fa-fw"></i></a> </li>
								</ul>
							</div>
							<div class="row clearfix f-space10"></div>
							<div class="box-content">
								<div class="box-products">';
	$sql = "SELECT a.`ID`,a.`Title`,a.`SubTitle`,a.`Description`,a.`ISBN`,b.`Price` FROM `Book` a JOIN `Stock` b ON a.`ID`=b.`ID Book` WHERE b.`ID Warehouse`=".$_SESSION['region']." ORDER BY ".$_SESSION['sort']." LIMIT ".($start-1).",".($end)."";
	$res = @mysql_query($sql) or die(mysql_error());
	if(mysql_num_rows($res) > 0){
		if($_SESSION['view'] == 'list'){
			while($row = mysql_fetch_assoc($res)){
				$rate = 0;
				$star = '';
				$sql_ = "SELECT * FROM `Book Review` WHERE `ID Book`=".$row['ID']."";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) > 0){
					while($row_ = mysql_fetch_assoc($res_)){$rate += $row_['Rate'];}
				}
				for($i=1; $i<=5; $i++){
					if($i <= (round($rate/20,0))){$star .= '<i class="fa fa-star"></i> ';}
					else{$star .= '<i class="fa fa-star-o"></i> ';}
				}
				echo '<!-- Product Row -->
							<div class="row list-product">
								<!-- Product -->
								<!-- Image -->
								<div class="col-md-4 col-sm-12 col-xs-12 product-image">
									<div class="image"><a class="img" href="./?product='.$row['ISBN'].'"><img alt="'.$row['Title'].'" src="images/cover/'.$row['Title'].'.png" title="'.$row['Title'].'" class="ani-image" style="height:340px;"></a> </div>
								</div>
								<!-- end: Image -->
								<div class="col-md-8 col-sm-12 col-xs-12 product-title">
									<div class="producttitle">
										<h1><a href="./?product='.$row['ISBN'].'">'.$row['Title'].'</a></h1>
										<div style="color:#ffffff">'.$row['SubTitle'].'&nbsp;</div>
										<div class="rating">'.$star.'</div>
										<span class="reviews-info">This product has '.(mysql_num_rows($res_)).' review(s)</span> </div>
								</div>
								<div class="col-md-3 col-sm-4 col-xs-12 product-price">
									<div class="big-price"> <span class="price-new"><span class="sym">'.symbol().'</span>1'.$row['Price'].'</span> </div>
								</div>
								<div class="col-md-5 col-sm-8 col-xs-12 product-meta">
									<div class="productmeta">
										'.substr(strip_tags($row['Description']),0,250).'... '.'<a href="./?product='.$row['ISBN'].'">read more</a>
										<div class="category-list-btns">
											<button class="btn normal btn-compare" data-toggle="tooltip" title="Add to Wishlist"  onclick="window.location=\'./?wishlist=add&item='.$row['ID'].'\'"> <i class="fa normal fa-heart fa-fw"></i> </button>
											<button class="btn normal btn-addtocart" onclick="window.location=\'./?cart=add&item='.$row['ID'].'\'"> <i class="fa fa-shopping-cart fa-fw"></i> Add to Cart </button>
										</div>
									</div>
								</div>
							</div>
							<!-- end: Product Row -->
							<div class="row clearfix f-space10"></div>';
			}
		}else{
			echo '<!-- Products Row -->
						<div class="row box-product">';
			while($row = mysql_fetch_assoc($res)){
				$rate = 0;
				$star = '';
				$sql_ = "SELECT * FROM `Book Review` WHERE `ID Book`=".$row['ID']."";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) > 0){
					while($row_ = mysql_fetch_assoc($res_)){$rate += $row_['Rate'];}
				}
				for($i=1; $i<=5; $i++){
					if($i <= (round($rate/20,0))){$star .= '<i class="fa fa-star"></i> ';}
					else{$star .= '<i class="fa fa-star-o"></i> ';}
				}
				echo '<!-- Product -->
							<div class="col-lg-4 col-md-4 col-sm-4 col-xs-12" style="margin-bottom:3.3%">
								<div class="product-block">
									<div class="image"><a class="img" href="./?product='.$row['ISBN'].'"><img alt="'.$row['Title'].'" src="images/cover/'.$row['Title'].'.png" title="'.$row['Title'].'"></a></div>
									<div class="product-meta">
										<div class="name"><a href="./?product='.$row['ISBN'].'">'.$row['Title'].'</a></div>
										<div class="big-price"> <span class="price-new"><span class="sym">'.symbol().'</span>'.$row['Price'].'</span> </div>
										<div class="big-btns"> <button class="btn btn-default btn-view pull-left" onclick="window.location=\'./?product='.$row['ISBN'].'\'">View</button> <button class="btn btn-default btn-addtocart pull-right" onclick="window.location=\'./?cart=add&item='.$row['ID'].'\'">Add to Cart</button> </div>
										<div class="small-price"> <span class="price-new"><span class="sym">'.symbol().'</span>'.$row['Price'].'</span> </div>
										<div class="rating">'.$star.'</div>
										<div class="small-btns">
											<button class="btn btn-default btn-compare pull-left" data-toggle="tooltip" title="Add to Wishlist"  onclick="window.location=\'./?wishlist=add&item='.$row['ID'].'\'"> <i class="fa fa-heart fa-fw"></i> </button>
											<button class="btn btn-default btn-addtocart pull-left" data-toggle="tooltip" title="Add to Cart" onclick="window.location=\'./?cart=add&item='.$row['ID'].'\'"> <i class="fa fa-shopping-cart fa-fw"></i> </button>
										</div>
									</div>
									<div class="meta-back"></div>
								</div>
							</div>
							<!-- end: Product -->';
			}
			echo '</div>
						<!-- end: Products Row -->';
		}
	}
	if($_SESSION['max'] < $max){
		$page = $max/$_SESSION['max'];
		if($max%$_SESSION['max'] != 0){
			$page = round($page,0)+1;
		}
	}else{
		$page = 1;
	}
	for($p=1; $p<=$page; $p++){
		if($page==1 OR $p==$_GET['pages']){$pa=' class="active"';}else{$pa='';}
		$po .= '<li'.$pa.'><a href="?pages='.$p.'">'.$p.'</a></li>';
	}
	$prev = '?pages='.($_GET['pages']-1);
	$next = '?pages='.($_GET['pages']+1);
	if($_GET['pages'] == 1 OR $page==1){$pp=' class="disabled"';$prev='';}
	if($_GET['pages'] == $page OR $page==1){$pn=' class="disabled"';$next='';}
	echo '	</div>
				</div>
				<span class="pull-left">Showing '.$start.'-'.$end.' of '.$max.' products</span>
				<div class="pull-right">
					<ul class="pagination pagination-lg">
						<li'.$pp.'><a href="'.$prev.'"><i class="fa fa-angle-left"></i></a></li>
						'.$po.'
						<li'.$pn.'><a href="'.$next.'"><i class="fa fa-angle-right"></i></a></li>
					</ul>
				</div>
			</div>
			<!-- side bar -->
			<div class="col-md-3 col-sm-12 col-xs-12 box-block page-sidebar">';
	$sql = "SELECT * FROM `Category` ORDER BY `Name` ASC";
	$res = @mysql_query($sql) or die(mysql_error());
	if(mysql_num_rows($res) > 0){
		echo '<div class="box-heading"><span>Categories</span></div>
					<!-- Categories -->
					<div class="box-content">
						<div class="panel-group" id="blogcategories">';
		while($row = mysql_fetch_assoc($res)){
			$sql_ = "SELECT DISTINCT(b.`Name`) FROM `Category` a JOIN `Category Detail` b ON a.`ID` = b.`ID Category` JOIN `Book Category` c ON b.`ID` = c.`ID Category Detail` JOIN `Stock` d ON c.`ID Book` = d.`ID Book` WHERE a.`ID`=".$row['ID']." AND d.`ID Warehouse`=".$_SESSION['region']." ORDER BY `Name` ASC";
			$res_ = @mysql_query($sql_) or die(mysql_error());
			if(mysql_num_rows($res_) > 0){
				echo '<div class="panel panel-default">
								<div class="panel-heading closed" data-parent="#blogcategories" data-target="#collapse'.$i.'" data-toggle="collapse">
									<h4 class="panel-title"> <a href="#a"> <span class="fa fa-plus"></span> '.$row['Name'].' </a><span class="categorycount">'.(mysql_num_rows($res_)).'</span> </h4>
								</div>
								<div class="panel-collapse collapse" id="collapse'.$i.'">
									<div class="panel-body">
										<ul>';
				while($row_ = mysql_fetch_assoc($res_)){
					echo '			<li class="item"> <a href="#a">'.$row_['Name'].'</a></li>';
				}
				echo '			</ul>
									</div>
								</div>
							</div>';
				$i++;
			}
		}
		echo '	</div>
					</div>
					<!-- end: Blog Categories -->';
	}
					special();
					bestseller();
  echo'		<div class="clearfix f-space30"></div>
				</div>
				<!-- end:sidebar -->
				</div>
				<!-- end:row -->
			</div>';
	mysql_close();
?>
