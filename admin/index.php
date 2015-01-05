<!--
   index.php

   Copyright 2014 Imancha <imancha_266@ymail.com>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.


-->
<?php include_once('inc/main.inc'); ?>
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1.0" />

		<title>Imancha</title>

		<link rel="stylesheet" href="css/style.default.css" type="text/css" />
		<link rel="stylesheet" href="css/responsive-tables.css">
		<link rel="stylesheet" href="css/bootstrap-fileupload.min.css" type="text/css" />
		<link rel="stylesheet" href="css/jquery-te-1.4.0.css" type="text/css" />

		<script type="text/javascript" src="js/jquery-1.9.1.min.js"></script>
		<script type="text/javascript" src="js/jquery-migrate-1.1.1.min.js"></script>
		<script type="text/javascript" src="js/jquery-ui-1.9.2.min.js"></script>
		<script type="text/javascript" src="js/bootstrap.min.js"></script>
		<script type="text/javascript" src="js/bootstrap-fileupload.min.js"></script>
		<script type="text/javascript" src="js/bootstrap-timepicker.min.js"></script>
		<script type="text/javascript" src="js/jquery.uniform.min.js"></script>
		<script type="text/javascript" src="js/jquery.validate.min.js"></script>
		<script type="text/javascript" src="js/jquery.tagsinput.min.js"></script>
		<script type="text/javascript" src="js/jquery.autogrow-textarea.js"></script>
		<script type="text/javascript" src="js/charCount.js"></script>
		<script type="text/javascript" src="js/colorpicker.js"></script>
		<script type="text/javascript" src="js/ui.spinner.min.js"></script>
		<script type="text/javascript" src="js/chosen.jquery.min.js"></script>
		<script type="text/javascript" src="js/jquery.cookie.js"></script>
		<script type="text/javascript" src="js/jquery.smartWizard.min.js"></script>
		<script type="text/javascript" src="js/modernizr.min.js"></script>
		<script type="text/javascript" src="js/flot/jquery.flot.min.js"></script>
		<script type="text/javascript" src="js/flot/jquery.flot.resize.min.js"></script>
		<script type="text/javascript" src="js/tinymce/jquery.tinymce.js"></script>
		<script type="text/javascript" src="js/jquery.dataTables.min.js"></script>
		<script type="text/javascript" src="js/jquery-te-1.4.0.min.js"></script>		
		<script type="text/javascript" src="js/responsive-tables.js"></script>
		<script type="text/javascript" src="js/wysiwyg.js"></script>
		<script type="text/javascript" src="js/forms.js"></script>
		<script type="text/javascript" src="js/custom.js"></script>
		<script type="text/javascript" src="js/script.js"></script>
		<!--[if lte IE 8]><script language="javascript" type="text/javascript" src="js/excanvas.min.js"></script><![endif]-->
	</head>

	<body>
		<div class="mainwrapper">
			<div class="header"><?php top(); ?></div>
			<div class="leftpanel"><?php navigation(); ?></div>
			<div class="rightpanel">
				<div class="breadcrumb"><?php breadcrumb(); ?></div>
        <div class="pageheader"><?php pageheader(); ?></div>
        <div class="maincontent">
					<div class="maincontentinner">
						<div class="main"><?php main(); ?></div>
						<div class="footer"><?php footer(); ?></div><!--footer-->
					</div><!--maincontentinner-->
        </div><!--maincontent-->
			</div><!--rightpanel-->
		</div><!--mainwrapper-->		
	</body>
</html>
