<?php include_once('connect.inc');
/*
 * product.inc
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
	if(isset($_POST['submit'])){
		$sql = "SELECT * FROM `Book Review` WHERE `ID Book`=(SELECT `ID` FROM `Book` WHERE `ISBN`=".$_GET['product']." LIMIT 1) AND LOWER(`Email`)=LOWER('".(strip_tags(mysql_real_escape_string(trim($_POST['email']))))."') LIMIT 1";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) == 0){
			mysql_query("START TRANSACTION");
			$sql = "INSERT INTO `Book Review` VALUES ((SELECT `ID` FROM `Book` WHERE `ISBN`='".$_GET['product']."' LIMIT 1),'".(strip_tags(mysql_real_escape_string(trim($_POST['name']))))."','".(strip_tags(mysql_real_escape_string(trim($_POST['email']))))."','".(strip_tags(mysql_real_escape_string(trim($_POST['review']))))."','".(strip_tags(mysql_real_escape_string(trim($_POST['rating']=='' ? 0 : $_POST['rating']))))."',NOW())";
			$res = @mysql_query($sql) or die(mysql_error());
			if(mysql_affected_rows() == 1){mysql_query("COMMIT");}else{mysql_query("ROLLBACK");}
		}
	}
	$sql = "SELECT a.`ID`,a.`Title`,a.`SubTitle`,a.`Description`,a.`ISBN`,a.`Publisher`,a.`Page`,a.`Year`,a.`Language`,b.`Price`,b.`Stock` FROM `Book` a JOIN `Stock` b ON a.`ID`=b.`ID Book` WHERE a.`ISBN`=".$_GET['product']." AND b.`ID Warehouse`=".$_SESSION['region']." LIMIT 1";
	$res = @mysql_query($sql) or die(mysql_error());
	if(mysql_num_rows($res) == 1){
		$row = mysql_fetch_assoc($res);
		$sql_ = "SELECT * FROM `Author` HAVING `ID` IN (SELECT `ID Author` FROM `Book Author` WHERE `ID Book`=".$row['ID'].")";
		$res_ = @mysql_query($sql_) or die(mysql_error());
		if(mysql_num_rows($res_) > 0){while($row_ = mysql_fetch_assoc($res_)){$author .= $row_['Name'].'; ';}}
		$rate = 0;
		$star = '';
		$sql_ = "SELECT * FROM `Book Review` WHERE `ID Book`=".$row['ID']."";
		$res_ = @mysql_query($sql_) or die(mysql_error());
		if(mysql_num_rows($res_) > 0){
			while($row_ = mysql_fetch_assoc($res_)){
				$st = '';
				$rate += $row_['Rate'];
				for($i=1; $i<=5; $i++){if($i <= $row_['Rate']){$st .= '<i class="fa fa-star"></i> ';}else{$st .= '<i class="fa fa-star-o"></i> ';}}
				$review .= '<div class="review">
											<div class="review-info">
												<div class="name"><i class="fa fa-comment-o fa-flip-horizontal fa-fw"></i> '.$row_['Reviewer'].'</div>
												<div class="date"> on <em>'.$row_['Date'].'</em></div>
												<div class="rating">'.$st.'</div>
											</div>
											<div class="text">'.$row_['Review'].'</div>
										</div>';
			}
		}
		for($i=1; $i<=5; $i++){if($i <= (round($rate/20,0))){$star .= '<i class="fa fa-star"></i> ';}else{$star .= '<i class="fa fa-star-o"></i> ';}}
		$sql__ = "SELECT * FROM `Category Detail` HAVING `ID` IN (SELECT `ID Category Detail` FROM `Book Category` WHERE `ID Book`=".$row['ID'].") ORDER BY `Name` ASC";
		$res__ = @mysql_query($sql__) or die(mysql_error());
		if(mysql_num_rows($res__) > 0){while($row__ = mysql_fetch_assoc($res__)){$tags .= '<a href="#a">'.$row__['Name'].'</a>';}}
		echo '<div class="container">
					<!-- row -->
					<div class="row">
						<div class="col-md-12 box-block">
							<!--  box content -->
							<div class="box-content">
								<!-- single product -->
								<div class="single-product">
									<!-- Images -->
									<div class="images col-md-4 col-sm-12 col-xs-12">
										<div class="row">
											<!-- Big Image and Zoom -->
											<div class="big-image col-md-12 col-sm-12 col-xs-12"> <img id="product-image" src="images/cover/'.$row['Title'].'.png" data-zoom-image="images/cover/'.$row['Title'].'.png" alt="" style="height:457px" /> </div>
											<!-- end: Big Image and Zoom -->
										</div>
									</div>
									<!-- end: Images -->
									<!-- product details -->
									<div class="product-details col-md-8 col-sm-12 col-xs-12">
										<!-- Title and rating info -->
										<div class="title">
											<h1>'.$row['Title'].'<div style="font-size:smaller"><small>'.$row['SubTitle'].'</small></div></h1>
											<div class="rating"> '.$star.' <span>'.$GLOBALS['O56'].' '.(mysql_num_rows($res_)).' '.$GLOBALS['O57'].' </span> </div>
										</div>
										<!-- end: Title and rating info -->
										<div class="row">
											<!-- Availability, Product Code, Brand and short info -->
											<div class="short-info-wr col-md-12 col-sm-12 col-xs-12">
												<div class="short-info">
													<div class="product-attr-text">'.$GLOBALS['O60'].': <span><i>'.$author.'</i></span></div>
													<div class="product-attr-text"><p>'.$GLOBALS['O61'].': <span><i>'.$row['Publisher'].'</i></span></p></div>
													<div class="product-attr-text"><p>ISBN: <span><i>'.$row['ISBN'].'</i></span></p></div>
													<div class="product-attr-text"><p>'.$GLOBALS['O62'].': <span><i>'.$row['Page'].'</i></span></p></div>
													<div class="product-attr-text"><p>'.$GLOBALS['O63'].': <span><i>'.$row['Year'].'</i></span></p></div>
													<div class="product-attr-text"><p>'.$GLOBALS['O64'].': <span><i>'.$row['Language'].'</i></span></p></div>
													<div class="product-attr-text"><p>'.$GLOBALS['O65'].': <span class="available"><i>'.$row['Stock'].' '.$GLOBALS['O66'].'</i></span></p></div>
												</div>
											</div>
											<!-- end: Availability, Product Code, Brand and short info -->
										</div>
										<div class="row">
											<div class="price-wr col-md-6 col-sm-8 col-xs-12">
												<div class="big-price"> <span class="price-new"><span class="sym">'.symbol().'</span>'.$row['Price'].'</span> </div>
											</div>
											<div class="product-btns-wr col-md-6 col-sm-8 col-xs-12">
												<div class="product-btns">
													<div class="product-big-btns">
														<button class="btn btn-compare"> <i class="fa fa-heart fa-fw"></i> '.$GLOBALS['O59'].' </button>
														<button class="btn btn-addtocart" onclick="window.location=\'./?cart=add&item='.$row['ID'].'\'"> <i class="fa fa-shopping-cart fa-fw"></i> '.$GLOBALS['O15'].' </button>
													</div>
												</div>
											</div>
										</div>
									</div>
									<!-- end: product details -->
								</div>
								<!-- end: single product -->
							</div>
							<!-- end: box content -->
						</div>
					</div>
					<!-- end:row -->
				</div>
				<!-- end: container-->
				<div class="clearfix f-space20"></div>
				<!-- container -->
				<div class="container">
					<!-- row -->
					<div class="row">
						<!-- tabs -->
						<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 main-column box-block product-details-tabs">
							<!-- Details Info/Reviews/Tags -->
							<!-- Nav tabs -->
							<ul class="nav nav-tabs blog-tabs nav-justified">
								<li class="active"><a href="#details-info" data-toggle="tab"><i class="fa  fa-th-list fa-fw"></i> '.$GLOBALS['O67'].'</a></li>
								<li><a href="#reviews" data-toggle="tab"><i class="fa fa-comments fa-fw"></i> '.$GLOBALS['O68'].'</a></li>
								<li> <a href="#tags" data-toggle="tab"><i class="fa fa-tags fa-fw"></i> '.$GLOBALS['O69'].' </a> </li>
							</ul>
						<!-- Tab panes -->
						<div class="tab-content">
							<div class="tab-pane active" id="details-info">'.$row['Description'].'</div>
						<div class="tab-pane" id="reviews">
							<div class="heading"> <span><strong>"'.$row['Title'].'"</strong> '.$GLOBALS['O70'].' '.(mysql_num_rows($res_)).' '.$GLOBALS['O57'].'</span>
								<div class="rating"> '.$star.' </div>
								<a href="#wr" style="color:#E65A4B"> '.$GLOBALS['O71'].'</a>
							</div>
							'.$review.'
							<div class="write-reivew" id="#write-review">
								<h3>'.$GLOBALS['O72'].'</h3>
								<div class="fr-border"></div>
								<!-- Form -->
								<form action="" id="review_form" method="post">
									<div class="row">
										<div class="col-md-4 col-xs-12"> <a name="wr"> </a>
											<fieldset class="rating">
												<input type="radio" id="star5" name="rating" value="5" />
												<label for="star5" title="Rocks!" class="fa fa-star">5 stars</label>
												<input type="radio" id="star4" name="rating" value="4" />
												<label for="star4" title="Pretty good" class="fa fa-star">4 stars</label>
												<input type="radio" id="star3" name="rating" value="3" />
												<label for="star3" title="Cool" class="fa fa-star">3 stars</label>
												<input type="radio" id="star2" name="rating" value="2" />
												<label for="star2" title="Kinda bad" class="fa fa-star">2 stars</label>
												<input type="radio" id="star1" name="rating" value="1" />
												<label for="star1" title="Oops!" class="fa fa-star">1 star</label>
											</fieldset>
											<input type="text" name="name" id="name" placeholder="'.$GLOBALS['O50'].'*" autocomplete="off" required>
											<input type="email" name="email" id="email" placeholder="'.$GLOBALS['O25'].'" autocomplete="off" required>
										</div>
										<div class="col-md-8 col-xs-12">
											<textarea name="review" id="review" placeholder="'.$GLOBALS['O68'].'" rows="8" autocomplete="off" required></textarea>
										</div>
									</div>
									<button name="submit" type="submit" class="btn normal color1 pull-right">Submit</button>
								</form>
								<!-- end: Form -->
							</div>
						</div>
						<div class="tab-pane" id="tags">
							<div class="tags">'.$tags.'</div>
						</div>
					</div>
					<!-- end: Tab panes -->
					<!-- end: Details Info/Reviews/Tags -->
					<div class="clearfix f-space30"></div>
				</div>
				<!-- end: tabs -->
					</div>
					<!-- row -->
				</div>
				<!-- end: container -->';
	}else{error();}
	mysql_close();
?>
