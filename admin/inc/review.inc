<?php include_once('connect.inc');
/*
 * review.inc
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

	function view(){
		echo '<table id="dyntable" class="table table-bordered responsive">
						<thead><tr><th class="head1 text-center"></th><th class="head0 text-center">#</th><th class="head1 text-center">Name</th><th class="head0 text-center">Email</th><th class="head1 text-center">Book</th><th class="head0 text-center">Rate</th><th class="head1 text-center">Date</th><th class="head0 text-center">Review</th></tr></thead>
						<tbody>';
		mysql_open();
		$sql = "SELECT * FROM `Book Review`";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				$sql_ = "SELECT `Title` FROM `Book` WHERE `ID`=".$row['ID Book']." LIMIT 1";
				$res_ = @mysql_query($sql_) or die(mysql_error());
				if(mysql_num_rows($res_) == 1){$row_ = mysql_fetch_assoc($res_);}
				echo '<tr>
								<td></td>
								<td>'.++$i.'</td>
								<td>'.$row['Reviewer'].'</td>
								<td>'.$row['Email'].'</td>
								<td>'.$row_['Title'].'</td>
								<td>'.$row['Rate'].'</td>
								<td>'.$row['Date'].'</td>
								<td class="text-center"><button class="btn btn-transparent btn-success" title="view" data-target="#view'.$i.'" data-toggle="modal"><i class="iconfa-external-link"></i></button></td>
							</tr>
							<div aria-hidden="false" aria-labelledby="myModalLabel" role="dialog" tabindex="-1" class="modal hide fade in" id="view'.$i.'">
								<div class="modal-header">
									<button aria-hidden="true" data-dismiss="modal" class="close" type="button">&times;</button>
									<h3 id="myModalLabel">'.$row['Reviewer'].'</h3>
								</div>
								<div class="modal-body">
									<p>'.$row['Review'].'</p>
								</div>
								<div class="modal-footer">
									<button data-dismiss="modal" class="btn">Close</button>
								</div>
							</div><!--#myModal-->';
			}
		}		
		mysql_close();
		echo '	</tbody>
					</table>';
	}
	
	switch($_GET['i']){
		default: view();
	}
?>
