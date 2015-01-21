<?php include_once('connect.inc');
/*
 * catalogue.inc
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
			$error = FALSE;
			mysql_open();
			mysql_query("START TRANSACTION");
			$sql = "INSERT INTO `Book` VALUES (NULL,'".mysql_real_escape_string(trim($_POST['title']))."','".mysql_real_escape_string(trim($_POST['subtitle']))."','".mysql_real_escape_string(trim($_POST['description']))."','".mysql_real_escape_string(trim($_POST['isbn']))."','".mysql_real_escape_string(trim($_POST['page']))."','".mysql_real_escape_string(trim($_POST['year']))."','".mysql_real_escape_string(trim($_POST['publisher']))."','".mysql_real_escape_string(trim($_POST['language']))."')";
			$res = @mysql_query($sql) or die(mysql_error());
			if(mysql_affected_rows() == 1){
				$id = mysql_insert_id();
				foreach($_POST['category'] as $val){
					$sql = "INSERT INTO `Book Category` VALUES ('$id','$val')";
					$res = mysql_query($sql) or die(mysql_error());
					if(mysql_affected_rows() != 1){ $error = TRUE; }
				}
				foreach(explode(',',($_POST['author'])) as $val){
					$sql = "SELECT * FROM `Author` WHERE LOWER(`Name`) = LOWER('$val') LIMIT 1";
					$res = mysql_query($sql) or die(mysql_error());
					if(mysql_num_rows($res) == 1){
						$row = mysql_fetch_assoc($res);
						$id_ = $row['ID'];
					}else{
						$sql = "INSERT INTO `Author` VALUES (NULL,'".mysql_real_escape_string(trim($val))."')";
						$res = @mysql_query($sql) or die(mysql_error());
						if(mysql_affected_rows() == 1){ $id_ = mysql_insert_id();	}else{ $error = TRUE; }
					}
					$sql = "INSERT INTO `Book Author` VALUES ('$id','$id_')";
					$res = @mysql_query($sql) or die(mysql_error());
					if(mysql_affected_rows() != 1){ $error = TRUE; }
				}
				foreach($_POST['warehouse'] as $val){
					if($val == 1){$p = $_POST['price1']; $s = $_POST['stock1'];}
					else if($val == 2){$p = $_POST['price2']; $s = $_POST['stock2'];}
					$sql = "INSERT INTO `Stock` VALUES ('$val','$id','$s','$p')";
					$res = @mysql_query($sql) or die(mysql_error());
					if(mysql_affected_rows() != 1){ $error = TRUE; }
				}
				$target_dir = "../images/cover/";
				$target_file = $target_dir . basename($_FILES["cover"]["name"]);
				$uploadOk = 1;
				$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
				$newfilename = mysql_real_escape_string(trim($_POST['title'])).'.'.$imageFileType;
				$target_file = $target_dir.$newfilename;
				$check = getimagesize($_FILES["cover"]["tmp_name"]);
				if($check !== false){$uploadOk = 1;}
				else{$uploadOk = 0;
					echo '<div class="alert alert-warning">
									<button class="close" type="button" data-dismiss="alert">x</button>
									<strong>Oh snap! </strong>
									File is not an image.
								</div>';
				}
				if(file_exists($target_file)){$uploadOk = 0;
					echo '<div class="alert alert-warning">
									<button class="close" type="button" data-dismiss="alert">x</button>
									<strong>Oh snap! </strong>
									Sorry, file already exists.
								</div>';
				}
				if($_FILES["cover"]["size"] > 500000){$uploadOk = 0;
					echo '<div class="alert alert-warning">
									<button class="close" type="button" data-dismiss="alert">x</button>
									<strong>Oh snap! </strong>
									Sorry, your file is too large.
								</div>';
				}
				if($imageFileType != "png"){$uploadOk = 0;
					echo '<div class="alert alert-warning">
									<button class="close" type="button" data-dismiss="alert">x</button>
									<strong>Oh snap! </strong>
									Sorry, only PNG files are allowed.
								</div>';
				}
				if($uploadOk == 0){$error = TRUE;}
				else{
					if(!move_uploaded_file($_FILES["cover"]["tmp_name"], $target_file)){
						$error = TRUE;
						echo '<div class="alert alert-warning">
										<button class="close" type="button" data-dismiss="alert">x</button>
										<strong>Oh snap! </strong>
										Sorry, there was an error uploading your file.
									</div>';
					}
				}
			}else { $error = TRUE; }
			if($error){
				mysql_query("ROLLBACK");
				echo '<div class="alert alert-error">
								<button class="close" type="button" data-dismiss="alert">x</button>
								<strong>Oh snap! </strong>
								Change a few things up and try submitting again.
							</div>';
			}else{
				mysql_query("COMMIT");
				echo '<div class="alert alert-success">
								<button class="close" type="button" data-dismiss="alert">x</button>
								<strong>Well done! </strong>
								You successfully added the <i>'.$_POST['title'].' <small>'.$_POST['subtitle'].'</small></i> into the Book Catalogue.
							</div>';
			}
			mysql_close();
		}
		mysql_open();
		$sql = "SELECT * FROM `Category Detail` ORDER BY `Name` ASC";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){while($row = mysql_fetch_assoc($res)){$cat .= '<option value='.$row['ID'].'>'.$row['Name'].'</option>';}}
		mysql_close();
		echo '<div class="widget">
						<h4 class="widgettitle">Book Catalogue Form</h4>
						<div class="widgetcontent nopadding">
							<form class="stdform stdform2" action="" method="post" enctype="multipart/form-data">
								<p>
									<label>Title <small>The title of the book</small></label>
									<span class="field"><input type="text" name="title" id="title" class="input-xxlarge" autocomplete="off" required></span>
								</p>
								<p>
									<label>Subtitle <small>The subtitle of the book</small></label>
									<span class="field"><input type="text" name="subtitle" id="subtitle" class="input-xxlarge" autocomplete="off"></span>
								</p>
								<p>
									<label>Description <small>The description of the book</small></label>
									<span class="field"><textarea id="elm1" name="description" rows="15" cols="80" style="width: 80%" class="tinymce"></textarea></span>
								</p>
								<p>
									<label>Author <small>The author(s) name of the book</small></label>
									<span class="field"><textarea name="author" id="author" class="span5" style="resize: vertical; height: 113px;" cols="80" rows="8"></textarea></span>
								</p>
								<p>
									<label>Category <small>The category of the book</small></label>
									<span class="formwrapper field">
										<span class="input-append" style="margin-bottom:-10px">
											<select name="category[]" id="category1" data-placeholder="Choose Categories..." class="chzn-select" multiple="multiple" style="width:321px;" tabindex="4">
												<option value=""></option>
												'.$cat.'
											</select>
											<!--<button type="button" class="btn" id="btn-add1" data-toggle="tooltip" data-placement="right" title="Add new category"><i class="icon-plus"></i></button>-->
										</span>
									</span>
								</p>
								<p>
									<label>Publisher <small>The publisher of the book</small></label>
									<span class="field"><input type="text" name="publisher" id="publisher" class="input-xlarge" autocomplete="off"></span>
								</p>
								<p>
									<label>ISBN <small>The ISBN of the book</small></label>
									<span class="field"><input type="number" name="isbn" id="isbn" class="input-xlarge" autocomplete="off"></span>
								</p>
								<p>
									<label>Language <small>The language of the book</small></label>
									<span class="field">
										<select name="language" id="language" data-placeholder="Choose a Language..." style="width:215px" class="chzn-select" tabindex="2">
											<option></option>
											<option value="Indonesia">Indonesia</option>
											<option value="English">English</option>
										</select>
									</span>
								</p>
								<p>
									<label>Page <small>The number of pages of the book</small></label>
									<span class="field"><input type="number" name="page" id="page" class="input-small" autocomplete="off"></span>
								</p>
								<p>
									<label>Year <small>The publication date (year) of the book</small></label>
									<span class="field"><input type="number" name="year" id="year" class="input-small" autocomplete="off"></span>
								</p>
								<p>
									<label>Warehouse <small>The warehouse of the book</small></label>
									<span class="field">
										<input type="checkbox" name="warehouse[]" id="wareid" value="1"> Indonesia
										<span id="itemid" style="margin-left:49px;">
											<input type="text" name="price1" id="priceid" class="input-small" placeholder="Rp" autocomplete="off">
											<input type="number" name="stock1" id="stockid" class="input-small" placeholder="Stock" autocomplete="off">
										</span>
										<br>
										<input type="checkbox" name="warehouse[]" id="wareus" value="2"> United States
										<span id="itemus" style="margin-left:30px;">
											<input type="text" name="price2" id="priceus" class="input-small" placeholder="$" autocomplete="off">
											<input type="number" name="stock2" id="stockus" class="input-small" placeholder="Stock" autocomplete="off">
										</span>
									</span>
								</p>
								<p>
								<label>Cover <small>The cover of the book</small></label>
									<span class="field">
										<span class="fileupload fileupload-new" data-provides="fileupload">
											<span class="input-append" style="margin-bottom:0px">
												<span class="uneditable-input span3">
													<i class="iconfa-file fileupload-exists"></i>
													<span class="fileupload-preview"></span>
												</span>
												<span class="btn btn-file"><span class="fileupload-new">Select file</span>
												<span class="fileupload-exists">Change</span>
												<input type="file" name="cover" />
											</span>
											<a href="#" class="btn fileupload-exists" data-dismiss="fileupload">Remove</a>
										</span>
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
		echo '<div><button class="btn btn-primary btn-rounded" onclick="window.location=\'./?!=catalogue&i=insert\'"><i class="iconsweets-notebook iconsweets-white"></i> &nbsp; Insert New Book</button></div>
					<table id="dyntable" class="table table-bordered responsive">
						<colgroup><col class="con0" /><col class="con1" /><col class="con0" /><col class="con1" /><col class="con0" /><col class="con1" /><col class="con0" /><col class="con1" /><col class="con0" /></colgroup>
						<thead><tr><th class="head0 text-center"></th><th class="head1">Title</th><th class="head0">Author</th><th class="head1">Publisher</th><th class="head0">Warehouse</th><th class="head1 text-center">Price</th><th class="head0 text-center" title="stock"><i class="iconfa-shopping-cart"></i></th><th class="head1 text-center" title="edit"><i class="iconfa-edit"></i></th><th class="head0 text-center" title="delete"><i class="iconfa-trash"></i></th></tr></thead>
						<tbody>';
		mysql_open();
		$sql = "SELECT a.`ID`,a.`Title`,a.`SubTitle`,a.`Publisher`,c.`Name`,d.`Price`,d.`Stock` FROM `Book` a JOIN `Stock` d ON (a.`ID` = d.`ID Book`) JOIN `Warehouse` c ON (d.`ID Warehouse` = c.`ID`) ORDER BY a.`Title` ASC";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_array($res)){
				echo '<tr>
								<td></td>
								<td>'.$row['Title'].'<small>: '.substr($row['SubTitle'],0,50).(strlen($row['SubTitle']) > 50 ? '...' : '').'</small></td>
								<td>';
				$sql_ = "SELECT `ID Author` FROM `Book Author` WHERE `ID Book` = '".$row['ID']."'";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) > 0){
					while($row_ = mysql_fetch_assoc($res_)){
						$sql__ = "SELECT `Name` FROM `Author` WHERE `ID` = '".$row_['ID Author']."' LIMIT 1";
						$res__ = @mysql_query($sql__) or die(mysql_error());
						if(mysql_num_rows($res__) == 1){
							$row__ = mysql_fetch_assoc($res__);
							echo $row__['Name'].'; ';
						}
					}
				}
				echo '	</td>
								<td>'.$row['Publisher'].'</td>
								<td>'.$row['Name'].'</td>
								<td class="text-center">'.$row['Price'].'</td>
								<td class="text-center">'.$row['Stock'].'</td>
								<td class="text-center"><button class="btn btn-transparent btn-warning" title="edit" onclick="window.location=\'./?!=catalogue&i=update&)='.please('encrypt',$row['ID']).'\'"><i class="iconfa-edit"></i></button></td>
								<td class="text-center"><button class="btn btn-transparent btn-danger" title="delete" data-target="#delete'.$i.'" data-toggle="modal"><i class="iconfa-trash"></i></button></td>
							</tr>
							<div aria-hidden="false" aria-labelledby="myModalLabel" role="dialog" tabindex="-1" class="modal hide fade in" id="delete'.$i.'">
								<div class="modal-header">
									<button aria-hidden="true" data-dismiss="modal" class="close" type="button">&times;</button>
									<h3 id="myModalLabel">'.$row['Title'].'</h3>
									<div><small>'.$row['SubTitle'].'</small></div>
								</div>
								<div class="modal-body">
									<p>Delete this book from the database...?</p>
								</div>
								<div class="modal-footer">
									<button data-dismiss="modal" class="btn">Cancel</button>
									<button class="btn btn-primary" onclick="window.location=\'./?!=catalogue&i=delete&)='.please('encrypt',$row['ID']).'\'">Delete</button>
								</div>
							</div><!--#myModal-->';
			}
		}
		echo '	</tbody>
					</table>';
		mysql_close();
	}
	function update(){
		if(isset($_POST['update'])){
			mysql_open();
			mysql_query("START TRANSACTION");
			$sql = "UPDATE `Book` SET `Title`='".mysql_real_escape_string(trim($_POST['title']))."',`SubTitle`='".mysql_real_escape_string(trim($_POST['subtitle']))."',`Description`='".mysql_real_escape_string(trim($_POST['description']))."',`ISBN`='".mysql_real_escape_string(trim($_POST['isbn']))."',`Page`='".mysql_real_escape_string(trim($_POST['page']))."',`Year`='".mysql_real_escape_string(trim($_POST['year']))."',`Publisher`='".mysql_real_escape_string(trim($_POST['publisher']))."',`Language`='".mysql_real_escape_string(trim($_POST['language']))."' WHERE `ID`=".$_POST['id']."";
			$res = @mysql_query($sql) or die(mysql_error());
			if(!$res){
				$error[] = '<div class="alert alert-error">
											<button class="close" type="button" data-dismiss="alert">x</button>
											<strong>Update Book Failed! </strong>
											Change a few things up and try submitting again.
										</div>';
			}
			$sql = "DELETE FROM `Book Category` WHERE `ID Book`=".$_POST['id']."";
			$res = @mysql_query($sql) or die(mysql_error());
			if($res){
				foreach($_POST['category'] as $val){
					$sql = "INSERT INTO `Book Category` VALUES (".$_POST['id'].",".$val.")";
					$res = @mysql_query($sql) or die(mysql_error());
					if(mysql_affected_rows() != 1){
						$error[] = '<div class="alert alert-error">
													<button class="close" type="button" data-dismiss="alert">x</button>
													<strong>Update Book Category Failed! </strong>
													Change a few things up and try submitting again.
												</div>';
					}
				}
			}
			if(!empty($_POST['author'])){
				foreach(explode(',',$_POST['author']) as $val){
					$sql = "SELECT * FROM `Author` WHERE LOWER(`Name`) LIKE LOWER('".$val."') LIMIT 1";
					$res = @mysql_query($sql) or die(mysql_error());
					if(mysql_num_rows($res) != 1){
						$sql = "INSERT INTO `Author` VALUE (NULL,'".$val."')";
						$res = @mysql_query($sql) or die(mysql_error());
						if(mysql_affected_rows() != 1){
							$error[] = '<div class="alert alert-error">
														<button class="close" type="button" data-dismiss="alert">x</button>
														<strong>Update Author Failed! </strong>
														Change a few things up and try submitting again.
													</div>';
						}
					}
				}
				$sql = "DELETE FROM `Book Author` WHERE `ID Book`=".$_POST['id']."";
				$res = @mysql_query($sql) or die(mysql_error());
				if($res){
					foreach(explode(',',$_POST['author']) as $val){
						$sql = "INSERT INTO `Book Author` VALUES (".$_POST['id'].",(SELECT `ID` FROM `Author` WHERE LOWER(`Name`) LIKE LOWER('".$val."') LIMIT 1))";
						$res = @mysql_query($sql) or die(mysql_error());
						if(mysql_affected_rows() != 1){
							$error[] = '<div class="alert alert-error">
														<button class="close" type="button" data-dismiss="alert">x</button>
														<strong>Update Book Author Failed! </strong>
														Change a few things up and try submitting again.
													</div>';
						}
					}
				}
			}else{
				$error[] = '<div class="alert alert-error">
											<button class="close" type="button" data-dismiss="alert">x</button>
											<strong>Empty Book Author! </strong>
											Change a few things up and try submitting again.
										</div>';
			}
			if(!empty($_POST['warehouse'])){
				$sql = "DELETE FROM `Stock` WHERE `ID Book`=".$_POST['id']."";
				$res = @mysql_query($sql) or die(mysql_error());
				if($res){
					foreach($_POST['warehouse'] as $val){
						if($val == 1){$p = $_POST['price1']; $s = $_POST['stock1'];}
						else if($val == 2){$p = $_POST['price2']; $s = $_POST['stock2'];}
						$sql = "INSERT INTO `Stock` VALUES ('".$val."','".$_POST['id']."','".$s."','".$p."')";
						$res = mysql_query($sql) or die(mysql_error());
						if(mysql_affected_rows() != 1){
							$error[] = '<div class="alert alert-error">
														<button class="close" type="button" data-dismiss="alert">x</button>
														<strong>Update Stock Failed! </strong>
														Change a few things up and try submitting again.
													</div>';
						}
					}
				}
			}else{
				$error[] = '<div class="alert alert-error">
											<button class="close" type="button" data-dismiss="alert">x</button>
											<strong>Empty Warehouse! </strong>
											Change a few things up and try submitting again.
										</div>';
			}
			if(!empty($_FILES["cover"]["name"])){
				$target_dir = "../images/cover/";
				$target_file = $target_dir . basename($_FILES["cover"]["name"]);
				$uploadOk = 1;
				$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
				$newfilename = mysql_real_escape_string(trim($_POST['title'])).'.'.$imageFileType;
				$target_file = $target_dir.$newfilename;
				$check = getimagesize($_FILES["cover"]["tmp_name"]);
				if($check !== false){$uploadOk = 1;}
				else{$uploadOk = 0;
					$error[] = '<div class="alert alert-warning">
												<button class="close" type="button" data-dismiss="alert">x</button>
												<strong>Oh snap! </strong>
												File is not an image.
											</div>';
				}
				if($_FILES["cover"]["size"] > 500000){$uploadOk = 0;
					$error[] = '<div class="alert alert-warning">
												<button class="close" type="button" data-dismiss="alert">x</button>
												<strong>Oh snap! </strong>
												Sorry, your file is too large.
											</div>';
				}
				if($imageFileType != "png"){$uploadOk = 0;
					$error[] = '<div class="alert alert-warning">
												<button class="close" type="button" data-dismiss="alert">x</button>
												<strong>Oh snap! </strong>
												Sorry, only PNG files are allowed.
											</div>';
				}
				if($uploadOk == 0){
					$error[] = '<div class="alert alert-warning">
												<button class="close" type="button" data-dismiss="alert">x</button>
												<strong>Oh snap! </strong>
												Sorry, there was an error uploading your file.
											</div>';
				}else{
					if(!move_uploaded_file($_FILES["cover"]["tmp_name"], $target_file)){
						$error[] = '<div class="alert alert-warning">
													<button class="close" type="button" data-dismiss="alert">x</button>
													<strong>Oh snap! </strong>
													Sorry, there was an error uploading your file.
												</div>';
					}
				}
			}
			if(empty($error)){
				mysql_query("COMMIT");
				echo '<div class="alert alert-success">
								<button class="close" type="button" data-dismiss="alert">x</button>
								<strong>Well done! </strong>
								You successfully updated the <i>'.$_POST['title'].' <small>'.$_POST['subtitle'].'</small></i> from the Book Catalogue.
							</div>';
			}else{
				mysql_query("ROLLBACK");
				foreach($error as $value){echo $value;}
			}
			mysql_close();
		}
		mysql_open();
		$sql = "SELECT * FROM `Book` WHERE `ID`=".please('decrypt',$_GET[')'])." LIMIT 1";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) == 1){
			$row = mysql_fetch_assoc($res);
			$sql_ = "SELECT * FROM `Author` HAVING `ID` IN (SELECT `ID Author` FROM `Book Author` WHERE `ID Book`=".$row['ID'].")";
			$res_ = @mysql_query($sql_) or die(mysql_error());
			if(mysql_num_rows($res_) > 0){
				while($row_ = mysql_fetch_assoc($res_)){$author .= $row_['Name'].',';}
			}
			$sql__ = "SELECT * FROM `Category Detail` ORDER BY `Name` ASC";
			$res__ = @mysql_query($sql__) or die(mysql_error());
			if(mysql_num_rows($res__) > 0){
				while($row__ = mysql_fetch_assoc($res__)){
					$sql___ = "SELECT * FROM `Book Category` WHERE `ID Book`=".$row['ID']." AND `ID Category Detail`=".$row__['ID']." LIMIT 1";
					$res___ = @mysql_query($sql___) or die(mysql_error());
					$category .= '<option value="'.$row__['ID'].'" '.(mysql_num_rows($res___)==1 ? 'selected' : '').'>'.$row__['Name'].'</option>';
				}
			}
			$sql___ = "SELECT * FROM `Stock` WHERE `ID Book`=".$row['ID']."";
			$res___ = @mysql_query($sql___) or die(mysql_error());
			if(mysql_num_rows($res___) > 0){
				while($row___ = mysql_fetch_assoc($res___)){
					if($row___['ID Warehouse']==1){$ware1='checked'; $price1=$row___['Price']; $stock1=$row___['Stock'];}
					if($row___['ID Warehouse']==2){$ware2='checked'; $price2=$row___['Price']; $stock2=$row___['Stock'];}
				}
			}
			echo '<div class="widget">
						<h4 class="widgettitle">Book Catalogue Form</h4>
						<div class="widgetcontent nopadding">
							<form class="stdform stdform2" action="" method="post" enctype="multipart/form-data">
							<input type="hidden" name="id" value="'.$row['ID'].'">
							<p>
								<label>Title <small>The title of the book</small></label>
								<span class="field"><input type="text" name="title" id="title" class="input-xxlarge" autocomplete="off" value="'.$row['Title'].'"></span>
							</p>
							<p>
								<label>Subtitle <small>The subtitle of the book</small></label>
								<span class="field"><input type="text" name="subtitle" id="subtitle" class="input-xxlarge" autocomplete="off" value="'.$row['SubTitle'].'"></span>
							</p>
							<p>
								<label>Description <small>The description of the book</small></label>
								<span class="field"><textarea id="elm1" name="description" rows="15" cols="80" style="width: 80%" class="tinymce">'.$row['Description'].'</textarea></span>
							</p>
							<p>
								<label>Author <small>The author(s) name of the book</small></label>
								<span class="field"><textarea name="author" id="author" style="resize: vertical; height: 113px;" >'.$author.'</textarea></span>
							</p>
							<p>
								<label>Category <small>The category of the book</small></label>
								<span class="formwrapper field">
									<span class="input-append" style="margin-bottom:-10px">
										<select name="category[]" id="category1" data-placeholder="Choose Categories..." class="chzn-select" multiple="multiple" style="width:321px;" tabindex="4">
											<option value=""></option>
											'.$category.'
										</select>
									</span>
								</span>
							</p>
							<p>
								<label>Publisher <small>The publisher of the book</small></label>
								<span class="field"><input type="text" name="publisher" id="publisher" class="input-xlarge" autocomplete="off" value="'.$row['Publisher'].'"></span>
							</p>
							<p>
								<label>ISBN <small>The ISBN of the book</small></label>
								<span class="field"><input type="number" name="isbn" id="isbn" class="input-xlarge" autocomplete="off" value="'.$row['ISBN'].'"></span>
							</p>
							<p>
								<label>Language <small>The language of the book</small></label>
								<span class="field">
									<select name="language" id="language" data-placeholder="Choose a Language..." style="width:215px" class="chzn-select" tabindex="2">
										<option></option>
										<option value="Indonesia" '.($row['Language']=='Indonesia' ? 'selected' : '').'>Indonesia</option>
										<option value="English" '.($row['Language']=='English' ? 'selected' : '').'>English</option>
									</select>
								</span>
							</p>
							<p>
								<label>Page <small>The number of pages of the book</small></label>
								<span class="field"><input type="number" name="page" id="page" class="input-small" autocomplete="off" value="'.$row['Page'].'"></span>
							</p>
							<p>
								<label>Year <small>The publication date (year) of the book</small></label>
								<span class="field"><input type="number" name="year" id="year" class="input-small" autocomplete="off" value="'.$row['Year'].'"></span>
							</p>
							<p>
								<label>Warehouse <small>The warehouse of the book</small></label>
								<span class="field">
									<input type="checkbox" name="warehouse[]" value="1" '.$ware1.'> Indonesia
									<span style="margin-left:49px;">
										<input type="text" name="price1" class="input-small" placeholder="Rp" autocomplete="off" value="'.$price1.'">
										<input type="number" name="stock1" class="input-small" placeholder="Stock" autocomplete="off" value="'.$stock1.'">
									</span>
									<br>
									<input type="checkbox" name="warehouse[]" value="2" '.$ware2.'> United States
									<span style="margin-left:30px;">
										<input type="text" name="price2" class="input-small" placeholder="$" autocomplete="off" value="'.$price2.'">
										<input type="number" name="stock2" class="input-small" placeholder="Stock" autocomplete="off" value="'.$stock2.'">
									</span>
								</span>
							</p>
							<p>
							<label>Cover <small>The cover of the book</small></label>
								<span class="field">
									<img src="../images/cover/'.$row['Title'].'.png" width="25%">
									<br>
									<span class="fileupload fileupload-new" data-provides="fileupload">
										<span class="input-append" style="margin-bottom:0px">
											<span class="uneditable-input span3">
												<i class="iconfa-file fileupload-exists"></i>
												<span class="fileupload-preview"></span>
											</span>
											<span class="btn btn-file"><span class="fileupload-new">Select file</span>
											<span class="fileupload-exists">Change</span>
											<input type="file" name="cover" />
										</span>
										<a href="#" class="btn fileupload-exists" data-dismiss="fileupload">Remove</a>
									</span>
								</span>
							</p>
							<p class="stdformbutton">
								<button name="update" type="submit" class="btn btn-primary">Save Changes</button>
								<button class="btn" onclick="window.location=\'./?!=catalogue\'; return false;">Cancel</button>
							</p>
							</form>
						</div>
					</div>';
		}
		mysql_close();
	}
	function delete(){
		mysql_open();
		mysql_query("START TRANSACTION");
		$sql = "DELETE FROM `Book` WHERE `ID`=".please('decrypt',$_GET[')'])." LIMIT 1";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_affected_rows() == 1){
			mysql_query("COMMIT");
			echo '<div class="alert alert-success">
							<button class="close" type="button" data-dismiss="alert">x</button>
							<strong>Well done! </strong>
							You successfully deleted the book from the Book Catalogue.
						</div>';
		}else{
			mysql_query("ROLLBACK");
			echo '<div class="alert alert-error">
							<button class="close" type="button" data-dismiss="alert">x</button>
							<strong>Oh snap! </strong>
							Change a few things up and try submitting again.
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
