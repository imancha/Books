<?php
/*
 * contact.inc
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
					<!-- row -->
					<div class="row">
						<div class="col-md-9 col-sm-12 col-xs-12 main-column box-block">
							<div id="map" class="map"></div>
							<div class="clearfix f-space30"></div>
							<div class="contactform">
								<h2 class="title" style="margin-top:19px">Contact Form</h2>
								<p>Vestibulum congue sollicitudin neque, placerat lobortis enim facilisis sed. Etiam interdum dignissim sem id luctus. Sed nunc lectus, 
									ornare quis interdum eu, auctor sit amet lorem. Quisque condimentum orci.</p>
								<form>
									<div class="row">
										<div class="col-md-5">
											<input class="input4" id="name" placeholder="Name*" data-validation="required" required>
											<input class="input4" id="email" placeholder="Email*" data-validation="email" required>
											<input class="input4" id="subject" placeholder="Subject" >
										</div>
										<div class="col-md-7">
											<textarea class="input4" name="message" id="message" rows="8" cols="60" placeholder="Message" data-validation="required" required></textarea>
										</div>
									</div>
									<div class="row">
										<div class="col-md-12">
											<button class="btn large color2 pull-right" type="submit">Send now</button>
										</div>
									</div>
								</form>
							</div>
						</div>
						
						<!-- side bar -->
						<div class="col-md-3 col-sm-12 col-xs-12 box-block page-sidebar">
							<div class="box-heading"><span>Contact Details</span></div>
							<!-- Contact Details -->
							<div class="box-content contactdetails-box-wr">
								<div class="contactdetails-box"> <span class="icon"><i class="fa fa-map-marker fa-fw"></i></span>
									<div class="details">
										<h1>Imancha<sup>OS</sup></h1>
										Imancha Street,<br/>
										Cirebon,
										West Java, <br/>
										Indonesia,
										45163
									</div>
								</div>
								<div class="contactdetails-box"> <span class="icon"><i class="fa fa-phone fa-fw"></i></span> <span class="details">+6285 795525434</span> </div>
								<div class="contactdetails-box"> <span class="icon"><i class="fa fa-envelope fa-fw"></i></span> <span class="details">imancha_266@ymail.com</span> </div>
								<div class="contactdetails-box"> <span class="icon"><i class="fa fa-globe fa-fw"></i></span> <span class="details">http://imanchaos.com</span> </div>
							</div>							
							<!-- end: Contact Details -->';							
							bestseller();
		echo'		</div>
						<!-- end:sidebar --> 
					</div>
					<!-- end:row --> 
				</div>
				<!-- end: container-->

				<div class="row clearfix f-space30"></div>';
?>
