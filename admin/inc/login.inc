<?php include_once('main.inc'); ?>
<!--
   login.inc

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
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1.0" />
		<title>Imancha</title>
		<link rel="stylesheet" href="../css/style.default.css" type="text/css" />		

		<script type="text/javascript" src="../js/jquery-1.9.1.min.js"></script>
		<script type="text/javascript" src="../js/jquery-migrate-1.1.1.min.js"></script>
		<script type="text/javascript" src="../js/jquery-ui-1.9.2.min.js"></script>
		<script type="text/javascript" src="../js/modernizr.min.js"></script>
		<script type="text/javascript" src="../js/bootstrap.min.js"></script>
		<script type="text/javascript" src="../js/jquery.cookie.js"></script>
		<script type="text/javascript" src="../js/custom.js"></script>		
	</head>

	<body class="loginpage">
		<div class="loginpanel">
			<div class="loginpanelinner">
				<div class="logo animate0 bounceIn"><img src="../images/logo.png" alt="" /></div>
				<form id="login" action="../" method="post">
					<div class="inputwrapper login-alert">
						<div class="alert alert-error">Invalid username or password</div>
					</div>
					<div class="inputwrapper animate1 bounceIn">
					<input type="text" name="username" id="username" placeholder="Enter username" autocomplete="off" />
					</div>
					<div class="inputwrapper animate2 bounceIn">
						<input type="password" name="password" id="password" placeholder="Enter password" autocomplete="off" />
					</div>
					<div class="inputwrapper animate3 bounceIn">
						<button name="login">Sign In</button>
					</div>
					<div class="inputwrapper animate4 bounceIn">
						<label><input type="checkbox" class="remember" name="signin" /> Keep me sign in</label>
					</div>
				</form>
			</div><!--loginpanelinner-->
		</div><!--loginpanel-->
		<div class="loginfooter">
			<p>&copy; 2013. Shamcey Admin Template. All Rights Reserved.</p>
		</div>
	</body>
</html>
