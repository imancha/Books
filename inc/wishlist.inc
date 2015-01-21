<?php include_once('connect.inc');
/*
 * wishlist.inc
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

	echo '<div class="container">
					<div class="row">
						<div class="col-md-12">
							<div class="page-title">
								<h2>'.$GLOBALS['O5'].' ('.count($_SESSION['wishlist']).' Items)</h2>
							</div>
						</div>
					</div>
				</div>
				<div class="row clearfix f-space10"></div>';
	if(!empty($_SESSION['wishlist'])){
		mysql_open();
		foreach($_SESSION['wishlist'] as $cart){
			$sql = "SELECT * FROM `Book` WHERE `ID`=".$cart['id']." LIMIT 1";
			$res = @mysql_query($sql) or die(mysql_error());
			if(mysql_num_rows($res) == 1){
				$row = mysql_fetch_assoc($res);
				$sql_ = "SELECT * FROM `Stock` WHERE `ID Book`=".$row['ID']." AND `ID Warehouse`=".$_SESSION['region']." LIMIT 1";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) == 1){
					$row_ = mysql_fetch_assoc($res_);
					$sql__ = "SELECT * FROM `Author` HAVING `ID` IN (SELECT `ID Author` FROM `Book Author` WHERE `ID Book`=".$row['ID'].")";
					$res__ = @mysql_query($sql__) or die(mysql_error());
					if(mysql_num_rows($res__) > 0){
						$author = '';
						while($row__ = mysql_fetch_assoc($res__)){
							$author .= $row__['Name'].'; ';
						}
					}
					echo '<!-- product -->
								<div class="container">
									<div class="row">
										<div class="product">
											<div class="col-md-2 col-sm-3 hidden-xs p-wr">
												<div class="product-attrb-wr">
													<div class="product-attrb">
														<div class="image"> <a class="img" href="./?product='.$row['ISBN'].'"><img alt="product info" src="images/cover/'.$row['Title'].'.png" title="'.$row['Title'].'"></a> </div>
													</div>
												</div>
											</div>
											<div class="col-md-3 col-sm-7 col-xs-9 p-wr">
												<div class="product-attrb-wr">
													<div class="product-meta">
														<div class="name"><h3><a href="./?product='.$row['ISBN'].'">'.$row['Title'].'</a></h3></div>
														<div class="subtitle"><small>'.$row['SubTitle'].'</small></div>
														<div class="author"><p>By: '.$author.'</p></div>
														<div class="publisher"><p>'.$row['Publisher'].'</p></div>
													</div>
												</div>
											</div>
											<div class="col-md-2 hidden-sm hidden-xs p-wr">
												<div class="product-attrb-wr">
													<div class="product-attrb">
														<div class="price"> <span class="a-price"><span class="sym">'.symbol().'</span>'.$row_['Price'].'</span> </div>
													</div>
												</div>
											</div>
											<div class="col-md-2 hidden-sm hidden-xs p-wr">
												<div class="product-attrb-wr">
													<div class="product-attrb">
														<div class="qtyinput">
															<div class="quantity-inp">
																<input type="text" class="quantity-input" name="p_quantity" value="'.$cart['qty'].'" disabled>
																<div class="quantity-txt minusbtn"><a href="./?wishlist=minus&item='.$cart['id'].'" class="qty qtyminus" ><i class="fa fa-minus fa-fw"></i></a></div>
																<div class="quantity-txt plusbtn"><a href="./?wishlist=plus&item='.$cart['id'].'" class="qty qtyplus" ><i class="fa fa-plus fa-fw"></i></a></div>
															</div>
														</div>
													</div>
												</div>
											</div>
											<div class="col-md-2 hidden-sm hidden-xs p-wr">
												<div class="product-attrb-wr">
													<div class="product-attrb">
														<div class="price"> <span class="t-price"><span class="sym">'.symbol().'</span>'.($row_['Price']*$cart['qty']).'</span> </div>
													</div>
												</div>
											</div>
											<div class="col-md-1 col-sm-2 col-xs-3 p-wr">
												<div class="product-attrb-wr">
													<div class="product-attrb">
														<div class="remove"> <button class="btn color2" data-toggle="tooltip" data-original-title="'.$GLOBALS['O15'].'" onclick="window.location=\'./?cart=add&item='.$row['ID'].'\'"><i class="fa fa-shopping-cart fa-fw color1"></i></button> </div>
														<div class="add"><button class="btn color2" data-toggle="tooltip" data-original-title="Remove" onclick="window.location=\'./?wishlist=remove&item='.$row['ID'].'\'"><i class="fa fa-trash-o fa-fw color2"></i></button></div>
													</div>
												</div>
											</div>
										</div>
									</div>
								</div>
								<!-- end: product -->
								<div class="row clearfix f-space30"></div>';
					$subtotal += $row_['Price']*$cart['qty'];
				}
			}
		}
		$total = $subtotal;
		echo '<div class="container">
						<div class="row">
							<!-- 	Estimate Shipping & Taxes -->
							<div class="col-md-4  col-sm-4 col-xs-12 cart-box-wr">
								<div class="box-heading"><span>Estimate Shipping & Taxes</span></div>
								<div class="clearfix f-space10"></div>
								<div class="box-content cart-box">
									<p>Enter your destination to get a shipping estimate.</p>
									<form>
										<input type="text" value="" placeholder="Country" class="input4" />
										<input type="text" value="" placeholder="Region/State" class="input4" />
										<button class="btn large color2 pull-right">Submit</button>
									</form>
								</div>
								<div class="clearfix f-space30"></div>
							</div>

							<!-- end: Estimate Shipping & Taxes -->

							<!-- 	Discount Codes -->

							<div class="col-md-4  col-sm-4 col-xs-12 cart-box-wr">
								<div class="box-heading"><span>Discount Codes</span></div>
								<div class="clearfix f-space10"></div>
								<div class="box-content cart-box">
									<p>Enter your coupon code if you have one.</p>
									<form>
										<input type="text" value="" placeholder="Country" class="input4" />
										<input type="text" value="" placeholder="Region/State" class="input4" />
										<button class="btn large color2 pull-right">Submit</button>
									</form>
								</div>
								<div class="clearfix f-space30"></div>
							</div>

							<!-- end: Discount Codes -->

							<!-- 	Total amount -->

							<div class="col-md-4 col-sm-4 col-xs-12 cart-box-wr">
								<div class="box-content">
									<div class="cart-box-tm">
										<div class="tm1">Sub-Total</div>
										<div class="tm2">'.symbol().$subtotal.'</div>
									</div>
									<div class="clearfix f-space10"></div>
									<div class="cart-box-tm">
										<div class="tm1">Eco Tax (0.00) </div>
										<div class="tm2">'.symbol().'0.00</div>
									</div>
									<div class="clearfix f-space10"></div>
									<div class="cart-box-tm">
										<div class="tm1">VAT (0%) </div>
										<div class="tm2">'.symbol().'0.00</div>
									</div>
									<div class="clearfix f-space10"></div>
									<div class="cart-box-tm">
										<div class="tm3 bgcolor2">Total </div>
										<div class="tm4 bgcolor2">'.symbol().$total.'</div>
									</div>
									<div class="clearfix f-space30"></div>
								</div>
							</div>

							<!-- end: Total amount -->

						</div>
					</div>';
		mysql_close();
	}
?>
