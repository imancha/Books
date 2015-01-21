<?php include_once('inc/main.inc');
/*
 * index.php
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

?>
<!DOCTYPE html>
<!--[if IE 7 ]><html class="ie ie7 lte9 lte8 lte7" lang="en-US"><![endif]-->
<!--[if IE 8]><html class="ie ie8 lte9 lte8" lang="en-US">	<![endif]-->
<!--[if IE 9]><html class="ie ie9 lte9" lang="en-US"><![endif]-->
<!--[if (gt IE 9)|!(IE)]><!-->
<html class="noIE" lang="<?php echo $GLOBALS['O73']; ?>">
<!--<![endif]-->
<head>
	<meta charset="UTF-8">
	<meta content="width=device-width, initial-scale=1, maximum-scale=1" name="viewport">
	<meta content="Imancha Online Shop" name="description">
	<meta content="Mohammad Abdul Iman Syah" name="author">
	<title>Imancha Online Shop</title>
	<!-- Reset CSS -->
	<link href="css/normalize.css" rel="stylesheet" type="text/css"/>
	<!-- Bootstrap core CSS -->
	<link href="css/bootstrap.css" rel="stylesheet">
	<!-- Iview Slider CSS -->
	<link href="css/iview.css" rel="stylesheet">
	<!--	Responsive 3D Menu	-->
	<link href="css/menu3d.css" rel="stylesheet"/>
	<!-- Animations -->
	<link href="css/animate.css" rel="stylesheet" type="text/css"/>	
	<!-- Custom styles for this template -->
	<link href="css/custom.css" rel="stylesheet" type="text/css" />
	<!-- Style Switcher -->
	<link href="css/style-switch.css" rel="stylesheet" type="text/css"/>
	<!-- Color -->
	<link href="css/skin/color.css" id="colorstyle" rel="stylesheet">
	<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
	<!--[if lt IE 9]> <script src="js/html5shiv.js"></script> <script src="js/respond.min.js"></script> <![endif]-->
	<!-- Bootstrap core JavaScript -->
	<script src="js/jquery-1.10.2.min.js"></script>
	<script src="js/bootstrap.min.js"></script>
	<script src="js/bootstrap-select.js"></script>
	<!-- Custom Scripts -->
	<script src="js/scripts.js"></script>
	<!-- MegaMenu -->
	<script src="js/menu3d.js" type="text/javascript"></script>
	<!-- iView Slider -->
	<script src="js/raphael-min.js" type="text/javascript"></script>
	<script src="js/jquery.easing.js" type="text/javascript"></script>
	<script src="js/iview.js" type="text/javascript"></script>
	<script src="js/retina-1.1.0.min.js" type="text/javascript"></script>
	<script src="js/script.js"></script>
	<!--[if IE 8]><script type="text/javascript" src="js/selectivizr.js"></script><![endif]-->
</head>

<body onload = date_time('date_time','<?php echo $GLOBALS['O73']; ?>');>
<!-- Header -->
<header>
  <!-- Top Heading Bar -->
  <div class="container"><?php top(); ?></div>
  <!-- end: Top Heading Bar -->
  <div class="f-space20"></div>
  <!-- Logo and Search -->
  <div class="container">
    <div class="row clearfix">
      <?php logo(); ?>
      <!-- end: logo -->
      <div class="visible-xs f-space20"></div>
      <!-- search -->
      <?php search(); ?>
      <!-- end: search -->
    </div>
  </div>
  <!-- end: Logo and Search -->
  <div class="f-space20"></div>
  <!-- Menu -->
  <div class="container">
    <div class="row clearfix">
      <div class="col-lg-3 col-md-3 col-sm-4 col-xs-12 menu-col">
        <div class="menu-heading menuHeadingdropdown"> <span> <i class="fa fa-bars"></i> <?php echo $GLOBALS['O1']; ?> <i class="fa fa-angle-down"></i></span> </div>
        <!-- Mega Menu -->
        <div class="menu3dmega vertical menuMegasub" id="menuMega">
          <ul>
            <!-- Menu Item Links for Mobiles Only -->
            <li class="visible-xs"><a href="#"><i class="fa fa-home"></i> <span><?php echo $GLOBALS['O0']; ?></span> <i class="fa fa-angle-right"></i></a><?php mobile(); ?></li>
            <!-- end: Menu Item -->
            <!-- Menu Item for Tablets and Computers Only-->
            <li class="hidden-xs"> <a href="#"><i class="fa fa-files-o"></i> <span><?php echo $GLOBALS['O2']; ?></span> <i class="fa fa-angle-right"></i></a><?php tablet(); ?></li>
            <!-- end: Menu Item -->
            <?php categories(); ?>            
            <!-- end: Menu Item -->
          </ul>
        </div>
        <!-- end: Mega Menu -->
      </div>
      <div class="col-lg-9 col-md-9 col-sm-8 col-xs-12 menu-col-2">
        <!-- Navigation Buttons/Quick Cart for Tablets and Desktop Only -->
        <div class="menu-links hidden-xs"><?php navigation(); ?></div>
        <!-- end: Navigation Buttons/Quick Cart Tablets and large screens Only -->
      </div>
    </div>
  </div>
</header>
<!-- end: Header -->
<div class="row clearfix"></div>
<div class="container">
  <div class="row">
    <div class="col-md-12">
      <div class="breadcrumb"> <a href="./"> <i class="fa fa-home fa-fw"></i> <?php echo $GLOBALS['O0']; ?> </a> <?php breadcrumb(); ?> </div>

      <!-- Quick Help for tablets and large screens -->
      <div class="quick-message hidden-xs">
        <div class="quick-box">
          <div class="quick-slide"> <span class="title"><?php $GLOBALS['O3']; ?></span>
            <div class="quickbox slide" id="quickbox">
              <div class="carousel-inner">
                <div class="item active"> <a href="#"> <i class="fa fa-envelope fa-fw"></i> Quick Message</a> </div>
                <div class="item"> <a href="#"> <i class="fa fa-question-circle fa-fw"></i> FAQ</a> </div>
                <div class="item"> <a href="#"> <i class="fa fa-phone fa-fw"></i> +6285 795525434</a> </div>
              </div>
            </div>
            <a class="left carousel-control" data-slide="prev" href="#quickbox"> <i class="fa fa-angle-left fa-fw"></i> </a> <a class="right carousel-control" data-slide="next" href="#quickbox"> <i class="fa fa-angle-right fa-fw"></i> </a> </div>
        </div>
      </div>
      <!-- end: Quick Help -->

    </div>
  </div>
</div>
<div class="row clearfix f-space10"></div>
<?php main(); banner(); ?>
<!-- footer -->
<footer class="footer"><?php footer(); ?></footer>
<!-- end: footer -->

<!-- Style Switcher JS -->
<script src="js/style-switch.js" type="text/javascript"></script>
<section id="style-switch" class="bgcolor3">
  <h2>Style Switch <a href="#" class="btn color2"><i class="fa fa-cog "></i></a></h2>
  <div class="inner">
    <h3>Predefined Styles</h3>
    <ul class="colors list-unstyled" id="color1">
      <li><a href="#" class="blue-red" data-toggle="tooltip" title="Blue Red" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="midnight-blue" data-toggle="tooltip" title="Midnight Blue" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="mono-red" data-toggle="tooltip" title="Mono Red" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="pinegreen-purple" data-toggle="tooltip" title="PineGreen Purple" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="darkmagenta-rosybrown" data-toggle="tooltip" title="DarkMagenta RosyBrown" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="darkorchid-seagreen" data-toggle="tooltip" title="DarkOrchid SeaGreen" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="steel-blue" data-toggle="tooltip" title="Steel Blue" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="cadetblue-violetred" data-toggle="tooltip" title="CadetBlue VioletRed" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="mediumpurple-seagreen" data-toggle="tooltip" title="MediumPurple SeaGreen" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="steelblue-leafgreen" data-toggle="tooltip" title="SteelBlue LeafGreen" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="orange-steelblue" data-toggle="tooltip" title="Orange SteelBlue" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
      <li><a href="#" class="gray" data-toggle="tooltip" title="Gray" > <i class="fa fa-cog fa-stop one"></i><i class="fa fa-cog fa-stop two"></i></a></li>
    </ul>
  </div>
  <div id="reset" class="inner"><a href="#" class="btn normal color2 ">Reset</a></div>
</section>
<!-- Google Maps -->
<script type="text/javascript" src="http://maps.google.com/maps/api/js?sensor=false&amp;language=en"></script>
<script type="text/javascript" src="js/gmap3.js"></script> 
<script src="js/custom.js" type="text/javascript"></script>
</body>
</html>
<?php ob_end_flush(); ?>
