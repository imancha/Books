<?php include_once('connect.inc');
/*
 * checkout.inc
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

	if(!empty($_SESSION['cart'])){
		echo '<!-- Page title -->
					<div class="container">
						<div class="row">
							<div class="col-md-12">
								<div class="page-title">
									<h2>'.$GLOBALS['O7'].' <span>(4 '.$GLOBALS['O19'].')</span></h2>
								</div>
							</div>
						</div>
					</div>
					<!-- end: Page title -->
					<div class="row clearfix f-space10"></div>
					<div class="container">
						<!-- row -->
						<div class="row">
							<div class="col-md-12 col-sm-12 col-xs-12 main-column box-block">
								<!-- Checkout Options -->
								<div class="box-content checkout-op">
									<div class="panel-group" id="checkout-options">
										<!--Shipping Address panel -->
										<div class="panel panel-default">
											<div class="panel-heading" data-parent="#checkout-options" data-target="#op3" data-toggle="collapse">
												<h4 class="panel-title"> <a href="#"> <span class="fa fa-envelope-o"></span> '.$GLOBALS['O20'].' </a><span class="op-number">01</span> </h4>
											</div>
											<div class="panel-collapse collapse in" id="op3">
												<div class="panel-body">
													<div class="row co-row">

															<!-- Login -->
															<div class="col-md-6 col-xs-12">
																<div class="box-content form-box">
																	<h4>'.$GLOBALS['O21'].'</h4>
																	<div id="error1" class="alert">'.$GLOBALS['O22'].'</div>
																	<input type="text" value="" autocomplete="off" id="firstname" placeholder="'.$GLOBALS['O23'].'" class="input4" required>
																	<div id="error2" class="alert">'.$GLOBALS['O22'].'</div>
																	<input type="text" value="" autocomplete="off" id="lastname" placeholder="'.$GLOBALS['O24'].'" class="input4" required>
																	<div id="error3" class="alert">'.$GLOBALS['O22'].'</div>
																	<input type="text" value="" autocomplete="off" id="email" placeholder="'.$GLOBALS['O25'].'" class="input4" required>
																	<div id="error4" class="alert">'.$GLOBALS['O22'].'</div>
																	<input type="text" value="" autocomplete="off" id="phone" placeholder="'.$GLOBALS['O26'].'" class="input4" required>
																</div>
															</div>
															<!-- end: Login -->
															<!-- Register -->

															<div class="col-md-6 col-xs-12">
																<div class="box-content form-box">
																	<h4>'.$GLOBALS['O27'].'</h4>
																	<div id="error5" class="alert">'.$GLOBALS['O22'].'</div>
																	<input type="text" value="" autocomplete="off" id="company" placeholder="'.$GLOBALS['O28'].'" class="input4">
																	<div id="error6" class="alert">'.$GLOBALS['O22'].'</div>
																	<input type="text" value="" autocomplete="off" id="address" placeholder="'.$GLOBALS['O29'].'" class="input4" required>
																	<div id="error7" class="alert">'.$GLOBALS['O22'].'</div>
																	<input type="text" value="" autocomplete="off" id="city" placeholder="'.$GLOBALS['O30'].'" class="input4" required>
																	<div id="error8" class="alert">'.$GLOBALS['O22'].'</div>
																	<input type="text" value="" autocomplete="off" id="postcode" placeholder="'.$GLOBALS['O31'].'" class="input4">
																	<div id="error9" class="alert">'.$GLOBALS['O22'].'</div>
																	<input type="text" value="" autocomplete="off" id="state" placeholder="'.$GLOBALS['O32'].'" class="input4" required>
																	<div id="error10" class="alert">'.$GLOBALS['O22'].'</div>
																	<input type="text" value="" autocomplete="off" id="country" placeholder="'.$GLOBALS['O33'].'" class="input4" required>
																	<button id="formOne" class="btn medium color2 pull-right" onclick="formOne()">'.$GLOBALS['O34'].'</button>
																	<button id="editOne" class="btn medium color2 pull-right none" onclick="editOne()">'.$GLOBALS['O35'].'</button>
																</div>
															</div>

														<!-- end: Register -->

													</div>
												</div>
											</div>
										</div>

										<!-- end: Shipping Address panel -->

										<!--Shipping Method -->

										<div id="p4" class="panel panel-default disabled"> <!-- add class disabled to prevent from clicking -->
											<div class="panel-heading collapsed" data-parent="#checkout-options" data-target="#op4" data-toggle="collapse">
												<h4 class="panel-title"> <a href="#a"> <span class="fa fa-truck"></span> '.$GLOBALS['O36'].' </a><span class="op-number">02</span> </h4>
											</div>
											<div class="panel-collapse collapse" id="op4">
												<div class="panel-body">
													<div class="row co-row">';
													mysql_open();
													$sql = "SELECT * FROM `Shipping Method` WHERE `ID Warehouse`=".$_SESSION['region']."";
													$res = @mysql_query($sql) or die(mysql_error());
													if(mysql_num_rows($res) > 0){
														echo '<!-- Shipping methods -->
																	<div class="col-md-12 col-xs-12">
																		<div class="box-content form-box">
																			<h4>'.$GLOBALS['O37'].'</h4>
																			<div id="error11" class="alert">'.$GLOBALS['O22'].'</div>';
														while($row = mysql_fetch_assoc($res)){
															echo '<label class="radio" for="radio'.++$k.'">
																			<input type="radio" value="'.$row['ID'].'" id="radio'.$k.'" data-toggle="radio" name="shippingmethod" class="pull-left">
																			<span class="pull-left color1 provider">'.$row['Name'].'</span> - <span class="color2 price">'.symbol().$row['Cost'].'</span><br/>
																			<em>'.$row['Description'].' <br/>'.$row['Estimate'].'</em>
																		</label>';
														}
														echo '<button id="formTwo" class="btn medium color2 pull-right" onclick="formTwo()">'.$GLOBALS['O34'].'</button>
																<button id="editTwo" class="btn medium color2 pull-right none" onclick="editTwo()">'.$GLOBALS['O34'].'</button>
															</div>
														</div>
														<!-- end: Shipping methods -->';
													}
													mysql_close();

									echo '	</div>
												</div>
											</div>
										</div>

										<!-- end: Shipping Method -->

										<!-- Payment Method -->

										<div id="p5" class="panel panel-default disabled"> <!-- add class disabled to prevent from clicking -->
											<div class="panel-heading collapsed" data-parent="#checkout-options" data-target="#op5" data-toggle="collapse">
												<h4 class="panel-title"> <a href="#a"> <span class="fa fa-money"></span> '.$GLOBALS['O38'].' </a><span class="op-number">03</span> </h4>
											</div>
											<div class="panel-collapse collapse" id="op5">
												<div class="panel-body">
													<div class="row co-row">';

													mysql_open();
													$sql = "SELECT * FROM `Payment Method` WHERE `ID Warehouse`=".$_SESSION['region']."";
													$res = @mysql_query($sql) or die(mysql_error());
													if(mysql_num_rows($res) > 0){
														echo '<!-- Payment methods -->
																	<div class="col-md-12 col-xs-12">
																		<div class="box-content form-box">
																			<h4>'.$GLOBALS['O39'].'</h4>
																			<div id="error12" class="alert">'.$GLOBALS['O22'].'</div>';
														while($row = mysql_fetch_assoc($res)){
															echo '	<label class="radio" for="radoi'.++$j.'">
																				<input type="radio" value="'.$row['ID'].'" id="radoi'.$j.'" data-toggle="radio" name="paymentmethod" class="pull-left">
																				<span class="pull-left color1 provider">'.$row['Name'].'</span><br/>
																				<em>'.$row['Description'].'</em>
																			</label>';
														}
														echo '		<textarea name="comments" id="comments" cols="10" rows="8" class="input4" placeholder="'.$GLOBALS['O40'].'"></textarea>
																			<button id="formThree" class="btn medium color2 pull-right" onclick="formThree()">'.$GLOBALS['O34'].'</button>
																			<button id="editThree" class="btn medium color2 pull-right none" onclick="editThree()">'.$GLOBALS['O35'].'</button>
																		</div>
																	</div>
																	<!-- end: Payment methods -->';
													}
													mysql_close();

										echo '</div>
												</div>
											</div>
										</div>

										<!-- end: Payment Method -->

										<!-- Confirm Order -->

										<div id="p6" class="panel panel-default disabled"> <!-- add class disabled to prevent from clicking -->
											<div class="panel-heading collapsed" data-parent="#checkout-options" data-target="#op6" data-toggle="collapse">
												<h4 class="panel-title"> <a href="#"> <span class="fa fa-check"></span> '.$GLOBALS['O41'].' </a><span class="op-number">04</span> </h4>
											</div>
											<div class="panel-collapse collapse" id="op6">
												<div class="panel-body">
													<div class="row co-row">
														<div class="col-md-12 col-xs-12">
															<div class="box-content form-box">
																<h4>'.$GLOBALS['O42'].'</h4>';
		mysql_open();
		foreach($_SESSION['cart'] as $cart){
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
					if(mysql_num_rows($res__) > 0){$author = ''; while($row__ = mysql_fetch_assoc($res__)){$author .= $row__['Name'].'; ';}}
					echo '<div class="row">
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
															<input type="text" style="text-align:center; padding:0px;" class="quantity-input" name="p_quantity" value="'.$cart['qty'].'" disabled>
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
													<div class="remove"> <button class="btn color2" data-toggle="tooltip" data-original-title="Update" onclick="window.location=\'./?!=cart#'.++$i.'\'"><i class="fa fa-edit fa-fw color2"></i></button> </div>
												</div>
											</div>
										</div>
									</div>
								</div>';
					$subtotal += $row_['Price']*$cart['qty'];
				}
			}
		}
		$total = $subtotal;
		echo' 								<div class="box-content cart-box-wr pull-right">
														<div class="cart-box-tm">
															<div class="tm1">Sub-Total</div>
															<div class="tm2">'.symbol().'<span class="pull-right">'.$subtotal.'</span></div>
														</div>
														<div class="clearfix f-space10"></div>
														<div class="cart-box-tm">
															<div class="tm1">Eco Tax (0.00) </div>
															<div class="tm2">'.symbol().'<span class="pull-right">0.00</span></div>
														</div>
														<div class="clearfix f-space10"></div>
														<div class="cart-box-tm">
															<div class="tm1">VAT (0%) </div>
															<div class="tm2">'.symbol().'<span class="pull-right">0.00</span></div>
														</div>
														<div class="clearfix f-space10"></div>
														<div class="cart-box-tm">
															<div class="tm3 bgcolor2">Total </div>
															<div class="tm4 bgcolor2">'.symbol().'<span class="pull-right">'.$total.'</span></div>
														</div>
													</div>
													<div class="clearfix f-space20"></div>
													<button class="btn large color1 pull-right" onclick="order()">Create Order</button>
													<button class="btn large color3 pull-right" style="margin-right:2px" onclick="window.location=\'./?!=cart\'">'.$GLOBALS['O43'].'</button>
												</div>
											</div>
										</div>
									</div>
								</div>
							</div>
							<!-- end: Confirm Order -->
						</div>
					</div>
					<!-- end: Checkout Options -->
				</div>
			</div>
		</div>
		<div class="clearfix f-space30"></div>';
		mysql_close();
	}else{header('Location: ./?!=cart'); exit();}
?>
