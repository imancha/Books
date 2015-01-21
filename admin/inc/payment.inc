<?php include_once('connect.inc');
/*
 * payment.inc
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
						<thead><tr><th class="head1 text-center"></th><th class="head0 text-center">#</th><th class="head1 text-center">Warehouse</th><th class="head0 text-center">Name</th><th class="head1 text-center">Account</th></tr></thead>
						<tbody>';
		mysql_open();
		$sql = "SELECT a.`ID`,a.`Name` Warehouse,b.* FROM `Warehouse` a JOIN `Payment Method` b ON a.`ID` = b.`ID Warehouse`";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				echo '<tr>
								<td></td>
								<td>'.++$i.'</td>
								<td>'.$row['Warehouse'].'</td>
								<td>'.$row['Name'].'</td>								
								<td>'.$row['Account'].'</td>																
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
