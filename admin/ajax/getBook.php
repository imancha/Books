<?php include_once('../inc/connect.inc');
/*
 * getBook.php
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
	
	mysql_open();
	$sql = "SELECT * FROM `Book` WHERE `ID`=".$_GET['id']." LIMIT 1";
	$res = @mysql_query($sql) or die(mysql_error());
	if(mysql_num_rows($res) == 1){
		$row = mysql_fetch_assoc($res);
		echo '<p>
							<label>Subtitle <small>The subtitle of the book</small></label>
							<span class="field"><input type="text" name="subtitle" id="subtitle" class="input-xxlarge" autocomplete="off" value="'.$row['SubTitle'].'"></span>
						</p>
						<p>
							<label>Description <small>The description of the book</small></label>
							<span class="field"><textarea name="description" id="autoResizeTA" class="jqte" style="resize:vertical" value="'.$row['Description'].'"></textarea></span>
						</p>
						<p>
							<label>Author <small>The author(s) name of the book</small></label>
							<span class="field">
								<span class="input-append" style="margin-bottom:-6px">
									<input type="text" name="author[]" id="author1" class="input-xlarge" autocomplete="off">
									<button type="button" class="btn" id="btn-add" data-toggle="tooltip" data-placement="right" title="Add new author"><i class="icon-plus"></i></button>
								</span>
							</span>
						</p>
						<p>
							<label>Category <small>The category of the book</small></label>
							<span class="formwrapper field">
								<span class="input-append" style="margin-bottom:-10px">
									<select name="category[]" id="category1" data-placeholder="Choose Categories..." class="chzn-select" multiple="multiple" style="width:321px;" tabindex="4">
										<option value="a" selected>a</option>
										<option value="b" selected>b</option>
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
							<button name="submit" type="submit" class="btn btn-primary">Submit Button</button>
							<button type="reset" class="btn">Reset Button</button>
						</p>';
	}
	mysql_close();
	
?>
