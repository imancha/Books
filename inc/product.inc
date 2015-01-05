<?php include_once('connect.inc'); ob_start(); session_start();
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
	$sql = "SELECT a.`ID`,a.`Title`,a.`SubTitle`,a.`Description`,a.`ISBN`,a.`Publisher`,a.`Page`,a.`Year`,a.`Language`,b.`Price`,b.`Stock` FROM `Book` a JOIN `Stock` b ON a.`ID`=b.`ID Book` WHERE a.`ISBN`=".$_GET['product']." AND b.`ID Warehouse`=".$_SESSION['region']." LIMIT 1";
	$res = @mysql_query($sql) or die(mysql_error());
	if(mysql_num_rows($res) == 1){
		$row = mysql_fetch_assoc($res);
		$sql_ = "SELECT * FROM `Author` HAVING `ID` IN (SELECT `ID Author` FROM `Book Author` WHERE `ID Book`=".$row['ID'].")";
		$res_ = @mysql_query($sql_) or die(mysql_error());
		if(mysql_num_rows($res_) > 0){
			while($row_ = mysql_fetch_assoc($res_)){
				$author .= $row_['Name'].'; ';
			}
		}		
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
											<div class="big-image col-md-12 col-sm-12 col-xs-12"> <img id="product-image" src="images/cover/'.$row['Title'].'.png" data-zoom-image="images/cover/'.$row['Title'].'.png" alt="big image" /> </div>
											<!-- end: Big Image and Zoom --> 
										</div>
									</div>									
									<!-- end: Images --> 									
									<!-- product details -->									
									<div class="product-details col-md-8 col-sm-12 col-xs-12">										
										<!-- Title and rating info -->
										<div class="title">
											<h1>'.$row['Title'].'</h1>
											<div class="rating"> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star-half-o"></i> <i class="fa fa-star-o"></i> <span>This product has 30 review(s) <a href="#a">Add Review</a></span> </div>
										</div>
										<!-- end: Title and rating info -->										
										<div class="row"> 
											<!-- Availability, Product Code, Brand and short info -->
											<div class="short-info-wr col-md-12 col-sm-12 col-xs-12">
												<div class="short-info">
													<div class="product-attr-text" style=""><strong>'.$row['Title'].': <span><i>'.$row['SubTitle'].'</i></span></strong></div>
													<div class="product-attr-text"><p>Author: <span><i>'.$author.'</i></span></p></div>
													<div class="product-attr-text"><p>Publisher: <span><i>'.$row['Publisher'].'</i></span></p></div>
													<div class="product-attr-text"><p>ISBN: <span><i>'.$row['ISBN'].'</i></span></p></div>
													<div class="product-attr-text"><p>Pages: <span><i>'.$row['Page'].'</i></span></p></div>
													<div class="product-attr-text"><p>Year: <span><i>'.$row['Year'].'</i></span></p></div>
													<div class="product-attr-text"><p>Language: <span><i>'.$row['Language'].'</i></span></p></div>
													<div class="product-attr-text"><p>Availability: <span class="available"><i>'.$row['Stock'].' in Stock</i></span></p></div>													
												</div>
											</div>
											<!-- end: Availability, Product Code, Brand and short info --> 											
										</div>										
										<div class="row">
											<div class="price-wr col-md-4 col-sm-8 col-xs-12">
												<div class="big-price"> <span class="price-new"><span class="sym">'.($_SESSION['region']==1 ? 'Rp' : '$').'</span>'.$row['Price'].'</span> </div>
											</div>
											<div class="product-btns-wr col-md-8 col-sm-8 col-xs-12">
												<div class="product-btns">
													<div class="product-big-btns">
														<button class="btn btn-addtocart"> <i class="fa fa-shopping-cart fa-fw"></i> Add to Cart </button>
														<button class="btn btn-compare"> <i class="fa fa-retweet fa-fw"></i> Add to Compare </button>
														<button class="btn btn-wishlist"> <i class="fa fa-heart fa-fw"></i> Add to Wishlist </button>														
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
				<!-- container -->
				<div class="container">
					<!-- row -->
					<div class="row"> 						
						<!-- tabs -->
						<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 main-column box-block product-details-tabs">       
							<!-- Details Info/Reviews/Tags --> 
							<!-- Nav tabs -->
							<ul class="nav nav-tabs blog-tabs nav-justified">
								<li class="active"><a href="#details-info" data-toggle="tab"><i class="fa  fa-th-list fa-fw"></i> Description</a></li>
								<li><a href="#reviews" data-toggle="tab"><i class="fa fa-comments fa-fw"></i> Reviews</a></li>
								<li> <a href="#tags" data-toggle="tab"><i class="fa fa-tags fa-fw"></i> Tags </a> </li>								
							</ul>
						<!-- Tab panes -->
						<div class="tab-content">
							<div class="tab-pane active" id="details-info">'.$row['Description'].'</div>
						<div class="tab-pane" id="reviews">
							<div class="heading"> <span><strong>"Ladies Stylish Handbag"</strong> has 30 review(s)</span>
								<div class="rating"> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star-half-o"></i> <i class="fa fa-star-o"></i> </div>
								<a href="#wr" class="btn color1 normal">Add Review</a> </div>
							<div class="review">
								<div class="review-info">
									<div class="name"><i class="fa fa-comment-o fa-flip-horizontal fa-fw"></i> Fida Khattak</div>
									<div class="date"> on <em>Aug 15, 2013</em></div>
									<div class="rating"> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star-half-o"></i> <i class="fa fa-star-o"></i> </div>
								</div>
								<div class="text">Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown.</div>
							</div>
							<div class="review">
								<div class="review-info">
									<div class="name"><i class="fa fa-comment-o fa-flip-horizontal fa-fw"></i> Fida Khattak</div>
									<div class="date"> on <em>Aug 15, 2013</em></div>
									<div class="rating"> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star"></i> <i class="fa fa-star-half-o"></i> <i class="fa fa-star-o"></i> </div>
								</div>
								<div class="text">Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown.</div>
							</div>
							<span class="pull-left">Showing 1 to 2 of 123 (4 Pages)</span>
							<div class="pull-right">
								<ul class="pagination pagination-xs">
									<li class="disabled"><a href="#"><i class="fa fa-angle-left"></i></a></li>
									<li  class="active"><a href="#">1</a></li>
									<li><a href="#">2</a></li>
									<li><a href="#">3</a></li>
									<li><a href="#">4</a></li>
									<li><a href="#"><i class="fa fa-angle-right"></i></a></li>
								</ul>
							</div>
							<div class="write-reivew" id="#write-review">
								<h3>Write a reivew</h3>
								<div class="fr-border"></div>
								
								<!-- Form -->
								<form action="#self" id="review_form" method="post">
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
											<input type="text" id="name" placeholder="Name">
											<input type="text" id="email" placeholder="E-mail">
										</div>
										<div class="col-md-8 col-xs-12">
											<textarea name="" id="review" placeholder="Review" rows="8"></textarea>
										</div>
									</div>
									<button class="btn normal color1 pull-right">Submit</button>
								</form>
								<!-- end: Form --> 
							</div>
						</div>
						<div class="tab-pane" id="tags">
							<div class="tags"> <a href="#a">Free</a> <a href="#a">Minimal</a> <a href="#a">Clean</a> <a href="#a">Flatro</a> <a href="#a">Metro</a> <a href="#a">Flat</a> <a href="#a">Blue</a> <a href="#a">Fashion</a> <a href="#a">Best</a> <a href="#a">Popular</a> <a href="#a">Good</a> <a href="#a">Free</a> <a href="#a">Minimal</a> <a href="#a">Clean</a> <a href="#a">Flatro</a> <a href="#a">Metro</a> <a href="#a">Flat</a> <a href="#a">Blue</a> <a href="#a">Fashion</a> <a href="#a">Best</a> <a href="#a">Popular</a> <a href="#a">Good</a> <a href="#a">Free</a> <a href="#a">Minimal</a> <a href="#a">Clean</a> <a href="#a">Flatro</a> <a href="#a">Metro</a> <a href="#a">Flat</a> <a href="#a">Blue</a> <a href="#a">Fashion</a> <a href="#a">Best</a> <a href="#a">Popular</a> <a href="#a">Good</a> <a href="#a">Free</a> <a href="#a">Minimal</a> <a href="#a">Clean</a> <a href="#a">Flatro</a> <a href="#a">Metro</a> <a href="#a">Flat</a> <a href="#a">Blue</a> <a href="#a">Fashion</a> <a href="#a">Best</a> <a href="#a">Popular</a> <a href="#a">Good</a> <a href="#a">Free</a> <a href="#a">Minimal</a> <a href="#a">Clean</a> <a href="#a">Flatro</a> <a href="#a">Metro</a> <a href="#a">Flat</a> <a href="#a">Blue</a> <a href="#a">Fashion</a> <a href="#a">Best</a> <a href="#a">Popular</a> <a href="#a">Good</a> </div>
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
