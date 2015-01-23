<?php session_start(); ?>
<!--
/*
 * region.inc
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
 -->
<!DOCTYPE html>
<!--[if IE 7 ]><html class="ie ie7 lte9 lte8 lte7" lang="en-US"><![endif]-->
<!--[if IE 8]><html class="ie ie8 lte9 lte8" lang="en-US">	<![endif]-->
<!--[if IE 9]><html class="ie ie9 lte9" lang="en-US"><![endif]-->
<!--[if (gt IE 9)|!(IE)]><!-->
<html class="noIE" lang="en-US">
<!--<![endif]-->
<head>
	<meta charset="UTF-8">
	<meta content="width=device-width, initial-scale=1, maximum-scale=1" name="viewport">
	<meta content="" name="description">
	<meta content="" name="author">
	<title>Imancha - Online Shop</title>
	<!-- Bootstrap core CSS -->
	<link href="../css/bootstrap.css" rel="stylesheet">
	<!-- Custom styles for this template -->
	<link href="../css/custom.css" rel="stylesheet" type="text/css" />
</head>

<body class="loginpage">
<div class="loginpanel">
	<div class="loginpanelinner">
		<div class="logo animate0 bounceIn">Please choose your region</div>
				<div class="animate1 bounceIn">
					<div class="row">
						<div class="col-xs-6" style="padding: 1px;">
							<a href="../?MyRegionIs=>id">
								<div class="rec-banner red">
									<div class="banner"> <i class="fa fa-home"></i>
										<h3>Indonesia</h3>
									</div>
								</div>
							</a>
						</div>
						<div class="col-xs-6" style="padding: 1px;">
							<a href="../?MyRegionIs=>us">
								<div class="rec-banner orange">
									<div class="banner"> <i class="fa fa-home"></i>
										<h3>United States</h3>
										<p><small>Other Country</small></p>
									</div>
								</div>
							</a>
						</div>
					</div>
				</div>
	</div><!--loginpanelinner-->
</div><!--loginpanel-->
</body>
</html>
