<?php include_once('connect.inc');
/*
 * categories.inc
 *
 * Copyright 2014 Imancha <imancha_266@ymail.com>
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

	function insert(){
		if(isset($_POST['submit'])){			
			$title 		= $_POST['title'];
			$category = $_POST['category'];

			mysql_open();
			$sql = "INSERT INTO
								`Category`
							VALUES
								(NULL,'$title')";
			$res = mysql_query($sql) or die(mysql_error());
			
			if(mysql_affected_rows() == 1){
				echo '<div class="alert alert-success">
								<button class="close" type="button" data-dismiss="alert">x</button>
								<strong>Well done! </strong>
								You successfully added the '.$title.' into the Book Categories.
							</div>';
							
				$id = mysql_insert_id();
				foreach($category as $value){
					$sql = "INSERT INTO
										`Category Detail`
									VALUES
									(NULL,'$id','$value')";
					$res = mysql_query($sql) or die(mysql_error());
					if(mysql_affected_rows() == 1){
						echo '<div class="alert alert-success">
										<button class="close" type="button" data-dismiss="alert">x</button>
										<strong>Success! </strong>
										Added the '.$value.' into the '.$title.' Categories.
									</div>';
					}else{
						echo '<div class="alert alert-error">
										<button class="close" type="button" data-dismiss="alert">x</button>
										<strong>Failed! </strong>
										Added the '.$value.' into the '.$title.' Categories.
									</div>';
					}
				}
			}else{
				echo '<div class="alert alert-error">
								<button class="close" type="button" data-dismiss="alert">x</button>
								<strong>Oh snap! </strong>
								Change a few things up and try submitting again.
							</div>';
			}
			mysql_close();
		}

		echo '<div class="widget">
						<h4 class="widgettitle">Book Categories Form</h4>
						<div class="widgetcontent nopadding">
							<form class="stdform stdform2" action="" method="post">
								<p>
									<label>Name <small>The name of the category</small></label>
									<span class="field"><input type="text" name="title" id="title" class="input-xlarge" required></span>
								</p>
								<p>
									<label>Category <small>The category(s) of the book</small></label>
									<span class="field">
										<span class="input-append" style="margin-bottom:-6px">
											<input type="text" name="category[]" id="author1" class="input-xlarge">
											<button type="button" class="btn" id="btn-add2" data-toggle="tooltip" data-placement="right" title="Add new category"><i class="icon-plus"></i></button>
										</span>
									</span>
								</p>
								<p class="stdformbutton">
									<button name="submit" type="submit" class="btn btn-primary">Submit Button</button>
									<button type="reset" class="btn">Reset Button</button>
								</p>
							</form>
						</div>
					</div>';
	}

	function view(){				
		mysql_open();

		$sql = "SELECT
							*
						FROM
							`Category`
						ORDER BY
							`Name` ASC";				
		$res = mysql_query($sql) or die(mysql_error());		

		echo '<table class="table table-bordered responsive">						
						<thead>
							<tr>
								<th></th>
								<th style="width:5%; text-align:center;">#</th>
								<th>Category</th>
								<th>Subject</th>								
							</tr>
						</thead>
						<tbody>';

		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				echo '<tr>
								<td></td>
								<td style="width:5%; text-align:center;">'.(++$i).'</td>
								<td>'.$row['Name'].'</td>
								<td style="padding:0px;">';
								
				$sql_ = "SELECT
										`Name`
								 FROM
										`Category Detail`
								 WHERE
										`ID Category` = '".$row['ID']."'
								 ORDER BY
										`Name` ASC";
				$res_ = mysql_query($sql_) or die(mysql_error());
				
				if(mysql_num_rows($res_) > 0){
					echo '<table class="table table-bordered table-hover" style="background:none; margin-bottom:0px;">									
									<tbody>';
					while($row_ = mysql_fetch_assoc($res_)){
						echo '	<tr>
											<td></td>
											<td>'.$row_['Name'].'</td>
										</tr>';
					}
					echo '	</tbody>
								</table>';
				}
				echo '	</td>
							</tr>';
			}
		}

		echo '	</tbody>
					</table>';

		mysql_close();
	}

	switch($_GET['i']){
		case 'insert' : insert(); break;
		case 'view' 	: view(); break;
	}
?>
