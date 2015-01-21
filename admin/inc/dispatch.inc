<?php include_once('connect.inc');
/*
 * dispatch.inc
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
						<thead><tr><th class="head1 text-center"></th><th class="head0 text-center">#</th><th class="head1 text-center">Name</th><th class="head0 text-center">Payment Method</th><th class="head1 text-center">Shipping Method</th><th class="head0 text-center">Warehouse</th><th class="head1 text-center">Status</th></tr></thead>
						<tbody>';
		mysql_open();
		$sql = "SELECT a.`First Name`,a.`Last Name`,b.`ID Order`,b.`ID Customer`,c.`Status`,d.`Name` AS Warehouse,e.`Name` AS Shipping,f.`Name` AS Payment
						FROM `Customer` a JOIN `Order` b ON a.`ID`=b.`ID Customer` JOIN `Dispatch` c ON b.`ID Order`=c.`ID Order` JOIN `Warehouse` d ON c.`ID Warehouse`=d.`ID` JOIN `Shipping Method` e ON c.`ID Shipping Method`=e.`ID` JOIN `Payment Method` f ON c.`ID Payment Method`=f.`ID`";
		$res = @mysql_query($sql) or die(mysql_error());
		if(mysql_num_rows($res) > 0){
			while($row = mysql_fetch_assoc($res)){
				echo '<tr>
								<td></td>
								<td>'.++$i.'</td>
								<td>'.$row['First Name'].' '.$row['Last Name'].'</td>
								<td>'.$row['Payment'].'</td>
								<td>'.$row['Shipping'].'</td>
								<td>'.$row['Warehouse'].'</td>
								<td>'.$row['Status'].'</td>								
							</tr>
							<div aria-hidden="false" aria-labelledby="myModalLabel" role="dialog" tabindex="-1" class="modal hide fade in" id="edit'.$i.'">
								<div class="modal-header">
									<button aria-hidden="true" data-dismiss="modal" class="close" type="button">&times;</button>
									<h3 id="myModalLabel">'.$row['First Name'].' '.$row['Last Name'].'</h3>
								</div>
								<div class="modal-body">
									<div>
										Status:
										<span>
											<select name="status">
												<option></option>
												<option>axdsdf</option>
												<option>adfjoiejf</option>
											</select>
										</span>
									</div>
								</div>
								<div class="modal-footer">
									<button data-dismiss="modal" class="btn">Cancel</button>
									<button data-dismiss="modal" class="btn btn-primary" onclick="window.location=\'./?!=categories&i=delete&)='.please('encrypt',$row_['ID']).'\'">Delete</button>
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
