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
									<h2>Checkout <span>(4 Steps)</span></h2>
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
											<div class="panel-heading closed" data-parent="#checkout-options" data-target="#op3" data-toggle="collapse">
												<h4 class="panel-title"> <a href="#a"> <span class="fa fa-envelope-o"></span> SHIPPING ADDRESS </a><span class="op-number">01</span> </h4>
											</div>
											<div class="panel-collapse collapse in" id="op3">
												<div class="panel-body">
													<div class="row co-row">
														<form>
															<!-- Login -->
															<div class="col-md-6 col-xs-12">
																<div class="box-content form-box">
																	<h4>Your Personal Details</h4>
																	<input type="text" value="" name="firstname" placeholder="First Name*" class="input4" required>
																	<input type="text" value="" name="lastname" placeholder="Last Name*" class="input4" required>
																	<input type="text" value="" name="email" placeholder="Email*" class="input4" required>
																	<input type="text" value="" name="phone" placeholder="Phone*" class="input4" required>
																</div>
															</div>
															<!-- end: Login -->
															<!-- Register -->

															<div class="col-md-6 col-xs-12">
																<div class="box-content form-box">
																	<h4>Your Address</h4>
																	<input type="text" value="" name="company" placeholder="Company" class="input4">
																	<input type="text" value="" name="address1" placeholder="Address line 1*" class="input4" required>
																	<input type="text" value="" name="address2" placeholder="Address line 2" class="input4">
																	<input type="text" value="" name="city" placeholder="City*" class="input4" required>
																	<input type="text" value="" name="postcode" placeholder="Post Code" class="input4">
																	<input type="text" value="" name="state" placeholder="State*" class="input4" required>
																	<input type="text" value="" name="country" placeholder="Country*" class="input4" required>
																	<button class="btn medium color2 pull-right">Continue</button>
																</div>
															</div>
														</form>
														<!-- end: Register -->

													</div>
												</div>
											</div>
										</div>

										<!-- end: Shipping Address panel -->

										<!--Shipping Method -->

										<div class="panel panel-default"> <!-- add class disabled to prevent from clicking -->
											<div class="panel-heading closed" data-parent="#checkout-options" data-target="#op4" data-toggle="collapse">
												<h4 class="panel-title"> <a href="#a"> <span class="fa fa-truck"></span> SHIPPING METHOD </a><span class="op-number">02</span> </h4>
											</div>
											<div class="panel-collapse collapse" id="op4">
												<div class="panel-body">
													<div class="row co-row">

														<!-- Shipping methods -->
														<div class="col-md-12 col-xs-12">
															<div class="box-content form-box">
																<h4>Please select the preferred shipping method to use on this order.</h4>
																<label class="radio" for="radio1">
																	<input type="radio" value="" id="radio1" data-toggle="radio"  name="shippingmethod" checked="checked" class="pull-left">
																	<span class="pull-left color1 provider">Standard International Postage</span> - <span class="color2 price">Free</span><br/>
																	<em>Delivered to your letterbox within <br/>
																	7-14 working days</em> </label>
																<label class="radio" for="radio2">
																	<input type="radio" value="" id="radio2" data-toggle="radio"  name="shippingmethod" class="pull-left">
																	<span class="pull-left color1 provider">DHL Standard Postage</span> - <span class="color2 price">$2.99</span><br/>
																	<em>Delivered to your letterbox within <br/>
																	2-5 working days</em> </label>
																<label class="radio" for="radio3">
																	<input type="radio" value="" id="radio3" data-toggle="radio" name="shippingmethod" class="pull-left">
																	<span class="pull-left color1 provider">FEDEX QUICK DELIVERY</span> - <span class="color2 price">$6.40</span><br/>
																	<em>Delivered to your letterbox within <br/>
																	1-3 working days</em> </label>
																<button class="btn medium color2 pull-right">Continue</button>
															</div>
														</div>
														<!-- end: Shipping methods -->

													</div>
												</div>
											</div>
										</div>

										<!-- end: Shipping Method -->

										<!-- Payment Method -->

										<div class="panel panel-default"> <!-- add class disabled to prevent from clicking -->
											<div class="panel-heading closed" data-parent="#checkout-options" data-target="#op5" data-toggle="collapse">
												<h4 class="panel-title"> <a href="#a"> <span class="fa fa-money"></span> PAYMENT METHOD </a><span class="op-number">03</span> </h4>
											</div>
											<div class="panel-collapse collapse" id="op5">
												<div class="panel-body">
													<div class="row co-row">

														<!-- Payment methods -->
														<div class="col-md-12 col-xs-12">
															<div class="box-content form-box">
																<h4>Please select the preferred Payment method to use on this order.</h4>
																<label class="radio" for="radio4">
																	<input type="radio" value="" id="radio4" data-toggle="radio"  name="paymentmethod" class="pull-left">
																	<span class="pull-left color1 provider">Direct Bank Transfer</span><br/>
																	<em>Make your payment directly into our bank account. Please use your Order ID as the payment reference. Your order wont be shipped until the funds have cleared in our account.</em> </label>
																<label class="radio" for="radio5">
																	<input type="radio" value="" id="radio5" data-toggle="radio"  name="paymentmethod" checked="checked" class="pull-left">
																	<span class="pull-left color1 provider">Monybookers</span><br/>
																	<em>Moneybookers(Skrill) makes it easy for developers to accept credit cards on the web.</em> </label>
																<label class="radio" for="radio6">
																	<input type="radio" value="" id="radio6" data-toggle="radio"  name="paymentmethod" class="pull-left">
																	<span class="pull-left color1 provider">Paypal</span><br/>
																	<em>Appropriately seize value-added quality vectors via fully researched process improvements. </em> </label>
																<textarea name="comments" id="comments" cols="10" rows="8" class="input4" placeholder="Comments/messsage"></textarea>
																<button class="btn medium color2 pull-right">Continue</button>
															</div>
														</div>
														<!-- end: Payment methods -->

													</div>
												</div>
											</div>
										</div>

										<!-- end: Payment Method -->

										<!-- Confirm Order -->

										<div class="panel panel-default"> <!-- add class disabled to prevent from clicking -->
											<div class="panel-heading closed" data-parent="#checkout-options" data-target="#op6" data-toggle="collapse">
												<h4 class="panel-title"> <a href="#a"> <span class="fa fa-check"></span> Confirm Order </a><span class="op-number">04</span> </h4>
											</div>
											<div class="panel-collapse collapse" id="op6">
												<div class="panel-body">
													<div class="row co-row">
														<div class="col-md-12 col-xs-12">
															<div class="box-content form-box">
																<h4>Please confirm your order.</h4>';
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
					if(mysql_num_rows($res__) > 0){
						$author = '';
						while($row__ = mysql_fetch_assoc($res__)){
							$author .= $row__['Name'].'; ';
						}
					}
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
															<input type="text" class="quantity-input" name="p_quantity" value="'.$cart['qty'].'" disabled>
															<div class="quantity-txt minusbtn"><a href="./?cart=minus&item='.$cart['id'].'" class="qty qtyminus" ><i class="fa fa-minus fa-fw"></i></a></div>
															<div class="quantity-txt plusbtn"><a href="./?cart=plus&item='.$cart['id'].'" class="qty qtyplus" ><i class="fa fa-plus fa-fw"></i></a></div>
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
													<div class="remove"> <button class="btn color2" data-toggle="tooltip" data-original-title="Remove" onclick="window.location=\'./?cart=remove&item='.$row['ID'].'\'"><i class="fa fa-trash-o fa-fw color2"></i></button> </div>
												</div>
											</div>
										</div>
									</div>
								</div>';
					$subtotal += $row_['Price']*$cart['qty'];
				}
			}
		}
		echo' 						<div class="box-content cart-box-wr pull-right">
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
                      </div>
                      <div class="clearfix f-space20"></div>
                      <!--  <textarea name="comments" id="comments" cols="5" rows="5" class="input4" placeholder="Comments/messsage"></textarea> -->

                      <button class="btn large color1 pull-right">Create Order</button>
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
		<div class="clearfix f-space30"></div>';
		mysql_close();
	}else{header('Location: ./?!=cart'); exit();}
?>
