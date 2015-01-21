<?php include_once('connect.inc');
/*
 * categories.inc
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

	function insert(){
		if(isset($_POST['submit'])){
			mysql_open();
			$sql = "SELECT `Name` FROM `Category` WHERE LOWER(`Name`) LIKE LOWER('".mysql_real_escape_string(trim($_POST['title']))."') LIMIT 1";
			$res = @mysql_query($sql) or die(mysql_error());
			if(mysql_num_rows($res) > 0){
			}else{
				$sql = "INSERT INTO `Category` VALUES (NULL,'".mysql_real_escape_string(trim($_POST['title']))."')";
				$res = @mysql_query($sql) or die(mysql_error());
				if(mysql_affected_rows() == 1){
					echo '<div class="alert alert-success">
									<button class="close" type="button" data-dismiss="alert">x</button>
									<strong>Well done! </strong>
									You successfully added the '.$_POST['title'].' into the Book Categories.
								</div>';
					$id = mysql_insert_id();
					foreach(explode(',',$_POST['category']) as $value){
						$sql = "INSERT INTO `Category Detail` VALUES (NULL,'$id','$value')";
						$res = @mysql_query($sql) or die(mysql_error());
						if(mysql_affected_rows() == 1){
							echo '<div class="alert alert-success">
											<button class="close" type="button" data-dismiss="alert">x</button>
											<strong>Success! </strong>
											Added the '.$value.' into the '.$_POST['title'].' Categories.
										</div>';
						}else{
							echo '<div class="alert alert-error">
											<button class="close" type="button" data-dismiss="alert">x</button>
											<strong>Failed! </strong>
											Added the '.$value.' into the '.$_POST['title'].' Categories.
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
										<textarea name="category" id="category" class="span5" style="resize: vertical; height: 113px;" cols="80" rows="8" required></textarea>
									</span>
								</p>
								<p class="stdformbutton">
									<button name="submit" type="submit" class="btn btn-primary">Submit</button>
									<button type="reset" class="btn">Reset</button>
								</p>
							</form>
						</div>
					</div>';
	}
	function view(){
		echo '<div><button class="btn btn-primary btn-rounded" onclick="window.location=\'./?!=categories&i=insert\'"><i class="iconsweets-notebook iconsweets-white"></i> &nbsp; Insert New Category</button></div>
					<div class="accordion-group accordion">
						<h3 class="text-center"><i class="iconfa-hand-up"></i></h3>
						<div class="nopadding nomargin"></div>';
		mysql_open();
		$sql = "SELECT * FROM `Category` ORDER BY `Name` ASC";
		$res = mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				echo '<h3>
								<a href="#'.$row['Name'].'"><strong>'.$row['Name'].'</strong></a>
								<span class="pull-right" style="position:absolute; top:10px; right:10px; font-size:larger;">
									<button class="btn btn-transparent btn-warning" data-original-title="Edit" data-rel="tooltip" data-placement="left" rel="tooltip" onclick="window.location=\'./?!=categories&i=update&)='.please('encrypt',$row['ID']).'\'"><i class="iconfa-edit"></i></button> &nbsp;
									<button class="btn btn-transparent btn-danger" data-original-title="Delete" data-rel="tooltip" data-placement="left" rel="tooltip" data-target="#delete'.$j.'" data-toggle="modal"><i class="iconfa-trash"></i></button>
								</span>
								<div aria-hidden="false" aria-labelledby="myModalLabel" role="dialog" tabindex="-1" class="modal hide fade in" id="delete'.$j.'">
									<div class="modal-header">
										<button aria-hidden="true" data-dismiss="modal" class="close" type="button">&times;</button>
										<h3 id="myModalLabel">'.$row['Name'].'</h3>
									</div>
									<div class="modal-body">
										<p>Delete this category from the database...?</p>
									</div>
									<div class="modal-footer">
										<button data-dismiss="modal" class="btn">Cancel</button>
										<button data-dismiss="modal" class="btn btn-primary" onclick="window.location=\'./?!=categories&i=delete&(='.please('encrypt',$row['ID']).'\'">Delete</button>
									</div>
								</div><!--#myModal-->
							</h3>
							<div class="nopadding nomargin">';
				$sql_ = "SELECT * FROM `Category Detail` WHERE `ID Category` = '".$row['ID']."' ORDER BY `Name` ASC";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) > 0){
					echo '<table class="table table-bordered table-hover table-transparent">
									<thead>
										<tr>
											<th>#</th>
											<th>Name</th>
											<th>Edit</th>
											<th>Delete</th>
										</tr>
									</thead>
									<tbody>';
					while($row_ = mysql_fetch_assoc($res_)){
						echo '	<tr>
											<td class="text-center">'.++$i.'</td>
											<td>'.$row_['Name'].'</td>
											<td class="text-center"><button class="btn btn-transparent btn-warning" data-original-title="Edit" data-rel="tooltip" data-placement="bottom" rel="tooltip" onclick="window.location=\'./?!=categories&i=update&(='.please('encrypt',$row_['ID']).'\'"><i class="iconfa-edit"></i></button></td>
											<td class="text-center"><button class="btn btn-transparent btn-danger" data-original-title="Delete" data-rel="tooltip" data-placement="bottom" rel="tooltip" data-target="#delete'.$i.'" data-toggle="modal"><i class="iconfa-trash"></i></button></td>
										</tr>
										<div aria-hidden="false" aria-labelledby="myModalLabel" role="dialog" tabindex="-1" class="modal hide fade in" id="delete'.$i.'">
											<div class="modal-header">
												<button aria-hidden="true" data-dismiss="modal" class="close" type="button">&times;</button>
												<h3 id="myModalLabel">'.$row_['Name'].'</h3>
											</div>
											<div class="modal-body">
												<p>Delete this category from the database...?</p>
											</div>
											<div class="modal-footer">
												<button data-dismiss="modal" class="btn">Cancel</button>
												<button data-dismiss="modal" class="btn btn-primary" onclick="window.location=\'./?!=categories&i=delete&)='.please('encrypt',$row_['ID']).'\'">Delete</button>
											</div>
										</div><!--#myModal-->';
					}
					echo '	</tbody>
								</table>';
				}
				echo '</div>';
			}
		}
		echo '</div>';
		mysql_close();
	}
	function update(){
		if(isset($_GET['('])){
			if(isset($_POST['submit'])){
				mysql_open();
				$sql = "UPDATE `Category Detail` SET `Name`='".mysql_real_escape_string(trim($_POST['title']))."' WHERE `ID`=".$_POST['id']." LIMIT 1";
				$res = @mysql_query($sql) or die(mysql_error());
				if(mysql_affected_rows() == 1){
					echo '<div class="alert alert-success">
									<button class="close" type="button" data-dismiss="alert">x</button>
									<strong>Well done! </strong>
									You successfully added the '.$_POST['title'].' into the Book Categories.
								</div>';
				}else{
					echo '<div class="alert alert-error">
									<button class="close" type="button" data-dismiss="alert">x</button>
									<strong>Oh snap! </strong>
									Change a few things up and try submitting again.
								</div>';
				}
				mysql_close();
			}
			mysql_open();
			$sql = "SELECT * FROM `Category Detail` WHERE `ID`=".please('decrypt',$_GET['('])." LIMIT 1";
			$res = @mysql_query($sql) or die(mysql_error());
			if(mysql_num_rows($res) == 1){
				$row = mysql_fetch_assoc($res);
				echo '<div class="widget">
								<h4 class="widgettitle">Book Categories Form</h4>
								<div class="widgetcontent nopadding">
									<form class="stdform stdform2" action="" method="post">
										<p>
											<label>Name <small>The name of the category</small></label>
											<span class="field"><input type="hidden" name="id" value="'.$row['ID'].'"><input type="text" name="title" id="title" class="input-xlarge" value="'.$row['Name'].'" autocomplete="off" required></span>
										</p>
										<p class="stdformbutton">
											<button name="submit" type="submit" class="btn btn-primary">Save Changes</button>
											<button class="btn" onclick="window.location=\'./?!=categories\'; return false;">Cancel</button>
										</p>
									</form>
								</div>
							</div>';
			}
			mysql_close();
		}else{
			mysql_open();
			if(isset($_POST['submit'])){
				$sql = "UPDATE `Category` SET `Name`='".mysql_real_escape_string(trim($_POST['title']))."' WHERE `ID`=".$_POST['id']." LIMIT 1";
				$res = @mysql_query($sql) or die(mysql_error());
				foreach(explode(',',$_POST['category']) as $value){
					$sql_ = "SELECT `ID` FROM `Category Detail` WHERE LOWER(`Name`) LIKE LOWER('".$value."') AND `ID Category`=".$_POST['id']." LIMIT 1";
					$res_ = @mysql_query($sql_) or die(mysql_error());
					if(mysql_num_rows($res_) == 1){
						continue;
					}else{
						$sql__ = "INSERT INTO `Category Detail` VALUES (NULL,".$_POST['id'].",'".mysql_real_escape_string(trim($value))."')";
						$res__ = @mysql_query($sql__) or die(mysql_error());
						if(mysql_affected_rows() == 1){
							echo '<div class="alert alert-success">
											<button class="close" type="button" data-dismiss="alert">x</button>
											<strong>Success! </strong>
											Added the '.$value.' into the '.$_POST['title'].' Categories.
										</div>';
						}else{
							echo '<div class="alert alert-error">
											<button class="close" type="button" data-dismiss="alert">x</button>
											<strong>Failed! </strong>
											Added the '.$value.' into the '.$_POST['title'].' Categories.
										</div>';
						}
					}
				}
			}
			$sql = "SELECT * FROM `Category` WHERE `ID`=".please('decrypt',$_GET[')'])." LIMIT 1";
			$res = @mysql_query($sql) or die(mysql_error());
			if(mysql_num_rows($res) == 1){
				$row = mysql_fetch_assoc($res);
				$sql_ = "SELECT * FROM `Category Detail` WHERE `ID Category`=".$row['ID']." ORDER BY `Name` ASC";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) > 0){
					while($row_ = mysql_fetch_assoc($res_)){
						$cat .= $row_['Name'].', ';
					}
				}
			}
			echo '<div class="widget">
							<h4 class="widgettitle">Book Categories Form</h4>
							<div class="widgetcontent nopadding">
								<form class="stdform stdform2" action="" method="post">
									<p>
										<label>Name <small>The name of the category</small></label>
										<span class="field"><input type="hidden" name="id" value="'.$row['ID'].'"><input type="text" name="title" id="title" class="input-xlarge" value="'.$row['Name'].'" autocomplete="off" required></span>
									</p>
									<p>
										<label>Category <small>The category(s) of the book</small></label>
										<span class="field">
											<textarea name="category" id="category" class="span5" style="resize: vertical; height: 113px;" cols="80" rows="8" autocomplete="off" required>'.$cat.'</textarea>
										</span>
									</p>
									<p class="stdformbutton">
										<button name="submit" type="submit" class="btn btn-primary">Save Changes</button>
										<button class="btn" onclick="window.location=\'./?!=categories\'; return false;">Cancel</button>
									</p>
								</form>
							</div>
						</div>';
			mysql_close();
		}
	}
	function delete(){
		mysql_open();
		mysql_query("START TRANSACTION");
		if(isset($_GET[')'])){$table='Category Detail'; $id=please('decrypt',$_GET[')']);}
		else if(isset($_GET['('])){$table='Category'; $id=please('decrypt',$_GET['(']);}
		$sql = "DELETE FROM `".$table."` WHERE `ID`=".$id." LIMIT 1";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_affected_rows() == 1){
			mysql_query("COMMIT");
			echo '<div class="alert alert-success">
							<button class="close" type="button" data-dismiss="alert">x</button>
							<strong>Success! </strong>
							Deleted from Categories.
						</div>';
		}else{
			mysql_query("ROLLBACK");
			echo '<div class="alert alert-error">
							<button class="close" type="button" data-dismiss="alert">x</button>
							<strong>Failed! </strong>
							Deleted from Categories.
						</div>';
		}
		mysql_close();
		view();
	}

	switch($_GET['i']){
		case 'insert' : insert(); break;
		case 'update' : update(); break;
		case 'delete' : delete(); break;
		default: view();
	}
?>
